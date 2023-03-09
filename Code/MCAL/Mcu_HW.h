/*
 * Mcu_HW.h
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Mcu_HW.h
*
*  breif    : this file contains all registers addresses
*
*****************************************************************
*/
#ifndef MCU_HW_H_
#define MCU_HW_H_
/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
//-------------------DIO-------------------
//------------------ END of DIO------------


#define PORTA_REG  (*((volatile u8*)0x3B))
#define DDRA_REG  (*((volatile u8*)0x3A))
#define PINA_REG  (*((volatile u8*)0x39))

#define PORTB_REG  (*((volatile u8*)0x38))
#define DDRB_REG  (*((volatile u8*)0x37))
#define PINB_REG  (*((volatile u8*)0x36))

#define PORTC_REG  (*((volatile u8*)0x35))
#define DDRC_REG  (*((volatile u8*)0x34))
#define PINC_REG  (*((volatile u8*)0x33))

#define PORTD_REG  (*((volatile u8*)0x32))
#define DDRD_REG  (*((volatile u8*)0x31))
#define PIND_REG  (*((volatile u8*)0x30))

/* INTERRUPTS*/
#define SREG_REG  (*((volatile u8*)0x5F))
#define MCUCR_REG  (*((volatile u8*)0x55))
#define MCUCSR_REG  (*((volatile u8*)0x54))
#define GICR_REG  (*((volatile u8*)0x5B))
#define GIFR_REG  (*((volatile u8*)0x5A))

/******************************************
  TIMERS
*******************************************/

/*TIMERS/Counter Register*/
#define TCNT0_REG  (*((volatile u8*)0x52))

/*Timer/Counter Control*/
#define TCCR0_REG  (*((volatile u8*)0x53))

/*Timer Output Compare Register*/
#define OCR0_REG  (*((volatile u8*)0x5C))

/*Timer/Compare Timer Flag Register */
#define TIFR_REG  (*((volatile u8*)0x58))			//Contains Flags of different Counters

/*Timer/Counter Interrupt Mask Register*/

#define TIMSK_REG  (*((volatile u8*)0x59))


/******************************************
  ADC
*******************************************/

#define ADMUX_REG  		(*((volatile u8*)0x27))
#define ADCSRA_REG		(*((volatile u8*)0x26))

#define ADCH_REG  		(*((volatile u8*)0x25))
#define ADCL_REG		(*((volatile u8*)0x24))

#define ADCLH_REG		(*((volatile u16*)0x24))

#define SFIOR_REG		(*((volatile u8*)0x50))

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
#endif /* MCU_HW_H_ */
