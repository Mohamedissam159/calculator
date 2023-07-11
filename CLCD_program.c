/*
 * CLCD_program.c
 *
 * Created: 7/4/2023 4:26:55 PM
 *  Author: mohamed issam
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"




void CLCD_vInit(void)
{
	/*locating direction*/
	DIO_u8SetportDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	
	
	_delay_ms(30);
	/*Function Set Command: 2Line , 5*8 Font Size */
	CLCD_vSendCommand(0b00111000);
	/*Display On Off Control: display enable , disable cursor , no Blink*/
	CLCD_vSendCommand(0b00001100);
	/*Display Clear */
	CLCD_vSendCommand(1);
}




void CLCD_vSendCommand(u8 command)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	
	DIO_u8SetPortValue(CLCD_DATA_PORT,command);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	
}

void CLCD_vSendData(u8 data)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	
	DIO_u8SetPortValue(CLCD_DATA_PORT,data);
	
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_vSendString(char *data)
{
	u8 Local_u8Counter=0;
	while (data[Local_u8Counter]!='\0')
	{
		CLCD_vSendData(data[Local_u8Counter]);
		Local_u8Counter++;

	}
}

void CLCD_vWriteNumber(u32 number)
{
	u32 Local_flag=1;
	if (number==0)
	{
		CLCD_vSendData('0');
	}
	else
	{
		while(number!=0)
		{
			Local_flag=(number%10)+(Local_flag*10);
			number/=10;
		}
		while(Local_flag!=1)
		{
			CLCD_vSendData((Local_flag%10)+48); // 48 ASCii to 0
			Local_flag/=10;
		}
	}
}


void CLCD_vGoToXY(u8 x_pos ,u8 y_pos)
{
	u8 Local_Address=0;
	if (x_pos==0)
	{
		Local_Address=y_pos;
	}
	else if(x_pos==1)
	{
		Local_Address=y_pos+ 0x40;
	}
	else{}
		
	CLCD_vSendCommand(Local_Address+128);
}


void CLCD_vWriteSpecialCharacter(u8 *pattern, u8 pattern_no , u8 x_pos , u8 y_pos)
{
	u8 Local_CGaddress=0;
	u8 Local_counter=0;
	/*Calculate CG RAM Address : each Block = 8 bytes */
	 Local_CGaddress=pattern_no*8;
	/*Send CG Ram Address To Locating Where Write  Pattern Value*/
	CLCD_vSendCommand(64+Local_CGaddress);
	/*Write The Value Pattern In CG RAM*/
	for (Local_counter=0;Local_counter<8;Local_counter++)
	{
		CLCD_vSendData(pattern[Local_counter]);
	}
	/*Go back DD RAM to display the pattern*/
	CLCD_vGoToXY(x_pos,y_pos);
	/*Display the pattern*/
	CLCD_vSendData(pattern_no);
	
}

void CLCD_vClearscreen()
{
	CLCD_vSendCommand(CLR_SCREEN);
	_delay_ms(10);
}

