/*
 * main.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"



void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTC , DIO_PIN0  ,DIO_PIN_OUTPUT );     //led
	DIO_voidSetPinDirection(DIO_PORTD , DIO_PIN3  ,DIO_PIN_INPUT_PULLUP );     //push button at INT0 pin (PD2)
	EXTI_voidINT1Init();

	while(1)
	{

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	DIO_voidTogglePin(DIO_PORTC , DIO_PIN0);
}
