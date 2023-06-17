/*
 * TIMER1_private.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Nourhan
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TIMER1_TCCR1A             *((volatile u8*)(0x4F))
#define TIMER1_WGM10              0
#define TIMER1_WGM11              1
#define TIMER1_FOC1B              2
#define TIMER1_FOC1A              3
#define TIMER1_COM1B0             4
#define TIMER1_COM1B1             5
#define TIMER1_COM1A0             6
#define TIMER1_COM1A1             7

#define TIMER1_TCCR1B             *((volatile u8*)(0x4E))
#define TIMER1_WGM12              3
#define TIMER1_WGM13              4
#define TIMER1_CS10               0
#define TIMER1_CS11               1
#define TIMER1_CS12               2

#define TIMER1_TCNT1H             *((volatile u8*)(0x4D))
#define TIMER1_TCNT1L             *((volatile u8*)(0x4C))
#define TIMER1_OCR1AL             *((volatile u16*)(0x4A))
#define TIMER1_OCR1BL             *((volatile u16*)(0x48))
#define TIMER1_ICR1L              *((volatile u16*)(0x46))

#endif /* TIMER1_PRIVATE_H_ */
