/*
 * Timer.c
 *
 * Created: 11/2/2022 12:14:53 AM
 *  Author: User
 */ 


#include "Timer.h"


/* Global pointer to function used to point to upper layer functions for use in Call Back */
static void (*Timer0_CallBack_Ptr)(void) = NULL_PTR;
static void (*Timer2_CallBack_Ptr)(void) = NULL_PTR;



/************************************************************
*************************************************************
 * 			          TIMER 0 FUNCTIONS						*
*************************************************************
************************************************************/
void Timer0_Init(Timer_PrescalerType prescaler, uint8 Value, boolean InterruptEnable)
{
	
	#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
	{
		ClearBit(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		ClearBit(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);
		
		TIMER0_TCNT0_R = Value;
		Timer0_Start(prescaler);
		
		if(InterruptEnable == TRUE)
		{
			SetBit(TIMER_TIMSK_R, TIMSK_TOIE0_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			ClearBit(TIMER_TIMSK_R, TIMSK_TOIE0_Bit);
		}
		else
		{
		}
		
	}
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
	{
		SetBit(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		ClearBit(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);
		
		
		TIMER0_OCR0_R = Value;
		Timer0_Start(prescaler);
		
		if(InterruptEnable == TRUE)
		{
			SetBit(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			ClearBit(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);
		}
		else
		{
		}
		
	}
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_FAST_PWM)
	{
		SetBit(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		SetBit(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);
		
		// Non inverted mode 
		ClearBit(TIMER0_TCCR0_R,TCCR0_COM00_Bit);
		SetBit(TIMER0_TCCR0_R,TCCR0_COM01_Bit);
	}
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT)
	{
		ClearBit(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
		SetBit(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);
	}
	#else
		#error "You shall define timer operation mode in Timer_Cfg.h"
	#endif
	
	
	/*
	// Prescaler = 1024 
	SetBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
	ClearBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
	SetBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	
	//	Timer/Counter Mode	//
	//TIMER0_TCNT0_R = Preload_Value;
	//SetBit(TIMER_TIMSK_R, TIMSK_TOIE0_Bit);	//Enable the overflow interrupt//
	
	
	//	 CTC Mode	
	// Select CTC Mode
	SetBit(TIMER0_TCCR0_R,TCCR0_WGM01_Bit);
	ClearBit(TIMER0_TCCR0_R,TCCR0_WGM00_Bit);
	
	TIMER0_TCNT0_R = Preload_Value;
	TIMER0_OCR0_R = 255;
	SetBit(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);	//Enable the overflow interrupt//
	*/

}

#if( (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)  ||  (TIMER0_OPERATION_MODE == TIMER_MODE_CTC) )
void Timer0_Start(Timer_PrescalerType prescaler)
{
	if (prescaler == No_Prescaler)
	{
		SetBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_8)
	{
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_64)
	{
		SetBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_256)
	{
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else if (prescaler == Prescaler_1024)
	{
		SetBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		ClearBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		SetBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
		SetBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
	}
	else
	{
	}
	
}

void Timer0_Stop (void)
{
	ClearBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
	ClearBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
	ClearBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
}



#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
void Timer0_SetPreload(uint8 preloadValue)
{
	TIMER0_TCNT0_R = preloadValue;
}

void __vector_11(void)
{
	static uint16 ovfCounter = 0;
	ovfCounter++;
	
	if(Timer0_CallBack_Ptr != NULL_PTR && ovfCounter == TIMER0_FINAL_OVFCOUNT)  /* 100 ms is passed */
	{
		(*Timer0_CallBack_Ptr)();
		ovfCounter = 0;
	}
	else
	{}
	
}





#elif( (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
void Timer0_SetCompareValue(uint8 compareValue)
{
	TIMER0_OCR0_R = compareValue;
}
#endif


uint8 Timer0_GetPreload(void)
{
	return TIMER0_TCNT0_R;
}

void Timer0_EnableInterrupt(void)
{
	#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
		SetBit(TIMER_TIMSK_R, TIMSK_TOIE0_Bit);
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
		SetBit(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);
	#endif		
}

void Timer0_DisableInterrupt(void)
{
	#if (TIMER0_OPERATION_MODE == TIMER_MODE_INTERVAL)
		ClearBit(TIMER_TIMSK_R, TIMSK_TOIE0_Bit);
	#elif (TIMER0_OPERATION_MODE == TIMER_MODE_CTC)
		ClearBit(TIMER_TIMSK_R, TIMSK_OCIE0_Bit);
	#endif
}



void Timer0_SetCallBack ( void(*Ptr2Func)(void) )
{
	Timer0_CallBack_Ptr = Ptr2Func;
}


#endif



#if( (TIMER0_OPERATION_MODE == TIMER_MODE_FAST_PWM)  ||  (TIMER0_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT) )
void Timer0_PWM(uint16 freq, uint8 dutyCycle)
{
	uint16 result =0;
	result = (dutyCycle * TIMER0_TOP)/100;
	TIMER0_OCR0_R = result;

	/*	Check for frequency then choose prescaler	*/
	SetBit(TIMER0_TCCR0_R, TCCR0_CS00_Bit);
	ClearBit(TIMER0_TCCR0_R, TCCR0_CS01_Bit);
	ClearBit(TIMER0_TCCR0_R, TCCR0_CS02_Bit);
}
#endif













/************************************************************
*************************************************************
 * 			          TIMER 2 FUNCTIONS						*
*************************************************************
************************************************************/
void Timer2_Init(Timer_PrescalerType prescaler, uint8 Value, boolean InterruptEnable)
{
	
	#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
	{
		ClearBit(TIMER2_TCCR2_R,TCCR2_WGM21_Bit);
		ClearBit(TIMER2_TCCR2_R,TCCR2_WGM20_Bit);
		
		TIMER2_TCNT2_R = Value;
		Timer2_Start(prescaler);
		
		if(InterruptEnable == TRUE)
		{
			SetBit(TIMER_TIMSK_R, TIMSK_TOIE2_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			ClearBit(TIMER_TIMSK_R, TIMSK_TOIE2_Bit);
		}
		else
		{
		}

	}
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
	{
		SetBit(TIMER2_TCCR2_R,TCCR2_WGM21_Bit);
		ClearBit(TIMER2_TCCR2_R,TCCR2_WGM20_Bit);
		
		TIMER2_OCR2_R = Value;
		Timer2_Start(prescaler);
		
		if(InterruptEnable == TRUE)
		{
			SetBit(TIMER_TIMSK_R, TIMSK_OCIE2_Bit);
		}
		else if(InterruptEnable == FALSE)
		{
			ClearBit(TIMER_TIMSK_R, TIMSK_OCIE2_Bit);
		}
		else
		{
		}
	}
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_FAST_PWM)
	{
		SetBit(TIMER2_TCCR2_R,TCCR2_WGM21_Bit);
		SetBit(TIMER2_TCCR2_R,TCCR2_WGM20_Bit);
		
		// Non inverted mode 
		ClearBit(TIMER2_TCCR2_R,TCCR2_COM20_Bit);
		SetBit(TIMER2_TCCR2_R,TCCR2_COM21_Bit);
	}
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT)
	{
		ClearBit(TIMER2_TCCR2_R,TCCR2_WGM21_Bit);
		SetBit(TIMER2_TCCR2_R,TCCR2_WGM20_Bit);
	}
	#else
		#error "You shall define timer operation mode in Timer_Cfg.h"
	#endif


}

#if( (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)  ||  (TIMER2_OPERATION_MODE == TIMER_MODE_CTC) )
void Timer2_Start(Timer_PrescalerType prescaler)
{
	if (prescaler == No_Prescaler)
	{
		SetBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_8)
	{
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_64)
	{
		SetBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_256)
	{
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else if (prescaler == Prescaler_1024)
	{
		SetBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		ClearBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else if (prescaler == ExtClk_FallingEdge)
	{
		SetBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
		SetBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
	}
	else
	{
	}
	
}

void Timer2_Stop (void)
{
	ClearBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
	ClearBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
	ClearBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
}



#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
void Timer2_SetPreload(uint8 preloadValue)
{
	TIMER2_TCNT2_R = preloadValue;
}

void __vector_5(void)
{
	static uint16 ovfCounter = 0;
	ovfCounter++;
	
	if(Timer2_CallBack_Ptr != NULL_PTR && ovfCounter == TIMER2_FINAL_OVFCOUNT)  /* 1000 ms is passed */
	{
		(*Timer2_CallBack_Ptr)();
		ovfCounter = 0;
	}
	else
	{}		
	
}




#elif( (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
void Timer2_SetCompareValue(uint8 compareValue)
{
	TIMER2_OCR2_R = compareValue;
}
#endif


uint8 Timer2_GetPreload(void)
{
	return TIMER2_TCNT2_R;
}

void Timer2_EnableInterrupt(void)
{
	#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
		SetBit(TIMER_TIMSK_R, TIMSK_TOIE2_Bit);
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
		SetBit(TIMER_TIMSK_R, TIMSK_OCIE2_Bit);
	#endif		
}

void Timer2_DisableInterrupt(void)
{
	#if (TIMER2_OPERATION_MODE == TIMER_MODE_INTERVAL)
		ClearBit(TIMER_TIMSK_R, TIMSK_TOIE2_Bit);
	#elif (TIMER2_OPERATION_MODE == TIMER_MODE_CTC)
		ClearBit(TIMER_TIMSK_R, TIMSK_OCIE2_Bit);
	#endif
}



void Timer2_SetCallBack ( void(*Ptr2Func)(void) )
{
	Timer2_CallBack_Ptr = Ptr2Func;
}



#endif



#if( (TIMER2_OPERATION_MODE == TIMER_MODE_FAST_PWM)  ||  (TIMER2_OPERATION_MODE == TIMER_MODE_PWM_PHASE_CORRECT) )
void Timer2_PWM(uint16 freq, uint8 dutyCycle)
{
	uint16 result =0;
	result = (dutyCycle * TIMER2_TOP)/100;
	TIMER2_OCR2_R = result;

	/*	Check for frequency then choose prescaler	*/
	SetBit(TIMER2_TCCR2_R, TCCR2_CS20_Bit);
	ClearBit(TIMER2_TCCR2_R, TCCR2_CS21_Bit);
	ClearBit(TIMER2_TCCR2_R, TCCR2_CS22_Bit);
}
#endif

