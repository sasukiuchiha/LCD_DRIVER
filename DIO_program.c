/*
 * DIO_program.c
 *
 * Created: 8/20/2022 8:36:39 AM
 *  Author: moham
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include <util/delay.h>
#define F_CPU 16000000UL
void DIO_SetPortDir(u8 port_id,u8 port_dir){
	
	switch(port_id){
		case PORTA:DDRA_REG=port_dir;break;
		case PORTB:DDRB_REG=port_dir;break;
		case PORTC:DDRC_REG=port_dir;break;
		case PORTD:DDRD_REG=port_dir;break;
		default:break;
		}}
void DIO_SetPortVal(u8 port_id,u8 port_val){
	
	switch(port_id){
		case PORTA:PORTA_REG=port_val;break;
		case PORTB:PORTB_REG=port_val;break;
		case PORTC:PORTC_REG=port_val;break;
		case PORTD:PORTC_REG=port_val;break;
		default:break;
	}}
	
	

u8 DIO_GetPortVal(u8 port_id){
	u8 port_add_Access=0;
	switch(port_id){
		case PORTA:port_add_Access=PINA_REG;break;
		case PORTB:port_add_Access=PINB_REG;break;
		case PORTC:port_add_Access=PINC_REG;break;
		case PORTD:port_add_Access=PIND_REG;break;
		default:break;
	}
	return port_add_Access;}
	
	u8 DIO_GetPortVal1(u8 port_id){
		u8 port_add_Access=0;
		switch(port_id){
			case PORTA:port_add_Access=PORTA_REG;break;
			case PORTB:port_add_Access=PORTB_REG;break;
			case PORTC:port_add_Access=PORTC_REG;break;
			case PORTD:port_add_Access=PORTD_REG;break;
			default:break;
		}
	return port_add_Access;}
	
	void DIO_SetPinDir(u8 port_id,u8 pin_num,u8 pin_dir){
		
		switch(port_id){
			case PORTA:
			if(pin_dir==1){
				SET_BIT(DDRA_REG,pin_num);
				
			}
			else if(pin_dir==0){
				CLR_BIT(DDRA_REG,pin_num);
				
			}
			else{}
				break;
			case PORTB:
				if(pin_dir==1){
					SET_BIT(DDRB_REG,pin_num);
					
				}
				else if(pin_dir==0){
					CLR_BIT(DDRB_REG,pin_num);
					
				}
				else{}
				break;
			case PORTC:
				if(pin_dir==1){
					SET_BIT(DDRC_REG,pin_num);
					
				}
				else if(pin_dir==0){
					CLR_BIT(DDRC_REG,pin_num);
					
				}
				else{}
				break;
			case PORTD:
				if(pin_dir==1){
					SET_BIT(DDRD_REG,pin_num);
					
				}
				else if(pin_dir==0){
					CLR_BIT(DDRD_REG,pin_num);
					
				}
				else{}
				break;
			default:break;
			
			
			
			
		}
		
		
	}
	void DIO_SetPinVal(u8 port_id,u8 pin_num,u8 pin_state){
		switch(port_id){
			case PORTA:
			if(pin_state==1){
				SET_BIT(PORTA_REG,pin_num);
				
			}
			else if(pin_state==0){
				CLR_BIT(PORTA_REG,pin_num);
				
			}
			else{}
			break;
			case PORTB:
			if(pin_state==1){
				SET_BIT(PORTB_REG,pin_num);
				
			}
			else if(pin_state==0){
				CLR_BIT(PORTB_REG,pin_num);
				
			}
			else{}
			break;
			case PORTC:
			if(pin_state==1){
				SET_BIT(PORTC_REG,pin_num);
				
			}
			else if(pin_state==0){
				CLR_BIT(PORTC_REG,pin_num);
				
			}
			else{}
			break;
			case PORTD:
			if(pin_state==1){
				SET_BIT(PORTD_REG,pin_num);
				
			}
			else if(pin_state==0){
				CLR_BIT(PORTD_REG,pin_num);
				
			}
			else{}
			break;
			default:break;
		
		
		
			}
		}
	u8 DIO_GetPinVal(u8 port_id,u8 pin_num){
		u8 pin_state=0;
		switch(port_id){
			case PORTA:pin_state=GET_BIT(PINA_REG,pin_num);break;
			case PORTB:pin_state=GET_BIT(PINB_REG,pin_num);break;
			case PORTC:pin_state=GET_BIT(PINC_REG,pin_num);break;
			case PORTD:pin_state=GET_BIT(PIND_REG,pin_num);break;
			default:break;
		
		
	}
	return pin_state;}