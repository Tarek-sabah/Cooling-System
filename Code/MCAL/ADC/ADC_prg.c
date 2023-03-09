/*
 * ADC_prg.c
 *
 *  Created on: Mar 3, 2023
 *      Author: tarek
 */

#include "Mcu_HW.h"
#include "STD_TYPES.h"		//Library
#include "BIT_MATH.h"
#include "DIO_int.h"		//Lower Layer interface

#include "ADC_priv.h"
#include "ADC_types.h"
#include "ADC_cfg.h"
#include "ADC_int.h"

static void (*ADC_CallBack) (void)= NULL;
static volatile u16 result=0;


void M_ADC_void_Init(const ADC_CONFIG* ADC_SETTINGS)
{

///*************************Selecting Voltage Refernce*************************/
//
	ADMUX_REG &=ADC_REFERENCE_MASK;
	ADMUX_REG |= ADC_SETTINGS->ADC_Vref;

///****************************************************************************/
//
///*************************ADC Trigger Mode*************************/
//
////	CLR_BIT(ADMUX_REG,ADC_AUTO_TRIGGER_BIT);
	SET_BIT(ADMUX_REG,ADC_AUTO_TRIGGER_BIT);
	SFIOR_REG &= ADC_AUTO_TRIGGER_SOURCE_MASK;
	SFIOR_REG |= Free_Running_mode;
///****************************************************************************/
//
///*************************ADC Selecting Adjustment*************************/
	CLR_BIT(ADMUX_REG,ADC_LEFT_ADJUST_BIT);
	SET_BIT(ADMUX_REG,ADC_SETTINGS->ADC_Adjust);
///****************************************************************************/
//
///*************************ADC Selecting Prescaler*************************/
//
	ADCSRA_REG &=ADC_PRESCALER_MASK;
	ADCSRA_REG|=ADC_SETTINGS->ADC_Prescaler;
///****************************************************************************/
//
//
///*************************ADC Clearing Interrupt Flag*************************/
//
	SET_BIT(ADCSRA_REG,ADC_INT_FLAG_BIT);
///****************************************************************************/
//
///*************************ADC Enable*************************/
//
	SET_BIT(ADCSRA_REG,ADC_ENABLE_BIT);
//
///****************************************************************************/


}
u16 M_ADC_getDigitalValueSynchNonBlocking (const ADC_Analog_Channel ADC_Channel)
{
	u16 counter =0;
	u16 Value=0;
/*************************ADC Selecting Channel*************************/

	ADMUX_REG &= ADC_ADMUX_MASK;
	ADMUX_REG |= ADC_Channel;
/****************************************************************************/

/*************************ADC Start Conversion*************************/

	SET_BIT(ADCSRA_REG,ADC_START_CONVERSION_BIT);
/****************************************************************************/


	while(((GET_BIT(ADCSRA_REG,ADC_INT_FLAG_BIT))==0) && counter <= 20000)
	{
		counter++;
	}
	counter=0;
	if((GET_BIT(ADCSRA_REG,ADC_INT_FLAG_BIT))==(1))
	{
		CLR_BIT(ADCSRA_REG,ADC_INT_FLAG_BIT);
		return ADCLH_REG;
	}



}

void M_ADC_void_EnableInt()
{
	/*************************ADC Enable Interrupt*************************/

		SET_BIT(ADCSRA_REG,ADC_INT_ENABLE_BIT);
	/****************************************************************************/

}
u16 M_ADC_getDigitalValueAsynchCallBack(ADC_Analog_Channel ADC_Channel,void (*ptr) (void))
{

	if(ptr != NULL)
	{
		ADC_CallBack = ptr;
	}
/*************************ADC Selecting Channel*************************/

	ADMUX_REG &= ADC_ADMUX_MASK;
	ADMUX_REG |= ADC_Channel;
/****************************************************************************/


/*************************ADC Start Conversion*************************/
	SET_BIT(ADCSRA_REG,ADC_START_CONVERSION_BIT);
/****************************************************************************/


}



void __vector_16 (void)
{
	ADC_CallBack();
}
