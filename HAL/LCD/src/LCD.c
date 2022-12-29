/*
 * LCD.c
 *
 * Created: 10/7/2022 6:30:31 AM
 *  Author: User
 */ 

#include "LCD.h"


void LCD_Init(void)
{
	DIO_WriteChannel(LCD_RW, STD_Low);
	DIO_WriteChannel(LCD_E, STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(100);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);	//Set Function 4-Bit & 2Line & 5*8 Dots
	LCD_Cmd(0x06);	//Entry mode move to right and no shift
	LCD_Cmd(0x0C);	//Display on & Cursor off and no blink
	LCD_Cmd(0b00001111);	
	LCD_Cmd(0x01);	//Clear LCD
	
}


void LCD_Cmd(uint8 cmd)
{
	uint8 PortValue = 0;
	DIO_WriteChannel(LCD_RS, STD_Low);	// Select command
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (cmd & 0xF0);
	DIO_WritePort(LCD_DataPort, PortValue);
	DIO_WriteChannel(LCD_E, STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E, STD_High);
	
	_delay_ms(5);
	
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (cmd << 4);
	DIO_WritePort(LCD_DataPort, PortValue);
	DIO_WriteChannel(LCD_E, STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E, STD_High);
	_delay_ms(2);
	
}
void LCD_Char(uint8 data)
{
	uint8 PortValue = 0;
	DIO_WriteChannel(LCD_RS, STD_High); // Select data
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (data & 0xF0);
	DIO_WritePort(LCD_DataPort, PortValue);
	DIO_WriteChannel(LCD_E, STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E, STD_High);
	
	_delay_ms(5);
	
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F) | (data << 4);
	DIO_WritePort(LCD_DataPort, PortValue);
	DIO_WriteChannel(LCD_E, STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E, STD_High);
	_delay_ms(2);
	
	
	
}
void LCD_String(int8 * string)
{
	uint8 i = 0;
	while(string[i] != '\0')
	{
		LCD_Char(string[i]);
		i++;
	}
	
}

void LCD_SetPos(uint8 LineNo, uint8 Pos)
{
	switch(LineNo)
	{
		case 1:
		LCD_Cmd((0x80 | (Pos & 0x0F)));
		break;
		
		case 2:
		LCD_Cmd((0xC0 | (Pos & 0x0F)));
		break;
		
	}
}

void LCD_Custom_Char(uint8 Memloc,uint8 * msg)
{
	if(Memloc < 8)
	{
		LCD_Cmd(0x40 + (Memloc*8));
		for(uint8 i=0;i<8;i++)
		{
			LCD_Char(msg[i]);
		}
	}
}






/* Special letters arrays */
/*
uint8 heartChar[] = {
	0x00,
	0x0E,
	0x15,
	0x11,
	0x0A,
	0x04,
	0x00,
	0x00
};

uint8 AlefChar[] = {
  0x00,
  0x06,
  0x0C,
  0x00,
  0x04,
  0x04,
  0x04,
  0x00
};

uint8 HChar[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x0C,
  0x02,
  0x1F,
  0x00
};

uint8 MeemChar[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x0E,
  0x1B,
  0x0E
};

uint8 DalChar[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x02,
  0x02,
  0x0F,
  0x00
};


uint8 AeenChar[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x07,
  0x04,
  0x1F,
  0x00
};

uint8 SaadChar[] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x0A,
  0x0D,
  0x1F,
  0x00
};

uint8 AlefMeshHamzaChar[] = {
  0x00,
  0x00,
  0x00,
  0x02,
  0x02,
  0x02,
  0x03,
  0x00
};

uint8 MeemEndChar[] = {
 0x00,
 0x00,
 0x00,
 0x00,
 0x0E,
 0x1A,
 0x1E,
 0x10
};

*/