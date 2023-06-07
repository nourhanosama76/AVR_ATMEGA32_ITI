/*
 * ADC_private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Nourhan
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


/******************************************private macros******************************************/
#define MUX_MASK              0b11100000
#define PRESCALER_MASK        0b00000111


/******************************************ADC registers******************************************/

#define ADMUX    *((volatile u8 *)(0x27))      //ADC multiplexer selection register
#define ADMUX_REFS1                   7         //for reference voltage selection bit1
#define ADMUX_REFS0                   6         //for reference voltage selection bit0
#define ADMUX_ADLAR                   5         //for left adjustment


#define ADCSRA   *((volatile u8 *)(0x26))      //ADC control and status registerA
#define ADCSRA_ADEN                   7         //for ADC enable
#define ADCSRA_ADSC                   6         //for ADC start conversion
#define ADCSRA_ADATE                  5         //for ADC auto trigger enable
#define ADCSRA_ADIF                   4         //for ADC interrupt flag
#define ADCSRA_ADIE                   3         //for ADC interrupt enable
#define ADCSRA_ADP2                   2         //for ADC clock prescaler bit 2
#define ADCSRA_ADP1                   1         //for ADC clock prescaler bit 1
#define ADCSRA_ADP0                   0         //for ADC clock prescaler bit 0

#define ADCH     *((volatile u8 *)(0x25))      //ADC high register
#define ADCL     *((volatile u8 *)(0x24))      //ADC low register

#define SFIOR    *((volatile u8 *)(0x50))      //ADC special function IO register
#define ADCR     *((volatile u16*)(0x24))      //ADC data register for 10 bit resolution

#define SREG     *((volatile u8 *)(0x5F))                          // status register *global interrupt enable bit in this register* (I-BIT)

#define SREG_IBIT                     7


#endif /* ADC_PRIVATE_H_ */
