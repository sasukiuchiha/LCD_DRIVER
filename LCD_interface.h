/*
 * LCD_interface.h
 *
 * Created: 8/23/2022 4:29:33 PM
 *  Author: moham
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#define F_CPU 16000000UL
#include <util/delay.h>



/**************LCD_COMMANDS*****************/
#define CLEAR_DISPLAY_SCREEN          0X01
#define RETURN_HOME					  0X02
#define _8_BIT_MODE_FOR1LINE          0X30
#define _8_BIT_MODE_FOR2LINE          0X38
#define _4_BIT_MODE_FOR1LINE          0X20
#define _4_BIT_MODE_FOR2LINE          0X28
#define ENTRY_MODE                    0X06
#define DISPLAYOFF_CURSOROFF          0X08
#define DISPLAYON_CURSORON            0X0E
#define DISPLAYON_CURSOROFF           0X0C
#define DISPLAYON_CURSORblanking      0X0F
#define SHIFT_DESPLAY_LEFT            0X18
#define SHIFT_DESPLAY_RIGHT           0X1C
#define MOVE_CURSORLEFT_BYONE_CHAR    0X10
#define MOVE_CURSORRIGHT_BYONE_CHAR   0X14
#define FORCE_CURSOR_TOSTART_1STROW   0X80
#define FORCE_CURSOR_TOSTART_2NDROW   0XC0
//*******************************************

/*****************CGRAM_locations_of_chars***********************/
#define FIRST_CHAR      0        //ADD OF 00H CHAR_FIRST_ROW 0X40 
#define SECOND_CHAR  	1	     //ADD OF 01H CHAR_FIRST_ROW 0X48
#define THIRD_CHAR   	2	     //ADD OF 02H CHAR_FIRST_ROW 0X56
#define FORTH_CHAR   	3		 //ADD OF 03H CHAR_FIRST_ROW 0X64
#define FIFTH_CHAR  	4		 //ADD OF 04H CHAR_FIRST_ROW 0X72	
#define SIXTH_CHAR   	5		 //ADD OF 05H CHAR_FIRST_ROW 0X80
#define SEVENTH_CHAR 	6		 //ADD OF 06H CHAR_FIRST_ROW 0X88
#define EIGHTH_CHAR  	7		 //ADD OF 07H CHAR_FIRST_ROW 0X96
//*****************************************************************

/*****************CGRAM_locations_of_chars_in memory****************************/
#define FIRST_CHAR_IN_MEMORY        0x00        //ADD OF 00H CHAR_FIRST_ROW 0X40
#define SECOND_CHAR_IN_MEMORY    	0x01	    //ADD OF 01H CHAR_FIRST_ROW 0X48
#define THIRD_CHAR_IN_MEMORY     	0x02	    //ADD OF 02H CHAR_FIRST_ROW 0X56
#define FORTH_CHAR_IN_MEMORY     	0x03		//ADD OF 03H CHAR_FIRST_ROW 0X64
#define FIFTH_CHAR_IN_MEMORY   	    0x04		//ADD OF 04H CHAR_FIRST_ROW 0X72
#define SIXTH_CHAR_IN_MEMORY     	0x05		//ADD OF 05H CHAR_FIRST_ROW 0X80
#define SEVENTH_CHAR_IN_MEMORY   	0x06		//ADD OF 06H CHAR_FIRST_ROW 0X88
#define EIGHTH_CHAR_IN_MEMORY    	0x07		//ADD OF 07H CHAR_FIRST_ROW 0X96
//******************************************************************************


void LCD_init(void);//intialize lcd
void LCD_WriteCommand(u8 command);//send command to lcd
void LCD_WriteCharacter(u8 character);//show character on lcd
void LCD_WriteString(u8 string[]);//show string on lcd
void LCD_Clear(void);//clear screen
void LCD_WriteNumbers(u8 num);//show numbers on lcd
void LCD_MoveToPos(u8 row,u8 col);//move the cursor to certain position
void LCD_Make_SpecialChar(u8 char_num_inCGRAM, u8 *ptr,u8 char_loc_in_memory);//MAKE SPECIAL CHARS,ptr wqill hold array contian the pattern
//char_loc_in_memory from 00 to 07 for the 8 char in CGRAM
#endif /* LCD_INTERFACE_H_ */