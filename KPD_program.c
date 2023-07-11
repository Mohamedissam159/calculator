/*
 * KPD_program.c
 *
 * Created: 7/6/2023 5:15:43 PM
 *  Author: mohamed issam
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"



void KPD_vINIT(void)
{
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN0_PIN,DIO_u8PIN_OUTPUT);			
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN1_PIN,DIO_u8PIN_OUTPUT);			
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN2_PIN,DIO_u8PIN_OUTPUT);			
	DIO_u8SetPinDirection(KPD_PORT,KPD_COLUMN3_PIN,DIO_u8PIN_OUTPUT);			
	
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW0_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW1_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW2_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_ROW3_PIN,DIO_u8PIN_INPUT);
	
	DIO_u8SetPinValue(KPD_PORT,KPD_COLUMN0_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_COLUMN1_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_COLUMN2_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_COLUMN3_PIN,DIO_u8PIN_HIGH);
	
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW0_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW1_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW2_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_ROW3_PIN,DIO_u8PIN_HIGH);
}

u8 KPD_u8GetPressdKey(void)
{
	u8 Local_PressedKey=KPD_NO_PRESSED_KEY;
	
	u8 Local_columcounter,Local_rowconter,Local_pinstate;
	
	static u8 Local_KpdArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;
	
	static u8 Local_columnarr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_rowarr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	
	for (Local_columcounter=0;Local_columcounter<COLUMN_NUM;Local_columcounter++)
	{
		DIO_u8SetPinValue(KPD_PORT,Local_columnarr[Local_columcounter],DIO_u8PIN_LOW);
		for(Local_rowconter=0;Local_rowconter<ROW_NUM;Local_rowconter++)
		{
			DIO_u8ReadPinValue(KPD_PORT, Local_rowarr[Local_rowconter],&Local_pinstate);
			if (Local_pinstate==DIO_u8PIN_LOW)
			{
				Local_PressedKey=Local_KpdArr[Local_rowconter][Local_columcounter];
				//Pooling (busy wating) until the key is released
				while(Local_pinstate==DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KPD_PORT, Local_rowarr[Local_rowconter],&Local_pinstate);
				}
				return Local_PressedKey;
	
			}
			
		}
		//return column high
		DIO_u8SetPinValue(KPD_PORT,Local_columnarr[Local_columcounter],DIO_u8PIN_HIGH);
	}
	
	return Local_PressedKey;
}
