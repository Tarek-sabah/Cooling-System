/*
 * main.h
 *
 *  Created on: Mar 1, 2023
 *      Author: tarek
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <util/delay.h>
#include "STD_TYPES.h"
#include "Port_int.h"
#include "Dio_int.h"
#include "GID_int.h"
#include "TIMER0_int.h"
#include "ADC_int.h"


#include "LCD_int.h"
#include "L298N_int.h"
#include "L298N_types.h"
#include "LM35_int.h"

//void APP_EXTI (void);
//void APP_TIMER0 (void);

void ADC_INT(void);

static u16 LM35_value;






#endif /* MAIN_H_ */
