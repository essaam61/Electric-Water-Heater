/*
* SSD.c
*
* Created: 10/1/2022 9:06:45 PM
*  Author: user
*/

#include "SSD.h"

void SSD_Init(void)
{
	DIO_ChannelType count = DIO_ChannelA4;
	
	for(count = DIO_ChannelA4 ; count<=(DIO_ChannelA7 - DIO_ChannelA4) ; count++)
	{
		DIO_ConfigureChannel(count, Output);
	}
	
	for(count = DIO_ChannelB4 ; count<=(DIO_ChannelB7 - DIO_ChannelB4) ; count++)
	{
		DIO_ConfigureChannel(count, Output);
	}
	
	DIO_ConfigureChannel(SSD_FirstDigit_En, Output);
	DIO_ConfigureChannel(SSD_SecondDigit_En, Output);
	
}


void SSD_WriteNum(uint8 FirstDigit,uint8 SecondDigit){
	uint8 PortValue = 0;
	for (uint8 w=0;w<200;w++)
	{
		PortValue = DIO_ReadPort(SSD_FirstDigit_DataPort);
		PortValue = (PortValue & 0x0F) | (FirstDigit<<4);
		DIO_WritePort(SSD_FirstDigit_DataPort,PortValue);
		DIO_WriteChannel(SSD_FirstDigit_En,STD_Low);
		_delay_us(100);
		DIO_WriteChannel(SSD_FirstDigit_En,STD_High);
		
		PortValue = DIO_ReadPort(SSD_SecondDigit_DataPort);
		PortValue = (PortValue & 0x0F) | (SecondDigit<<4);
		DIO_WritePort(SSD_SecondDigit_DataPort,PortValue);
		DIO_WriteChannel(SSD_SecondDigit_En,STD_Low);
		_delay_us(100);
		DIO_WriteChannel(SSD_SecondDigit_En,STD_High);
	}
}