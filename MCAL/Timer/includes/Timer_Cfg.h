/*
 * Timer0_Cfg.h
 *
 * Created: 11/2/2022 1:35:57 PM
 *  Author: User
 */ 
#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/************************************************************
 * 			TIMER OPERATION MODES							*
 ************************************************************/
/*
 * TIMER_MODE_NONE
 * TIMER_MODE_INTERVAL
 * TIMER_MODE_CTC
 * TIMER_MODE_FAST_PWM
 * TIMER_MODE_PWM_PHASE_CORRECT
 */
#define TIMER0_OPERATION_MODE TIMER_MODE_INTERVAL
#define TIMER2_OPERATION_MODE TIMER_MODE_INTERVAL

#define TIMER0_TOP 256
#define TIMER2_TOP 256
#define TIMER0_FINAL_OVFCOUNT 6250		/* no prescaler used (prescaler = 1) | 6250 overflows means 100ms passed */
#define TIMER2_FINAL_OVFCOUNT 62500		/* no prescaler used (prescaler = 1) | 62500 overflows means 1000ms passed */


#endif /* TIMER_CFG_H_ */