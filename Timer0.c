/*
 * Timer0.c
 *
 * Created: 10/7/2022 3:25:37 PM
 *  Author: Win 10 5G
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Timer0.h"
#include "DIO.h"
#include "DIO_Config.h"


void TimerNormalModeStart (void) {
	
	/*
		Description: this function initialize the timer
		inputs: none
		outputs: none
		return: none
	*/ 
	
	 TCCR0_REG = 0x00 ;  //set to normal mode
	 TCNT0_REG = 0x00 ; //initial value is zero
	
}


void Timer0Genaral (u16 ChoosenPrescaler, u32 OverFlowsNumber)

/*
		Description: this function is general for any timer 
		inputs: the prescaler and the number of flows 
		outputs: none
		return: none
	*/
{
	u32 OverFlowsCounter = 0;
	switch (ChoosenPrescaler)
	{
		case 1: //no prescaler selected
		SET_BIT (TCCR0_REG, 0) ;
		break;
		case 8:
		SET_BIT (TCCR0_REG, 1) ;
		break;
		case 64:
		SET_BIT (TCCR0_REG, 0) ;
		SET_BIT (TCCR0_REG, 1) ;
		break;
		case 256:
		SET_BIT (TCCR0_REG, 2) ;
		break;
		case 1024:
		SET_BIT (TCCR0_REG, 0) ;
		SET_BIT (TCCR0_REG, 2) ;
		break;
	}
	
	while ( OverFlowsCounter < OverFlowsNumber )
	{
	while ( ( TIFR_REG & (1 << 0) )  == 0) ; // checking interrupt flag to see if it reached the overflow
	SET_BIT (TIFR_REG , 0 )  ; //clearing the register after the first overflow
		OverFlowsCounter++;
	}
	OverFlowsCounter = 0 ;
}


void DelayingFor5Sec(void)
{
	/*
		Description: this function is used to delay 5 sec
		input : none
		outputs: none
		return: none
	*/
	Timer0Genaral(256, 77);
}

void Timer0_stop(void)
{
	// Timer stop
	TCCR0_REG = 0x00;
}


void DelayingFor5msec(void)
{
	/*
		Description: this function is used to delay 5 sec
		input : none
		outputs: none
		return: none
	*/
	Timer0Genaral(1024, 2); // alomost 2
	TCNT0_REG = 6 ; //timer inatial value
	Timer0_stop ();

}
