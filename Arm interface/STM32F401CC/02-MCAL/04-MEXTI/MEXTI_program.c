/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: EXTI					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 19, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/


/* Library Include */
#include "LSTD_types.h"

/* SWC Include */
#include "MEXTI_config.h"
#include "MEXTI_private.h"
#include "MEXTI_interface.h"



STD_error_t MEXTI_stderrorNotMasK
(
	MEXTI_LINE_t ARG_udtLineNumber
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtLineNumber<=15)
	{
		EXTI_IMR |=(1U<<ARG_udtLineNumber);
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}


STD_error_t MEXTI_stderrorMasK
(
	MEXTI_LINE_t ARG_udtLineNumber
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtLineNumber<=15)
	{
		EXTI_IMR &=(~(1U<<ARG_udtLineNumber));
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}


STD_error_t MEXTI_stderrorEventType
(
	MEXTI_LINE_t ARG_udtLineNumber,
	MEXTI_EVENT_TYPE_t ARG_udtEventType
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtLineNumber<=15&&ARG_udtEventType<=1)
	{
		if(ARG_udtEventType==FALLING_TRIGGER)
		{
			EXTI_FTSR|=(1U<<ARG_udtLineNumber);
			L_stderrorError=E_OK;
		}
		else
		{
			EXTI_RTSR|=(1U<<ARG_udtLineNumber);
			L_stderrorError=E_OK;
		}
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}


STD_error_t MEXTI_stderrorSWTrigger
(
	MEXTI_LINE_t ARG_udtLineNumber,
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtLineNumber<=15)
	{
		EXTI_SWIER|=(1U<<ARG_udtLineNumber);
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}




STD_error_t MEXTI_stderrorSelectPort
(
	MEXTI_LINE_t ARG_udtLineNumber,
	MEXTI_PORT_NAME_t ARG_udtPortName
)
{
	
	#define CLEAR_BIT(reg, bit) 	reg	&=~(1<<bit)
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtLineNumber<=15&&(ARG_udtPortName<=4||ARG_udtPortName==7))
	{
		if(ARG_udtLineNumber <=3)
		{
			
			SYSCFG_EXTICR1 &=~(15U<<(4*ARG_udtLineNumber));
			SYSCFG_EXTICR1 |=(ARG_udtPortName<<(4*ARG_udtLineNumber));
			
		}
		else if (ARG_udtLineNumber >=4 && ARG_udtLineNumber <=7)
		{
			
			SYSCFG_EXTICR2 &=~(15U<<(4*(ARG_udtLineNumber-4U)));
			SYSCFG_EXTICR2 |=(ARG_udtPortName<<(4*(ARG_udtLineNumber-4U)));
			
			
		}
		else if (ARG_udtLineNumber >=8 && ARG_udtLineNumber <=11)
		{
			SYSCFG_EXTICR3 &=~(15U<<(4*(ARG_udtLineNumber-8U)));
			SYSCFG_EXTICR3 |=(ARG_udtPortName<<(4*(ARG_udtLineNumber-8U)));
			
			
		}
		else if (ARG_udtLineNumber >=12 && ARG_udtLineNumber <=15)
		{
			SYSCFG_EXTICR4 &=~(15U<<(4*(ARG_udtLineNumber-15U)));
			SYSCFG_EXTICR4 |=(1U<<(4*(ARG_udtLineNumber-15U)));
		}
		else
		{
			
			/**/
		}
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}