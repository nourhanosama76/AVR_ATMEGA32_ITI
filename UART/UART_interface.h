/*
 * UART_interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Nourhan
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*UART parity mode settings*/
#define No_Parity          0
#define Even_Parity        1
#define Odd_Parity         2

/*UART operation mode select*/
#define Sync_Mode          0
#define Async_Mode         1

/*UART stop bit select*/
#define One_Bit            0
#define Two_Bit            1

/*UART character size select*/
#define Five_Bit           0
#define Six_Bit            1
#define Seven_Bit          2
#define Eight_Bit          3
#define Nine_Bit           4

/*node mode*/
#define Trasmitter         0
#define Receiver           1
#define Tranceiver         2

typedef struct
{
	u8 Parity          ;
	u8 Stop_Bit        ;
	u8 Node_Mode       ;
	u8 Char_Size       ;
	u8 Node_Sync_Async ;
}UART_t ;

void UART_voidInit(UART_t * PtrToStruct);

void UART_voidTransmitDataSync(u8 Copy_u8Data);

u8 UART_voidRecieveDataSync(void);

void UART_voidReceivedAsync(u8 Copy_pu8ReceivedData , void(*Copy_ptrToFunc)(void));

void UART_voidSendStringSync(char * Copy_PtrToCharString);

void UART_voidReceiveBufferSync(char * Copy_ptrToReceiveBuffer , u8 Copy_u8BufferSize);

#endif /* UART_INTERFACE_H_ */
