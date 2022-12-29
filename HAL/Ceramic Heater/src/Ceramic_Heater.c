/*
 * Ceramic_Heater.c
 *
 * Created: 12/12/2022 2:44:09 AM
 *  Author: User
 */ 
#include "Ceramic_Heater.h"

void Heater_Init(void)
{
	DIO_ConfigureChannel(HEATER_Channel, Output);
	Heater_SetMode(HEATER_UNDEFINED_MODE);
}

void Heater_SetMode(Heater_ModeType HeaterMode)
{
	switch(HeaterMode)
	{
		case (HEATER_ON_MODE):
		{
			DIO_WriteChannel(HEATER_Channel,STD_High);
			break;
		}
		case (HEATER_OFF_MODE):
		{
			DIO_WriteChannel(HEATER_Channel,STD_Low);
			break;
		}
		case (HEATER_UNDEFINED_MODE):
		{
			break;
		}
		default: {}
	}
	
}
