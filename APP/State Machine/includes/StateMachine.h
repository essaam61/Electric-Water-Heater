/*
 * StateMachine.h
 *
 * Created: 12/11/2022 2:13:17 PM
 *  Author: User
 */ 


#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Button.h"
#include "SSD.h"
#include "EINT.h"
#include "GINT.h"
#include "WaterHeater_Control.h"


#define OFF_State 0
#define ON_State  1

#define ON_OFF_Button Button_2

void SM_Init(void);
void SM(void);
void Change_WaterHeater_State (void);


#endif /* STATEMACHINE_H_ */