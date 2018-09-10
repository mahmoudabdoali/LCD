/*
 * Lcd_Driver.h
 *
 * Created: 3/6/2018 8:58:43 PM
 *  Author: mahmo
 */ 


#ifndef LCD-DRIVER_H_
#define LCD-DRIVER_H_

#define F_CPU (8000000UL)
#include <stdint.h>
#include <util/delay.h>

#include "Lcd_Config.h"

void LCD_Initializaion(void);

void Send_A_Character(unsigned char character);

void Send_A_String(char *string);

void Goto_Location(uint8_t y , uint8_t x);

void Triger_Enable(void);

void Send_A_Command(unsigned char command);

void Send_A_String_WithLoc(uint8_t y, uint8_t x, char *StringOfCharacters);

void Send_An_Integer_WithLoc(uint8_t y, uint8_t x, int IntegerToDisplay, char NumberOfDigits);

void Send_4BitData(char data);

void Send_A_Float_withloc(uint8_t y, uint8_t x ,  float number , unsigned int decimal);

void Send_An_Integer(int IntegerToDisplay, char NumberOfDigits);

#endif /* LCD-DRIVER_H_ */