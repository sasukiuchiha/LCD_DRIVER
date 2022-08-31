/*
 * DIO_interface.h
 *
 * Created: 8/20/2022 8:35:03 AM
 *  Author: moham
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*PORT PINS*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//********************

/* PIN DIRECTION */
#define INPUT_PIN  0
#define OUTPUT_PIN 1
//********************

/***** port DIRECTION ********************/
#define INPUT_PORT  0
#define OUTPUT_PORT 255
#define FIRST_2_OUTPUT 3
#define LAST_2_OUTPUT 192
#define FIRST_3_OUTPUT 7
#define LAST_3_OUTPUT 224
#define FIRST_4_OUTPUT 15
#define LAST_4_OUTPUT 240
#define FIRST_3_AFTER_FIRST_BIT_OUTPUT 14
#define LAST_3_BEFORE_LAST_BIT_OUTPUT 112
//*****************************************



/****PORT_ID*********/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
//*******************

/*PORT STATE*/
#define HIGH 1
#define LOW  0
//*************

//port functions prototypes
void DIO_SetPortDir(u8 port_id,u8 port_dir); //SET THE DIRECTION OF THE SELECTED PORT
void DIO_SetPortVal(u8 port_id,u8 port_val); //SET THE OUTPUT PINS IN THE SELECTED PORT
u8 DIO_GetPortVal(u8 port_id);//get or return the value inside the pin_REG port 
u8 DIO_GetPortVal1(u8 port_id);//get or return the value inside the PORT_REG port 
//PIN FUNCTION PROTOTYPES
void DIO_SetPinDir(u8 port_id,u8 pin_num,u8 pin_dir); // SET THE DIRECTION OF THE SELECTED PIN TO THE THE ENTERED PORT AS INPUT OR OUTPUT
void DIO_SetPinVal(u8 port_id,u8 pin_num,u8 pin_state); //SET THE VALUE OF THE SELECTED PIN TO THE THE ENTERED PORT AS HIGH OR LOW
u8 DIO_GetPinVal(u8 port_id,u8 pin_num); // GET THE SATAE OF THE SELECTED PIN TO THE SELECTED PORT IF THERE HIGH APPLIED ON THE PIN OR NOT(1,0)




#endif /* DIO_INTERFACE_H_ */