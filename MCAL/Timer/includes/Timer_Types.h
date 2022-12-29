/*
 * Timer_Types.h
 *
 * Created: 11/2/2022 1:32:54 PM
 *  Author: User
 */ 


#ifndef TIMER_TYPES_H_
#define TIMER_TYPES_H_

typedef enum
{
	NoClkSrc=0,
	No_Prescaler,
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024,
	ExtClk_FallingEdge,
	ExtClk_RisingEdge
	
}Timer_PrescalerType;



#endif /* TIMER_TYPES_H_ */