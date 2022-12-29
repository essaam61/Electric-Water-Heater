/*
 * LCD.h
 *
 * Created: 10/7/2022 6:30:21 AM
 *  Author: User
 */ 
#include "DIO.h"
#include "Clock.h"

#ifndef LCD_H_
#define LCD_H_

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3

#define LCD_DataPort DIO_PortA

void LCD_Init(void);
void LCD_Cmd(uint8 cmd);
void LCD_Char(uint8 data);
void LCD_String(int8 * string);
void LCD_SetPos(uint8 LineNo, uint8 Pos);
void LCD_Custom_Char(uint8 Memloc,uint8 * msg);

/* Special letters arrays */
/*
uint8 heartChar[];

uint8 AlefChar[];
uint8 HChar[];
uint8 MeemChar[];
uint8 DalChar[];
uint8 AeenChar[];
uint8 SaadChar[];
uint8 AlefMeshHamzaChar[];
uint8 MeemEndChar[];
*/

#endif /* LCD_H_ */