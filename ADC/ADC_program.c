/*
 * ADC_program.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Nourhan
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include <util/delay.h>
#include "DIO_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_cfg.h"


/****************************************************************************************/
/************************************Global Variables************************************/
/****************************************************************************************/

/*global pointer to function to set end of conversion interrupt call back*/
void (*Global_ptrEndOfConversion)(void) = NULL;

/*global pointer to u8 to receive u8 reading*/
u8 * Global_u8Reading = NULL;

/***********************************************************************************************/
/***********************************Functions' Implementation***********************************/
/***********************************************************************************************/
/*function to init the ADC peripheral*/
void ADC_voidInit(void)
{
	/*set the reference voltage -> Avcc */
	SET_BIT(ADMUX , ADMUX_REFS0);
	CLR_BIT(ADMUX , ADMUX_REFS1);

	/*set left adjust*/
	SET_BIT(ADMUX , ADMUX_ADLAR);



	/*set clk prescaler ->128 */
	SET_BIT(ADCSRA , ADCSRA_ADP0);
	SET_BIT(ADCSRA , ADCSRA_ADP1);
	SET_BIT(ADCSRA , ADCSRA_ADP2);


	/*enable ADC*/
	SET_BIT(ADCSRA , ADCSRA_ADEN);

}

/*this function shall start the conversion*/
void ADC_voidStartConversionAsync(u8 Copy_u8Channel , u8 * Copy_u8Reading)
{

	/*enable end of conversion interrupt*/
	SET_BIT(ADCSRA , ADCSRA_ADIE);


	SET_BIT(SREG , SREG_IBIT);

	/*set ADC channel*/
	ADMUX &= MUX_MASK ;
	ADMUX |= Copy_u8Channel ;

	/*assign to get reading*/
	Global_u8Reading = Copy_u8Reading;

	/*start conversion*/
	SET_BIT(ADCSRA , ADCSRA_ADSC);

}




void ADC_voidSetCallBack(void(*Copy_ptrToFunction)(void))
{
	if(Copy_ptrToFunction != NULL)
	{
		Global_ptrEndOfConversion = Copy_ptrToFunction ;
	}
	else
	{

	}


}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if(Global_ptrEndOfConversion != NULL)
	{
		*Global_u8Reading = ADCH;
		Global_ptrEndOfConversion();
	}
	else
	{

	}
}
