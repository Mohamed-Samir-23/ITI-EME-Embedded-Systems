/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 17, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MTIM_config.h"
#include "MTIM_private.h"
#include "MTIM_interface.h"

static u8 MTIM_u8Timer0Clock;

static volatile u16 MTIM_u8Timer0OVfCount;

static volatile u8 MTIM_u8Timer0Preload;

void(*MTIM_pvoidfUserFunctionT0OVF)(void)=NULL_POINTER;

void(*MTIM_pvoidfUserFunctionT0OCM)(void)=NULL_POINTER;


STD_error_t MTIM_stderrorIint(u8 ARG_u8TimerNo, u8 ARG_u8ClockSource, u8 ARG_u8Mode, u8 ARG_u8HWPinMode)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8TimerNo>=0&&ARG_u8TimerNo<=2)&&(ARG_u8Mode>=0&&ARG_u8Mode<=3)&&(ARG_u8HWPinMode>=0&&ARG_u8HWPinMode<=3)&&(ARG_u8ClockSource>=0&&ARG_u8ClockSource<=7))
	{
		switch(ARG_u8TimerNo)
		{
			
			case MTIM_TIMER0:
			{
				switch(ARG_u8Mode)
				{
					case MTIM_MODE_NORMAL : 
					{	
						CLEAR_BIT(MTIM_TCCR0, MTIM_WGM01);CLEAR_BIT(MTIM_TCCR0, MTIM_WGM00);
						L_stderrorError=E_OK;
						break;
					}
					case MTIM_MODE_PHASECORRECTPWM :
					{
						CLEAR_BIT(MTIM_TCCR0, MTIM_WGM01);SET_BIT(MTIM_TCCR0, MTIM_WGM00);
						L_stderrorError=E_OK;
						break;
					}
					case MTIM_MODE_CTC :
					{
						SET_BIT(MTIM_TCCR0, MTIM_WGM01);CLEAR_BIT(MTIM_TCCR0, MTIM_WGM00);
						L_stderrorError=E_OK;
						break;
					}
					case MTIM_MODE_FASTPWM :
					{
						SET_BIT(MTIM_TCCR0, MTIM_WGM01);SET_BIT(MTIM_TCCR0, MTIM_WGM00);
						L_stderrorError=E_OK;
						break;
					}
					
					default:L_stderrorError=E_NOK;break;
				}
				
				/*Oc0 pin mode*/
				MTIM_TCCR0=(MTIM_TCCR0&0xCF)|(ARG_u8HWPinMode<<4);
				MTIM_u8Timer0Clock=ARG_u8ClockSource;
				break;
			}
			case MTIM_TIMER1:
			{
				
				
				break;
			}
			case MTIM_TIMER2:
			{
				
				
				break;
			}
			default:L_stderrorError=E_NOK;break;
		}
	
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

void MTIM_voidForceOutputCompare(void)
{
	SET_BIT(MTIM_TCCR0,MTIM_F0C0);
}


STD_error_t MTIM_stderrorEnableInterrupt(u8 ARG_u8InterruptSource)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8InterruptSource>=0&&ARG_u8InterruptSource<=7))
	{
		
		SET_BIT(MTIM_TIMSK,ARG_u8InterruptSource);
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;	
}



STD_error_t MTIM_stderrorDisableInterrupt(u8 ARG_u8InterruptSource)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8InterruptSource>=0&&ARG_u8InterruptSource<=7))
	{
		
		CLEAR_BIT(MTIM_TIMSK,ARG_u8InterruptSource);
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;	
	
	
	
}

STD_error_t MTIM_stderrorSetCallBack(u8 ARG_u8InterruptSource, void (*ARG_pvoidfUserFunction)(void))
{
	
	STD_error_t L_stderrorError=E_NOK;
	if(ARG_pvoidfUserFunction!=NULL_POINTER)
	{
				switch(ARG_u8InterruptSource)
				{
					
					
					case MTIM_INTERRUPT_T0_OVF:
					{
						MTIM_pvoidfUserFunctionT0OVF=ARG_pvoidfUserFunction;
						L_stderrorError=E_OK;
						break;
					}
					case MTIM_INTERRUPT_T0_OCM:
					{
						
						MTIM_pvoidfUserFunctionT0OCM=ARG_pvoidfUserFunction;
						L_stderrorError=E_OK;
						break;
					}
					default:L_stderrorError=E_NOK;break;
					
				}
	
	}
	else
	{
		
		L_stderrorError=E_NULL_POINTER;
	}
	
	
	return L_stderrorError;
	
}
STD_error_t MTIM_stderrorStartTimer(u8 ARG_u8TimerNo)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8TimerNo>=0&&ARG_u8TimerNo<=2))
	{
		switch(ARG_u8TimerNo)
		{
			
			case MTIM_TIMER0:
			{
				MTIM_TCCR0=(MTIM_TCCR0&0xF8)|MTIM_u8Timer0Clock ;
				L_stderrorError=E_OK;
				break;
			}
			case MTIM_TIMER1:
			{
				
				
				break;
			}
			case MTIM_TIMER2:
			{
				
				
				break;
			}
			default:L_stderrorError=E_NOK;break;
		}
	
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
	
}
STD_error_t MTIM_stderrorStopTimer(u8 ARG_u8TimerNo)
{
	
		STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8TimerNo>=0&&ARG_u8TimerNo<=2))
	{
		switch(ARG_u8TimerNo)
		{
			
			case MTIM_TIMER0:
			{
				MTIM_TCCR0=(MTIM_TCCR0&0xF8)|MTIM_CS_NO_CLOCK ;
				L_stderrorError=E_OK;
				break;
			}
			case MTIM_TIMER1:
			{
				
				
				break;
			}
			case MTIM_TIMER2:
			{
				
				
				break;
			}
			default:L_stderrorError=E_NOK;break;			
		}
	
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

STD_error_t MTIM_stderrorSetOCR(u8 ARG_u8TimerNo, u16 ARG_u16OCRValue)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8TimerNo>=0&&ARG_u8TimerNo<=2))
	{
		switch(ARG_u8TimerNo)
		{
			
			case MTIM_TIMER0:
			{
				MTIM_OCR0=ARG_u16OCRValue;
				L_stderrorError=E_OK;
				break;
			}
			case MTIM_TIMER1:
			{
				
				
				break;
			}
			case MTIM_TIMER2:
			{
				
				
				break;
			}
			default:L_stderrorError=E_NOK;break;
		}
	
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
	
	
}


STD_error_t MTIM_stderrorTimerDelay(u8 ARG_u8TimerNo, u32 ARG_u32Delay)
{
		STD_error_t L_stderrorError=E_NOK;
		f32 L_f32TickTime,L_f32OVFTime;
		u16 L_Prescalar;
	
	if((ARG_u8TimerNo>=0&&ARG_u8TimerNo<=2))
	{
		switch(ARG_u8TimerNo)
		{
			
			case MTIM_TIMER0:
			{
				
				
				switch(MTIM_u8Timer0Clock)
				{
					
					case MTIM_CS_PRESCALAR_1	:L_Prescalar=1;		break;
					case MTIM_CS_PRESCALAR_8	:L_Prescalar=8;		break;
					case MTIM_CS_PRESCALAR_64	:L_Prescalar=64;	break;
					case MTIM_CS_PRESCALAR_256	:L_Prescalar=256;	break;
					case MTIM_CS_PRESCALAR_1024	:L_Prescalar=1024;	break;
					default:L_stderrorError=E_NOK;break;
				}
				
				L_f32TickTime  	=	(f32)L_Prescalar / F_CPU;
				
				L_f32OVFTime 	=	L_f32TickTime*256;
				
				MTIM_u8Timer0OVfCount=((f32)ARG_u32Delay/1000)/L_f32OVFTime;

				MTIM_u8Timer0Preload=256-((ARG_u32Delay/1000) % (u32)L_f32OVFTime);
				
				MTIM_TCNT0=MTIM_u8Timer0Preload;
				
				L_stderrorError=E_OK;
				break;
			}
			case MTIM_TIMER1:
			{
				
				
				break;
			}
			case MTIM_TIMER2:
			{
				
				
				break;
			}
			default:L_stderrorError=E_NOK;break;
		}
	
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
	
	
}

void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	
	
	static volatile u16 L_u16OVFCounter =0;
	L_u16OVFCounter++;
	
	if(MTIM_pvoidfUserFunctionT0OVF!=NULL_POINTER)
	{
		if((MTIM_u8Timer0OVfCount+1)==L_u16OVFCounter)
		{
			
			
			L_u16OVFCounter=0;
			MTIM_TCNT0=MTIM_u8Timer0Preload;
			MTIM_pvoidfUserFunctionT0OVF();
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
	
	if(MTIM_pvoidfUserFunctionT0OCM!=NULL_POINTER)
	{
		
			MTIM_pvoidfUserFunctionT0OCM();
	}
	else
	{
		
		/* */
		
	}
	
}