/*
 * ADC_HW.h
 *
 * Created: 10/8/2022 9:39:55 PM
 *  Author: user
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

#include "STD_Types.h"

#define ADCMUX_REFS1_Bit (7)
#define ADCMUX_REFS0_Bit (6)

#define ADCSRA_ADPS0_Bit (0)
#define ADCSRA_ADPS1_Bit (1)
#define ADCSRA_ADPS2_Bit (2)
#define ADCSRA_ADIF_Bit  (4)
#define ADCSRA_ADSC_Bit	 (6)
#define ADCSRA_ADEN_Bit  (7)

#define ADMUX_Reg (*(volatile uint8 *)0x27)
#define ADCSRA_Reg (*(volatile uint8 *)0x26)
#define ADCH_Reg (*(volatile uint8 *)0x25)
#define ADCL_Reg (*(volatile uint8 *)0x24)


#endif /* ADC_HW_H_ */