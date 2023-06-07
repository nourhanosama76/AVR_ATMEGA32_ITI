#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "LED_interface.h"


/**************************************************************************************/
/*******************************functions' declaration*********************************/
void Flash_LED(void);

void shift_UP_DOWN(void);

void shift_DOWN_UP(void);

void Converge_LED(void);

void Diverge_LED(void);

void Ping_pong_LED(void);

void Increment_LED(void);

void Converge_Diverge_LED(void);

void DIP_Init(void);

//void DIP_Get_value(u8 SW1 , u8 SW2 , u8 SW3);
/*************************************main function************************************/
void main(void)
{

	u8 SW1 , SW2 ,  SW3, St;

    LED_Init(DIO_PORTA);
	DIP_Init();

    while(1){

    	SW1 = DIO_u8GetPinValue(DIO_PORTC , DIO_PIN0 );
    	SW2 = DIO_u8GetPinValue(DIO_PORTC , DIO_PIN1 );
    	SW3 = DIO_u8GetPinValue(DIO_PORTC , DIO_PIN2 );
    	St = ((SW1|(SW2<<1))|(SW3<<2));

    	switch(St)
    	{
    	case 0:
    		Flash_LED();
    		break;

    	case 1:
    		shift_UP_DOWN();
    		break;

    	case 2:
		shift_DOWN_UP();
		break;

    	case 3 :
    		Converge_LED();
    		break;

   		case 4 :
   			Diverge_LED();
    		break;

    	case 5 :
 			Ping_pong_LED();
    		break;

    	case 6 :
    		Increment_LED();
    		break;

    	case 7 :
    		Converge_Diverge_LED();
    		break;

    	}
		/*if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 0)
		{
			Flash_LED();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 0)
		{
			shift_UP_DOWN();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 0)
		{
			shift_DOWN_UP();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 0)
		{
			Converge_LED();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 1)
		{
			Diverge_LED();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 1)
		{
			Ping_pong_LED();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 0 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 1)
		{
			Increment_LED();
		}

		 if(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1) == 1 && DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2) == 1)
		{
			Converge_Diverge_LED();
		}*/

    }

}


void Flash_LED(void)
{
	        LED_ON(DIO_PORTA,DIO_PIN0);
			LED_ON(DIO_PORTA,DIO_PIN1);
			LED_ON(DIO_PORTA,DIO_PIN2);
			LED_ON(DIO_PORTA,DIO_PIN3);
			LED_ON(DIO_PORTA,DIO_PIN4);
			LED_ON(DIO_PORTA,DIO_PIN5);
			LED_ON(DIO_PORTA,DIO_PIN6);
			LED_ON(DIO_PORTA,DIO_PIN7);
			_delay_ms(500);

			LED_OFF(DIO_PORTA,DIO_PIN0);
			LED_OFF(DIO_PORTA,DIO_PIN1);
			LED_OFF(DIO_PORTA,DIO_PIN2);
			LED_OFF(DIO_PORTA,DIO_PIN3);
			LED_OFF(DIO_PORTA,DIO_PIN4);
			LED_OFF(DIO_PORTA,DIO_PIN5);
			LED_OFF(DIO_PORTA,DIO_PIN6);
			LED_OFF(DIO_PORTA,DIO_PIN7);
			_delay_ms(500);
}

/*****************************************************************************/
void shift_UP_DOWN(void)
{
	LED_ON(DIO_PORTA,DIO_PIN0);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN0);

	LED_ON(DIO_PORTA,DIO_PIN1);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN1);

	LED_ON(DIO_PORTA,DIO_PIN2);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN2);

	LED_ON(DIO_PORTA,DIO_PIN3);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN3);

	LED_ON(DIO_PORTA,DIO_PIN4);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN4);

	LED_ON(DIO_PORTA,DIO_PIN5);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN5);

	LED_ON(DIO_PORTA,DIO_PIN6);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN6);

	LED_ON(DIO_PORTA,DIO_PIN7);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN7);
}


/*****************************************************************************/
void shift_DOWN_UP(void)
{
	LED_ON(DIO_PORTA,DIO_PIN7);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN7);

	LED_ON(DIO_PORTA,DIO_PIN6);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN6);

	LED_ON(DIO_PORTA,DIO_PIN5);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN5);

	LED_ON(DIO_PORTA,DIO_PIN4);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN4);

	LED_ON(DIO_PORTA,DIO_PIN3);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN3);

	LED_ON(DIO_PORTA,DIO_PIN2);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN2);

	LED_ON(DIO_PORTA,DIO_PIN1);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN1);

	LED_ON(DIO_PORTA,DIO_PIN0);
	_delay_ms(250);
	LED_OFF(DIO_PORTA,DIO_PIN0);

}


/*****************************************************************************/
void Converge_LED(void)
{
	LED_ON(DIO_PORTA,DIO_PIN0);
	LED_ON(DIO_PORTA,DIO_PIN7);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN0);
	LED_OFF(DIO_PORTA,DIO_PIN7);

	LED_ON(DIO_PORTA,DIO_PIN1);
	LED_ON(DIO_PORTA,DIO_PIN6);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN1);
	LED_OFF(DIO_PORTA,DIO_PIN6);

	LED_ON(DIO_PORTA,DIO_PIN2);
	LED_ON(DIO_PORTA,DIO_PIN5);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN2);
	LED_OFF(DIO_PORTA,DIO_PIN5);

	LED_ON(DIO_PORTA,DIO_PIN3);
	LED_ON(DIO_PORTA,DIO_PIN4);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN3);
	LED_OFF(DIO_PORTA,DIO_PIN4);
}


/*****************************************************************************/
void Diverge_LED(void)
{
	LED_ON(DIO_PORTA,DIO_PIN3);
	LED_ON(DIO_PORTA,DIO_PIN4);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN3);
	LED_OFF(DIO_PORTA,DIO_PIN4);

	LED_ON(DIO_PORTA,DIO_PIN2);
	LED_ON(DIO_PORTA,DIO_PIN5);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN2);
	LED_OFF(DIO_PORTA,DIO_PIN5);

	LED_ON(DIO_PORTA,DIO_PIN1);
	LED_ON(DIO_PORTA,DIO_PIN6);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN1);
	LED_OFF(DIO_PORTA,DIO_PIN6);

	LED_ON(DIO_PORTA,DIO_PIN0);
	LED_ON(DIO_PORTA,DIO_PIN7);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN0);
	LED_OFF(DIO_PORTA,DIO_PIN7);

}


/*****************************************************************************/
void Ping_pong_LED(void)
{
	shift_UP_DOWN();
	shift_DOWN_UP();
}


/*****************************************************************************/
void Increment_LED(void)
{
	LED_ON(DIO_PORTA,DIO_PIN0);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN1);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN2);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN3);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN4);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN5);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN6);
	_delay_ms(300);

	LED_ON(DIO_PORTA,DIO_PIN7);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN7);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN6);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN5);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN4);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN3);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN2);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN1);
	_delay_ms(300);

	LED_OFF(DIO_PORTA,DIO_PIN0);
	_delay_ms(300);
}


/*****************************************************************************/
void Converge_Diverge_LED(void)
{
	Converge_LED();
	Diverge_LED();
}


/*****************************************************************************/
void DIP_Init()
{
	DIO_voidSetPinDirection(DIO_PORTC , DIO_PIN0 , DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection(DIO_PORTC , DIO_PIN1 , DIO_PIN_INPUT_PULLUP);
	DIO_voidSetPinDirection(DIO_PORTC , DIO_PIN2 , DIO_PIN_INPUT_PULLUP);
}


/*****************************************************************************/
/*void DIP_Get_value(u8 SW1 , u8 SW2 , u8 SW3)
{

}*/
