/*
 * TIMER1_interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Nourhan
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#define CHANNEL_A             1       //activate action on OC1A
#define CHANNEL_B             2       //activate action on OC1B

/*PWM options*/
#define FAST_PWM              1
#define PHASE_COREECT_PWM     2

/*mode for the signal*/
/*duty cycle is directly proportional to compare match value or inversely proportional to it*/
#define INVERTING             1       //inversely proportional
#define NON_INVERTING         2       //directly proportional

/*possible frequencies represented by values to be set in ICR1 register*/
#define FREQUENCY_1000        1000
#define FREQUENCY_500         2000
#define FREQUENCY_250         4000
#define FREQUENCY_200         5000
#define FREQUENCY_125         8000
#define FREQUENCY_100         10000
#define FREQUENCY_50          20000
#define FREQUENCY_40          25000
#define FREQUENCY_25          40000
#define FREQUENCY_20          50000

/******************************************************************************************/
/***************************** functions' declaration *************************************/
/******************************************************************************************/

void TMR1_voidTMR1Init(void);

void TMR1_voidTMR1SetCompareMatchValue(u16 Copy_u16OCR1Value);

/*this function shall run timer1 on PWM mode*/
void PWM_voidRunPWM(u8 Copy_u8Channel , u16 Copy_u16Frequency);

/*this function shall set the duty cycle of the signal according to the TOP value in ICR*/
void PWM_voidSetDutyCycle(f32 Copy_u8DutyCycle);

#endif /* TIMER1_INTERFACE_H_ */
