/*
 * Relay.c
 *
 * Created: 12/29/2022 3:44:34 PM
 *  Author: User
 */ 
#include "Relay.h"

void Relay_Init(void)
{
	DIO_ConfigureChannel(RELAY_1, Output);
	DIO_ConfigureChannel(RELAY_2, Output);
	DIO_WriteChannel(RELAY_1, STD_Low);
	DIO_WriteChannel(RELAY_2, STD_Low);
}
void Relay_switchON(DIO_ChannelType RelayNo)
{
	DIO_WriteChannel(RelayNo, STD_High);
}
void Relay_switchOFF(DIO_ChannelType RelayNo)
{
	DIO_WriteChannel(RelayNo, STD_Low);
}