/*
 * ICU_interface.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Nourhan
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define CHANNEL_A                1
#define CHANNEL_B_               2

#define FALLING                  0
#define RISING                   1

#define TMR0_NO_CLK              0
#define TMR0_NO_PRESCALER        1
#define TMR0_PRESCALER_8         2
#define TMR0_PRESCALER_64        3
#define TMR0_PRESCALER_256       4
#define TMR0_PRESCALER_1024      5

void TMR0_voidNonInvertedPWM(void);

void TMR1_voidOVF(void (* PtrToCallBack)(void));

u16 ICU_u16GetReading(void);

void ICU_voidSetSenseSignal(u8 Copy_u8Signal);

void ICU_voidDisableInterrupt(void);

#endif /* ICU_INTERFACE_H_ */
