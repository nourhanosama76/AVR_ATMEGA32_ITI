/*
 * main.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Nourhan
 */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "SSD_interface.h"

#include "TIMER0_interface.h"


/******************************************************************************************************************/
/***************************************global variables***********************************************************/
/******************************************************************************************************************/

/*numbers to be displayed on the SSD*/
u8 Local_u8Arr[10]={Number0 , Number1 , Number2 , Number3 , Number4 , Number5 , Number6 , Number7 , Number8 , Number9};
u8 Local_u8IteratorUp = 0 ;
u8 Local_u8IteratorDown = 9 ;

/******************************************************************************************************************/
/***************************************functions' declaration**************************************************************/
/******************************************************************************************************************/

void Application(void);

/******************************************************************************************************************/
/***************************************main function**************************************************************/
/******************************************************************************************************************/
void main(void)
{
	SSD_voidInit(DIO_PORTB , DIO_PORTA , DIO_PIN0);
	SSD_voidInit(DIO_PORTB , DIO_PORTA , DIO_PIN1);

	/*enable global interrupt*/
	GIE_voidEnable();

	/*run timer 0 on CTC mode to count 1 second between every number to be displayed*/
	TMR0_voidRunTMR0CTCAsync(Application);


	while(1)
	{
	/*activate SSD1*/
	SSD_voidON(SSD_MODE_COMMON_CATHODE , DIO_PORTA , DIO_PIN0);
	/*deactivate SSD2*/
	SSD_voidOFF(SSD_MODE_COMMON_CATHODE , DIO_PORTA , DIO_PIN1);

	SSD_voidDisplayNumber(SSD_MODE_COMMON_CATHODE , DIO_PORTB , Local_u8Arr[Local_u8IteratorUp]);
	_delay_ms(10);

	/*deactivating SSD1 and activating SSD2*/
	SSD_voidOFF(SSD_MODE_COMMON_CATHODE , DIO_PORTA , DIO_PIN0);
	SSD_voidON(SSD_MODE_COMMON_CATHODE , DIO_PORTA , DIO_PIN1);

	SSD_voidDisplayNumber(SSD_MODE_COMMON_CATHODE , DIO_PORTB , Local_u8Arr[Local_u8IteratorDown]);
	_delay_ms(10);

	}

}

/******************************************************************************************************************/
/*************************************** Function Implementation **************************************************/
/******************************************************************************************************************/
void Application(void)
{
	u16 static Local_u16Counter = 0 ;
	Local_u16Counter++ ;

	/*timer0 counts till 4000 which represents 1 second*/
	if(Local_u16Counter == 4000)
	{
		/*display the numbers in ascending and descending orders*/
		Local_u8IteratorUp++ ;
		Local_u8IteratorDown-- ;

		if(Local_u8IteratorUp > 9)
		{
			Local_u8IteratorUp = 0 ;
	     	Local_u8IteratorDown = 9 ;
		}
		/*reset the counter*/
		Local_u16Counter = 0 ;
	}

}
