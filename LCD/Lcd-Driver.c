/*
 * Lcd_Driver.c
 *
 * Created: 3/6/2018 8:13:14 PM
 *  Author: mahmo
 */ 

#include "LCD-Driver.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <math.h>

char column_position [2] = {0x80,0xc0};

void Triger_Enable()
{
	
	LCD_EN_Port |=(1u<<LCD_EN);
	_delay_us(1);
	LCD_EN_Port &=~(1u<<LCD_EN);
	_delay_ms(3);	
	
}

void Send_4BitData(char data)
{
	
	if (data & (1u<<7))			LCD_D7_Port |= (1u<<LCD_D7);	//check bit 7 of data
	else						LCD_D7_Port &= ~(1u<<LCD_D7);	//check bit 7 of data
	
	if (data & (1u<<6))			LCD_D6_Port |= (1u<<LCD_D6);	//check bit 6 of data
	else						LCD_D6_Port &= ~(1u<<LCD_D6);	//check bit 6 of data
	
	if (data & (1u<<5))			LCD_D5_Port |= (1u<<LCD_D5);	//check bit 5 of data
	else					    LCD_D5_Port &= ~(1u<<LCD_D5);	//check bit 5 of data
	
	if (data & (1u<<4))			LCD_D4_Port |= (1u<<LCD_D4);	//check bit 4 of data
	else						LCD_D4_Port &= ~(1u<<LCD_D4);	//check bit 4 of data

	Triger_Enable();
	
	if (data & (1u<<3))			LCD_D7_Port |= (1u<<LCD_D7);	//check bit 3 of data
	else					    LCD_D7_Port &= ~(1u<<LCD_D7);	//check bit 3 of data

	if (data & (1u<<2))		    LCD_D6_Port |= (1u<<LCD_D6);	//check bit 2 of data
	else						LCD_D6_Port &= ~(1u<<LCD_D6);	//check bit 2 of data

	if (data & (1u<<1))			LCD_D5_Port |= (1u<<LCD_D5);	//check bit 1 of data
	else						LCD_D5_Port &= ~(1u<<LCD_D5);	//check bit 1 of data

	if (data & (1u<<0))		    LCD_D4_Port |= (1u<<LCD_D4);	//check bit 0 of data
	else					    LCD_D4_Port &= ~(1u<<LCD_D4);	//check bit 0 of data

	Triger_Enable();

}

void Send_A_Character(unsigned char character)
{
	
	LCD_RS_Port |= (1u<<LCD_RS);
	LCD_RW_Port &=~(1u<<LCD_RW);
	Send_4BitData(character);

}

void Send_A_Command(unsigned char command)
{
	
	LCD_RS_Port &=~(1u<<LCD_RS);
	LCD_RW_Port &=~(1u<<LCD_RW);
	Send_4BitData(command);
	
}

void Send_A_String(char *string)
{
	while (*string > 0)
	{
		Send_A_Character(*string++);
	}
}

void Goto_Location(uint8_t y , uint8_t x)
{
	Send_A_Command(column_position[y-1]+(x-1));
}


void LCD_Initializaion(void)
{
	_delay_ms(20);
	
	LCD_RW_DDR |=(1u<<LCD_RW);
	LCD_RS_DDR |=(1u<<LCD_RS);
	LCD_EN_DDR |=(1u<<LCD_EN);
	LCD_D4_DDR |=(1u<<LCD_D4);
	LCD_D5_DDR |=(1u<<LCD_D5);
	LCD_D6_DDR |=(1u<<LCD_D6);
	LCD_D7_DDR |=(1u<<LCD_D7);
	
	Send_A_Command(0x33U);
	Send_A_Command(0x32U);
	Send_A_Command(0x28U);
	Send_A_Command(0x0CU);
	Send_A_Command(0x01U);
	
}

void Send_A_String_WithLoc(uint8_t y, uint8_t x, char *StringOfCharacters)
{
	Goto_Location(y,x);
	Send_A_String(StringOfCharacters);
}

void Send_An_Integer_WithLoc(uint8_t y, uint8_t x, int IntegerToDisplay, char NumberOfDigits)
{
	char StringToDisplay[NumberOfDigits];
	itoa(IntegerToDisplay,StringToDisplay,10);
	for (int i=0;i<NumberOfDigits;i++)	Send_A_String(" ");
	Send_A_String_WithLoc(y,x,StringToDisplay);
	
}

void Send_A_Float_withloc(uint8_t y, uint8_t x ,  float number , unsigned int decimal)
{
	Goto_Location(y,x);
	
	float after=10.0;

	if (decimal == 1 )		after = after *1;

	else if (decimal==2)	after = 100.0;

	else if (decimal==3)	after = 1000.0;

	else if (decimal==4)	after = 10000.0;

	else if (decimal==5)	after = 100000.0;

	else if (decimal==6)	after = 1000000.0;

	else if (decimal==7)	after = 10000000.0;

	else if (decimal==8)	after = 100000000.0;

	int intValue = (int)number;
	float diffValue = number - (float)intValue;
	int decimalValue = (int)(diffValue * after);
	
	
	Send_An_Integer(intValue,5);
	Send_A_Character('.');
	Send_An_Integer(decimalValue,5);

}

void Send_An_Integer(int IntegerToDisplay, char NumberOfDigits)
{
		char StringToDisplay[NumberOfDigits];
		itoa(IntegerToDisplay,StringToDisplay,10);
		Send_A_String(StringToDisplay);
	
}

