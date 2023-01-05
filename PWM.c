/*
 * PWM.c
 *
 *  Created on: Apr 20, 2022
 *      Author: Eng. Aya Adel
 *
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Config.h"
#include "DIO.h"
#include "PWM.h"
#include "PWM_prv.h"
#include "PWM_cfg.h"

void PWM_vidInit(void)
{
#if PWM_CHANNEL == PWM_CHANNEL_1
	TCNT1 = 0;
	OCR1A = 0;
	ICR1 = PWM_TOP_VAL;
	TCCR1A |= (1<<COM1A1) | (1<<WGM11);
	TCCR1B |= (1<<WGM13) | (1<<WGM12);
#else
#error("Invalid Channel")
#endif

}

PWM_tenuErrorState PWM_enuSetDutyCycle(u8 DutyCycle)
{
	PWM_tenuErrorState Loc_enuReturnErrorState = PWM_enuOk;
	u16 Loc_u16OCRvalue;
	if(DutyCycle > 100)
	{
		Loc_enuReturnErrorState = PWM_enuDutyCycleError;
	}
	else
	{
		switch(PWM_CHANNEL)
		{
	/*	case PWM_CHANNEL_0:
			Loc_u16OCRvalue = ((f32)DutyCycle/100) * 256;
			OCR0 = Loc_u16OCRvalue;
			break; */
		case PWM_CHANNEL_1:
			Loc_u16OCRvalue = (u16)(((f32)DutyCycle/100) * ICR1);
			OCR1A = Loc_u16OCRvalue;
			break;
	/*	case PWM_CHANNEL_2:
			Loc_u16OCRvalue = ((f32)DutyCycle/100) * 256;
			OCR2 = Loc_u16OCRvalue;
			break; */
		}
	}

	return Loc_enuReturnErrorState;
}

void PWM_enuSetOCR(u16 OCR)
{
	switch(PWM_CHANNEL)
	{
	/*case PWM_CHANNEL_0:
		OCR0 = (u8)OCR;
		break; */
	case PWM_CHANNEL_1:
		OCR1A = OCR;
		PORTA_Reg = OCR1A;
		PORTC_Reg = OCR1A >> 8;
		break;
	/*case PWM_CHANNEL_2:
		OCR2 = (u8)OCR;
		break; */
	}
}

void PWM_vidStart(PWM_PrescalerType Prescaler,u16 LoadVal)
{
	u16 TempReg;
	switch(PWM_CHANNEL)
	{
	/*	case PWM_CHANNEL_0:
			TCNT0 = (u8)LoadVal;
			TempReg = TCCR0;
			TempReg &=~ TCCR_PRES_MSK;
			TempReg |= Prescaler;
			TCCR0 = TempReg;
			break; */
		case PWM_CHANNEL_1:
			TCNT1 = (u16)LoadVal;
			TempReg = TCCR1B;
			TempReg &=~ (u16)TCCR_PRES_MSK;
			TempReg |= Prescaler;
			TCCR1B = TempReg;
			break;
	/*	case PWM_CHANNEL_2:
			TCNT2 = (u8)LoadVal;
			TempReg = TCCR2;
			TempReg &=~ TCCR_PRES_MSK;
			TempReg |= Prescaler;
			TCCR2 = TempReg;
			break; */
	}
}

