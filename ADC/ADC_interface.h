/*
 * ADC_interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Nourhan
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_CHANNEL0             0
#define ADC_CHANNEL1             1
#define ADC_CHANNEL2             2
#define ADC_CHANNEL3             3
#define ADC_CHANNEL4             4
#define ADC_CHANNEL5             5
#define ADC_CHANNEL6             6
#define ADC_CHANNEL7             7



/*function to init the ADC peripheral*/
void ADC_voidInit(void);


/*this function shall start the conversion on a specific channel*/
void ADC_voidStartConversionAsync(u8 Copy_u8Channel , u8 * Copy_u8Reading);

/**/
void ADC_voidSetCallBack(void(*Copy_ptrToFunction)(void));


void __vector_16(void) __attribute__((signal));

#endif /* ADC_INTERFACE_H_ */
