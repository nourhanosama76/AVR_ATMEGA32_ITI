/*
 * DCMotor_program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "DCMotor_interface.h"
#include "DCMotor_private.h"
#include "DIO_cfg.h"


void DCMotor_voidInit(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 )
{
	DIO_voidSetPinDirection(Copy_u8PortID0 , Copy_u8Pin0 , DIO_PIN_OUTPUT );
	DIO_voidSetPinDirection(Copy_u8PortID1 , Copy_u8Pin1 , DIO_PIN_OUTPUT );
}


void DCMotor_voidRotCW(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 )
{
	DIO_voidSetPinValue(Copy_u8PortID0, Copy_u8Pin0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(Copy_u8PortID1, Copy_u8Pin1 , DIO_LOW_PIN);
}


void DCMotor_voidRotCCW(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 )
{
	DIO_voidSetPinValue(Copy_u8PortID0, Copy_u8Pin0 , DIO_LOW_PIN);
	DIO_voidSetPinValue(Copy_u8PortID1, Copy_u8Pin1 , DIO_HIGH_PIN);
}


void DCMotor_voidStopMotor(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 )
{
	DIO_voidSetPinValue(Copy_u8PortID0, Copy_u8Pin0 , DIO_LOW_PIN);
	DIO_voidSetPinValue(Copy_u8PortID1, Copy_u8Pin1 , DIO_LOW_PIN);
}
