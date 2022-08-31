/*
 * LCD_program.c
 *
 * Created: 8/23/2022 4:29:50 PM
 *  Author: moham
 */ 
#include "LCD_interface.h"


#if (LCD_MODE==4)

void LCD_init(void){
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D4_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D5_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D6_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D7_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_CONTROL_PORT,LCD_RS_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_CONTROL_PORT,LCD_RW_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_CONTROL_PORT,LCD_EN_PIN,OUTPUT_PIN);
	
	_delay_ms(50);
	LCD_WriteCommand(RETURN_HOME);
	_delay_ms(1);
	LCD_WriteCommand(_4_BIT_MODE_FOR2LINE);
	_delay_ms(1);
	LCD_WriteCommand(DISPLAYON_CURSORON);
	_delay_ms(1);
	LCD_WriteCommand(CLEAR_DISPLAY_SCREEN);
	_delay_ms(20);
	LCD_WriteCommand(ENTRY_MODE);
	
	
}
void LCD_WriteCommand(u8 command){
	
	
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
	DIO_SetPortVal(LCD_DATA_PORT,((PORTA_REG&0x0f)|(command&0xf0)));
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	_delay_ms(2);
	
	DIO_SetPortVal(LCD_DATA_PORT,((PORTA_REG&0x0f)|(command<<4)));
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	_delay_ms(2);
	
}
void LCD_WriteCharacter(u8 character){
	
		
		DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
		DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
		DIO_SetPortVal(LCD_DATA_PORT,((PORTA_REG&0x0f)|(character&0xf0)));
		DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(2);
		DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
		_delay_ms(2);
		
		DIO_SetPortVal(LCD_DATA_PORT,((PORTA_REG&0x0f)|(character<<4)));
		DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(2);
		DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
		_delay_ms(2);
	
	
}
void LCD_WriteString(u8 string[]){
	for(int i=0;string[i]!='\0';i++){
	LCD_WriteCharacter(string[i]);
	_delay_ms(100);
	
	}
}
void LCD_Clear(void){
	LCD_WriteCommand(CLEAR_DISPLAY_SCREEN);
	
}
void LCD_WriteNumbers(u8 num){
			u8 x=(u8)(num+48);
			LCD_WriteCharacter(x);
			_delay_ms(100);
			
		}
	
void LCD_MoveToPos(u8 row,u8 col){
	
	switch(row){
		case 0://i will not put 0 in ' ' because i will enter it to the fun as int ex lcd_movetopos(0,1) this zero will converte to char like the zero on the case will converted to if i put the zero in the case between '' that will make the default case always obtained
			LCD_WriteCommand(FORCE_CURSOR_TOSTART_1STROW);
			for(int i=0;i<col;i++){
			
			LCD_WriteCommand(MOVE_CURSORRIGHT_BYONE_CHAR);
		}
			break;
		case 1:
			LCD_WriteCommand(FORCE_CURSOR_TOSTART_2NDROW);
			for(int i=0;i<col;i++){
					
					LCD_WriteCommand(MOVE_CURSORRIGHT_BYONE_CHAR);
				}
			break;
	  default: break;
	
		
	}
	
}

void LCD_Make_SpecialChar(u8 char_num_inCGRAM, u8 *ptr,u8 char_loc_in_memory){
	unsigned char i;
	if(char_num_inCGRAM<8){
		LCD_WriteCommand(0x40+(char_num_inCGRAM*8));
		for(i=0;i<8;i++)
		LCD_WriteCharacter(ptr[ i ]);
	}
	LCD_WriteCommand(0X80);//TO RETURN TO DDRAM 8 FOR RETURNING BUT ZERO CAN CHANGE DEPEND ON THE PLACE THAT I WANT TO DISPLAY THE CHARACTER ON THE SCREEN 81 THE WILL SHIFT TO RIGHT ONE STEP
	LCD_WriteCharacter(char_loc_in_memory);//ADD OF FIRST CHAR IN CGRAM AND ADD OR LAST CHAR 08
}


#elif (LCD_MODE==8)
void LCD_init(void){
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D4_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D5_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D6_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_DATA_PORT,LCD_D7_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_CONTROL_PORT,LCD_RS_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_CONTROL_PORT,LCD_RW_PIN,OUTPUT_PIN);
	DIO_SetPinDir(LCD_CONTROL_PORT,LCD_EN_PIN,OUTPUT_PIN);
	
	_delay_ms(50);
	LCD_WriteCommand(_8_BIT_MODE_FOR2LINE);
	_delay_ms(1);
	LCD_WriteCommand(DISPLAYON_CURSORON);
	_delay_ms(1);
	LCD_WriteCommand(CLEAR_DISPLAY_SCREEN);
	_delay_ms(20);
	LCD_WriteCommand(ENTRY_MODE);
	
		
	
	
	
}

void LCD_WriteCommand(u8 command){
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
	DIO_SetPortVal(LCD_DATA_PORT,command);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	_delay_ms(2);
	
}
void LCD_WriteCharacter(u8 character){
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
	DIO_SetPortVal(LCD_DATA_PORT,character);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_SetPinVal(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
	_delay_ms(2);
	
	
}
void LCD_WriteString(u8 string[]){
	LCD_WriteCharacter(string[0]);
	_delay_ms(100);
	
	
}

	
void LCD_Clear(void){
		LCD_WriteCommand(CLEAR_DISPLAY_SCREEN);
		_delay_ms(100);
}
void LCD_WriteNumbers(u8 num){
	u8 x=(u8)(num+48);
	LCD_WriteCharacter(x);
	_delay_ms(100);
	
}
void LCD_MoveToPos(u8 row,u8 col){
	
	switch(row){
		case 0://i will not put 0 in ' ' because i will enter it to the fun as int ex lcd_movetopos(0,1) this zero will converte to char like the zero on the case will converted to if i put the zero in the case between '' that will make the default case always obtained
		LCD_WriteCommand(FORCE_CURSOR_TOSTART_1STROW);
		for(int i=0;i<col;i++){
			
			LCD_WriteCommand(MOVE_CURSORRIGHT_BYONE_CHAR);
		}
		break;
		case 1:
		LCD_WriteCommand(FORCE_CURSOR_TOSTART_2NDROW);
		for(int i=0;i<col;i++){
			
			LCD_WriteCommand(MOVE_CURSORRIGHT_BYONE_CHAR);
		}
		break;
		default: break;
		
		
	}
	
}

#endif















