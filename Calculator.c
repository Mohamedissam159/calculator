/*
 * Calculator.c
 *
 * Created: 7/10/2023 10:50:45 PM
 *  Author: mohamed issam
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"

#define  F_CPU 8000000UL
#include <util/delay.h>

#include <avr/io.h>

int main(void)
{
	label:	CLCD_vInit();
	KPD_vINIT();
	
	u8 arr[6]={KPD_NO_PRESSED_KEY,KPD_NO_PRESSED_KEY,KPD_NO_PRESSED_KEY,KPD_NO_PRESSED_KEY,KPD_NO_PRESSED_KEY,KPD_NO_PRESSED_KEY} ;
	u16 res ;
	u8 counter=0 ;
	
	
    while(1)
    {
        do
        {
	        arr[counter]= KPD_u8GetPressdKey();
        }while(arr[counter]==KPD_NO_PRESSED_KEY);
		
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_vClearscreen();
			goto label ;
		}
		else
		{
			 CLCD_vWriteNumber(arr[counter]-48);
		}
		counter++;
		_delay_ms(300);
		
		do
		{
			arr[counter]= KPD_u8GetPressdKey();
		}while(arr[counter]==KPD_NO_PRESSED_KEY);
		
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_vClearscreen();
			goto label ;
		}
		else
		{
			CLCD_vWriteNumber(arr[counter]-48);
		}
		counter++;
		_delay_ms(300);
		
		do
		{
			arr[counter]= KPD_u8GetPressdKey();
		}while(arr[counter]==KPD_NO_PRESSED_KEY);
		
		if(arr[counter]=='A'||arr[counter]=='=')
		{
			CLCD_vClearscreen();
			goto label ;
		}
		else
		{
			CLCD_vSendData(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		
		do
		{
			arr[counter]= KPD_u8GetPressdKey();
		}while(arr[counter]==KPD_NO_PRESSED_KEY);
		
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_vClearscreen();
			goto label ;
		}
		else
		{
			CLCD_vWriteNumber(arr[counter]-48);
		}
		counter++;
		_delay_ms(300);
		
		do
		{
			arr[counter]= KPD_u8GetPressdKey();
		}while(arr[counter]==KPD_NO_PRESSED_KEY);
		
		if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			CLCD_vClearscreen();
			goto label ;
		}
		else
		{
			CLCD_vWriteNumber(arr[counter]-48);
		}
		counter++;
		_delay_ms(300);
		
		do
		{
			arr[counter]= KPD_u8GetPressdKey();
		}while(arr[counter]==KPD_NO_PRESSED_KEY);
		
		if(arr[counter]=='=')
		{
			CLCD_vSendData(arr[counter]);
			
			switch(arr[2])
			{
				case '+' : res=((arr[0]-48)*10)+((arr[1]-48))+((arr[3]-48)*10)+((arr[4]-48));
							CLCD_vWriteNumber(res);
				break;
				
				case '-' : res=((arr[0]-48)*10)+((arr[1]-48))-((arr[3]-48)*10)+((arr[4]-48));
							CLCD_vWriteNumber(res);
				break;
				
				case '*' : res=(((arr[0]-48)*10)+((arr[1]-48)))*(((arr[3]-48)*10)+((arr[4]-48)));
							CLCD_vWriteNumber(res);
				break;
				
				case '/' : res=(((arr[0]-48)*10)+((arr[1]-48)))/(((arr[3]-48)*10)+((arr[4]-48)));
							CLCD_vWriteNumber(res);
				break;
				
				default:break;
				
				
			}
			
		}
		else
		{
			CLCD_vClearscreen();
			goto label ;
		}
		_delay_ms(200);
         
    }
}
