/*
 * main.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
#include <util/delay.h>
#include "main.h"
#include "Mcu_HW.h"

extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
extern const TIMER0_SETTINGS_CONFIG TIMER0_SETTINGS_PARAMETERS;
const ADC_CONFIG ADC_SETTINGS;

int main()
{

/**********************************INTIALIZATION****************************************/
	Port_Init(PORT_Config_Arr);
	M_TIMER0_void_Timer_Init(&TIMER0_SETTINGS_PARAMETERS);
	M_ADC_void_Init(&ADC_SETTINGS);
	L298N_Init(L298N_FORWARD,L298N_ENABLE);
	H_LCD_void_Init();
/*************************************************************************************/


	M_ADC_void_EnableInt();
	M_GID_void_Enable();


	H_LCD_void_gotoXY(1, 1);
	H_LCD_void_sendString("Temperature: ");


	_delay_ms(500);

	while(1)
	{
		M_ADC_getDigitalValueAsynchCallBack(1,ADC_INT);
		H_LCD_void_gotoXY(1, 2);
		H_LCD_void_sendIntNum(LM35_value);
		H_LCD_void_gotoXY(1, 3);
		H_LCD_void_sendString("Duty: ");

		if(LM35_value<=25)
		{
			L298N_Init(L298N_FORWARD,L298N_DISABLE);
			H_LCD_void_gotoXY(1, 4);
			H_LCD_void_sendIntNum(0);

		}
		else if(LM35_value>25 && LM35_value<=35)
		{
			L298N_Init(L298N_FORWARD,L298N_ENABLE);
			L298N_Start(5,50);
			H_LCD_void_gotoXY(1, 4);
			H_LCD_void_sendIntNum(50);
		}
		else if(LM35_value>35)
		{
			L298N_Init(L298N_FORWARD,L298N_ENABLE);
			L298N_Start(5,80);
			H_LCD_void_gotoXY(1, 4);
			H_LCD_void_sendIntNum(80);
		}

	}
	return 0;
}

void ADC_INT(void)
{
	LM35_value=H_LM35_Calculate_Data(1);
}


