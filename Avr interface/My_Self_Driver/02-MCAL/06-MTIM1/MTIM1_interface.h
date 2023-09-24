/**************************************/
/*  Author		: Mohamed Samir		  */
/*  SWC			: MTIM1				  */
/*  Layer		: MCAL				  */
/*  Version		: 1.0				  */
/*  Date		: September 01, 2023  */
/*  Last Edit	: N/V 				  */
/**************************************/

#ifndef	_MTIM1_INTERFACE_H_
#define _MTIM1_INTERFACE_H_


/* CS12-CS11-CS10 -> PRESCALER */
#define MTIM1_CS_NO_CLOCK								0
#define MTIM1_CS_PRESCALAR_1							1
#define MTIM1_CS_PRESCALAR_8							2
#define MTIM1_CS_PRESCALAR_64							3
#define MTIM1_CS_PRESCALAR_256							4
#define MTIM1_CS_PRESCALAR_1024							5
#define MTIM1_CS_T0_FALLING								6
#define MTIM1_CS_T0_RISING								7


/* Waveform Generation Mode Bit Description */
/* WGM13 - WGM12 - WGM11 - WGM10 */
#define MTIM1_MODE_NORMAL								0
#define MTIM1_MODE_PHASECORRECTPWM_8BIT					1
#define MTIM1_MODE_PHASECORRECTPWM_9BIT					2
#define MTIM1_MODE_PHASECORRECTPWM_10BIT				3
#define MTIM1_MODE_CTC_OCR1A							4
#define MTIM1_MODE_FASTPWM_8BIT							5
#define MTIM1_MODE_FASTPWM_9BIT							6
#define MTIM1_MODE_FASTPWM_10BIT						7
#define MTIM1_MODE_PWM_PHASEFREQUENCYCORREC_ICR1		8
#define MTIM1_MODE_PWM_PHASEFREQUENCYCORREC_OCR1A		9
#define MTIM1_MODE_PWM_PHASECORRECTPWM_ICR1				10
#define MTIM1_MODE_PWM_PHASECORRECTPWM_OCR1A			11
#define MTIM1_MODE_CTC_ICR1								12
#define MTIM1_MODE_FASTPWM_ICR1							14
#define MTIM1_MODE_FASTPWM_OCR1A						15



/* COM1A1/COM1B1 COM1A0/COM1B0 -> MODE */
/*Compare Output Mode, non-PWM Mode*/
#define MTIM1_OC1A_HWPIN_DISCONNECTED					0
#define MTIM1_OC1A_HWPIN_TOGGLE							1
#define MTIM1_OC1A_HWPIN_CLEAR							2
#define MTIM1_OC1A_HWPIN_SET							3

#define MTIM1_OC1B_HWPIN_DISCONNECTED					0
#define MTIM1_OC1B_HWPIN_TOGGLE							1
#define MTIM1_OC1B_HWPIN_CLEAR							2
#define MTIM1_OC1B_HWPIN_SET							3

/*Compare Output Mode, Fast PWM Mode*/
#define MTIM1_OC1A_HWPIN_NOVINVERTING_PWM				2
#define MTIM1_OC1A_HWPIN_INVERTING_PWM					3

#define MTIM1_OC1B_HWPIN_NOVINVERTING_PWM				2
#define MTIM1_OC1B_HWPIN_INVERTING_PWM					3
 
/*ISR TYPE*/
#define MTIM1_INTERRUPT_OVF								2
#define MTIM1_INTERRUPT_OCMB							3
#define MTIM1_INTERRUPT_OCMA							4
#define MTIM1_INTERRUPT_ICU								5

#ifndef F_CPU
#define F_CPU 8000000UL
#warning F_CPU is not define. Assuming 8MHz clock.
#endif


STD_error_t MTIM1_stderrorInit(u8 ARG_u8ClockSource, u8 ARG_u8Mode, u8 ARG_u8HWPin1Mode, ARG_u8HWPin2Mode);

void MTIM1_voidForceAOutputCompare(void);

void MTIM1_voidForceBOutputCompare(void);

STD_error_t MTIM1_stderrorEnableInterrupt(u8 ARG_u8InterruptSource);

STD_error_t MTIM1_stderrorDisableInterrupt(u8 ARG_u8InterruptSource);

STD_error_t MTIM1_stderrorStartTimer(void);

STD_error_t MTIM1_stderrorStopTimer(void);

void MTIM1_voidSetOCRA(u16 ARG_u16OCRValue);

void MTIM1_voidSetOCRB(u16 ARG_u16OCRValue);

void MTIM1_voidSetICR(u16 ARG_u16OCRValue);

STD_error_t MTIM1_stderrorTimerDelay(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void), u16 ARG_u16TopLimitInit, u32 ARG_u32Delay);

STD_error_t	MTIM1_stderrorFASTPWM(u8 ARG_FastPwmMode,u8 ARG_u8ClockSource, u8 ARG_u8DutyCycle, u8 ARG_u8HWPin1Mode, ARG_u8HWPin2Mode);

STD_error_t MTIM1_stderrorGetTimerValue(u16 *ARG_u16pTimerValue);

void MTIM1_voidSetTimerValue(u16 ARG_u16TimerValue);

STD_error_t	MTIM1_stderrorPHASECORRECT(u8 ARG_PhaseCorrectMode, u8 ARG_u8ClockSource, u8 ARG_u8DutyCycle, u8 ARG_u8HWPin1Mode, ARG_u8HWPin2Mode);

#endif 
