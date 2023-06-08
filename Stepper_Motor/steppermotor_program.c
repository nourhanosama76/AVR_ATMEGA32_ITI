/*
 * steppermotor_program.c
 *
 *  Created on: May 14, 2023
 *      Author: Nourhan
 */
#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "steppermotor_interface.h"
#include "steppermotor_private.h"
#include "steppermotor_cfg.h"


void Stepper_voidInit(void)
{
	/*setting the stepper motor pins to be output*/
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN0 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN1 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN2 , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(STEPPER_PORT , STEPPER_PIN3 , DIO_PIN_OUTPUT);
}

void Stepper_voidRotCWCont(void)
{
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_LOW_PIN );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	_delay_ms(10);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_LOW_PIN );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	_delay_ms(10);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_LOW_PIN );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	_delay_ms(10);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_LOW_PIN );
	_delay_ms(10);


}

void Stepper_voidRotCCWCont(void)
{
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_LOW_PIN );
	_delay_ms(10);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_LOW_PIN );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	_delay_ms(10);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_LOW_PIN );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	_delay_ms(10);

	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_LOW_PIN );
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_HIGH_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_HIGH_PIN);
	_delay_ms(10);
}

void Stepper_voidRotCWAngle(f32 Copy_f32Angle)
{
	u8 Local_u8Iterator ;
	for(Local_u8Iterator = 0 ; Local_u8Iterator <= ((Copy_f32Angle/STEP_ANGLE)*4) ; Local_u8Iterator ++)
	{
		Stepper_voidRotCWCont();
	}
}

void Stepper_voidRotCCWAngle(f32 Copy_f32Angle)
{
	u8 Local_u8Iterator ;
	for(Local_u8Iterator = 0 ; Local_u8Iterator <= ((Copy_f32Angle/STEP_ANGLE)*4) ; Local_u8Iterator ++)
	{
		Stepper_voidRotCCWCont();
	}

}

void Stepper_voidStopMotor(void)
{
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN0 , DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN1 , DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN2 , DIO_LOW_PIN);
	DIO_voidSetPinValue(STEPPER_PORT , STEPPER_PIN3 , DIO_LOW_PIN);

}
