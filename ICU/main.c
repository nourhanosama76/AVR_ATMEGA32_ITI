/*
 * main.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Nourhan
 */
#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "GIE_interface.h"
#include "HLCD_interface.h"
#include "ICU_interface.h"

/*global variables to hold the ranges of T*/
u16 Reading1, Reading2, Reading3 ;

/*T -> period time, T_ON -> T on period*/
u16 T_ON = 0, T = 0 ;

void Application(void);

void main(void)
{

	DIO_voidSetPinDirection(DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT);          //PWM output signal from TIMER0
	DIO_voidSetPinDirection(DIO_PORTD , DIO_PIN6 , DIO_PIN_INPUT_FLOAT);     //this signal is taken from TIMER0 as an input for ICP pin

	GIE_voidEnable();
	LCD_voidLCDInit();

	TMR0_voidNonInvertedPWM();         //to generate PWM signal as an input for ICU
	TMR1_voidOVF(Application);         //to count T, Ton

	while(1)
	{
		while((T_ON == 0) && (T == 0));

		LCD_U8GoToRowCol(0,0);
		LCD_voidSendString("T =");
		LCD_U8GoToRowCol(0,3);
		LCD_voidSendNumber(T);
		LCD_U8GoToRowCol(1,0);
		LCD_voidSendString("T_ON =");
		LCD_U8GoToRowCol(1,6);
		LCD_voidSendNumber(T_ON);
	}
}


void Application(void)
{
	static u16 Counter = 0 ;
	Counter++ ;

	if(Counter == 1)
	{
		Reading1 = ICU_u16GetReading();
	}

	else if(Counter == 2)
	{
		Reading2 = ICU_u16GetReading();
		ICU_voidSetSenseSignal(FALLING);

		/*assign the period time to T */
		T = Reading2 - Reading1 ;
	}

	else if(Counter == 3)
	{
		Reading3 = ICU_u16GetReading();
		ICU_voidDisableInterrupt();
		T_ON = Reading3 - Reading2 ;
	}
}

