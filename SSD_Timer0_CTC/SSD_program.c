/*
 * SSD_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Nourhan
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_cfg.h"


void SSD_voidInit(u8 Copy_u8PortID , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin)
{
	DIO_voidSetPortDirection(Copy_u8PortID , DIO_PORT_OUTPUT);

	DIO_voidSetPinDirection(Copy_u8CommonPortID , Copy_u8CommonPin , DIO_PIN_OUTPUT);
}


/************************************************************************************************************/
void SSD_voidON(u8 Copy_u8SSDConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin)
{
	//DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , Copy_u8SSDConnection);

	if(Copy_u8SSDConnection == SSD_MODE_COMMON_CATHODE)
	{
		DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , DIO_LOW_PIN );
	}

	else if(Copy_u8SSDConnection == SSD_MODE_COMMON_ANODE)
	{
		DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , DIO_HIGH_PIN );
	}
}



/************************************************************************************************************/
void SSD_voidOFF(u8 Copy_u8SSDConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin)
{
	if(Copy_u8SSDConnection == SSD_MODE_COMMON_CATHODE)
	{
		DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , DIO_HIGH_PIN);
	}

	else if(Copy_u8SSDConnection == SSD_MODE_COMMON_ANODE)
	{
		DIO_voidSetPinValue(Copy_u8CommonPortID , Copy_u8CommonPin , DIO_LOW_PIN);
	}
}



/************************************************************************************************************/
void SSD_voidDisplayNumber(u8 Copy_u8SSDConnection , u8 Copy_u8PortID , u8 Copy_u8Number )
{

		//DIO_u8SetPortValue(Copy_u8PortID , ~Copy_u8Number);
	if(Copy_u8SSDConnection == SSD_MODE_COMMON_CATHODE)
	{
		DIO_u8SetPortValue(Copy_u8PortID , Copy_u8Number);
	}

	else if(Copy_u8SSDConnection == SSD_MODE_COMMON_ANODE)
	{
		DIO_u8SetPortValue(Copy_u8PortID , ~Copy_u8Number);
	}
}

