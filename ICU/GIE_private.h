/*
 * GIE_private.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Nourhan
 */

#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_

#define SREG            (*(volatile u8 *)(0x5F))         // status register *global interrupt enable bit in this register* (I-BIT)
#define SREG_IBIT       7

#endif /* GIE_PRIVATE_H_ */
