/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 26, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MTIM0_config.h"
#include "MTIM0_private.h"
#include "MTIM0_interface.h"

static u8 MTIM0_u8TimerClock;

static volatile u16 MTIM0_u8TimerCount;

static volatile u8 MTIM0_u8TimerPreload;

void(*MTIM0_pvoidfUserFunctionOVF)(void)=NULL_POINTER;

void(*MTIM0_pvoidfUserFunctionOCM)(void)=NULL_POINTER;

u32 MTIM0_u32Delay;

STD_error_t MTIM0_stderrorInit(u8 ARG_u8ClockSource, u8 ARG_u8Mode, u8 ARG_u8HWPinMode)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8ClockSource>=0&&ARG_u8ClockSource<=7)&&(ARG_u8Mode>=0&&ARG_u8Mode<=3)&&(ARG_u8HWPinMode>=0&&ARG_u8HWPinMode<=3))
	{
		MTIM0_u8TimerClock = ARG_u8ClockSource;
		
		switch(ARG_u8Mode)
		{
			
			case MTIM0_MODE_NORMAL			:CLEAR_BIT(MTIM0_TCCR0,MTIM0_WGM01);CLEAR_BIT(MTIM0_TCCR0,MTIM0_WGM00);	L_stderrorError=E_OK;break;
			case MTIM0_MODE_PHASECORRECTPWM	:CLEAR_BIT(MTIM0_TCCR0,MTIM0_WGM01);SET_BIT(MTIM0_TCCR0,MTIM0_WGM00);	L_stderrorError=E_OK;break;
			case MTIM0_MODE_CTC				:SET_BIT(MTIM0_TCCR0,MTIM0_WGM01);	CLEAR_BIT(MTIM0_TCCR0,MTIM0_WGM00);	L_stderrorError=E_OK;break;
			case MTIM0_MODE_FASTPWM			:SET_BIT(MTIM0_TCCR0,MTIM0_WGM01);	SET_BIT(MTIM0_TCCR0,MTIM0_WGM00);	L_stderrorError=E_OK;break;
			default 						:L_stderrorError=E_NOK;break;
		}
		
		MTIM0_TCCR0=(MTIM0_TCCR0&MTIM0_HWPINFLAG)|ARG_u8HWPinMode;
		
		L_stderrorError=E_NOK;
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}

	
	
	return L_stderrorError;
	
}


void MTIM0_voidForceOutputCompare(void)
{
	SET_BIT(MTIM0_TCCR0,MTIM0_F0C0);
}



STD_error_t MTIM0_stderrorEnableInterrupt(u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8InterruptSource==MTIM0_INTERRUPT_OVF)
	{
		
		SET_BIT(MTIM0_TIMSK,MTIM0_TOIE0);
		L_stderrorError=E_OK;

	}
	else if(ARG_u8InterruptSource==MTIM0_INTERRUPT_OCM)
	{
		
		SET_BIT(MTIM0_TIMSK,MTIM0_OCIE0);
		L_stderrorError=E_OK;
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

STD_error_t MTIM0_stderrorDisableInterrupt(u8 ARG_u8InterruptSource)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8InterruptSource==MTIM0_INTERRUPT_OVF)
	{
		
		CLEAR_BIT(MTIM0_TIMSK,MTIM0_TOIE0);
		L_stderrorError=E_OK;

	}
	else if(ARG_u8InterruptSource==MTIM0_INTERRUPT_OCM)
	{
		
		CLEAR_BIT(MTIM0_TIMSK,MTIM0_OCIE0);
		L_stderrorError=E_OK;
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

STD_error_t MTIM0_stderrorStartTimer(void)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((MTIM0_ClOCKFLAG>=0&&MTIM0_ClOCKFLAG<=7))
	{
		
		MTIM0_TCCR0=(MTIM0_TCCR0&MTIM0_ClOCKFLAG)|MTIM0_u8TimerClock;
		L_stderrorError=E_OK;
	}
	else
	{
		 L_stderrorError=E_NOK;
		
	}
	
	return L_stderrorError;
}


STD_error_t MTIM0_stderrorStopTimer(void)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((MTIM0_ClOCKFLAG>=0&&MTIM0_ClOCKFLAG<=7))
	{
		MTIM0_TCCR0=MTIM0_TCCR0&MTIM0_ClOCKFLAG;
		L_stderrorError=E_OK;
	}
	else
	{
		 L_stderrorError=E_NOK;
		
	}
	
	return L_stderrorError;
	
}


void MTIM0_voidSetOCR(u8 ARG_u8OCRValue)
{	
	MTIM0_OCR0 =ARG_u8OCRValue;
}

STD_error_t MTIM0_stderrorTimerDelay(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void), u8 ARG_u8OSRInit, u32 ARG_u32Delay)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pvoidfUserFunction!=NULL_POINTER)
	{
		if(MTIM0_u8TimerClock>=1&&MTIM0_u8TimerClock<=5)
		{
			MTIM0_u32Delay=ARG_u32Delay;
			if(ARG_u8InterruptSource==MTIM0_INTERRUPT_OVF)
			{
				MTIM0_pvoidfUserFunctionOVF=ARG_pvoidfUserFunction;
				
				f32 L_u8PreScaler=0;
				switch(MTIM0_u8TimerClock)
				{
					case MTIM0_CS_NO_CLOCK		: 	L_u8PreScaler=1;L_stderrorError=E_OK;break;
					case MTIM0_CS_PRESCALAR_8	: 	L_u8PreScaler=8;L_stderrorError=E_OK;break;
					case MTIM0_CS_PRESCALAR_64	: 	L_u8PreScaler=64;L_stderrorError=E_OK;break;
					case MTIM0_CS_PRESCALAR_256	:	L_u8PreScaler=256;L_stderrorError=E_OK;break;
					case MTIM0_CS_PRESCALAR_1024:	L_u8PreScaler=1024;L_stderrorError=E_OK;break;
					default 					:	L_stderrorError=E_NOK;break;
				}
				
				f32 L_f32TickTime=L_u8PreScaler/(f32)F_CPU;
				
				f32 L_f32OverFlowTime=L_f32TickTime*256.0;
				
				MTIM0_u8TimerCount=((f32)ARG_u32Delay/1000)/L_f32OverFlowTime;
				
				f64 L_f64TimerPreload=((f32)ARG_u32Delay/1000)/L_f32OverFlowTime;
				
				L_f64TimerPreload=L_f64TimerPreload-MTIM0_u8TimerCount;
				
				MTIM0_u8TimerPreload=256*((f32)1-(L_f64TimerPreload));
			
				MTIM0_TCNT0=MTIM0_u8TimerPreload;
				
				MTIM0_OCR0 =ARG_u8OSRInit;
				
				L_stderrorError=E_OK;
			}
			else if(ARG_u8InterruptSource==MTIM0_INTERRUPT_OCM)
			{
				MTIM0_pvoidfUserFunctionOCM=ARG_pvoidfUserFunction;
				MTIM0_TCNT0=0;
				MTIM0_OCR0 =ARG_u8OSRInit;
				MTIM0_u8TimerCount=(ARG_u32Delay*1000)/ARG_u8OSRInit;
				L_stderrorError=E_OK;
			}
			else
			{
				L_stderrorError=E_NOK;
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


STD_error_t	MTIM0_stderrorFASTPWM(u8 ARG_u8ClockSource, u8 ARG_u8DutyCycle, u8 ARG_u8HWPinMode)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((MTIM0_ClOCKFLAG>=0&&MTIM0_ClOCKFLAG<=7))
	{
		if(ARG_u8HWPinMode==MTIM0_HWPIN_NOVINVERTING_PWM)
		{
			MTIM0_OCR0 =256*(ARG_u8DutyCycle/100.0);
			MTIM0_TCCR0=(MTIM0_TCCR0&MTIM0_ClOCKFLAG)|MTIM0_u8TimerClock;
			L_stderrorError=E_NOK;			
		}
		else if((ARG_u8HWPinMode==MTIM0_HWPIN_INVERTING_PWM)
		{
			MTIM0_OCR0=((f32)1-(ARG_u8DutyCycle/100.0))*256;
			MTIM0_TCCR0=(MTIM0_TCCR0&MTIM0_ClOCKFLAG)|MTIM0_u8TimerClock;	
			L_stderrorError=E_NOK;
		}
		else
		{
			
			L_stderrorError=E_NOK;
			
		}
		
	}
	else
	{
		
		
		L_stderrorError=E_NOK;
		
		
	}
			
}


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



