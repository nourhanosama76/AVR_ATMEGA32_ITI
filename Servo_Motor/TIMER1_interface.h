/*
 * TIMER1_interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Nourhan
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define CHANNEL_A     1
#define CHANNEL_B     2

/*this function shall rotate the servo motor at a specific required angle*/
void Servo_voidRotateServo(u8 Copy_u8Channel , u32 Copy_u8Angle);

#endif /* TIMER1_INTERFACE_H_ */
