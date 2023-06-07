/************************************************************************/
/*Author      : Nourhan Osama										    */
/*File Name   : LED_interface.h                                         */
/*Layer       : HAL									      			    */
/*Description : This file contains interfacing parameters of LED module */
/*Date        : 26 March 2023                                           */
/************************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



void LED_Init(u8 Copy_u8PortID);

void LED_ON(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_OFF(u8 Copy_u8PortID , u8 Copy_u8Pin);

void LED_TOGGLE(u8 Copy_u8PortID , u8 Copy_u8Pin);


#endif /* LED_INTERFACE_H_ */
