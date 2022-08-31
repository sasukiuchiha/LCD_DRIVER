/*
 * LCE_DRIVER.c
 *
 * Created: 8/23/2022 4:27:09 PM
 * Author : moham
 */ 

#include "LCD_interface.h"


int main(void)
{

LCD_init();

u8 pattern[]={0x00,0x1f,0x01,0x10,0x16,0x12,0x00,0x03};
    /* Replace with your application code */
    while (1) 
    {
		
		
		LCD_Make_SpecialChar( SECOND_CHAR,pattern,SECOND_CHAR_IN_MEMORY);
	}
}

