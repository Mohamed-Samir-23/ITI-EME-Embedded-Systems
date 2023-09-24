/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: SYSTICK				*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 20, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

/* Library Include */
#include "LSTD_types.h"

/* SWC Include */
#include "MSYSTICK_config.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_interface.h"

static void (*MSYSTICK_pvoidfUserFunctionSysTick)(void) =NULL_POINTER;

static u8 MSYSTICK_u8SelectISR;

STD_error_t MSYSTICK_stderrorInit
(
	MSYSTICK_CLkSRC_t ARG_udtCLkSRC
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtCLkSRC <=1)
	{
		/*Disable SysTick peripheral and SysTick interrupt*/
		STK_CTRL =(STK_CTRL&(~STK_CTRL_Flag))|(ARG_udtCLkSRC<<2);
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}




STD_error_t MSYSTICK_stderrorSetBusyWait
(
	u32 ARG_u32Ticks
)
{
	STD_error_t L_stderrorError=E_NOK;
	STK_LOAD =ARG_u32Ticks;
	STK_CTRL |=1U;
	while(((STK_CTRL>>16)&1)!=1);
	STK_CTRL &=~(1U);
	return L_stderrorError;
}




STD_error_t MSYSTICK_stderrorSetSingleInterval
(
	u32 ARG_u32Ticks,
	void (*ARG_pvoidfUserFunction)(void)
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pvoidfUserFunction != NULL_POINTER)
	{
		MSYSTICK_u8SelectISR=0;
		MSYSTICK_pvoidfUserFunctionSysTick=ARG_pvoidfUserFunction;
		STK_LOAD =ARG_u32Ticks;
		STK_CTRL |=3U;
		
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	
	return L_stderrorError;
}


STD_error_t MSYSTICK_stderrorSetPeriodiceInterval
(
	u32 ARG_u32Ticks,
	void (*ARG_pvoidfUserFunction)(void)
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pvoidfUserFunction != NULL_POINTER)
	{
		MSYSTICK_u8SelectISR=1;
		MSYSTICK_pvoidfUserFunctionSysTick=ARG_pvoidfUserFunction;
		STK_LOAD =ARG_u32Ticks;
		STK_CTRL |=3U;
		
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	
	return L_stderrorError;
}


void MSYSTICK_voidStopTICK
(
	void
)
{
	STK_CTRL &=~(3U);
}


void SysTick_Handler(void)
{
	
	if(MSYSTICK_u8SelectISR ==0)
	{
		
		MSYSTICK_pvoidfUserFunctionSysTick();
		STK_CTRL &=~(2U);
	}
	else if(MSYSTICK_u8SelectISR ==1)
	{
		MSYSTICK_pvoidfUserFunctionSysTick();
	}
	else
	{
		
	}
	
}
