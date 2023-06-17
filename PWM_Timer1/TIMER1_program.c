/*
 * TIMER1_program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Nourhan
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_cfg.h"

//void TMR1_voidTMR1SetCompareMatchValue(u16 Copy_u16OCR1Value)
//{
//	TIMER1_OCR1AL = Copy_u16OCR1Value;
//}



void PWM_voidRunPWM(u8 Copy_u8Channel , u16 Copy_u16Frequency)
{
		/* Select Timer1 Mode => 14 */
		CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM10);
		SET_BIT(TIMER1_TCCR1A , TIMER1_WGM11);
		SET_BIT(TIMER1_TCCR1B , TIMER1_WGM12);
		SET_BIT(TIMER1_TCCR1B , TIMER1_WGM13);

	if(Copy_u8Channel == CHANNEL_A)
	{
    #if(PWM_MODE == NON_INVERTING)
		/* Select HW Action on OC1A pin => Non Inverting */
		CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1A0);
		SET_BIT(TIMER1_TCCR1A , TIMER1_COM1A1);

    #elif(PWM_MODE == INVERTING)
		/* Select HW Action on OC1A pin => Inverting */
		SET_BIT(TIMER1_TCCR1A , TIMER1_COM1A0);
		SET_BIT(TIMER1_TCCR1A , TIMER1_COM1A1);
    #endif
	}

	else if(Copy_u8Channel == CHANNEL_B)
	{
    #if(PWM_MODE == NON_INVERTING)
		/* Select HW Action on OC1B pin => Non Inverting */
		CLR_BIT(TIMER1_TCCR1B , TIMER1_COM1B0);
		SET_BIT(TIMER1_TCCR1B , TIMER1_COM1B1);

    #elif(PWM_MODE == INVERTING)
		/* Select HW Action on OC1B pin => Non Inverting */
		SET_BIT(TIMER1_TCCR1B , TIMER1_COM1B0);
		SET_BIT(TIMER1_TCCR1B , TIMER1_COM1B1);
    #endif
	}

		/*set TOP value in ICR1 register represented in frequency*/
		TIMER1_ICR1L = Copy_u16Frequency ;

		/* Set Prescaler Value CLK/8 */
		CLR_BIT(TIMER1_TCCR1B , TIMER1_CS10);
		SET_BIT(TIMER1_TCCR1B , TIMER1_CS11);
		CLR_BIT(TIMER1_TCCR1B , TIMER1_CS12);
}



void PWM_voidSetDutyCycle(f32 Copy_u8DutyCycle)
{
	/*multiply the percentage of duty cycle by 2^resolution to get the OCR1 value*/
	if(CHANNEL == CHANNEL_A)
	{
		TIMER1_OCR1AL = (f32)((Copy_u8DutyCycle/100) * (TIMER1_ICR1L)) ;
	}

	else if(CHANNEL == CHANNEL_B)
	{
		TIMER1_OCR1BL = (f32)((Copy_u8DutyCycle/100) * (TIMER1_ICR1L)) ;
	}

}
