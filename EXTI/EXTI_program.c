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
void(*EXTI_INT0CallBack)(void)=NULL;
void(*EXTI_INT1CallBack)(void)=NULL;
void(*EXTI_INT2CallBack)(void)=NULL;


/****************************************************************************************/
/*****************************Functions' implementation**********************************/
/****************************************************************************************/

/*this function is to initialize INT0*/
void EXTI_voidINT0Init_RunTime(u8 Copy_INT0_SenseSignal)
{
	if(Copy_INT0_SenseSignal == LOW_LEVEL)
	{
		CLR_BIT(MCUCR , MCUCR_ISC00);
		CLR_BIT(MCUCR , MCUCR_ISC01);
	}

	else if (Copy_INT0_SenseSignal == ON_CHANGE)
	{
		SET_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);
	}

	else if (Copy_INT0_SenseSignal == FALLING_EDGE)
	{
		CLR_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	}

	else if (Copy_INT0_SenseSignal == RISING_EDGE)
	{
		SET_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	}

	/*enable INT0 pin in GICR*/
	SET_BIT(GICR , GICR_INT0);

}

/**************************************************************************************/
/*this function is to initialize INT1*/
void EXTI_voidINT1Init_RunTime(u8 Copy_INT0_SenseSignal)
{
	if(Copy_INT0_SenseSignal == LOW_LEVEL)
	{
		CLR_BIT(MCUCR , MCUCR_ISC10);
		CLR_BIT(MCUCR , MCUCR_ISC11);
	}

	else if (Copy_INT0_SenseSignal == ON_CHANGE)
	{
		SET_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);
	}

	else if (Copy_INT0_SenseSignal == FALLING_EDGE)
	{
		CLR_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	}

	else if (Copy_INT0_SenseSignal == RISING_EDGE)
	{
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	}

	/*enable INT0 pin in GICR*/
	SET_BIT(GICR , GICR_INT1);
	SET_BIT(SREG , SREG_IBIT);

}

/**************************************************************************************/
/*this function is to initialize INT2*/
void EXTI_voidINT2Init_RunTime(u8 Copy_INT0_SenseSignal)
{
    if (Copy_INT0_SenseSignal == FALLING_EDGE)
	{
		CLR_BIT(MCUCSR, MCUCSR_ISC2);
	}

	else if (Copy_INT0_SenseSignal == RISING_EDGE)
	{
		SET_BIT(MCUCSR, MCUCSR_ISC2);
	}

	/*enable INT0 pin in GICR*/
	SET_BIT(GICR , GICR_INT2);

}



/**************************************************************************************/
void EXTI_voidINT0Init_PreBuild(void)
{
#if (INT0_SENSE_SIGNAL == LOW_LEVEL)
	CLR_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);

#elif (INT0_SENSE_SIGNAL == ON_CHANGE)
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif (INT0_SENSE_SIGNAL == FALLING_EDGE)
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

#elif (INT0_SENSE_SIGNAL == RISING_EDGE)
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);
#endif

	SET_BIT(GICR , GICR_INT0);

}



/**************************************************************************************/
void EXTI_voidINT1Init_PreBuild(void)
{
#if (INT1_SENSE_SIGNAL == LOW_LEVEL)
	CLR_BIT(MCUCR , MCUCR_ISC10);
	CLR_BIT(MCUCR , MCUCR_ISC11);

#elif (INT1_SENSE_SIGNAL == ON_CHANGE)
	SET_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#elif (INT1_SENSE_SIGNAL == FALLING_EDGE)
	CLR_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);

#elif (INT1_SENSE_SIGNAL == RISING_EDGE)
	SET_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);
#endif

	SET_BIT(GICR , GICR_INT1);

}



/**************************************************************************************/
void EXTI_voidINT2Init_PreBuild(void)
{
#if (INT2_SENSE_SIGNAL == FALLING_EDGE)
	CLR_BIT(MCUCSR, MCUCSR_ISC2);

#elif (INT2_SENSE_SIGNAL == RISING_EDGE)
	SET_BIT(MCUCSR, MCUCSR_ISC2);
#endif

	SET_BIT(GICR , GICR_INT2);

}



/**************************************************************************************/
void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_INT0CallBack = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}
}

/**************************************************************************************/
void EXTI_voidSetCallBackINT1(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_INT1CallBack = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}
}


/**************************************************************************************/
void EXTI_voidSetCallBackINT2(void(*Copy_ptrToFunc)(void))
{
	if(Copy_ptrToFunc != NULL)
	{
		EXTI_INT2CallBack = Copy_ptrToFunc ;
	}
	else
	{
		/*do nothing*/
	}
}

/**************************************************************************************/
void EXTI_voidDisableEXTI(u8 INT_ID)
{
	if(INT_ID == INT0)
		CLR_BIT(GICR , GICR_INT0);

	else if(INT_ID == INT1)
		CLR_BIT(GICR , GICR_INT1);

	else if(INT_ID == INT2)
		CLR_BIT(GICR , GICR_INT2);
}



///****************************************************************************************/
///*******************************ISRs' Implementation*************************************/
///****************************************************************************************/


/*ISR for INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_INT0CallBack != NULL)
	{
		EXTI_INT0CallBack();
	}
	else
	{
		/*do nothing*/
	}
}


/*ISR for INT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_INT1CallBack != NULL)
	{
		EXTI_INT1CallBack();
	}
	else
	{
		/*do nothing*/
	}
}
/*ISR for INT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_INT2CallBack != NULL)
	{
		EXTI_INT2CallBack();
	}
	else
	{
		/*do nothing*/
	}
}
