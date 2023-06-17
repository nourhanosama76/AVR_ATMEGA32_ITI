/*
 * DelayTMR1_program.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Nourhan
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "GIE_interface.h"

#include "DelayTMR1_interface.h"
#include "DelayTMR1_private.h"
#include "DelayTMR1_cfg.h"

/**************************************************************************************/
/*********************************Global variables*************************************/
/**************************************************************************************/

/*global pointer to function to call in ISR */
void (* Global_ptrToCallBack)(void) = NULL;

/**************************************************************************************/
/*****************************Functions' implementation********************************/
/**************************************************************************************/

void TMR_voidSetDelaySync(u32 Copy_u32Time_ms)
{
	/*activate CTC mode 4 using timer1*/
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM10);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM11);
	SET_BIT(TIMER1_TCCR1A , TIMER1_WGM12);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM13);

	/*setting prescaler to be 1024 */
	SET_BIT(TIMER1_TCCR1B , TIMER1_CS10);
	CLR_BIT(TIMER1_TCCR1B , TIMER1_CS11);
	SET_BIT(TIMER1_TCCR1B , TIMER1_CS12);

	/* Disconnect OC1A, OC1B */
	CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1A0);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1A1);

#if(CHANNEL == CHANNEL_A)
	{
	if(Copy_u32Time_ms > 0 && Copy_u32Time_ms < 8300)
	{
	/*Set the compare match value into OCR1A register */
	/* OCR1A = compare match time * 1000 / 128        */
	/*1000 to transfer to ms and 128 is the tick time */
	TIMER1_OCR1AL = (UL)(Copy_u32Time_ms * (125UL/16UL)) ;
	}

	/*polling over compare match flag*/
	/*this flag is automatically cleared by HW when the Output Compare Match A Interrupt Vector is executed*/
	while(GET_BIT(TIMER1_TIFR , TIMER1_OCF1A) == 0);

	/*clear timer interrupt flag register*/
	SET_BIT(TIMER1_TIFR , TIMER1_OCF1A);
	}

#elif(CHANNEL == CHANNEL_B)
	{
	if(Copy_u32Time_ms > 0 && Copy_u32Time_ms < 8300)
	{
	/*Set the compare match value into OCR1B register */
	/* OCR1B = compare match time * 1000 / 128        */
	/*1000 to transfer to ms and 128 is the tick time */
	TIMER1_OCR1BL = (UL)(Copy_u32Time_ms * (125UL/16UL)) ;
	}

	/*polling over compare match flag*/
	/*this flag is automatically cleared by HW when the Output Compare Match B Interrupt Vector is executed*/
	while(GET_BIT(TIMER1_TIFR , TIMER1_OCF1B) == 0);

	/*clear timer interrupt flag register*/
	SET_BIT(TIMER1_TIFR , TIMER1_OCF1B);
	}
#endif

}


void TMR_voidSetDelayAsync(u32 Copy_u32Time_ms , void (*PtrToCallBack)(void))
{
	/*activate CTC mode 4 using timer1*/
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM10);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM11);
	SET_BIT(TIMER1_TCCR1A , TIMER1_WGM12);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM13);

	/*setting prescaler to be 1024 */
	SET_BIT(TIMER1_TCCR1B, TIMER1_CS10);
	CLR_BIT(TIMER1_TCCR1B, TIMER1_CS11);
	SET_BIT(TIMER1_TCCR1B, TIMER1_CS12);

#if(CHANNEL == CHANNEL_A)
	{
	/* Disconnect OC1A, OC1B */
	CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1A0);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1A1);

	if(Copy_u32Time_ms > 0 && Copy_u32Time_ms < 8300)
	{
	/*Set the compare match value into OCR1A register */
	/* OCR1A = compare match time * 1000 / 128        */
	/*1000 to transfer to ms and 128 is the tick time */
	TIMER1_OCR1AL = (Copy_u32Time_ms * (125UL/16UL)) ;
	}

	/*output compare match A interrupt enable in TIMSK register(SIE)*/
	SET_BIT(TIMER1_TIMSK , TIMER1_OCIE1A);

    }

#elif(CHANNEL == CHANNEL_B)
	{
	/* Disconnect OC1A, OC1B */
	CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1B0);
	CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1B1);

	if(Copy_u32Time_ms > 0 && Copy_u32Time_ms < 8300)
	{
	/*Set the compare match value into OCR1B register */
	/* OCR1B = compare match time * 1000 / 128        */
	/*1000 to transfer to ms and 128 is the tick time */
	TIMER1_OCR1BL = (UL)(Copy_u32Time_ms * (125UL/16UL)) ;
	}

	/*output compare match B interrupt enable in TIMSK register(SIE)*/
	SET_BIT(TIMER1_TIMSK , TIMER1_OCIE1B);

	}
#endif

		/*pass ISR pointer to the global*/
		Global_ptrToCallBack = PtrToCallBack ;
}


/*ISR for timer1 compare match A*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if(Global_ptrToCallBack != NULL)
	{
		Global_ptrToCallBack() ;
	}
	else
	{
		/*do nothing*/
	}

}


/*ISR for timer1 compare match B*/
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	if(Global_ptrToCallBack != NULL)
	{
		Global_ptrToCallBack() ;
	}
	else
	{
		/*do nothing*/
	}

}
