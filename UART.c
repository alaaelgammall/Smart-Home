/*
 * UART.c
 *
 *  Created on: Dec 3, 2021
 *      Author: WIN 10
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"
#include "DIO_Config.h"
#include "DIO.h"

void UART_Int(void)
{
  // Set BaudRate -> 9600/8MhZ
  UBRRL = 0x33;
 // UBRRH = 51;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0x86;
  // Enable RX and TX
  UCSRB = 0x18;

}

void UART_SendChar(u8 data)
{
	while ( GET_BIT (UCSRA , 5) == 0 ) ;
	UDR = data ;
}

u8 UART_GetChar(void)
{
	while   (GET_BIT (UCSRA ,7) == 0) ;
 	return UDR;
  /* Clear Flag */
  //SET_BIT(UCSRA,7);
}

void UART_SendString(u8 *str)
{
	while( *str != '\0')
	{
		UART_SendChar (*str) ;
		str++ ;
	}
	 str = '\0';
}

void UART_ReceiveString(u8 *str)
{
	u8 counter = 0;
	str[counter] = UART_GetChar();
	while(str[counter] != '\0')
	{
		counter++;
		str[counter] = UART_GetChar();
	}
	str[counter] = '\0';
}
