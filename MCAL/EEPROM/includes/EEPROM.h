/*
 * EEPROM.h
 *
 * Created: 10/22/2022 8:02:07 PM
 *  Author: User
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "EEPROM_HW.h"
#include "BitMath.h"

#define EERE_Bit 0
#define EEWE_Bit 1
#define EEMWE_Bit 2
#define EERIE_Bit 3

void EEPROM_write(uint16 uiAddress, uint8 ucData);
uint8 EEPROM_read(uint16 uiAddress);


#endif /* EEPROM_H_ */