/*
 * PWM.h
 *
 *  Created on: Apr 20, 2022
 *      Author: Eng. Aya Adel
 */

#ifndef PWM_H_
#define PWM_H_


/* Timer 1 */

 #define OCR1A   *((volatile u16*)0x4A)

#define TCNT1    *((volatile u16*)0x4C)

#define TCCR1B   *((volatile u16*)0x4E)

#define TCCR1A   *((volatile u16*)0x4F)

#define ICR1     *((volatile u16*)0x46)

/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

typedef enum
{
	PWM_enuOk,
	PWM_enuDutyCycleError

}PWM_tenuErrorState;

typedef enum
{
	PWM_PRES_DIV_1 = 1,
	PWM_PRES_DIV_8,
	PWM_PRES_DIV_64,
	PWM_PRES_DIV_256,
	PWM_PRES_DIV_1024,
	PWM_PRES_EXT_Falling,
	PWM_PRES_EXT_Rising
}PWM_PrescalerType;

void PWM_vidInit(void);
PWM_tenuErrorState PWM_enuSetDutyCycle(u8 DutyCycle);
void PWM_vidStart(PWM_PrescalerType Prescaler,u16 LoadVal);
void PWM_enuSetOCR(u16 OCR);

#endif /* PWM_H_ */
