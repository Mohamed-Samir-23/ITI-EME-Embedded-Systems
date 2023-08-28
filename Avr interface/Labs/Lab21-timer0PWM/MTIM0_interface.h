/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 26, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


#ifndef	_MTIM0_INTERFACE_H_
#define _MTIM0_INTERFACE_H_

/*TCCR0 - REG*/




/* CS02 - CS01 - CS00 -> PRESCALER */
#define MTIM0_CS_NO_CLOCK					0
#define MTIM0_CS_PRESCALAR_1				1
#define MTIM0_CS_PRESCALAR_8				2
#define MTIM0_CS_PRESCALAR_64				3
#define MTIM0_CS_PRESCALAR_256				4
#define MTIM0_CS_PRESCALAR_1024				5
#define MTIM0_CS_T0_FALLING					6
#define MTIM0_CS_T0_RISING					7


/* Waveform Generation Mode Bit Description */
/* WGM01 - WGM00 */

#define MTIM0_MODE_NORMAL					0
#define MTIM0_MODE_PHASECORRECTPWM			1
#define MTIM0_MODE_CTC						2
#define MTIM0_MODE_FASTPWM					3

/* COM01 - COM00 -> MODE */

/*Compare Output Mode, non-PWM Mode*/
#define MTIM0_HWPIN_DISCONNECTED			0
#define MTIM0_HWPIN_TOGGLE					1
#define MTIM0_HWPIN_CLEAR					2
#define MTIM0_HWPIN_SET						3

/*Compare Output Mode, Fast PWM Mode*/
#define MTIM0_HWPIN_NOVINVERTING_PWM		2
#define MTIM0_HWPIN_INVERTING_PWM			3
 
/*ISR TYPE*/
#define MTIM0_INTERRUPT_OVF					0

#define MTIM0_INTERRUPT_OCM					1

#ifndef F_CPU
#define F_CPU 8000000UL
#warning F_CPU is not define. Assuming 8MHz clock.
#endif





STD_error_t MTIM0_stderrorInit(u8 ARG_u8ClockSource, u8 ARG_u8Mode, u8 ARG_u8HWPinMode);

void MTIM0_voidForceOutputCompare(void);

STD_error_t MTIM0_stderrorEnableInterrupt(u8 ARG_u8InterruptSource);
				
STD_error_t MTIM0_stderrorDisableInterrupt(u8 ARG_u8InterruptSource);
					
STD_error_t MTIM0_stderrorStartTimer(void);
				
STD_error_t MTIM0_stderrorStopTimer(void);
				
void MTIM0_voidSetOCR(u8 ARG_u8OCRValue);
				
STD_error_t MTIM0_stderrorTimerDelay(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void),u8 ARG_u8OSRInit, u32 ARG_u32Delay);
				
STD_error_t	MTIM0_stderrorFASTPWM(u8 ARG_u8ClockSource, u8 ARG_u8DutyCycle, u8 ARG_u8HWPinMode);

//STD_error_t MTIM0_stderrorGetTimerValue(u16 *ARG_u16pTimerValue, u8 ARG_u8TimerNo);
				
//STD_error_t MTIM0_stderrorSetTimerValue(u8 ARG_u8TimerNo, u16 ARG_u16TimerValue);

#endif 
