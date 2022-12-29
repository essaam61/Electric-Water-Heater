/*
 * DIO_HW.h
 *
 * Created: 9/30/2022 7:31:20 PM
 *  Author: User
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

#include "STD_Types.h"

#define PORTA_R *((volatile uint8*)0x3B)
#define DDRA_R *((volatile uint8*)0x3A)
#define PINA_R *((volatile uint8*)0x39)

#define PORTB_R *((volatile uint8*)0x38)
#define DDRB_R *((volatile uint8*)0x37)
#define PINB_R *((volatile uint8*)0x36)

#define PORTC_R *((volatile uint8*)0x35)
#define DDRC_R *((volatile uint8*)0x34)
#define PINC_R *((volatile uint8*)0x33)

#define PORTD_R *((volatile uint8*)0x32)
#define DDRD_R *((volatile uint8*)0x31)
#define PIND_R *((volatile uint8*)0x30)


#endif /* DIO_HW_H_ */