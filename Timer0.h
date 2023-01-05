/*
 * Timer0.h
 *
 * Created: 10/7/2022 3:25:22 PM
 *  Author: Win 10 5G
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

// timers REG

#define TCCR0_REG     *((volatile u8*)0x53)
#define TCNT0_REG     *((volatile u8*)0x52)
#define OCR0_REG      *((volatile u8*)0x5C)
#define TIMSK_REG     *((volatile u8*)0x59) // used to enable the interrupt
#define TIFR_REG      *((volatile u8*)0x58)
#define SREG_REG      *((volatile u8*)0x5f)

// Functions Prototypes 

void TimerNormalModeStart (void) ;
void Timer0_stop(void) ;
void Timer0Genaral (u16 ChoosenPrescaler, u32 OverFlowsNumber) ;
void DelayingFor5Sec(void) ;
void DelayingFor5msec(void) ;

#endif /* TIMER0_H_ */
