/*
 * SSD_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Nourhan
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define SSD_MODE_COMMON_CATHODE          0
#define SSD_MODE_COMMON_ANODE            1


#define Number0                     0b00111111
#define Number1                     0b00000110
#define Number2                     0b01011011
#define Number3                     0b01001111
#define Number4                     0b01100110
#define Number5                     0b01101101
#define Number6                     0b01111101
#define Number7                     0b00000111
#define Number8                     0b01111111
#define Number9                     0b01101111

void SSD_voidInit(u8 Copy_u8PortID , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin);

void SSD_voidON(u8 Copy_u8SSDConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin);

void SSD_voidOFF(u8 Copy_u8SSDConnection , u8 Copy_u8CommonPortID , u8 Copy_u8CommonPin);

void SSD_voidDisplayNumber(u8 Copy_u8SSDConnection , u8 Copy_u8PortID , u8 Copy_u8Number );

#endif /* SSD_INTERFACE_H_ */
