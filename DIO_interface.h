/*
 * DIO_interface.h
 *
 * Created: 7/2/2023 7:48:36 PM
 *  Author: mohamed issam
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define DIO_u8PIN_OUTPUT		1
#define DIO_u8PIN_INPUT 		0

#define DIO_u8PIN_HIGH			1
#define DIO_u8PIN_LOW			0

#define DIO_u8PORT_OUTPUT		0xFF
#define DIO_u8PORT_INPUT 		0

#define DIO_u8PORT_HIGH			0xFF
#define DIO_u8PORT_LOW 			0


#define DIO_u8PORTA				1
#define DIO_u8PORTB				2
#define DIO_u8PORTC				3
#define DIO_u8PORTD				4

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7


u8 DIO_u8SetPinDirection(u8 port, u8 pin , u8 dir);//1

u8 DIO_u8SetportDirection(u8 port, u8 dir); //1

u8 DIO_u8SetPinValue(u8 port, u8 pin , u8 val); // write

u8 DIO_u8SetPortValue(u8 port, u8 val);  // write

u8 DIO_u8TogglePin(u8 port, u8 pin); //1

u8 DIO_u8TogglePort(u8 port);//1

u8 DIO_u8ReadPinValue(u8 port, u8 pin, u8 *val);//

u8 DIO_u8readPort(u8 portname,u8 pinnumber);



#endif /* DIO_INTERFACE_H_ */