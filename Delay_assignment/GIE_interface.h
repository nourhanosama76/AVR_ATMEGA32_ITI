/*
 * GIE_interface.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Nourhan
 */

#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/****************************************************************************************/
/*****************************Functions' declaration*************************************/
/****************************************************************************************/


/*this function is to enable the global interrupt by setting the I-BIT to 1*/
void GIE_voidEnable(void);

/*this function is to disable the global interrupt by clearing the I-BIT*/
void GIE_voidDisable(void);

#endif /* GIE_INTERFACE_H_ */
