/*
 * EXTI_interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Nourhan
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*possible sense signals*/
#define LOW_LEVEL             0
#define ON_CHANGE             1
#define FALLING_EDGE          2
#define RISING_EDGE           3

#define INT0                  0
#define INT1                  1
#define INT2                  2

/**********************************************************************************************************************/
/*****************************************Functions' Declaration*******************************************************/
/**********************************************************************************************************************/

/*this function is a simple initiation for INT1*/
void EXTI_voidINT1Init(void);

/*this function is to initialize INT0 during run time*/
void EXTI_voidINT0Init_RunTime(u8 Copy_INT0_SenseSignal);

/*this function is to initialize INT1 during run time*/
void EXTI_voidINT1Init_RunTime(u8 Copy_INT0_SenseSignal);

/*this function is to initialize INT2 during run time*/
void EXTI_voidINT2Init_RunTime(u8 Copy_INT0_SenseSignal);

/*this function is to initialize INT0 by prebuild process*/
void EXTI_voidINT0Init_PreBuild(void);

/*this function is to initialize INT1 by prebuild process*/
void EXTI_voidINT1Init_PreBuild(void);

/*this function is to initialize INT2 by prebuild process*/
void EXTI_voidINT2Init_PreBuild(void);

/*this is a call back function for INT0 that takes a pointer to a function as an argument and pass it to the ISR corresponding*/
void EXTI_voidSetCallBackINT0(void(*Copy_ptrToFunc)(void));

/*this is a call back function for INT1 that takes a pointer to a function as an argument and pass it to the ISR corresponding*/
void EXTI_voidSetCallBackINT1(void(*Copy_ptrToFunc)(void));

/*this is a call back function for INT2 that takes a pointer to a function as an argument and pass it to the ISR corresponding*/
void EXTI_voidSetCallBackINT2(void(*Copy_ptrToFunc)(void));

/*this function is to disable the INT being passed as an argument*/
void EXTI_voidDisableEXTI(u8 INT_ID);

#endif /* EXTI_INTERFACE_H_ */
