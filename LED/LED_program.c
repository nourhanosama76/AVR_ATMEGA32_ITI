/**************************************************************************/
/*Author      : Nourhan Osama										      */
/*File Name   : LED_program.c                                             */
/*Layer       : HAL  										  		      */
/*Description : This file contains functions' implementation of LED module*/
/*Date        : 26 March 2023                                             */
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_cfg.h"


void LED_Init(u8 Copy_u8PortID )
{
	DIO_voidSetPortDirection(Copy_u8PortID , DIO_PORT_OUTPUT);
}

/**********************************************************************************/
void LED_ON(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID , Copy_u8Pin , DIO_HIGH_PIN);
}

/**********************************************************************************/
void LED_OFF(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8PortID , Copy_u8Pin , DIO_LOW_PIN);
}

/**********************************************************************************/
void LED_TOGGLE(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	DIO_voidTogglePin(Copy_u8PortID , Copy_u8Pin);
}
