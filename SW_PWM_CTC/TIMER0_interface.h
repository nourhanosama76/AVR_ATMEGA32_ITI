/*
 * TIMER0_interface.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Nourhan
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TMR0_NO_CLK              0
#define TMR0_NO_PRESCALER        1
#define TMR0_PRESCALER_8         2
#define TMR0_PRESCALER_64        3
#define TMR0_PRESCALER_256       4
#define TMR0_PRESCALER_1024      5

/* this function shall start timer0 in ctc mode*/
void TMR0_voidRunTMR0CTCAsync(void(*Copy_ptrToFuncCTCINT)(void));

#endif /* TIMER0_INTERFACE_H_ */
