/*
 * main.c
 *
 *  Created on: Apr 5, 2023
 *      Author: Nourhan
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "GIE_interface.h"

#include "TIMER0_interface.h"


/**************************************************************************************/
/*********************************Functions' declaration*******************************/
/**************************************************************************************/

/*this function shall generate a SW PWM signal with the following configurations:     */
/*Prescaler = 256, frequency = 40 HZ, duty cycle = 20%                                */
void Application(void);

int main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH_PIN);

	GIE_voidEnable();
	TMR0_voidRunTMR0CTCAsync(Application);

	while(1);
}


void Application(void)
{
	static u16 Counter = 0 ;
	Counter ++ ;

	if(Counter == 5)
	{
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW_PIN);
	}

	else if(Counter == 25)
	{
		DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH_PIN);
		Counter = 0;
	}
}
