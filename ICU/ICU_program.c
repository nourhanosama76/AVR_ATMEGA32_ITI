/*

 * ICU_program.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Nourhan
 */
#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_cfg.h"

/**************************************************************************************/
/*********************************Global variables*************************************/
/**************************************************************************************/

void (* GlobalPtrToFunc)(void) = NULL ;

/**************************************************************************************/
/*****************************Functions' implementation********************************/
/**************************************************************************************/

void TMR0_voidNonInvertedPWM(void)
{
	/*configure timer0 to be in fast PWM mode*/
	SET_BIT(TIMER0_TCCR0 , TCCR0_WGM0);
	SET_BIT(TIMER0_TCCR0 , TCCR0_WGM1);

	/*configure OC0 pin to be non-inverting mode*/
	CLR_BIT(TIMER0_TCCR0 , TCCR0_COM0);
	SET_BIT(TIMER0_TCCR0 , TCCR0_COM1);

	/*Setting Compare match value = 128*/
	TIMER0_OCR0 = 128 ;      //interrupt every 128us....Ton=128 as duty cycle = 50%

	/*set prescaler value to be -> sysclk/8*/
	TIMER0_TCCR0 &= PRESCALER_MASK ;
	TIMER0_TCCR0 |= TMR0_PRESCALER_8 ;
}


void TMR1_voidOVF(void (* PtrToCallBack)(void))
{
	/* Select mode of Timer1 = Normal Mode */
	CLR_BIT(TIMER1_TCCR1A, TIMER1_WGM10);
	CLR_BIT(TIMER1_TCCR1A, TIMER1_WGM11);
	CLR_BIT(TIMER1_TCCR1B, TIMER1_WGM12);
	CLR_BIT(TIMER1_TCCR1B, TIMER1_WGM13);

	/*disconnect OC1A, OC1B*/
	CLR_BIT(TIMER1_TCCR1A, TIMER1_COM1A0);
	CLR_BIT(TIMER1_TCCR1A, TIMER1_COM1A1);
	CLR_BIT(TIMER1_TCCR1A, TIMER1_COM1B0);
	CLR_BIT(TIMER1_TCCR1A, TIMER1_COM1B1);

	/*set sense signal to be RISING EDGE*/
	SET_BIT(TIMER1_TCCR1B , TIMER1_ICES1);

	/*input capture interrupt enable*/
	SET_BIT(TIMSK , TIMSK_TICIE1);

	if(PtrToCallBack != NULL)
	{
		GlobalPtrToFunc = PtrToCallBack ;
	}
	else
	{
		/*do nothing*/
	}

	/* Starts Timer1 at Prescaler 8 */
	TIMER1_TCCR1B &= PRESCALER_MASK ;
	TIMER1_TCCR1B |= TMR0_PRESCALER_8 ;
}

u16 ICU_u16GetReading(void)
{
	/*get the reading taken as a snapshot from TCNT*/
	return TIMER1_ICR1L ;
}


void ICU_voidDisableInterrupt(void)
{
	/*input capture interrupt disable*/
	CLR_BIT(TIMSK , TIMSK_TICIE1);
}


void ICU_voidSetSenseSignal(u8 Copy_u8Signal)
{
	if(Copy_u8Signal == FALLING)
	{
	/*set sense signal to be FALLING EDGE*/
	CLR_BIT(TIMER1_TCCR1B , TIMER1_ICES1);
	}

	/*set sense signal to be RISING EDGE*/
	else if(Copy_u8Signal == RISING)
	{
	SET_BIT(TIMER1_TCCR1B , TIMER1_ICES1);
	}
}


/*ISR for TIMER1 Input capture mode*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(GlobalPtrToFunc != NULL)
	{
		GlobalPtrToFunc();
	}

	else
	{
		/*do nothing*/
	}
}
