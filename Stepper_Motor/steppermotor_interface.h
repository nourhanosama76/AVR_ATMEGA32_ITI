/*
 * steppermotor_interface.h
 *
 *  Created on: May 14, 2023
 *      Author: Nourhan
 */

#ifndef STEPPERMOTOR_INTERFACE_H_
#define STEPPERMOTOR_INTERFACE_H_

/*this function shall initialize the motor pins to be output*/
void Stepper_voidInit(void);

/*this function is to rotate the stepper motor clock wise continuously*/
void Stepper_voidRotCWCont(void);

/*this function is to rotate the stepper motor counter clock wise continuously*/
void Stepper_voidRotCCWCont(void);

/*this function is to rotate the stepper motor clock wise with a specific angle*/
void Stepper_voidRotCWAngle(f32 Copy_f32Angle);

/*this function is to rotate the stepper motor counter clock wise with a specific angle*/
void Stepper_voidRotCCWAngle(f32 Copy_f32Angle);

/*this function shall stop the motor*/
void Stepper_voidStopMotor(void);

#endif /* STEPPERMOTOR_INTERFACE_H_ */
