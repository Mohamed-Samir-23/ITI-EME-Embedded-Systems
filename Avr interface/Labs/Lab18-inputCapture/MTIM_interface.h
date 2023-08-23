/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 17, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


#ifndef	_MTIM_INTERFACE_H_
#define _MTIM_INTERFACE_H_

#define MTIM_TIMER0			0	
#define MTIM_TIMER1			1	
#define MTIM_TIMER2			2	

/*TCCR0 - REG*/

/* CS02 - CS01 - CS00 -> PRESCALER */
#define MTIM_CS_NO_CLOCK					0
#define MTIM_CS_PRESCALAR_1					1
#define MTIM_CS_PRESCALAR_8					2
#define MTIM_CS_PRESCALAR_64				3
#define MTIM_CS_PRESCALAR_256				4
#define MTIM_CS_PRESCALAR_1024				5
#define MTIM_CS_T0_FALLING					6
#define MTIM_CS_T0_RISING					7


/* Waveform Generation Mode Bit Description */
/* WGM01 - WGM00 */

#define MTIM_MODE_NORMAL					0
#define MTIM_MODE_PHASECORRECTPWM			1
#define MTIM_MODE_CTC						2
#define MTIM_MODE_FASTPWM					3

/* COM01 - COM00 -> MODE */

/*Compare Output Mode, non-PWM Mode*/
#define MTIM_HWPIN_DISCONNECTED				0
#define MTIM_HWPIN_TOGGLE					1
#define MTIM_HWPIN_CLEAR					2
#define MTIM_HWPIN_SET						3

/*Compare Output Mode, Fast PWM Mode*/
#define MTIM_HWPIN_NOVINVERTING_PWM			2
#define MTIM_HWPIN_INVERTING_PWM			3
 
/*ISR TYPE*/
#define MTIM_INTERRUPT_T0_OVF				0
#define MTIM_INTERRUPT_T0_OCM				1

#ifndef F_CPU
#define F_CPU 8000000UL
#warning F_CPU is not define. Assuming 8MHz clock.
#endif





STD_error_t MTIM_stderrorIint(u8 ARG_u8TimerNo, u8 ARG_u8ClockSource, u8 ARG_u8Mode, u8 ARG_u8HWPinMode);
void MTIM_voidForceOutputCompare(void);
STD_error_t MTIM_stderrorEnableInterrupt(u8 ARG_u8InterruptSource);
STD_error_t MTIM_stderrorDisableInterrupt(u8 ARG_u8InterruptSource);
STD_error_t MTIM_stderrorSetCallBack(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void));
STD_error_t MTIM_stderrorStartTimer(u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrorStopTimer(u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrorSetOCR(u8 ARG_u8TimerNo, u16 ARG_u16OCRValue);
STD_error_t MTIM_stderrorTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay);


STD_error_t MTIM_stderrorGetTimerValue(u16 *ARG_u16pTimerValue, u8 ARG_u8TimerNo);
STD_error_t MTIM_stderrorSetTimerValue(u8 ARG_u8TimerNo, u16 ARG_u16TimerValue);


#endif 
