/*
 * DCMotor_interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_


void DCMotor_voidInit(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 );

void DCMotor_voidRotCW(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 , u8 Copy_u8Pin0 , u8 Copy_u8Pin1 );

void DCMotor_voidRotCCW(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 );

void DCMotor_voidStopMotor(u8 Copy_u8PortID0 , u8 Copy_u8PortID1 ,  u8 Copy_u8Pin0 , u8 Copy_u8Pin1 );


#endif /* DCMOTOR_INTERFACE_H_ */
