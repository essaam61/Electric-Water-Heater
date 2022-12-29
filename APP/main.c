/*
 * GP_Electric_Water_Heater.c
 *
 * Created: 12/11/2022 11:54:27 AM
 * Author : User
 */ 
#include "StateMachine.h"
#include "WaterHeater_Control.h"


int main(void)
{
	WaterHeater_Control_Init();
	App_SM_Init();
	
	SSD_WriteNum(0,0);
    while (1) 
    {
		App_SM();
    }
}

