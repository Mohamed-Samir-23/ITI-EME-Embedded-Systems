/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: NIVC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 18, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

/* Library Include */
#include "LSTD_types.h"

/* SWC Include */
#include "MNIVC_config.h"
#include "MNIVC_private.h"
#include "MNIVC_interface.h"

static volatile u8 MNIVC_u8GroupPriority;


STD_error_t NVIC_stderrorEnable
(
	NIVC_SRC_t ARG_udtSrc
)
{
	STD_error_t L_stderrorError=E_NOK;
	if(ARG_udtSrc <=31)
	{
		NVIC_ISER0 =(1U<<ARG_udtSrc);
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=32 && ARG_udtSrc <=63)
	{
		NVIC_ISER1 =(1U<<(ARG_udtSrc-32));
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=64 && ARG_udtSrc <=158)
	{
		NVIC_ISER2 =(1U<<(ARG_udtSrc-64));
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	return L_stderrorError;
}



STD_error_t NVIC_stderrorDisable
(
	NIVC_SRC_t ARG_udtSrc
)
{
	STD_error_t L_stderrorError=E_NOK;
	if(ARG_udtSrc <=31)
	{
		NVIC_ICER0 =(1U<<ARG_udtSrc);
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=32 && ARG_udtSrc <=63)
	{
		NVIC_ICER1 =(1U<<(ARG_udtSrc-32));
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=64 && ARG_udtSrc <=158)
	{
		NVIC_ICER2 =(1U<<(ARG_udtSrc-64));
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	return L_stderrorError;
}
	
		
STD_error_t NVIC_stderrorSetPending
(
	NIVC_SRC_t ARG_udtSrc
)
{
	STD_error_t L_stderrorError=E_NOK;
	if(ARG_udtSrc <=31)
	{
		NVIC_ISPR0 =(1U<<ARG_udtSrc);
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=32 && ARG_udtSrc <=63)
	{
		NVIC_ISPR1 =(1U<<(ARG_udtSrc-32));
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=64 && ARG_udtSrc <=158)
	{
		NVIC_ISPR2 =(1U<<(ARG_udtSrc-64));
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	return L_stderrorError;
}


STD_error_t NVIC_stderrorClearPending
(
	NIVC_SRC_t ARG_udtSrc
)
{
	STD_error_t L_stderrorError=E_NOK;
	if(ARG_udtSrc <=31)
	{
		NVIC_ICPR0 =(1U<<ARG_udtSrc);
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=32 && ARG_udtSrc <=63)
	{
		NVIC_ICPR1 =(1U<<(ARG_udtSrc-32));
		L_stderrorError=E_OK;
	}
	else if(ARG_udtSrc >=64 && ARG_udtSrc <=158)
	{
		NVIC_ICPR2 =(1U<<(ARG_udtSrc-64));
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	return L_stderrorError;
}

STD_error_t NVIC_stderrorGetPending
(
	NIVC_SRC_t ARG_udtSrc ,
	u8* ARG_pu8PendingValue
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8PendingValue != NULL_POINTER)
	{
		if(ARG_udtSrc <=31)
		{
			*ARG_pu8PendingValue = ((NVIC_ISPR0>>ARG_udtSrc)&1);
			L_stderrorError=E_OK;
		}
		else if(ARG_udtSrc >=32 && ARG_udtSrc <=63)
		{
			*ARG_pu8PendingValue = ((NVIC_ISPR1>>(ARG_udtSrc-32))&1);
			L_stderrorError=E_OK;
		}
		else if(ARG_udtSrc >=64 && ARG_udtSrc <=158)
		{
			*ARG_pu8PendingValue = ((NVIC_ISPR2>>(ARG_udtSrc-64))&1);
			L_stderrorError=E_OK;
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



STD_error_t NVIC_stderrorGetActive
(
	NIVC_SRC_t ARG_udtSrc ,
	u8* ARG_pu8ActiveValue
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8PendingValue != NULL_POINTER)
	{
		if(ARG_udtSrc <=31)
		{
			*ARG_pu8ActiveValue = ((NVIC_IABR0>>ARG_udtSrc)&1);
			L_stderrorError=E_OK;
		}
		else if(ARG_udtSrc >=32 && ARG_udtSrc <=63)
		{
			*ARG_pu8ActiveValue = ((NVIC_IABR1>>(ARG_udtSrc-32))&1);
			L_stderrorError=E_OK;
		}
		else if(ARG_udtSrc >=64 && ARG_udtSrc <=158)
		{
			*ARG_pu8ActiveValue = ((NVIC_IABR2>>(ARG_udtSrc-64))&1);
			L_stderrorError=E_OK;
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


STD_error_t NVIC_stderrorSetPriorityGrouping
(
	NIVC_SRC_t ARG_udtSrc ,
	SCB_PriorityGroup_t ARG_udtGroupPriority
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGroupPriority <= 7)
	{
		MNIVC_u8GroupPriority =	ARG_udtGroupPriority;
		
		SCB_AIRCR = (VECTKEY<<15)|(ARG_udtGroupPriority<<8);
		L_stderrorError=E_OK;
	}
	else
	{
		
		L_stderrorError=E_NOK;
		
		
	}
	return L_stderrorError;
}


STD_error_t NVIC_stderrorSetInterruptPriority
(
	NIVC_SRC_t ARG_udtSrc ,
	NIVC_GroupPriority_t ARG_udtGroupPriority,
	NIVC_SubGroupPriority_t ARG_udtSubGroupPriority
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	switch(MNIVC_u8GroupPriority)
	{
		
		case PRIGROUP_16GRU_0SUB:
		{
			/*obxxxx0000*/
			NVIC_IPR0[ARG_udtSrc]=(ARG_udtGroupPriority<<4U);
			L_stderrorError=E_OK;
			break;
		}
		case PRIGROUP_8GRU_2SUB:
		{
			/*0bxxxy0000*/
			NVIC_IPR0[ARG_udtSrc]=(ARG_udtGroupPriority<<5U) |(ARG_udtSubGroupPriority<<4U);
			L_stderrorError=E_OK;
			break;
		}
		case PRIGROUP_4GRU_4SUB:
		{
			/*0bxxyy0000*/
			NVIC_IPR0[ARG_udtSrc]=(ARG_udtGroupPriority<<6U) |(ARG_udtSubGroupPriority<<4U);
			L_stderrorError=E_OK;
			break;
		}
		case PRIGROUP_2GRU_8SUB:
		{
			/*0bxyyy0000*/
			NVIC_IPR0[ARG_udtSrc]=(ARG_udtGroupPriority<<7U) |(ARG_udtSubGroupPriority<<4U);
			L_stderrorError=E_OK;
			break;
		}
		case PRIGROUP_0GRU_16SUB:
		{
			/*obyyyy0000*/
			NVIC_IPR0[ARG_udtSrc]=(ARG_udtSubGroupPriority<<4U);
			L_stderrorError=E_OK;
			break;
		}
		default
		{
			L_stderrorError=E_NOK;
		}
		
	}
	
	return L_stderrorError;	
}


STD_error_t NVIC_stderrorGetPriority
(
	NIVC_SRC_t ARG_udtSrc
	u8* ARG_pu8PriorityValue
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8PriorityValue != NULL_POINTER)
	{
		ARG_pu8PriorityValue=(NVIC_IPR0[ARG_udtSrc]>>4)&0x0F;
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	return L_stderrorError;
}

STD_error_t NVIC_stderrorGetPriorityGrouping
(
	u8* ARG_pu8PriorityGroupingValue
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8PriorityGroupingValue != NULL_POINTER)
	{
		ARG_pu8PriorityGroupingValue=MNIVC_u8GroupPriority;
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	return L_stderrorError;
}