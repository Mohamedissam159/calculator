/*
 * CLCD_config.h
 *
 * Created: 7/4/2023 4:28:15 PM
 *  Author: mohamed issam
 */ 


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_DATA_PORT			 DIO_u8PORTA

#define CLCD_CTRL_PORT			 DIO_u8PORTB
#define CLCD_RS_PIN				 DIO_u8PIN0
#define CLCD_RW_PIN				 DIO_u8PIN1
#define CLCD_E_PIN				 DIO_u8PIN2

#define CLR_SCREEN				 0x01




#endif /* CLCD_CONFIG_H_ */