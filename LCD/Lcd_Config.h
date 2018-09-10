/*
 * Lcd_Config.h
 *
 * Created: 3/6/2018 9:11:36 PM
 *  Author: mahmo
 */ 

#ifndef Lcd_Config_H_
#define Lcd_Config_H_

#include <avr/io.h>

#define LCD_RW (2u)
#define LCD_RW_DDR (DDRB)
#define LCD_RW_Port (PORTB)

#define LCD_RS (1u)
#define LCD_RS_DDR (DDRB)
#define LCD_RS_Port (PORTB)

#define LCD_EN (3u)
#define LCD_EN_DDR (DDRB)
#define LCD_EN_Port (PORTB)


#define LCD_D4 (4u)
#define LCD_D4_DDR (DDRA)
#define LCD_D4_Port (PORTA)

#define LCD_D5 (5u)
#define LCD_D5_DDR (DDRA)
#define LCD_D5_Port (PORTA)



#define LCD_D6 (6u)
#define LCD_D6_DDR (DDRA)
#define LCD_D6_Port (PORTA)

#define LCD_D7 (7u)
#define LCD_D7_DDR (DDRA)
#define LCD_D7_Port (PORTA)

#endif /* Lcd_Config_H_ */