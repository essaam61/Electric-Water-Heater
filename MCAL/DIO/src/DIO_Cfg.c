/*
 * DIO_Cfg.c
 *
 * Created: 9/30/2022 8:06:36 PM
 *  Author: User
 */ 

#include "DIO_Cfg.h"

DIO_PinCfg PinCfg[] = {
	//PORTA
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},		
	{Output, STD_High},	
	{Output, STD_High},
	{Output, STD_High},		
	{Output, STD_High},		
	{Output, STD_High},		
		
	//PORTB
	{Input, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},

	//PORTC
	{Output, STD_High},
	{Input,  STD_Low},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
	{Output, STD_High},
		
	//PORTD
	{Output, STD_High},
	{Output, STD_High},
	{Input, STD_High},
	{Output, STD_High},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low},
	{Input, STD_Low}	
			
};


void DIO_Init (void) {
	
	DIO_ChannelType count = DIO_ChannelA0;
	DIO_PortType Portx;
	DIO_ChannelType BitNo;
	
	for(count = DIO_ChannelA0 ; count<PINCOUNT ; count++)
	{
		Portx = count/8;
		BitNo = count%8;
		switch(Portx){
			case DIO_PortA:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRA_R,BitNo);
			}
			else{
				ClearBit(DDRA_R,BitNo);
			}
			break;
			
			case DIO_PortB:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRB_R,BitNo);
			}
			else{
				ClearBit(DDRB_R,BitNo);
			}
			break;
			
			case DIO_PortC:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRC_R,BitNo);
			}
			else{
				ClearBit(DDRC_R,BitNo);
			}
			break;
			
			case DIO_PortD:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRD_R,BitNo);
			}
			else{
				ClearBit(DDRD_R,BitNo);
			}
			break;
		}
		
	}
	
	
}