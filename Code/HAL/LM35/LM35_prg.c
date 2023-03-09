/*
 * LM35_prg.c
 *
 *  Created on: Mar 3, 2023
 *      Author: tarek
 */

#include "Mcu_HW.h"

#include"STD_TYPES.h"

#include "LM35_int.h"
#include "ADC_int.h"
#include "LCD_int.h"

u16 H_LM35_Calculate_Data(u8 Channel)
{
	u16 Data;
	f32 step_size = (5*1000.0/1024.0);
	Data = (u16)(ADCLH_REG* step_size)/10;
	return Data;
}
