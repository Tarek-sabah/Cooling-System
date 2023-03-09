/*
 * ADC_priv.h
 *
 *  Created on: Mar 3, 2023
 *      Author: tarek
 */

#ifndef ADC_ADC_PRIV_H_
#define ADC_ADC_PRIV_H_


/******************************************
  Masks
*******************************************/
/*ADMUX Register*/
#define ADC_ADMUX_MASK					0xE0
#define	ADC_REFERENCE_MASK				0x3F

/*ADCSRA Register*/
#define ADC_PRESCALER_MASK				0xF8


/*SFIOR Register*/
#define ADC_AUTO_TRIGGER_SOURCE_MASK	0X1F


/******************************************
  BITS
*******************************************/

/*ADMUX bits*/
#define	ADC_LEFT_ADJUST_BIT						5


/*ADCSRA Register*/

#define ADC_ENABLE_BIT							7
#define ADC_START_CONVERSION_BIT				6
#define ADC_AUTO_TRIGGER_BIT					5
#define ADC_INT_FLAG_BIT						4
#define ADC_INT_ENABLE_BIT						3


void __vector_16 (void) __attribute__((signal,used));




#endif /* ADC_ADC_PRIV_H_ */
