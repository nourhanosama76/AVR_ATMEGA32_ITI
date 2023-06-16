/*
 * TIMER0_program.c
 *
 *  Created on: Apr 5, 2023
 *      Author: Nourhan
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_cfg.h"

/**************************************************************************************/
/*********************************Global variables*************************************/
/**************************************************************************************/

void (* Global_ptrToFuncCTCCallBack)(void) = NULL;


/**************************************************************************************/
/*****************************Functions' implementation********************************/
/**************************************************************************************/

void TMR0_voidRunTMR0CTCAsync(void(*Copy_ptrToFuncCTCINT)(void))
{
	/*configure wave generation mode to CTC in TCCR register*/
	CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM0);
	SET_BIT(TIMER0_TCCR0 , TCCR0_WGM1);

	/*disconnect OC0 pin*/
	CLR_BIT(TIMER0_TCCR0 , TCCR0_COM0);
	CLR_BIT(TIMER0_TCCR0 , TCCR0_COM1);

	/*Setting Compare match value = 250*/
	TIMER0_OCR0 = 250;      //compare match interrupt every250 us

	/*Enable compare match interrupt*/
	SET_BIT(TIMSK , TIMSK_OCIE0);

	if(Copy_ptrToFuncCTCINT != NULL)
	{
		Global_ptrToFuncCTCCallBack = Copy_ptrToFuncCTCINT;
	}

	/*setting the prescaler value for TIMER0 -> 8*/
	TIMER0_TCCR0 &= PRESCALER_MASK;
	TIMER0_TCCR0 |= TMR0_PRESCALER_8;

}


void TMR0_voidNonInvertedPWM(void)
{
	/*configure timer0 to be in fast PWM mode*/
	SET_BIT(TIMER0_TCCR0 , TCCR0_WGM0);
	SET_BIT(TIMER0_TCCR0 , TCCR0_WGM1);

	/*configure oc0 pin to be non-inverting mode*/
	CLR_BIT(TIMER0_TCCR0 , TCCR0_COM0);
	SET_BIT(TIMER0_TCCR0 , TCCR0_COM1);

	/*set prescaler value to be -> 64*/
	SET_BIT(TIMER0_TCCR0 , TCCR0_CS00);
	SET_BIT(TIMER0_TCCR0 , TCCR0_CS01);
	CLR_BIT(TIMER0_TCCR0 , TCCR0_CS02);
}


void TMR0_voidSetOCR0Value(u8 Copy_u8OCR0Value)
{
	/*setting the compare match value in OCR register to set Duty Cycle*/
	TIMER0_OCR0 = Copy_u8OCR0Value;
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(Global_ptrToFuncCTCCallBack != NULL)
	{
	Global_ptrToFuncCTCCallBack();
	}

	else
	{
		/*do nothing*/
	}
}

