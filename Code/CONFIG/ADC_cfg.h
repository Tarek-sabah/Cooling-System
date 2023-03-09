/*
 * ADC_cfg.h
 *
 *  Created on: Mar 3, 2023
 *      Author: tarek
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


#define ADC_CHANNEL_0	DIO_PA0
#define ADC_CHANNEL_1	DIO_PA1
#define ADC_CHANNEL_2	DIO_PA2
#define ADC_CHANNEL_3	DIO_PA3
#define ADC_CHANNEL_4	DIO_PA4
#define ADC_CHANNEL_5	DIO_PA5
#define ADC_CHANNEL_6	DIO_PA6
#define ADC_CHANNEL_7	DIO_PA7



typedef struct{
	ADC_Prescaler_type ADC_Prescaler;
	ADC_Vref_type ADC_Vref;
	ADC_adjust_type ADC_Adjust;
}ADC_CONFIG;

#endif /* ADC_CFG_H_ */
