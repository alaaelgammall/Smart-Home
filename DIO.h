/*
 * DIO.h
 *
 *  Created on: Nov 5, 2021
 *      Author: WIN 10
 */

#ifndef DIO_H_
#define DIO_H_

void DIO_SetPinDirection (u8 u8cpy_Port , u8 u8cpy_PinNo , u8 u8cpy_Mood ) ;
void DIO_SetPinValue (u8 u8cpy_Port , u8 u8cpy_PinNo , u8 u8cpy_Value ) ;
u8 DIO_GetPinValue (u8 u8cpy_Port , u8 u8cpy_PinNo ) ;
u8 DIO_GetPortValue (u8 u8cpy_Port) ;
void DIO_Int (void) ;
void DIO_TogglePinValue (u8 u8cpy_Port , u8 u8cpy_PinNo );

#define DIO_PortA 1
#define DIO_PortB 2
#define DIO_PortC 3
#define DIO_PortD 4
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define High 1
#define Low 0
#define Input 0
#define Output 1
#define PullUp 1
#define Floating 0


/* Group A Registers */
#define PORTA_Reg  *((volatile u8*)0x3B)
#define DDRA_Reg   *((volatile u8*)0x3A)
#define PINA_Reg  *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Reg  *((volatile u8*)0x38)
#define DDRB_Reg   *((volatile u8*)0x37)
#define PINB_Reg   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Reg *((volatile u8*)0x35)
#define DDRC_Reg   *((volatile u8*)0x34)
#define PINC_Reg   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Reg  *((volatile u8*)0x32)
#define DDRD_Reg   *((volatile u8*)0x31)
#define PIND_Reg  *((volatile u8*)0x30)



#endif /* DIO_H_ */
