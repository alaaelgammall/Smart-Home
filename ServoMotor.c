/*
 * ServoMotor.c
 *
 *  Created on: Apr 21, 2022
 *      Author: Eng. Aya Adel
 */
#include "Std_types.h"
#include "ServoMotor.h"
#include "STD_TYPES.h"
#include "PWM.h"
#include "PWM_cfg.h"
#include "PWM_prv.h"

void ServoMotor_Init(void)
{
	PWM_vidInit();
}

void ServoMotor_Start(void)
{
	PWM_vidStart(PWM_PRES_DIV_8,0); // ticktime is 1 micro sec
}

void ServoMotor_SetAngleDeg(u8 Angle_Degree)
{
	u16 OCRValue;
	OCRValue = 1000 + (f32)(11.11*Angle_Degree) ;
	PWM_enuSetOCR(OCRValue);
}

