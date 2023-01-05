/*
 * UART.h
 *
 *  Created on: Dec 3, 2021
 *      Author: WIN 10
 */

#ifndef UART_H_
#define UART_H_

void UART_Int(void) ;

void UART_SendChar(u8 data);

u8 UART_GetChar(void);

void UART_ReceiveString(u8 *str);

void UART_SendString (u8 *str);

#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)
#define UCSRC *((volatile u8*)0x40)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRA *((volatile u8*)0x2B)
#define UDR *((volatile u8*)0x2C)

#endif /* UART_H_ */
