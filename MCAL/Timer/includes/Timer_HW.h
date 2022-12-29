/*
 * Timer_HW.h
 *
 * Created: 11/2/2022 12:14:34 AM
 *  Author: User
 */ 


#ifndef TIMER_HW_H_
#define TIMER_HW_H_

#include "STD_Types.h"


/************************************************************
 * 			COMMON TIMERS REGISTERS							*
 ************************************************************/
#define TIMER_TIMSK_R *((volatile uint8*)0x59)
#define TIMER_TIFR_R  *((volatile uint8*)0x58)


/************************************************************
 * 			TIMER 0 REGISTERS							*
 ************************************************************/
#define TIMER0_TCCR0_R *((volatile uint8*)0x53)
#define TIMER0_TCNT0_R *((volatile uint8*)0x52)
#define TIMER0_OCR0_R  *((volatile uint8*)0x5C)


/************************************************************
 * 			TIMER 2 REGISTERS							*
 ************************************************************/
#define TIMER2_TCCR2_R *((volatile uint8*)0x45)
#define TIMER2_TCNT2_R *((volatile uint8*)0x44)
#define TIMER2_OCR2_R  *((volatile uint8*)0x43)

#endif /* TIMER_HW_H_ */

