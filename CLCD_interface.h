/*
 * CLCD_interface.h
 *
 * Created: 7/4/2023 4:29:01 PM
 *  Author: mohamed issam
 */ 


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_vSendCommand(u8 command);

void CLCD_vSendData(u8 data);

void CLCD_vInit(void);

void CLCD_vSendString(char *data);

void CLCD_vGoToXY(u8 x_pos ,u8 y_pos);

void CLCD_vWriteSpecialCharacter(u8 *pattern, u8 pattern_no , u8 x_pos , u8 y_pos);

void CLCD_vWriteNumber(u32 number);

void CLCD_vClearscreen();


#endif /* CLCD_INTERFACE_H_ */