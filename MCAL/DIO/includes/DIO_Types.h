/*
 * DIO_Types.h
 *
 * Created: 9/30/2022 7:36:44 PM
 *  Author: User
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
	DIO_ChannelA0=0,
	DIO_ChannelA1,
	DIO_ChannelA2,
	DIO_ChannelA3,
	DIO_ChannelA4,
	DIO_ChannelA5,
	DIO_ChannelA6,
	DIO_ChannelA7,
	
	DIO_ChannelB0,
	DIO_ChannelB1,
	DIO_ChannelB2,
	DIO_ChannelB3,
	DIO_ChannelB4,
	DIO_ChannelB5,
	DIO_ChannelB6,
	DIO_ChannelB7,
	
	DIO_ChannelC0,
	DIO_ChannelC1,
	DIO_ChannelC2,
	DIO_ChannelC3,
	DIO_ChannelC4,
	DIO_ChannelC5,
	DIO_ChannelC6,
	DIO_ChannelC7,
	
	DIO_ChannelD0,
	DIO_ChannelD1,
	DIO_ChannelD2,
	DIO_ChannelD3,
	DIO_ChannelD4,
	DIO_ChannelD5,
	DIO_ChannelD6,
	DIO_ChannelD7
	
}DIO_ChannelType;

typedef enum {
	DIO_PortA=0,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
	
}DIO_PortType;

typedef enum {
	Input=0,
	Output
}DIO_DirType;

#endif /* DIO_TYPES_H_ */