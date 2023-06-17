/*
 * HLCD_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Mohamed
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "HLCD_interface.h"
#include "HLCD_cfg.h"
#include "HLCD_private.h"


void LCD_voidLCDInit(void)
{

	DIO_voidSetPortDirection(HLCD_DATA_PORT,DIO_PORT_OUTPUT);

	DIO_voidSetPinDirection(HLCD_CONTROL_PORT,RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(HLCD_CONTROL_PORT,RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(HLCD_CONTROL_PORT,ENABLE_PIN,DIO_PIN_OUTPUT);

	_delay_ms(50);

	LCD_voidSendCommand(0x3C);

	_delay_us(50);

	LCD_voidSendCommand(0x0C);

	_delay_us(50);

	LCD_voidSendCommand(0x01);


}

void LCD_voidSendCommand(u8 CMD)
{
	DIO_voidSetPinValue(HLCD_CONTROL_PORT,RS_PIN,DIO_LOW_PIN);
	DIO_voidSetPinValue(HLCD_CONTROL_PORT,RW_PIN,DIO_LOW_PIN);

	DIO_u8SetPortValue(HLCD_DATA_PORT,CMD);

	DIO_voidSetPinValue(HLCD_CONTROL_PORT,ENABLE_PIN,DIO_HIGH_PIN);
	_delay_us(100);
	DIO_voidSetPinValue(HLCD_CONTROL_PORT,ENABLE_PIN,DIO_LOW_PIN);

}


void LCD_voidSendCharacter(u8 Character)
{
	DIO_voidSetPinValue(HLCD_CONTROL_PORT , RS_PIN , DIO_HIGH_PIN);
	DIO_voidSetPinValue(HLCD_CONTROL_PORT , RW_PIN , DIO_LOW_PIN);

	DIO_u8SetPortValue(HLCD_DATA_PORT , Character);

	DIO_voidSetPinValue(HLCD_CONTROL_PORT , ENABLE_PIN , DIO_HIGH_PIN);
	_delay_ms(50);
	DIO_voidSetPinValue(HLCD_CONTROL_PORT , ENABLE_PIN , DIO_LOW_PIN);

}

void LCD_voidSendString( u8 arr[] )
{
	u8 i = 0;

	while( arr[i] != '\0')
	{
		LCD_voidSendCharacter(arr[i]);
		i++;
	}
}



u8 LCD_U8GoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col)
{

	u8 Local_u8ErrorState = 0;

	u8 Local_u8DDRAMAddress;

	if((Copy_u8Row == 0 || Copy_u8Row == 1) && (Copy_u8Col >= 0 && Copy_u8Col < 16))
	{
		if(Copy_u8Row == 0)
		{
			Local_u8DDRAMAddress = Copy_u8Col;
		}

		else if(Copy_u8Row == 1)
		{
			Local_u8DDRAMAddress = Copy_u8Col + 0x40;
		}
	}

	else
	{
		Local_u8ErrorState = 1;
	}

	SET_BIT(Local_u8DDRAMAddress , 7);

	LCD_voidSendCommand(Local_u8DDRAMAddress);

	return Local_u8ErrorState;

}


void LCD_voidSendSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_u8Location , u8 Copy_u8Row , u8 Copy_u8Col)
{

	u8 Local_u8CGRAMAddress ;

	u8 Local_u8PatternIterator ;

	Local_u8CGRAMAddress = Copy_u8Location * 8 ;

	SET_BIT(Local_u8CGRAMAddress , 6);

	LCD_voidSendCommand(Local_u8CGRAMAddress);

	for(Local_u8PatternIterator = 0 ; Local_u8PatternIterator < 8 ; Local_u8PatternIterator ++)
	{
		LCD_voidSendCharacter(Copy_pu8Pattern[Local_u8PatternIterator]);
	}

	LCD_U8GoToRowCol(Copy_u8Row , Copy_u8Col);


	LCD_voidSendCharacter(Copy_u8Location);
}



void LCD_voidSendNumber(u16 Copy_u16Number)
{
	u8 Local_u8Temp[16] ;
	u8 Local_u8Remainder = 0 ;
    u8 Local_u8Iterator = 0 ;
	u8 Local_u8Count = 0 ;

	if(Copy_u16Number == 0)
	{
		LCD_voidSendCharacter('0');
	}

	while(Copy_u16Number > 0)
	{
		Local_u8Remainder = Copy_u16Number % 10 ;
		Local_u8Temp[Local_u8Iterator] = Local_u8Remainder ;
		Copy_u16Number /= 10 ;
		Local_u8Iterator++ ;
		Local_u8Count++ ;
	}

	for(Local_u8Iterator = Local_u8Count ; Local_u8Iterator > 0 ; Local_u8Iterator--)
	{
		if(Local_u8Temp[Local_u8Iterator-1] == 1)
		{
			LCD_voidSendCharacter('1');
		}
		else if(Local_u8Temp[Local_u8Iterator-1] == 2)
		{
			LCD_voidSendCharacter('2');
		}

		else if(Local_u8Temp[Local_u8Iterator-1] == 3)
		{
			LCD_voidSendCharacter('3');
		}

		else if(Local_u8Temp[Local_u8Iterator-1] == 4)
		{
			LCD_voidSendCharacter('4');
		}
		else if(Local_u8Temp[Local_u8Iterator-1] == 5)
		{
			LCD_voidSendCharacter('5');
		}


		else if(Local_u8Temp[Local_u8Iterator-1] == 6)
		{
			LCD_voidSendCharacter('6');
		}


		else if(Local_u8Temp[Local_u8Iterator-1] == 7)
		{
			LCD_voidSendCharacter('7');
		}

		else if(Local_u8Temp[Local_u8Iterator-1] == 8)
		{
			LCD_voidSendCharacter('8');
		}

		else if(Local_u8Temp[Local_u8Iterator-1] == 9)
		{
			LCD_voidSendCharacter('9');
		}
	}
}
