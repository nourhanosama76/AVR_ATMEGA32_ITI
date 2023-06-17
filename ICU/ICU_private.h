/*
 * ICU_private.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Nourhan
 */

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

/******************Bit masks*******************/
#define PRESCALER_MASK            0b11111000


/*****************Private bits*****************/
//TIMER-COUNTER0

#define TIMER0_TCCR0              *((volatile u8*)(0x53))
#define TCCR0_WGM0                6  //two bits for mode of timer0
#define TCCR0_WGM1                3
#define TCCR0_COM1                5  //two bits for behavior of OC0 pin
#define TCCR0_COM0                4

#define TIMER0_TCNT0              *((volatile u8*)(0x52))
#define TIMER0_OCR0               *((volatile u8*)(0x5C))


#define TIFR	                  *((volatile u8*)(0x58))
#define TIFR_TOV0                 0  //timer0 over flow interrupt flag
#define TIFR_OCF0                 1  //timer0 compare match interrupt flag

/******************************************************/
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
#define TIMER1_CS10               0
#define TIMER1_CS11               1
#define TIMER1_CS12               2
#define TIMER1_WGM12              3
#define TIMER1_WGM13              4
#define TIMER1_ICES1              6

#define TIMER1_TCNT1H             *((volatile u8*)(0x4D))
#define TIMER1_TCNT1L             *((volatile u8*)(0x4C))
#define TIMER1_OCR1AL             *((volatile u16*)(0x4A))
#define TIMER1_OCR1BL             *((volatile u16*)(0x48))
#define TIMER1_ICR1L              *((volatile u16*)(0x46))

#define TIMSK                     *((volatile u8*)(0x59))
#define TIMSK_TOIE1                2  //timer1 over flow interrupt enable
#define TIMSK_OCIE1B               3  //timer1 compare match B interrupt enable
#define TIMSK_OCIE1A               4  //timer1 compare match A interrupt enable
#define TIMSK_TICIE1               5  //timer1 input capture interrupt enable

#endif /* ICU_PRIVATE_H_ */
