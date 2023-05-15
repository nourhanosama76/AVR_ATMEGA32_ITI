/*
 * EXTI_program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_cfg.h"


/************************Global variables*************************/
void(*EXTI_Int0CallBack)(void)=NULL;


/****************************************************************************************/
/*****************************Functions' implementation**********************************/
/****************************************************************************************/

void EXTI_voidINT1Init(void)
{
	/* set sense signal on int1 to be falling edge*/
	CLR_BIT(MCUCR , MCUCR_ISC10);
	SET_BIT(MCUCR , MCUCR_ISC11);


	/*enable INT1*/
	SET_BIT(GICR , GICR_INT1);

	/*enable global interrupt*/
	SET_BIT(SREG , SREG_IBIT);
}


void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_Int0CallBack = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}
}

/****************************************************************************************/
/*******************************ISRs' Implementation*************************************/
/****************************************************************************************/


/*ISR for INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_Int0CallBack != NULL)
	{
		EXTI_Int0CallBack();
	}
	else
	{
		/*do nothing*/
	}
}
