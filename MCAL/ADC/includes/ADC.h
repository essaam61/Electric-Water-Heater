/*
 * ADC.h
 *
 * Created: 10/8/2022 9:40:05 PM
 *  Author: user
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "BitMath.h"
#include "ADC_HW.h"
#include "ADC_Types.h"

void ADC_Init(void);
int16 ADC_Read(ADC_ChannelType ChannelId);


#endif /* ADC_H_ */