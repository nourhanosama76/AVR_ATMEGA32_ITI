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


void Servo_voidRotateServo(u8 Copy_u8Channel , u32 Copy_u32Angle)
{
	/* Select Timer1 Mode => 14 */
	CLR_BIT(TIMER1_TCCR1A , TIMER1_WGM10);
	SET_BIT(TIMER1_TCCR1A , TIMER1_WGM11);
	SET_BIT(TIMER1_TCCR1B , TIMER1_WGM12);
	SET_BIT(TIMER1_TCCR1B , TIMER1_WGM13);

	if(Copy_u8Channel == CHANNEL_A)
	{
		/* Select HW Action on OC1A pin => Non Inverting */
		CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1A0);
		SET_BIT(TIMER1_TCCR1A , TIMER1_COM1A1);

		/*set TOP value in ICR1 register represented in frequency*/
		TIMER1_ICR1L = 20000 ;

		/*set Ton value in ICR register*/
		TIMER1_OCR1AL = (long)(750 + ((175/18) * Copy_u32Angle)) ;
	}

	else if(Copy_u8Channel == CHANNEL_B)
	{
		/* Select HW Action on OC1A pin => Non Inverting */
		CLR_BIT(TIMER1_TCCR1A , TIMER1_COM1B0);
		SET_BIT(TIMER1_TCCR1A , TIMER1_COM1B1);

		/*set top value in ICR1 register represented in frequency*/
		TIMER1_ICR1L = 20000 ;

		TIMER1_OCR1BL = (long)(750 + ((175/18) * Copy_u32Angle)) ;
	}

		/* Set Prescaler Value CLK/8 */
		CLR_BIT(TIMER1_TCCR1B , TIMER1_CS10);
		SET_BIT(TIMER1_TCCR1B , TIMER1_CS11);
		CLR_BIT(TIMER1_TCCR1B , TIMER1_CS12);
}
