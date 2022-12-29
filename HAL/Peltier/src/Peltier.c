/*
 * Peltier.c
 *
 * Created: 12/12/2022 3:08:31 AM
 *  Author: User
 */ 
#include "Peltier.h"


void Peltier_Init(void)
{
	DIO_ConfigureChannel(PELTIER_Channel, Output);
	Peltier_SetMode(PELTIER_UNDEFINED_MODE);
}

void Peltier_SetMode(Peltier_ModeType PeltierMode)
{
	switch(PeltierMode)
	{
		case (PELTIER_ON_MODE):
		{
			DIO_WriteChannel(PELTIER_Channel,STD_High);
			break;
		}
		case (PELTIER_OFF_MODE):
		{
			DIO_WriteChannel(PELTIER_Channel,STD_Low);
			break;
		}
		case (PELTIER_UNDEFINED_MODE):
		{
			break;
		}
		default: {}
	}
	
}
