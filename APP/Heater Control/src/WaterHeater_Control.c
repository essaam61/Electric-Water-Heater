/*
 * WaterHeater_Control.c
 *
 * Created: 12/12/2022 1:59:56 AM
 *  Author: User
 */ 
#include "WaterHeater_Control.h"

static WaterHeater_ModeType WaterHeater_mode;

volatile static uint8 Temperature;
//static int8 Temp[10];
static uint8 TempReadings_Avg = 0;
static uint8 Setpoint;
//static int8 Sp[10];

static uint8 ButtonsReleased_Counter = 0;

static boolean StartLEDTimer_Flag = TRUE;
static boolean StartSSDTimer_Flag = FALSE;
static boolean LED_Blink_Flag = FALSE;
static boolean SSD_Blink_Flag = FALSE;

static boolean TempDisplay_Flag = FALSE;
static boolean Display_Flag = TRUE;


void WaterHeater_Control_Init(void)
{
	WaterHeater_mode = DEFAULT_MODE;
	Setpoint = 45;
	
	DIO_Init();
	Button_Init();
	LED_Init();
	LM35_Init();
	Heater_Init();
	Peltier_Init();
	GINT_Enable_AllInterrupts();
	Timer0_SetCallBack(Read_WaterTemperature);
	Timer2_SetCallBack(Display_Blink_SetPointTemperature_LED);
	Timer0_Init(NoClkSrc,0,TRUE);
	Timer2_Init(NoClkSrc,0,TRUE);
	
	if(EEPROM_read(EEPROM_SP_Address) != 255)
	{
		Setpoint = EEPROM_read(EEPROM_SP_Address);
	}
}

void WaterHeater_Control(void)
{
	static boolean ButtonDebouncing_Flag = FALSE;
	
	
	switch(WaterHeater_mode)
	{
		case(DEFAULT_MODE):
		{
		

			
			if( (Setpoint - TempReadings_Avg) == 5)
			{
				Heater_SetMode(HEATER_ON_MODE);
				Peltier_SetMode(PELTIER_OFF_MODE);
				
				if(StartLEDTimer_Flag == TRUE)
				{
					Timer2_Start(No_Prescaler);
					
					StartLEDTimer_Flag = FALSE;
					LED_Blink_Flag = TRUE;
				}
				else {}
			}
			else if( (TempReadings_Avg - Setpoint) == 5)
			{
				Heater_SetMode(HEATER_OFF_MODE);
				Peltier_SetMode(PELTIER_ON_MODE);
				
				Timer2_Stop();
				LED_Blink_Flag = FALSE;
				StartLEDTimer_Flag = TRUE;
				SetLED_ON(Heater_LED);
			}
			else
			{
				Timer2_Stop();
				LED_Blink_Flag = FALSE;
				StartLEDTimer_Flag = TRUE;
				Heater_SetMode(HEATER_OFF_MODE);
				Peltier_SetMode(PELTIER_OFF_MODE);
				SetLED_OFF(Heater_LED);
			}
			
			
			
			
			if( Button_getState(UP_Button) == BUTTON_PRESSED || Button_getState(DOWN_Button) == BUTTON_PRESSED )
			{
				Timer2_Stop();
				LED_Blink_Flag = FALSE;
				StartLEDTimer_Flag = TRUE;
				SetLED_OFF(Heater_LED);
				
				WaterHeater_mode = TEMPERATURE_SETTING_MODE;
				StartSSDTimer_Flag = TRUE;
				ButtonDebouncing_Flag = TRUE;
			}
			else
			{}
			
			break;
		}
		
		case(TEMPERATURE_SETTING_MODE):
		{
			if(StartSSDTimer_Flag == TRUE)
			{
				Timer2_Start(No_Prescaler);
				
				SSD_Blink_Flag = TRUE;
				StartSSDTimer_Flag = FALSE;
			}
			else {}
						
			
			if(ButtonDebouncing_Flag == TRUE)
			{
				while( Button_getState(UP_Button) == BUTTON_PRESSED || Button_getState(DOWN_Button) == BUTTON_PRESSED );
				ButtonDebouncing_Flag = FALSE;
			}
						
			
			if( Button_getState(UP_Button) == BUTTON_PRESSED && Setpoint < 75 )
			{
				Setpoint += TEMP_SETPOINT_OFFSET;
				EEPROM_write(EEPROM_SP_Address, Setpoint);
				
				ButtonDebouncing_Flag = TRUE;
				ButtonsReleased_Counter = 0;
			}
			else if( Button_getState(DOWN_Button) == BUTTON_PRESSED && Setpoint > 35 )
			{
				Setpoint -= TEMP_SETPOINT_OFFSET;
				EEPROM_write(EEPROM_SP_Address, Setpoint);
				
				ButtonDebouncing_Flag = TRUE;
				ButtonsReleased_Counter = 0;
			}
			else if( Button_getState(UP_Button) == BUTTON_RELEASED && Button_getState(DOWN_Button) == BUTTON_RELEASED )
			{
				if( ButtonsReleased_Counter == 5)
				{
					Timer2_Stop();
					WaterHeater_mode = DEFAULT_MODE;
					SSD_Blink_Flag = FALSE;
					ButtonsReleased_Counter = 0;
					TempDisplay_Flag = TRUE;
				}
				else 
				{}
					
			}
			else 
			{}
			
			
			break;
		}
		
		default: {}
	}
	
	
}




void Read_WaterTemperature(void)
{
	uint8 Temp_firstDigit=0, Temp_secondDigit=0;
	static uint8 prevTemp = 0;
	static uint16 Temp_Sum = 0;
	static uint8 TempReadings_Counter = 0;
	
	TempReadings_Counter++;
	
	
	Temperature = LM35_Read(TEMP_CHANNEL);
	/* Check to display temperature to avoid many writings and blinkings on SSD */
	if( (Temperature != prevTemp && WaterHeater_mode == DEFAULT_MODE) || TempDisplay_Flag == TRUE)
	{
		/* SSD Display */
		Temp_secondDigit = Temperature % 10;
		Temp_firstDigit = Temperature / 10;
		SSD_WriteNum(Temp_firstDigit, Temp_secondDigit);
		
		TempDisplay_Flag = FALSE;
	}
	prevTemp = Temperature;
	
	
	Temp_Sum += Temperature;
	if( TempReadings_Counter == TEMP_READCOUNT )
	{
		TempReadings_Avg = Temp_Sum / TEMP_READCOUNT;
		TempReadings_Counter = 0;
		Temp_Sum = 0;
	}
	else
	{
	}
	
}


void Display_Blink_SetPointTemperature_LED(void)
{
	ButtonsReleased_Counter++;
	
	uint8 Setpoint_firstDigit=0, Setpoint_secondDigit=0;

	if( LED_Blink_Flag == TRUE )
	{
		Flip_LED(Heater_LED);
	}
	else if( SSD_Blink_Flag == TRUE )
	{
		if( Display_Flag == TRUE )
		{
			/* SSD Display */
			Setpoint_secondDigit = Setpoint % 10;
			Setpoint_firstDigit = Setpoint / 10;
			SSD_WriteNum(Setpoint_firstDigit, Setpoint_secondDigit);

			Display_Flag = FALSE;
		}
		else if( Display_Flag == FALSE )
		{
			SSD_WriteNum(0,0);
			Display_Flag = TRUE;
		}

	}
	else {}
	
	
}



void Stop_WaterHeater_Operation(void)
{
	Timer0_Stop();
	Timer2_Stop();
	StartSSDTimer_Flag = TRUE;
	StartLEDTimer_Flag = TRUE;
}