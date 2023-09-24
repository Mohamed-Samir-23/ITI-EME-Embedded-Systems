/**************************************/
/*  Author		: Mohamed Samir		  */
/*  SWC			: MTIM1				  */
/*  Layer		: MCAL				  */
/*  Version		: 1.0				  */
/*  Date		: September 01, 2023  */
/*  Last Edit	: N/V 				  */
/**************************************/


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MTIM1_config.h"
#include "MTIM1_private.h"
#include "MTIM1_interface.h"

static u8 MTIM1_u8TimerClock;

static volatile u16 MTIM1_u16TimerCountOVF;

static volatile u16 MTIM1_u16TimerCountOCMA;

static volatile u16 MTIM1_u16TimerCountOCMB;

static volatile u16 MTIM1_u16TimerCountOICU;

static volatile u16 MTIM1_u16TimerPreload;

void(*MTIM1_pvoidfUserFunctionOVF)(void)=NULL_POINTER;

void(*MTIM1_pvoidfUserFunctionOCMA)(void)=NULL_POINTER;

void(*MTIM1_pvoidfUserFunctionOCMB)(void)=NULL_POINTER;

void(*MTIM1_pvoidfUserFunctionICU)(void)=NULL_POINTER;


u32 MTIM1_u32Delay;



STD_error_t MTIM1_stderrorInit(u8 ARG_u8ClockSource, u8 ARG_u8Mode, u8 ARG_u8HWPin1Mode, ARG_u8HWPin2Mode)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8ClockSource>=0&&ARG_u8ClockSource<=7)&&(ARG_u8Mode>=0&&ARG_u8Mode<=15&&ARG_u8Mode!=13)&&(ARG_u8HWPin1Mode>=0&&ARG_u8HWPin1Mode<=3)&&(ARG_u8HWPin2Mode>=0&&ARG_u8HWPin2Mode<=3))
	{
		
		MTIM1_u8TimerClock =ARG_u8ClockSource;
		
		/*Timer Mode AND HWPIN*/
		MTIM1_TCCR1A=(MTIM1_TCCR1A&MTIM1_TIMERMODEFLAG1)|(ARG_u8Mode&0x03)|(ARG_u8HWPin1Mode<<MTIM1_COM1A0)|(ARG_u8HWPin2Mode<<MTIM1_COM1B0);
		MTIM1_TCCR1B=(MTIM1_TCCR1B&MTIM1_TIMERMODEFLAG2)|((ARG_u8Mode&0x0C)<<MTIM1_WGM12);
		
		L_stderrorError=E_OK;

	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

void MTIM1_voidForceAOutputCompare(void)
{
	SET_BIT(MTIM1_TCCR1A,MTIM1_FOC1A);
}

void MTIM1_voidForceBOutputCompare(void)
{
	SET_BIT(MTIM1_TCCR1A,MTIM1_FOC1B);
}

STD_error_t MTIM1_stderrorEnableInterrupt(u8 ARG_u8InterruptSource)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8InterruptSource>=2&&ARG_u8InterruptSource<=5)
	{
		SET_BIT(MTIM_TIMSK,ARG_u8InterruptSource);
		L_stderrorError=E_OK;
	}
	else
	{
		
		L_stderrorError=E_NOK;
		
	}
	
	return L_stderrorError;
}

STD_error_t MTIM1_stderrorDisableInterrupt(u8 ARG_u8InterruptSource)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8InterruptSource>=2&&ARG_u8InterruptSource<=5)
	{
		CLEAR_BIT(MTIM_TIMSK,ARG_u8InterruptSource);
		L_stderrorError=E_OK;
	}
	else
	{
		
		L_stderrorError=E_NOK;
		
	}
	
	return L_stderrorError;
	
}

STD_error_t MTIM1_stderrorStartTimer(void)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((MTIM1_u8TimerClock>=0&&MTIM1_u8TimerClock<=7))
	{
		MTIM1_TCCR1B=(MTIM1_TCCR1B&MTIM1_ClOCKFLAG)|MTIM1_u8TimerClock;
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
	
}

STD_error_t MTIM1_stderrorStopTimer(void)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((MTIM1_u8TimerClock>=0&&MTIM1_u8TimerClock<=7))
	{
		MTIM1_TCCR1B=MTIM1_TCCR1B&MTIM1_ClOCKFLAG;
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

void MTIM1_voidSetOCRA(u16 ARG_u16OCRValue)
{
	MTIM_OCR1AL=ARG_u16OCRValue;
}

void MTIM1_voidSetOCRB(u16 ARG_u16OCRValue)
{
	MTIM_OCR1BL=ARG_u16OCRValue;
}

void MTIM1_voidSetICR(u16 ARG_u16OCRValue)
{
	MTIM_ICR1L=ARG_u16OCRValue
}

STD_error_t MTIM1_stderrorTimerDelay(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void), u16 ARG_u16TopLimitInit, u32 ARG_u32Delay)
{
	
	STD_error_t L_stderrorError=E_NOK;

	if(ARG_pvoidfUserFunction!=NULL_POINTER)
	{
		if(MTIM1_u8TimerClock>=1&&MTIM1_u8TimerClock<=5)
		{
			
			MTIM1_u32Delay=ARG_u32Delay;
			
			switch(ARG_u8InterruptSource)
			{
				
				case MTIM1_INTERRUPT_OVF:
				{
					MTIM1_pvoidfUserFunctionOVF=ARG_pvoidfUserFunction;
					f32 L_u8PreScaler=0;
					switch(MTIM1_u8TimerClock)
					{
						case MTIM0_CS_NO_CLOCK		: 	L_u8PreScaler=1;break;
						case MTIM0_CS_PRESCALAR_8	: 	L_u8PreScaler=8;break;
						case MTIM0_CS_PRESCALAR_64	: 	L_u8PreScaler=64;break;
						case MTIM0_CS_PRESCALAR_256	:	L_u8PreScaler=256;break;
						case MTIM0_CS_PRESCALAR_1024:	L_u8PreScaler=1024;break;
						default 					:	break;
					}
					
					f32 L_f32TickTime=L_u8PreScaler/(f32)F_CPU;
				
					f32 L_f32OverFlowTime=L_f32TickTime*65536.0;
					
					MTIM1_u16TimerCountOVF=((f32)ARG_u32Delay/1000)/L_f32OverFlowTime;
					
					f64 L_f64TimerPreload=((f32)ARG_u32Delay/1000)/L_f32OverFlowTime;
					
					L_f64TimerPreload=L_f64TimerPreload-MTIM1_u16TimerCountOVF;
					
					MTIM1_u16TimerPreload=(u16)(65536*((f32)1-(L_f64TimerPreload)));
				
					MTIM_TCNT1L=MTIM1_u16TimerPreload;
					
					MTIM_OCR1AL =ARG_u16TopLimitInit;
					
					L_stderrorError=E_OK;
					
				}
				case MTIM1_INTERRUPT_OCMB:
				{
					MTIM1_pvoidfUserFunctionOCMB=ARG_pvoidfUserFunction;
					MTIM_TCNT1L=0;
					MTIM1_u16TimerCountOCMB=(ARG_u32Delay*1000)/ARG_u8OSRInit;
					MTIM_OCR1BL =ARG_u16TopLimitInit;
				}
				case MTIM1_INTERRUPT_OCMA:
				{
					
					MTIM1_pvoidfUserFunctionOCMA=ARG_pvoidfUserFunction;
					MTIM_OCR1AL=ARG_u16TopLimitInit;
					
					
					
				}
				case MTIM1_INTERRUPT_ICU:
				{
					
					MTIM1_pvoidfUserFunctionICU;
					MTIM_ICR1L =ARG_u16TopLimitInit;
				
				}
				default :
				{
					
					L_stderrorError=E_NOK;
					break;
					
				}
				
				
			}

		}
		else
		{
			
			L_stderrorError=E_NOK;
			
		}
		
		
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	
	return L_stderrorError;
}

STD_error_t	MTIM1_stderrorFASTPWM(u8 ARG_FastPwmMode,u8 ARG_u8ClockSource, u8 ARG_u8DutyCycle, u8 ARG_u8HWPin1Mode, ARG_u8HWPin2Mode);

STD_error_t MTIM1_stderrorGetTimerValue(u16 *ARG_u16pTimerValue);

void MTIM1_voidSetTimerValue(u16 ARG_u16TimerValue);

STD_error_t	MTIM1_stderrorPHASECORRECT(u8 ARG_PhaseCorrectMode, u8 ARG_u8ClockSource, u8 ARG_u8DutyCycle, u8 ARG_u8HWPin1Mode, ARG_u8HWPin2Mode);


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static volatile u16 L_u16OVFCounter =0;
	
	L_u16OVFCounter++;
	
	if(MTIM0_pvoidfUserFunctionOVF!=NULL_POINTER)
	{
		if((MTIM0_u8TimerCount+1)==L_u16OVFCounter)
		{
			L_u16OVFCounter=0;
			MTIM0_TCNT0=MTIM0_u8TimerPreload;
			MTIM0_pvoidfUserFunctionOVF();
		}
		else
		{
			
			
			
			
		}
	}
	else
	{
		
		/* */
		
	}
	
	
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	
	if(MTIM0_pvoidfUserFunctionOCM!=NULL_POINTER)
	{
		
			MTIM0_pvoidfUserFunctionOCM();
	}
	else
	{
		
		/* */
		
	}
	
}



