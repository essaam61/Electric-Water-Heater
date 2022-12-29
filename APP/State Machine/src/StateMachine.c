/*
 * StateMachine.c
 *
 * Created: 12/11/2022 2:13:50 PM
 *  Author: User
 */ 
#include "StateMachine.h"


static uint8 state;
static boolean ButtonState_Flag = FALSE;

void SM_Init(void)
{
	state = OFF_State;
	
	Ext_INT_SetCallBack(Change_WaterHeater_State);
	Ext_INT_SnControl(Ext_INT0,Rising_Edge);
	Ext_INT_Enable(Ext_INT0);	//Enable INT0
}


void SM(void)
{
	switch(state)
	{
		case (OFF_State):
		{
				//All displays are off
				//SSD_WriteNum(0,0);
				SetLED_OFF(Heater_LED);

			break;
		}
		
		case (ON_State):
		{
				WaterHeater_Control();
			
			break;
		}
		
		default: {}
	}
	
}


void Change_WaterHeater_State (void)
{	
	
	if( ButtonState_Flag == TRUE )
	{
		state = ON_State;
		ButtonState_Flag = FALSE;
		Timer0_Start(No_Prescaler);
	}
	else if( ButtonState_Flag == FALSE )
	{
		state = OFF_State;
		ButtonState_Flag = TRUE;
		SSD_WriteNum(0,0);
		Stop_WaterHeater_Operation();
	}
	else
	{
	}

}