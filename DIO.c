/*
 * DIO.c
 *
 *  Created on: Nov 5, 2021
 *      Author: WIN 10
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Config.h"
#include "DIO.h"


void DIO_SetPinDirection ( u8 u8cpy_Port , u8 u8cpy_PinNo , u8 u8cpy_Mood ) {

	switch ( u8cpy_Port ) {

		case DIO_PortA :

			if ( u8cpy_Mood == Output)
			{
			SET_BIT( DDRA_Reg , u8cpy_PinNo ) ;
			}
			else if ( u8cpy_Mood == Input )
			{
			CLR_BIT( DDRA_Reg , u8cpy_PinNo ) ;
			}
           break ;

		case DIO_PortB :

			if ( u8cpy_Mood == Output )
				{
				SET_BIT(DDRB_Reg , u8cpy_PinNo ) ;
				}
				else if ( u8cpy_Mood == Input )
				{
				CLR_BIT(DDRB_Reg , u8cpy_PinNo ) ;
				}
			break ;

		case DIO_PortC :

			if ( u8cpy_Mood == Output )
				{
				SET_BIT(DDRC_Reg , u8cpy_PinNo ) ;
				}
				else if (u8cpy_Mood == Input )
				{
				CLR_BIT(DDRC_Reg , u8cpy_PinNo ) ;
				}
			break ;

		case DIO_PortD :

			if ( u8cpy_Mood == Output )
				{
				SET_BIT(DDRD_Reg , u8cpy_PinNo ) ;
				}
				else if (u8cpy_Mood == Input )
				{
				CLR_BIT(DDRD_Reg , u8cpy_PinNo ) ;
				}
				break ;
	}
}

void DIO_SetPinValue (u8 u8cpy_Port , u8 u8cpy_PinNo , u8 u8cpy_Value ) {

	switch (u8cpy_Port) {

	case DIO_PortA :

				if ((u8cpy_Value == High)||(u8cpy_Value == PullUp ))
				{
				SET_BIT( PORTA_Reg  , u8cpy_PinNo ) ;
				}
				else if ((u8cpy_Value == Low)||(u8cpy_Value == Floating ))
				{
				CLR_BIT(PORTA_Reg  , u8cpy_PinNo) ;
				}
	           break ;

	case DIO_PortB :

				if ((u8cpy_Value == High)||(u8cpy_Value == PullUp ))
				{
				SET_BIT( PORTB_Reg  , u8cpy_PinNo ) ;
				}
				else if ((u8cpy_Value == Low)||(u8cpy_Value == Floating ))
				{
				CLR_BIT(PORTB_Reg  , u8cpy_PinNo) ;
				}
		         break ;

	case DIO_PortC :
				if ((u8cpy_Value == High)||(u8cpy_Value == PullUp ))
				{
					SET_BIT( PORTC_Reg  , u8cpy_PinNo ) ;
				}
				else if ((u8cpy_Value == Low)||(u8cpy_Value == Floating ))
				{
					CLR_BIT( PORTC_Reg , u8cpy_PinNo) ;
				}
		         break ;

	case DIO_PortD :
				if ((u8cpy_Value == High)||(u8cpy_Value == PullUp ))
				{
					SET_BIT ( PORTD_Reg , u8cpy_PinNo ) ;
				}
				else if ((u8cpy_Value == Low)||(u8cpy_Value == Floating ))
				{
					CLR_BIT( PORTD_Reg, u8cpy_PinNo) ;
				}
		          break ;
	}
}


u8 DIO_GetPinValue (u8 u8cpy_Port , u8 u8cpy_PinNo ) {

u8 Loc_PinValue = 0 ;

	switch (u8cpy_Port) {

		case DIO_PortA :

	       Loc_PinValue =  GET_BIT(PINA_Reg, u8cpy_PinNo ) ;

           break ;

		case DIO_PortB :

			Loc_PinValue =  GET_BIT(PINB_Reg, u8cpy_PinNo ) ;

			break ;

		case DIO_PortC :

			Loc_PinValue =  GET_BIT(PINC_Reg, u8cpy_PinNo ) ;

			break ;

		case DIO_PortD :

			Loc_PinValue = 	 GET_BIT(PIND_Reg, u8cpy_PinNo ) ;

			 break ;
	}
	 return Loc_PinValue ;
}

void DIO_Int (void) {

	//Port A

	DIO_SetPinDirection ( DIO_PortA , PIN0 , PinDirectionPortAPin0 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN1 , PinDirectionPortAPin1 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN2 , PinDirectionPortAPin2 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN3 , PinDirectionPortAPin3 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN4 , PinDirectionPortAPin4 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN5 , PinDirectionPortAPin5 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN6 , PinDirectionPortAPin6 ) ;
	DIO_SetPinDirection ( DIO_PortA , PIN7 , PinDirectionPortAPin7 ) ;


	//Port B

	DIO_SetPinDirection ( DIO_PortB , PIN0 , PinDirectionPortBPin0 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN1 , PinDirectionPortBPin1 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN2 , PinDirectionPortBPin2 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN3 , PinDirectionPortBPin3 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN4 , PinDirectionPortBPin4 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN5 , PinDirectionPortBPin5 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN6 , PinDirectionPortBPin6 ) ;
	DIO_SetPinDirection ( DIO_PortB , PIN7 , PinDirectionPortBPin7 ) ;

	//Port C

	DIO_SetPinDirection ( DIO_PortC , PIN0 , PinDirectionPortCPin0 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN1 , PinDirectionPortCPin1 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN2 , PinDirectionPortCPin2 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN3 , PinDirectionPortCPin3 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN4 , PinDirectionPortCPin4 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN5 , PinDirectionPortCPin5 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN6 , PinDirectionPortCPin6 ) ;
	DIO_SetPinDirection ( DIO_PortC , PIN7 , PinDirectionPortCPin7 ) ;


	//Port D

	DIO_SetPinDirection ( DIO_PortD , PIN0 , PinDirectionPortDPin0 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN1 , PinDirectionPortDPin1 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN2 , PinDirectionPortDPin2 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN3 , PinDirectionPortDPin3 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN4 , PinDirectionPortDPin4 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN5 , PinDirectionPortDPin5 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN6 , PinDirectionPortDPin6 ) ;
	DIO_SetPinDirection ( DIO_PortD , PIN7 , PinDirectionPortDPin7 ) ;



}

void DIO_TogglePinValue (u8 u8cpy_Port , u8 u8cpy_PinNo ) {

	switch (u8cpy_Port) {

		case DIO_PortA :
			TOG_BIT( PORTA_Reg  , u8cpy_PinNo ) ;
			break ;

		case DIO_PortB :
			TOG_BIT( PORTB_Reg  , u8cpy_PinNo ) ;
			break ;

		case DIO_PortC :
			TOG_BIT( PORTC_Reg  , u8cpy_PinNo ) ;
			break ;

		case DIO_PortD :
			TOG_BIT( PORTD_Reg  , u8cpy_PinNo ) ;
			break ;
	}
}
