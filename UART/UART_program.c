/*

 * UART_program.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Nourhan
 */
#include "BIT_MATHS.h"
#include "STD_TYPES.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_cfg.h"

/*****************************sync mode**********************************/
/*Global pointer to function for end of receive ISR*/
void (*EndOfReceive)(void) = NULL ;

void (*GlobalPtrToFunc)(void) = NULL ;
u8 * Global_u8ReceivedData = NULL ;




void UART_voidInit(UART_t * PtrToStruct)
{
	/*local variable to assign the value of UCSRC*/
	u8 Local_u8UCSRC_Value = 0 ;

	/*setting the node mode*/
	switch(PtrToStruct -> Node_Mode)
	{
	   case Trasmitter :
	   	   SET_BIT(UART_UCSRB , UCSRB_TXEN) ;
	   	   break ;

	   case Receiver :
	   	   SET_BIT(UART_UCSRB , UCSRB_RXEN) ;
	   	   break ;

	   case Tranceiver :
		   SET_BIT(UART_UCSRB , UCSRB_TXEN) ;
		   SET_BIT(UART_UCSRB , UCSRB_RXEN) ;
		   break ;
	}

	switch(PtrToStruct -> Char_Size)
	{
	   case Five_Bit :
		   Local_u8UCSRC_Value = (1<<UCSRC_URSEL)|((PtrToStruct->Node_Sync_Async)<<UCSRC_UMSEL)|
		                         ((PtrToStruct->Parity)<<UCSRC_UPM0)|((PtrToStruct->Stop_Bit)<<UCSRC_USBS)|
								 (0<<UCSRC_UCSZ0)|(0<<UCSRC_UCSZ1) ;
		   UART_UCSRC = Local_u8UCSRC_Value ;
		   break;

	   case Six_Bit :
	       Local_u8UCSRC_Value = (1<<UCSRC_URSEL)|((PtrToStruct->Node_Sync_Async)<<UCSRC_UMSEL)|
                                 ((PtrToStruct->Parity)<<UCSRC_UPM0)|((PtrToStruct->Stop_Bit)<<UCSRC_USBS)|
				                 (0<<UCSRC_UCSZ0)|(1<<UCSRC_UCSZ1) ;
		   UART_UCSRC = Local_u8UCSRC_Value  ;
		   CLR_BIT(UART_UCSRB , UCSRB_UCSZ2) ;
	       break ;

	   case Seven_Bit :
	       Local_u8UCSRC_Value = (1<<UCSRC_URSEL)|((PtrToStruct->Node_Sync_Async)<<UCSRC_UMSEL)|
                                 ((PtrToStruct->Parity)<<UCSRC_UPM0)|((PtrToStruct->Stop_Bit)<<UCSRC_USBS)|
				                 (1<<UCSRC_UCSZ0)|(0<<UCSRC_UCSZ1) ;
		   UART_UCSRC = Local_u8UCSRC_Value  ;
		   CLR_BIT(UART_UCSRB , UCSRB_UCSZ2) ;
	       break ;

	   case Eight_Bit :
	       Local_u8UCSRC_Value = (1<<UCSRC_URSEL)|((PtrToStruct->Node_Sync_Async)<<UCSRC_UMSEL)|
                                 ((PtrToStruct->Parity)<<UCSRC_UPM0)|((PtrToStruct->Stop_Bit)<<UCSRC_USBS)|
				                 (1<<UCSRC_UCSZ0)|(1<<UCSRC_UCSZ1) ;
		   UART_UCSRC = Local_u8UCSRC_Value  ;
		   CLR_BIT(UART_UCSRB , UCSRB_UCSZ2) ;
	       break ;

	   case Nine_Bit :
	       Local_u8UCSRC_Value = (1<<UCSRC_URSEL)|((PtrToStruct->Node_Sync_Async)<<UCSRC_UMSEL)|
                                 ((PtrToStruct->Parity)<<UCSRC_UPM0)|((PtrToStruct->Stop_Bit)<<UCSRC_USBS)|
				                 (1<<UCSRC_UCSZ0)|(1<<UCSRC_UCSZ1) ;
		   UART_UCSRC = Local_u8UCSRC_Value  ;
		   SET_BIT(UART_UCSRB , UCSRB_UCSZ2) ;
	       break ;
	}

    /*Baude rate = 9600*/
    UART_UBRRL = 51 ;
}


void UART_voidTransmitDataSync(u8 Copy_u8Data)
{
	/*make sure that UDR buffer is empty(empty = 1)*/
	while(GET_BIT(UART_UCSRA , UCSRA_UDRE) == 0);

	/*assign the value to get transmit*/
	UART_UDR = Copy_u8Data ;

	/*polling till the end of transmission*/
	while(GET_BIT(UART_UCSRA , UCSRA_TXC) == 0);

	/*clear end of transmission flag by writing 1 */
	SET_BIT(UART_UCSRA , UCSRA_TXC);
}


u8 UART_voidRecieveDataSync(void)
{
	/*make sure that the data is completely received*/
	while(GET_BIT(UART_UCSRA , UCSRA_RXC) == 0);

	/*get the received data*/
	return UART_UDR ;
}


void UART_voidReceivedAsync(u8 Copy_pu8ReceivedData , void(*Copy_ptrToFunc)(void))
{
	/*enable receive complete interrupt*/
	SET_BIT(UART_UCSRB , UCSRB_RXCIE);

	if(Copy_ptrToFunc != NULL)
	{
		GlobalPtrToFunc = Copy_ptrToFunc ;
	}
	/*passing the address of the location to store the received data to be global*/
	/*received data is done by ISR*/
	Global_u8ReceivedData = Copy_pu8ReceivedData;
}



void UART_voidTransmitStringSync(char * Copy_PtrToCharString)
{
	/*local variable to loop over the string*/
	u8 Local_u8Counter = 0 ;

	/*loop over the transmitted string characters*/
	while(Copy_PtrToCharString[Local_u8Counter] != '/0')
	{
		/*send the string char by char*/
		UART_voidTransmitDataSync(Copy_PtrToCharString[Local_u8Counter]);
		Local_u8Counter ++ ;
	}
}


void UART_voidReceiveBufferSync(char * Copy_ptrToReceiveBuffer , u8 Copy_u8BufferSize)
{
	/*local variable to loop over buffer*/
	u8 Local_u8Counter = 0 ;

	/*loop over buffer to assign the data from buffer and pass it to the receive data*/
	for(Local_u8Counter = 0 ; Local_u8Counter <= Copy_u8BufferSize ; Local_u8Counter++)
	{
		Copy_ptrToReceiveBuffer[Local_u8Counter] = UART_voidRecieveDataSync();
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	/*getting the received data*/
	*Global_u8ReceivedData = UART_UDR ;

	/*call the application ISR*/
//	Global_u8ReceivedData();
	EndOfReceive();
}
