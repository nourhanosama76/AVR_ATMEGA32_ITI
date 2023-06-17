/*
 * DelayTMR1_interface.h
 *
 *  Created on: Apr 15, 2023
 *      Author: Nourhan
 */

#ifndef DELAYTMR1_INTERFACE_H_
#define DELAYTMR1_INTERFACE_H_

#define CHANNEL_A         1
#define CHANNEL_B         2

/*this function shall set the delay Synchronously (polling over a flag)*/
void TMR_voidSetDelaySync(u32 Copy_u32Time_ms);

/*this function shall set the delay Asynchronously (Interrupt)*/
void TMR_voidSetDelayAsync(u32 Copy_u32Time_ms , void (*PtrToCallBack)(void));

#endif /* DELAYTMR1_INTERFACE_H_ */
