/*
 * App_config.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Win 10 5G
 */

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_


#define TurnLedOn '1'

#define TurnLedPinOn DIO_SetPinValue( DIO_PortB , PIN3 , High )

#define TurnLedOff '2'

#define TurnLedPinOff  DIO_SetPinValue( DIO_PortB , PIN3 , Low )

#define OpenDoor '3'

#define CloseDoor '4'

#define Exit '5'

#endif /* APP_CONFIG_H_ */
