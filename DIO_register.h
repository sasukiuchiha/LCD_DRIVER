/*
 * IncFile1.h
 *
 * Created: 8/19/2022 7:12:44 PM
 *  Author: moham
 */ 


#ifndef DIO_register_H_
#define DIO_register_H_

//PORTA REGISTER
#define PORTA_REG *((volatile u8 *)0x3B)
#define DDRA_REG  *((volatile u8 *)0x3A)
#define PINA_REG  *((volatile u8 *)0x39)
//***********************************

//PORTB REGISTER
#define PORTB_REG *((volatile u8 *)0x38)
#define DDRB_REG  *((volatile u8 *)0x37)
#define PINB_REG  *((volatile u8 *)0x36)
//***********************************

//PORTC REGISTER
#define PORTC_REG *((volatile u8 *)0x35)
#define DDRC_REG  *((volatile u8 *)0x34)
#define PINC_REG  *((volatile u8 *)0x33)
//***********************************

//PORTD REGISTER
#define PORTD_REG *((volatile u8 *)0x32)
#define DDRD_REG  *((volatile u8 *)0x31)
#define PIND_REG  *((volatile u8 *)0x30)
//***********************************


#endif /* registers_H_ */