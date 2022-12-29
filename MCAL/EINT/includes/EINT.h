/*
 * EINT.h
 *
 * Created: 10/7/2022 9:06:26 PM
 *  Author: User
 */ 


#ifndef EINT_H_
#define EINT_H_

#include "BitMath.h"
#include "EINT_HW.h"
#include "EINT_Types.h"


void Ext_INT_Enable(ExtINT_Type INTId);
void Ext_INT_Disable(ExtINT_Type INTId);
void Ext_INT_SnControl(ExtINT_Type INTId, ExtISC_Type mode);
void Ext_INT_SetCallBack ( void(*Ptr2Func)(void) );
void __vector_1(void) __attribute__ ((signal));	/*ISR Function Prototype for Ext INT0 */

#endif /* EINT_H_ */