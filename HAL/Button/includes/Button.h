/*
 * Button.h
 *
 * Created: 12/11/2022 12:21:52 PM
 *  Author: User
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "Std_Types.h"
#include "DIO.h"

#define Button_0 DIO_ChannelB0
#define Button_1 DIO_ChannelD6
#define Button_2 DIO_ChannelD2

/* Button State according to its configuration PULL UP/Down */
#define BUTTON_PRESSED  STD_High
#define BUTTON_RELEASED STD_Low


void Button_Init(void);
uint8 Button_getState(DIO_ChannelType ButtonNo);

#endif /* BUTTON_H_ */