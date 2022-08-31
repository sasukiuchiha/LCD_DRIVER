/*
 * LCD_config.h
 *
 * Created: 8/27/2022 10:58:06 AM
 *  Author: moham
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE   4

/******DATA AND CONTROL PORTS****/
#define LCD_DATA_PORT         PORTA
#define LCD_CONTROL_PORT      PORTB
//********************************


/**************DATA PINS************/ 
#define LCD_D4_PIN             PIN4              
#define LCD_D5_PIN             PIN5 
#define LCD_D6_PIN             PIN6 
#define LCD_D7_PIN             PIN7
//************************************


/***********CONTROL PINS************/ 
#define LCD_RS_PIN              PIN1
#define LCD_RW_PIN              PIN2
#define LCD_EN_PIN              PIN3
//***********************************

#endif /* LCD_CONFIG_H_ */