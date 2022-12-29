/*
 * WaterHeater_Control.h
 *
 * Created: 12/12/2022 2:00:10 AM
 *  Author: User
 */ 


#ifndef WATERHEATER_CONTROL_H_
#define WATERHEATER_CONTROL_H_

#include "DIO.h"
#include "Timer.h"
#include "LM35.h"
#include "SSD.h"
#include "Button.h"
#include "LED.h"
#include "EEPROM.h"
#include "Ceramic_Heater.h"
#include "Peltier.h"
#include "GINT.h"


#define TEMP_CHANNEL ADC_Channel0
#define TEMP_SETPOINT_OFFSET 5
#define TEMP_READCOUNT 10

#define UP_Button Button_0
#define DOWN_Button Button_1
#define Heater_LED LED_1

#define EEPROM_SP_Address 0

typedef enum {
	DEFAULT_MODE=0,
	TEMPERATURE_SETTING_MODE
	
}WaterHeater_ModeType;


void WaterHeater_Control_Init(void);
void WaterHeater_Control(void);
void Read_WaterTemperature(void);
void Blink_SetPointTemperature_HeaterLED(void);
void Stop_WaterHeater_Operation(void);


#endif /* WATERHEATER_CONTROL_H_ */