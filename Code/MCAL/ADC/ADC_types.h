/*
 * ADC_types.h
 *
 *  Created on: Mar 3, 2023
 *      Author: tarek
 */

#ifndef ADC_ADC_TYPES_H_
#define ADC_ADC_TYPES_H_


typedef enum{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
}ADC_Analog_Channel;


typedef enum{
	Prescaler_2 = 1,
	Prescaler_4,
	Prescaler_8,
	Prescaler_16,
	Prescaler_32,
	Prescaler_64,
	Prescaler_128
}ADC_Prescaler_type;


typedef enum{
	AREF = 0x00,
	AVCC = 0x40,
	Reserved=0x80,
	Internal_2_56V =0xC0
}ADC_Vref_type;

typedef enum{
	RIGHT_ADJUST,
	LEFT_ADJUST,
}ADC_adjust_type;

typedef enum{
	Free_Running_mode = 0x00,
	Analog_Comparator = 0x20,
	EXTI_Request_0 = 0x40,
	TIMER0_Compare_Match = 0x60,
	TIMER0_OverFlow = 0x80,
	TIMER1_Compare_Match_B = 0xA0,
	TIMER1_OverFlow = 0xC0,
	TIMER1_Capture_Event = 0xE0,
}ADC_AUTO_TRIGGER_SOURCE;


#endif /* ADC_ADC_TYPES_H_ */
