/*
 * EEPROM.c
 *
 * Created: 10/22/2022 8:06:04 PM
 *  Author: User
 */ 
#include "EEPROM.h"


void EEPROM_write(uint16 uiAddress, uint8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR_R & (1<<EEWE_Bit))
	;
	/* Set up address and data registers */
	EEARL_R = uiAddress;
	EEARH_R = uiAddress>>8;
	EEDR_R = ucData;
	/* Write logical one to EEMWE */
	EECR_R |= (1<<EEMWE_Bit);
	/* Start eeprom write by setting EEWE */
	EECR_R |= (1<<EEWE_Bit);
}


uint8 EEPROM_read(uint16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR_R & (1<<EEWE_Bit))
	;
	/* Set up address register */
	EEARL_R = uiAddress;
	EEARH_R = uiAddress>>8;
	/* Start eeprom read by writing EERE */
	EECR_R |= (1<<EERE_Bit);
	/* Return data from data register */
	return EEDR_R;
}
