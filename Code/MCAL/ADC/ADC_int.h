/*
 * ADC_int.h
 *
 *  Created on: Mar 3, 2023
 *      Author: tarek
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

#include "ADC_types.h"
#include "ADC_cfg.h"

void M_ADC_void_Init(const ADC_CONFIG* ADC_SETTINGS);
u16 M_ADC_getDigitalValueSynchNonBlocking (const ADC_Analog_Channel ADC_Channel);
u16 M_ADC_getDigitalValueAsynchCallBack(ADC_Analog_Channel ADC_Channel,void (*ptr) (void));
void M_ADC_void_EnableInt();

#endif /* ADC_ADC_INT_H_ */
