/*
 * Timer.h
 *
 * Created: 11/2/2022 12:14:44 AM
 *  Author: User
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "BitMath.h"
#include "Timer_HW.h"
#include "Timer_Cfg.h"
#include "Timer_Types.h"


#define TIMER_MODE_NONE					-1
#define TIMER_MODE_INTERVAL				0
#define TIMER_MODE_CTC					1
#define TIMER_MODE_FAST_PWM				2
#define TIMER_MODE_PWM_PHASE_CORRECT	3


/* TIMER 0 BITS */
#define TCCR0_CS00_Bit 0
#define TCCR0_CS01_Bit 1
#define TCCR0_CS02_Bit 2
#define TCCR0_WGM00_Bit 3
#define TCCR0_COM00_Bit 4
#define TCCR0_COM01_Bit 5
#define TCCR0_WGM01_Bit 6


/* TIMER 2 BITS */
#define TCCR2_CS20_Bit 0
#define TCCR2_CS21_Bit 1
#define TCCR2_CS22_Bit 2
#define TCCR2_WGM21_Bit 3
#define TCCR2_COM20_Bit 4
#define TCCR2_COM21_Bit 5
#define TCCR2_WGM20_Bit 6

/* TIMSK REGISTER BITS */
#define TIMSK_TOIE0_Bit 0
#define TIMSK_OCIE0_Bit	1
#define TIMSK_TOIE2_Bit 6
#define TIMSK_OCIE2_Bit	7



/***             TIMER 0 MODULE APIS			***/
void Timer0_Init(Timer_PrescalerType prescaler, uint8 Value, boolean InterruptEnable);
void Timer0_Start(Timer_PrescalerType prescaler);
void Timer0_Stop (void);
void Timer0_SetPreload(uint8 preloadValue);
void __vector_11(void) __attribute__ ((signal));    /*ISR Function Prototype for TMR0 OVF*/
void Timer0_SetCompareValue(uint8 compareValue);
void __vector_10(void) __attribute__ ((signal));	/*ISR Function Prototype for TMR0 CTC*/
uint8 Timer0_GetPreload(void);
void Timer0_EnableInterrupt(void);
void Timer0_DisableInterrupt(void);
void Timer0_SetCallBack ( void(*Ptr2Func)(void) );
void Timer0_PWM(uint16 freq, uint8 dutyCycle);


/***             TIMER 2 MODULE APIS			***/
void Timer2_Init(Timer_PrescalerType prescaler, uint8 Value, boolean InterruptEnable);
void Timer2_Start(Timer_PrescalerType prescaler);
void Timer2_Stop (void);
void Timer2_SetPreload(uint8 preloadValue);
void __vector_5(void) __attribute__ ((signal));		/*ISR Function Prototype for TMR2 OVF*/
void Timer2_SetCompareValue(uint8 compareValue);
void __vector_4(void) __attribute__ ((signal));		/*ISR Function Prototype for TMR2 CTC*/
uint8 Timer2_GetPreload(void);
void Timer2_EnableInterrupt(void);
void Timer2_DisableInterrupt(void);
void Timer2_SetCallBack ( void(*Ptr2Func)(void) );
void Timer2_PWM(uint16 freq, uint8 dutyCycle);


#endif /* TIMER_H_ */