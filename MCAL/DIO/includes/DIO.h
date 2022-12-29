/*
 * DIO.h
 *
 * Created: 9/30/2022 7:46:30 PM
 *  Author: User
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_Cfg.h"

void DIO_WriteChannel (DIO_ChannelType ChannelId, STD_LevelType Level);
STD_LevelType DIO_ReadChannel (DIO_ChannelType ChannelId);
void DIO_ToggleChannel (DIO_ChannelType ChannelId);
uint8 DIO_ReadPort (DIO_PortType PortId);
void DIO_WritePort (DIO_PortType PortId, uint8 PortValue);
void DIO_ConfigureChannel (DIO_ChannelType ChannelId, DIO_DirType Direction);


#endif /* DIO_H_ */