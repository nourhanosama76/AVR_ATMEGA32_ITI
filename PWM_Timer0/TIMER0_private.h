/*
 * TIMER0_private.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Nourhan
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


/******************Bit masks*******************/
#define PRESCALER_MASK      0b11111000


/*****************Private bits*****************/
//TIMER-COUNTER0

#define TIMER0_TCCR0      *((volatile u8*)(0x53))
#define TCCR0_WGM0                 6  //two bits for mode of timer0
#define TCCR0_WGM1                 3
#define TCCR0_COM1                 5  //two bits for behavior of OC0 pin
#define TCCR0_COM0                 4

/*3 bits to set the prescaler value*/
#define TCCR0_CS00                 0
#define TCCR0_CS01                 1
#define TCCR0_CS02                 2


#define TIMER0_TCNT0      *((volatile u8*)(0x52))
#define TIMER0_OCR0       *((volatile u8*)(0x5C))

#define TIMSK             *((volatile u8*)(0x59))
#define TIMSK_TOIE0                0  //timer0 over flow interrupt enable
#define TIMSK_OCIE0                1  //timer0 compare match interrupt enable

#define TIFR	          *((volatile u8*)(0x58))
#define TIFR_TOV0                  0  //timer0 over flow interrupt flag
#define TIFR_OCF0                  1  //timer0 compare match interrupt flag


#endif /* TIMER0_PRIVATE_H_ */
