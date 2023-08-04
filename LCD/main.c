/*
 * LCD Driver
 *
 * Created: 7/23/2023 12:19:53 PM
 * Author : Khaled Eyada
 */ 

#define F_CPU 8000000UL
#include "../HAL/LCD/lcd.h"
#include "../GENERAL/std_types.h"
#include <util/delay.h>


int main(){
	LCD_init();//initialize the lcd
	/* design the shape */
	u8 sepcialCharacterDesigne[8]={0b00000110,
							0b00000110,
							0b00001111,
							0b00000110,
							0b00000110,
							0b00001111,
							0b00001111,
	};
	LCD_saveSpecialCharacter(1,sepcialCharacterDesigne);//save the designed character
	LCD_moveCursor(0,0);//move the cursor back to position row 0 and column 0
	LCD_displayCharacter(1);
	char x='0';//initialize a variable with type character with initial value of character '0'
	LCD_moveCursor(0,3);//move the cursor back to position row 0 and column 3
	LCD_displayString("Khaled");//display a string with the name Khaled
		while(1)
		{
			LCD_displayCharacter(x++);//display the character saved in variable x then go to the next character in the ascii table
			_delay_ms(500);//wait 500 milli seconds
			LCD_moveCursor(2,3);//move the cursor back to position row 2 and column 3
			LCD_displayCharacter(x++);//display the character saved in variable x then go to the next character in the ascii table
			/* this if is mainly made to reset the x variable when it reaches the end of the ascii table */
			if (x=='9') // if variable x contains character 9 
			{
				x='0'; //make x contain character '0' again
			}
		}
		return 0;
}
