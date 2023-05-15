/*
 * EXTI_private.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


/*external interrupts registers*/
#define SREG            (*(volatile u8 *)(0x5F))                          // status register *global interrupt enable bit in this register* (I-BIT)
#define MCUCR           (*(volatile u8 *)(0x55))                          // MCU control register
#define MCUCSR          (*(volatile u8 *)(0x54))                          // MCU control and status register
#define GICR            (*(volatile u8 *)(0x5B))                          // general interrupt control register
#define GIFR            (*(volatile u8 *)(0x5A))                          // general interrupt flag register

#define MCUCR_ISC00       0    //for sense signal for INT0
#define MCUCR_ISC01       1    //for sense signal for INT0
#define MCUCR_ISC10       2    //for sense signal for INT1
#define MCUCR_ISC11       3    //for sense signal for INT1


/* MCU control and status register */
#define MCUCSR_ISC2       6    //for sense signal for INT2

/* general interrupt control register */
#define GICR_INT0         6
#define GICR_INT1         7
#define GICR_INT2         5

/* general interrupt flag register */
#define GIFR_INT0         6
#define GIFR_INT1         7
#define GIFR_INT2         5


#define SREG_IBIT         7

//void __vector_1(void) __attribute__((signal));       //INT0
//void __vector_2(void) __attribute__((signal));       //INT1
//void __vector_3(void) __attribute__((signal));       //INT2
//

#endif /* EXTI_PRIVATE_H_ */
