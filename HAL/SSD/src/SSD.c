/*
* SSD.c
*
* Created: 10/1/2022 9:06:45 PM
*  Author: user
*/

#include "SSD.h"

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