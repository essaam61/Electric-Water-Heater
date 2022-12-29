/*
 * DIO.c
 *
 * Created: 9/30/2022 7:48:43 PM
 *  Author: User
 */ 

#include "DIO.h"

void DIO_WriteChannel (DIO_ChannelType ChannelId, STD_LevelType Level)
{
	DIO_PortType Portx = ChannelId/8;
	DIO_ChannelType BitNo = ChannelId%8;
	
	switch (Portx)
	{
		case DIO_PortA:
		if (Level == STD_High)
		{
			SetBit(PORTA_R,BitNo);
		}
		else{
			ClearBit(PORTA_R,BitNo);
		}
		break;
		
		case DIO_PortB:
		if (Level == STD_High)
		{
			SetBit(PORTB_R,BitNo);
		}
		else{
			ClearBit(PORTB_R,BitNo);
		}
		break;
		
		case DIO_PortC:
		if (Level == STD_High)
		{
			SetBit(PORTC_R,BitNo);
		}
		else{
			ClearBit(PORTC_R,BitNo);
		}
		break;
		
		case DIO_PortD:
		if (Level == STD_High)
		{
			SetBit(PORTD_R,BitNo);
		}
		else{
			ClearBit(PORTD_R,BitNo);
		}
		break;
	}
	
	
}
STD_LevelType DIO_ReadChannel (DIO_ChannelType ChannelId)
{
		DIO_PortType Portx = ChannelId/8;
		DIO_ChannelType BitNo = ChannelId%8;
		STD_LevelType BitValue = STD_Low;
		
		switch(Portx){
			case DIO_PortA:
			BitValue = GetBit(PINA_R,BitNo);
			break;
			case DIO_PortB:
			BitValue = GetBit(PINB_R,BitNo);
			break;
			case DIO_PortC:
			BitValue = GetBit(PINC_R,BitNo);
			break;
			case DIO_PortD:
			BitValue = GetBit(PIND_R,BitNo);
			break;
		}
		return BitValue;
	
	
}

void DIO_ToggleChannel (DIO_ChannelType ChannelId)
{
	DIO_PortType Portx = ChannelId/8;
	DIO_ChannelType BitNo = ChannelId%8;
	
	switch (Portx)
	{
		case DIO_PortA:
		ToggleBit(PORTA_R,BitNo);
		break;
		
		case DIO_PortB:
		ToggleBit(PORTB_R,BitNo);
		break;
		
		case DIO_PortC:
		ToggleBit(PORTC_R,BitNo);
		break;
		
		case DIO_PortD:
		ToggleBit(PORTD_R,BitNo);
		break;
	}
	
	
}


uint8 DIO_ReadPort (DIO_PortType PortId)
{
	uint8 Data=0;
	
	switch(PortId)
	{
		case DIO_PortA:
		Data = PORTA_R;
		break;
		
		case DIO_PortB:
		Data = PORTB_R;
		break;
		
		case DIO_PortC:
		Data = PORTC_R;
		break;
		
		case DIO_PortD:
		Data = PORTD_R;
		break;
	}
	
	return Data;
}


void DIO_WritePort (DIO_PortType PortId, uint8 PortValue)
{
	
	switch(PortId)
	{
		case DIO_PortA:
		PORTA_R = PortValue;
		break;
		
		case DIO_PortB:
		PORTB_R = PortValue;
		break;
		
		case DIO_PortC:
		PORTC_R = PortValue;
		break;
		
		case DIO_PortD:
		PORTD_R = PortValue;
		break;
	}
	

}



void DIO_ConfigureChannel (DIO_ChannelType ChannelId, DIO_DirType Direction)
{
	DIO_PortType Portx = ChannelId/8;
	DIO_ChannelType BitNo = ChannelId%8;
	
	switch (Portx)
	{
		case DIO_PortA:
		if (Direction == Output)
		{
			SetBit(DDRA_R,BitNo);
		}
		else{
			ClearBit(DDRA_R,BitNo);
		}
		break;
		
		case DIO_PortB:
		if (Direction == Output)
		{
			SetBit(DDRB_R,BitNo);
		}
		else{
			ClearBit(DDRB_R,BitNo);
		}
		break;
		
		case DIO_PortC:
		if (Direction == Output)
		{
			SetBit(DDRC_R,BitNo);
		}
		else{
			ClearBit(DDRC_R,BitNo);
		}
		break;
		
		case DIO_PortD:
		if (Direction == Output)
		{
			SetBit(DDRD_R,BitNo);
		}
		else{
			ClearBit(DDRD_R,BitNo);
		}
		break;
	}
	
	
}