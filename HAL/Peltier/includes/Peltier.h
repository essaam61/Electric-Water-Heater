/*
 * Peltier.h
 *
 * Created: 12/12/2022 3:08:07 AM
 *  Author: User
 */ 


#ifndef PELTIER_H_
#define PELTIER_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Relay.h"


#define PELTIER_Channel RELAY_2

typedef enum
{
	PELTIER_OFF_MODE = 0,
	PELTIER_ON_MODE,
	PELTIER_UNDEFINED_MODE
}Peltier_ModeType;

void Peltier_Init(void);
void Peltier_SetMode(Peltier_ModeType PeltierMode);


#endif /* PELTIER_H_ */