/*
 * main.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Nourhan
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "GIE_interface.h"

#include "DelayTMR1_interface.h"

void Application(void);

void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW_PIN);

	/*enable global interrupt*/
	GIE_voidEnable();


	while(1)
	{
	TMR_voidSetDelayAsync(2000 , Application);

//	TMR_voidSetDelaySync(2000);
//	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH_PIN);
//	TMR_voidSetDelaySync(2000);
//	DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW_PIN);
	}
}


void Application(void)
{
	DIO_voidTogglePin(DIO_PORTA , DIO_PIN0);
}
