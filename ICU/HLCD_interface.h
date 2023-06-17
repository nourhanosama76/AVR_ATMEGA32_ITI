/*
 * HLCD_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mohamed
 */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

void LCD_voidLCDInit(void);

void LCD_voidSendCommand(u8 CMD);

void LCD_voidSendCharacter(u8 Character);

void LCD_voidSendString( u8 arr[] );

u8 LCD_U8GoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col);

void LCD_voidSendSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_pu8Location , u8 Copy_u8Row , u8 Copy_u8Col);

void LCD_voidSendNumber(u16 Copy_u16Number);

#endif /* HLCD_INTERFACE_H_ */
