/*
 * EXTI_cfg.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/*LOW LEVEL -> 00 , LOGICAL CHANGE -> 01 , FALLING EDGE -> 10 , RISING EDGE -> 11*/
#define INT0_SENSE_SIGNAL          FALLING_EDGE

/*LOW LEVEL -> 00 , LOGICAL CHANGE -> 01 , FALLING EDGE -> 10 , RISING EDGE -> 11*/
#define INT1_SENSE_SIGNAL          LOW_LEVEL

/* FALLING EDGE -> 10 , RISING EDGE -> 11*/
#define INT2_SENSE_SIGNAL          FALLING_EDGE


#endif /* EXTI_CFG_H_ */
