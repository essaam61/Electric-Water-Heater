/*
 * EINT.c
 *
 * Created: 10/7/2022 9:23:07 PM
 *  Author: User
 */ 

#include "EINT.h"
#include "LED.h"

static void (*ExtINT_CallBack_Ptr)(void) = NULL_PTR;


void Ext_INT_Enable(ExtINT_Type INTId)
{
	switch(INTId)
	{
		case Ext_INT0:
		SetBit(GICR_R, GICR_INT0_Bit);
		break;
		
		case Ext_INT1:
		SetBit(GICR_R, GICR_INT1_Bit);
		break;
		
		case Ext_INT2:
		SetBit(GICR_R, GICR_INT2_Bit);
		break;
	}
}
void Ext_INT_Disable(ExtINT_Type INTId)
{
		switch(INTId)
		{
			case Ext_INT0:
			ClearBit(GICR_R, GICR_INT0_Bit);
			break;
			
			case Ext_INT1:
			ClearBit(GICR_R, GICR_INT1_Bit);
			break;
			
			case Ext_INT2:
			ClearBit(GICR_R, GICR_INT2_Bit);
			break;
		}
}
void Ext_INT_SnControl(ExtINT_Type INTId, ExtISC_Type mode)
{
		switch(INTId)
		{
			case Ext_INT0:
			MCUCR_R |= (mode<<0);
			break;
			
			case Ext_INT1:
			MCUCR_R |= (mode<<2);
			break;
			
			case Ext_INT2:
			if (mode == Falling_Edge)
			{
				ClearBit(MCUCSR_R, MCUCSR_INT2_ISC2_Bit);
			}
			else if(mode == Rising_Edge)
			{
				SetBit(MCUCSR_R, MCUCSR_INT2_ISC2_Bit);
			}
			else {
				
			}
			break;
		}
	
}

void Ext_INT_SetCallBack ( void(*Ptr2Func)(void) )
{
	ExtINT_CallBack_Ptr = Ptr2Func;
}



void __vector_1(void)
{
	(*ExtINT_CallBack_Ptr)();

}