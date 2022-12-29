/*
 * LED.c
 *
 * Created: 9/30/2022 8:39:53 PM
 *  Author: User
 */ 

#include "LED.h"

void LED_Init(void)
{
	DIO_ConfigureChannel(LED_0, Output);
	DIO_ConfigureChannel(LED_1, Output);
	DIO_ConfigureChannel(LED_2, Output);
}

void SetLED_ON (DIO_ChannelType ChannelId)
{
	DIO_WriteChannel(ChannelId, STD_High);
}

void SetLED_OFF (DIO_ChannelType ChannelId)
{
	DIO_WriteChannel(ChannelId, STD_Low);
}

void Flip_LED (DIO_ChannelType ChannelId)
{
	DIO_ToggleChannel(ChannelId);
}