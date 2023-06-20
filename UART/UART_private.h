/*
 * UART_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Nourhan
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UART_UDR             *((volatile u8*)(0x2C))     //data register
#define UART_UCSRA           *((volatile u8*)(0x2B))     //control and status register
#define UCSRA_UDRE           5
#define UCSRA_TXC            6
#define UCSRA_RXC            7


#define UART_UCSRB           *((volatile u8*)(0x2A))
#define UCSRB_RXCIE          7
#define UCSRB_TXCIE          6
#define UCSRB_UDRIE          5
#define UCSRB_RXEN           4
#define UCSRB_TXEN           3
#define UCSRB_UCSZ2          2


#define UART_UCSRC           *((volatile u8*)(0x40))
#define UCSRC_UCPOL          0
#define UCSRC_UCSZ0          1
#define UCSRC_UCSZ1          2
#define UCSRC_USBS           3      //stop bit select
#define UCSRC_UPM0           4      //parity mode
#define UCSRC_UPM1           5
#define UCSRC_UMSEL          6      //bit setting sync or async
#define UCSRC_URSEL          7


#define UART_UBRRL           *((volatile u8*)(0x29))
#define UBRRH_URSEL          7

#define UART_UBRRH           *((volatile u8 *)0x40)

#endif /* UART_PRIVATE_H_ */
