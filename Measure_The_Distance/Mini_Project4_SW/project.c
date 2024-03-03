/*
 * project.c
 *
 *  Created on: Feb 26, 2024
 *      Author: samy
 */

#include "std_types.h"
#include "lcd.h"
#include "g_interrupt.h"
#include "ultrasonic.h"
#include <util/delay.h>

extern uint8 g_timeHigh;
int main()
{

	uint16 Distance =0;
	LCD_init();
	LCD_clearScreen();
	Global_interruptEnable();
	LCD_displayString("welcome");
	_delay_ms(500);
	LCD_clearScreen();
	Ultrasonic_init();
	LCD_displayString("Distance = ");



	while(1)
	{
		Distance=Ultrasonic_readDistance();
		LCD_moveCursor(0,11);

		LCD_intgerToString(Distance);
		if(Distance<100)
		{
			LCD_displayCharacter(' ');
		}
		_delay_ms(30);
		LCD_moveCursor(0,14);
		LCD_displayString("CM");
		_delay_ms(100);
	}



	return 0;
}
