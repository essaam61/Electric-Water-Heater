/*
 * LM35.h
 *
 * Created: 10/8/2022 10:25:12 PM
 *  Author: user
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

void LM35_Init();
int16 LM35_Read(ADC_ChannelType ChannelId);

#endif /* LM35_H_ */