/*
 * Lcd driver 
 *
 * Created: 3/6/2018 9:11:36 PM
 *  Author: Mahmoud gaber :)
 */ 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	LCD_Initializaion();
	Send_A_String_WithLoc(1,1,"adc0");
	Send_A_Float_withloc(2,3,111.158,2);

	while (1)
	{	
		Send_An_Integer_WithLoc(1,7,15000,4);
		_delay_ms(100);
	}
}