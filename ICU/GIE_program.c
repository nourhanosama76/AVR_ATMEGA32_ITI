/*
 * GIE_program.c
 *
 *  Created on: Apr 6, 2023
 *      Author: Nourhan
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_cfg.h"

/****************************************************************************************/
/*****************************Functions' implementation**********************************/
/****************************************************************************************/

void GIE_voidEnable(void)
{
	SET_BIT(SREG , SREG_IBIT);
}


void GIE_voidDisable(void)
{
	CLR_BIT(SREG , SREG_IBIT);
}


