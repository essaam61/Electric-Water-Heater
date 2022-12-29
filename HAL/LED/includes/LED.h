/*
 * LED.h
 *
 * Created: 9/30/2022 8:38:23 PM
 *  Author: User
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"

#define LED_0 DIO_ChannelC2
#define LED_1 DIO_ChannelC7
#define LED_2 DIO_ChannelD3

void LED_Init(void);
void SetLED_ON (DIO_ChannelType ChannelId);
void SetLED_OFF (DIO_ChannelType ChannelId);
void Flip_LED (DIO_ChannelType ChannelId);

#endif /* LED_H_ */