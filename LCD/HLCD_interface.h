/*
 * HLCD_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mohamed
 */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

void HLCD_voidLCDInit(void);

void HLCD_voidSendCommand(u8 CMD);

void HLCD_voidSendCharacter(u8 Character);

void HLCD_voidSendString( u8 arr[] );

u8 HLCD_U8GoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col);

void LCD_voidSendSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_pu8Location , u8 Copy_u8Row , u8 Copy_u8Col);

void LCD_voidSendNumber(u8 Copy_u16Number);

#endif /* HLCD_INTERFACE_H_ */
