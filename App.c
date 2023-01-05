/*
 * App.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Win 10 5G
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "DIO_Config.h"
#include "UART.h"
#include "App.h"
#include "App_config.h"
#include "PWM.h"
#include "PWM_cfg.h"
#include "PWM_prv.h"
#include "ServoMotor.h"
#include "Timer0.h"

ST_accountsDB_t accountsDB[10] = {
		{"Alaa" , "12345"} ,  {"Ahmed","456"} ,
		{"A","1123"} , {"B", "12445"} ,
		{"C", "123"} ,  {"D","345"} ,
		{"E", "123"} , {"F",  "12123"} ,
		{"J", "123"} ,  {"H", "12324"} ,
};

void App_Int(void) {
	DIO_Int();
	UART_Int();
	ServoMotor_Init () ;
	ServoMotor_Start() ;
	 TimerNormalModeStart () ;
	ST_accountsDB_t *gpDataBase = accountsDB;
	u8 TrailerFlag =0;
	u8 SearchFlag =0;
	u8 UserFlag =0;
	u8 PassFlag =0;
	u8 i=0;
	u8 UserName[10];
	u8 Password[10];
	 DelayingFor5msec() ;
	UART_SendString ((u8 *)"Welcome Back! ");
	while(1)
	{
		UART_SendString ((u8 *)"Enter Your Username.");
		UART_ReceiveString(UserName);
		UART_SendString ((u8 *)"Enter Your Password.");
		UART_ReceiveString (Password);
		for(i=0; i<10; i++)
		{
			SearchFlag = StringCompare(gpDataBase[i].UserNameSaved, UserName, StringLength(gpDataBase[i].UserNameSaved));
			if(0 == SearchFlag)  // Valid
			{
				UserFlag =1;
				break;
			}else{	}
		}
		for(i=0; i<10; i++)
		{
			SearchFlag = StringCompare(gpDataBase[i].PasswordSaved, Password, StringLength(gpDataBase[i].PasswordSaved));
			if(0 == SearchFlag)  // Valid
			{
				PassFlag =1;
				break;
			}else{	}
		}
		if(1 == UserFlag &&  1 == PassFlag)
		{
			UART_SendString ((u8 *)"Thank You! ");
			TrailerFlag =0;
			SmartHome() ;
			break;
		}else{	// Not found and name not valid
			UserFlag =0;
			PassFlag =0;
			TrailerFlag++;
			UART_SendString ((u8 *)"Not Valid! ");
		}
		if(3 == TrailerFlag)
		{
			// Call Police
			UART_SendString ((u8 *)"Calling Police!");

			break;
		}else{}
	}
}

u8 StringCompare(u8 *StrDefault, u8 *Str, u8 SizeofDefault)
{
	u8 j=0;
	u8 RetFlag =0;
	for(j=0; j<SizeofDefault; j++)
	{
		if(StrDefault[j] != Str[j])
		{
			RetFlag =1;
			break;
		}else{	}
	}
	return RetFlag;
}

u8 StringLength(u8 *StrDefault)
{
	u8 i=0;
	u8 StrLen =0;
	while(1)
	{
		StrLen++;
		if('\0'== StrDefault[i])
		{
			break;
		}else{	}
		i++;
	}
	return StrLen;
}

void SmartHome (void) {
	u8 Data ;
		UART_SendString ((u8 *)"Please, Choose Operation."); ;
		while (1)
		{
		   Data = UART_GetChar();
			if (Data == TurnLedOn)
			{
				DIO_SetPinValue (DIO_PortB, PIN0 , High);
				TurnLedPinOn;
				UART_SendString((u8 *)"Light Is On, Would you like anything else?");
				DelayingFor5msec() ;
			}
			else if (Data == TurnLedOff)
			{
				TurnLedPinOff;
				UART_SendString((u8 *)"Light Is Off, Would you like anything else?");
				DelayingFor5msec() ;
		   }
			else if (Data == OpenDoor )
			{
				UART_SendString ((u8 *)"Door Is Opened, Would you like anything else?");
			ServoMotor_SetAngleDeg (90) ;
			DelayingFor5msec() ;
			}
			else if  (Data == CloseDoor)
			{
				UART_SendString ((u8 *)"Door Is Closed,Would you like anything else?");
			ServoMotor_SetAngleDeg (0) ;
			DelayingFor5msec() ;
			}
			else if (Data == Exit)
			{
				UART_SendString ((u8 *)"Thank you for using!");
                 break;
			}
	}

}
