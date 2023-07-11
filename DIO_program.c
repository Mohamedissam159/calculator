/*
 * DIO_program.c
 
 * Created: 7/2/2023 7:46:53 PM
 *  Author: mohamed issam
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_privet.h"
#include "DIO_config.h"
//#include <avr/io.h>



u8 DIO_u8SetPinDirection(u8 port, u8 pin , u8 dir)
{
	u8 Local_u8ErrorState=0;
	if(pin<=DIO_u8PIN7)
	{
		if (dir==DIO_u8PIN_INPUT)
		{
			switch(port)
			{
				case DIO_u8PORTA : CLEAR_BIT(DDRA,pin); break;
				case DIO_u8PORTB : CLEAR_BIT(DDRB,pin); break;
				case DIO_u8PORTC : CLEAR_BIT(DDRC,pin); break;
				case DIO_u8PORTD : CLEAR_BIT(DDRD,pin); break;
				default:Local_u8ErrorState=1; break;
			}
		}	
				
		else if(dir==DIO_u8PIN_OUTPUT)
		{
			switch(port)
			{
				case DIO_u8PORTA : SET_BIT(DDRA,pin); break;
				case DIO_u8PORTB : SET_BIT(DDRB,pin); break;
				case DIO_u8PORTC : SET_BIT(DDRC,pin); break;
				case DIO_u8PORTD : SET_BIT(DDRD,pin); break;
				default:Local_u8ErrorState=1; break;
			}
		}	
									
		
		else{Local_u8ErrorState=1;}
	}
	else{Local_u8ErrorState=1;}
		return Local_u8ErrorState;
}



u8 DIO_u8SetportDirection(u8 port, u8 dir)
{
	u8 Local_u8ErrorState=0;
		switch(port)
		{
			case DIO_u8PORTA : DDRA=dir; break;
			case DIO_u8PORTB : DDRB=dir; break;
			case DIO_u8PORTC : DDRC=dir; break;
			case DIO_u8PORTD : DDRD=dir; break;
			default:Local_u8ErrorState=1; break;
		}
	
	
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 port, u8 pin , u8 val)
{
	u8 Local_u8ErrorState=0;
	if (pin<=DIO_u8PIN7)
	{
		if (val==DIO_u8PIN_LOW)
		{
			switch(port)
			{
				case DIO_u8PORTA :CLEAR_BIT(PORTA,pin); break;
				case DIO_u8PORTB :CLEAR_BIT(PORTB,pin); break;
				case DIO_u8PORTC :CLEAR_BIT(PORTC,pin); break;
				case DIO_u8PORTD :CLEAR_BIT(PORTD,pin); break;
				default:Local_u8ErrorState=1; break;
			}
			
		}
		else if (val==DIO_u8PIN_HIGH)
		{
			switch(port)
			{
				case DIO_u8PORTA :SET_BIT(PORTA,pin); break;
				case DIO_u8PORTB :SET_BIT(PORTB,pin); break;
				case DIO_u8PORTC :SET_BIT(PORTC,pin); break;
				case DIO_u8PORTD :SET_BIT(PORTD,pin); break;
				default:Local_u8ErrorState=1; break;
			}
		}
		else{Local_u8ErrorState=1;}
		
	}
	else{Local_u8ErrorState=1;}
	
	return Local_u8ErrorState;
}



u8 DIO_u8SetPortValue(u8 port, u8 val)
{
	u8 Local_u8ErrorState=0;
	switch(port)
	{
		case DIO_u8PORTA: PORTA=val; break;
		case DIO_u8PORTB: PORTB=val; break;
		case DIO_u8PORTC: PORTC=val; break;
		case DIO_u8PORTD: PORTD=val; break;
		default:Local_u8ErrorState=1; break;
	}
	
	return Local_u8ErrorState;
}



u8 DIO_u8TogglePin(u8 port, u8 pin)
{
	u8 Local_u8ErrorState=0;
	if(pin<=DIO_u8PIN7)
	{
		switch(port)
		{
			case DIO_u8PORTA : TOG_BIT(PORTA,pin); break;
			case DIO_u8PORTB : TOG_BIT(PORTB,pin); break;
			case DIO_u8PORTC : TOG_BIT(PORTC,pin); break;
			case DIO_u8PORTD : TOG_BIT(PORTD,pin); break;
			default: Local_u8ErrorState=1; break;						
		}
		
	}
	else{Local_u8ErrorState=1;}
	
	return Local_u8ErrorState;
}



u8 DIO_u8TogglePort(u8 port)
{
	u8 Local_u8ErrorState=0;
	switch(port)
	{
		case DIO_u8PORTA : PORTA=~PORTA; break;
		case DIO_u8PORTB : PORTB=~PORTB; break;
		case DIO_u8PORTC : PORTC=~PORTC; break;
		case DIO_u8PORTD : PORTD=~PORTD; break;
		default: Local_u8ErrorState=1; break;
	}
	
	return Local_u8ErrorState;
}



u8 DIO_u8ReadPinValue(u8 port, u8 pin,u8 *val)
{
	u8 Local_u8ErrorState=0;
	if ((val!=NULL)&&(pin<=DIO_u8PIN7))
	{
		switch(port)
		{
			case DIO_u8PORTA : *val=READ_BIT(PINA,pin); break;
			case DIO_u8PORTB : *val=READ_BIT(PINB,pin); break;
			case DIO_u8PORTC : *val=READ_BIT(PINC,pin); break;
			case DIO_u8PORTD : *val=READ_BIT(PIND,pin); break;
			default: Local_u8ErrorState=1; break;
		}
	}
	else{Local_u8ErrorState=1;}
	
	
	return Local_u8ErrorState;
}

u8 DIO_u8readPort(u8 portname,u8 pinnumber)
{
	unsigned char return_value=0;
	switch(portname)
	{
		case DIO_u8PORTA :
		return_value=READ_BIT(PINA,pinnumber);//Read the value from the given pin in port A
		break;
		
		case DIO_u8PORTB :
		return_value=READ_BIT(PINB,pinnumber);//Read the value from the given pin in port B
		break;
		
		case DIO_u8PORTC :
		return_value=READ_BIT(PINC,pinnumber);//Read the value from the given pin in port C
		break;
		
		case DIO_u8PORTD :
		return_value=READ_BIT(PIND,pinnumber);//Read the value from the given pin in port D
		break;
		default:
		break;
	}
	return return_value ;
}










