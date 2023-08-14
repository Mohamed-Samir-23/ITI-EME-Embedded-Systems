/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: EXTI				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 13, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"


/* SWC Include */
#include "MEXTI_config.h"
#include "MEXTI_private.h"
#include "MEXTI_interface.h"




static void (*pvoidfUserFunctionINT0)(void) =NULL_POINTER;
static void (*pvoidfUserFunctionINT1)(void) =NULL_POINTER;
static void (*pvoidfUserFunctionINT2)(void) =NULL_POINTER;


STD_error_t MEXTI_stderrorInit
(
	u8 ARG_u8InterruptNo,
	u8 ARG_u8SensMode
)
{
	STD_error_t L_stderrorError=E_NOK;

	switch(ARG_u8SensMode)
	{
		
		case MEXTI_MODE_LOW: 
		{
			switch(ARG_u8InterruptNo)
			{
				
				case MEXTI_INT0:
				{
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC00);
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC01);
					L_stderrorError = E_OK;
				}
				case MEXTI_INT1:
				{
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC10);
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC11);
					L_stderrorError = E_OK;
					
				}
				default:L_stderrorError=E_NOK;break;
			}
			break;
		}
		case MEXTI_MODE_IOC: 
		{
			
			switch(ARG_u8InterruptNo)
			{
				
				case MEXTI_INT0:
				{
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC00);
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC01);
					L_stderrorError = E_OK;
				}
				case MEXTI_INT1:
				{
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC10);
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC11);
					L_stderrorError = E_OK;
					
				}

				default:L_stderrorError=E_NOK;break;
			}
			break;
			
		}
		case MEXTI_MODE_FALLING: 
		{
			
			switch(ARG_u8InterruptNo)
			{
				
				case MEXTI_INT0:
				{
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC00);
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC01);
					L_stderrorError = E_OK;
				}
				case MEXTI_INT1:
				{
					CLEAR_BIT(MEXTI_MCUCR,MEXTI_ISC10);
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC11);
					L_stderrorError = E_OK;
					
				}
				case MEXTI_INT2:
				{
					
					CLEAR_BIT(MEXTI_MCUCSR, MEXTI_ISC2);
					L_stderrorError = E_OK;
					
				}
				default:L_stderrorError=E_NOK;break;
			}
			break;
			
		}
		case MEXTI_MODE_RISING: 
		{
			
			switch(ARG_u8InterruptNo)
			{
				
				case MEXTI_INT0:
				{
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC00);
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC01);
					L_stderrorError = E_OK;
				}
				case MEXTI_INT1:
				{
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC10);
					SET_BIT(MEXTI_MCUCR,MEXTI_ISC11);
					L_stderrorError = E_OK;
					
				}
				case MEXTI_INT2:
				{
					
					SET_BIT(MEXTI_MCUCSR, MEXTI_ISC2);
					L_stderrorError = E_OK;
					
				}
				default:L_stderrorError=E_NOK;break;
			}
			break;
		}
		
		default:L_stderrorError=E_NOK;break;
	}
	
	
	return L_stderrorError;	
}


STD_error_t MEXTI_stderrorEnableInterrupt
(
	u8 ARG_u8InterruptNo
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8InterruptNo>=5&&ARG_u8InterruptNo<=7)
	{
		
		SET_BIT(MEXTI_GICR,ARG_u8InterruptNo);
		L_stderrorError = E_OK;
	}
	else
	{
		
		L_stderrorError=E_NOK;
		
	}
	
	return L_stderrorError;
	
}


STD_error_t MEXTI_stderrorDisableInterrupt
(
	u8 ARG_u8InterruptNo
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8InterruptNo>=5&&ARG_u8InterruptNo<=7)
	{
		
		CLEAR_BIT(MEXTI_GICR,ARG_u8InterruptNo);
		L_stderrorError = E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;

}


STD_error_t MEXTI_stderrorSetCallBack
(
	void (*ARG_pvoidfUserFunction)(void),
	u8 ARG_u8InterruptNo
)
{
	STD_error_t L_stderrorError=E_NOK;
	if(NULL_POINTER!=ARG_pvoidfUserFunction)
	{
		STD_error_t L_stderrorError=E_NOK;
		switch(ARG_u8InterruptNo)
		{
			case MEXTI_INT0 :pvoidfUserFunctionINT0 = ARG_pvoidfUserFunction;L_stderrorError = E_OK;break;
			case MEXTI_INT1 :pvoidfUserFunctionINT1 = ARG_pvoidfUserFunction;L_stderrorError = E_OK;break;
			case MEXTI_INT2 :pvoidfUserFunctionINT2 = ARG_pvoidfUserFunction;L_stderrorError = E_OK;break;
			default : L_stderrorError=E_NOK; break;
		}
		
	}
	else
	{
		
		L_stderrorError = E_NULL_POINTER;
		
		
	}
	return L_stderrorError;
	
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	
	
	if(NULL_POINTER!=pvoidfUserFunctionINT0)
	{
		
		pvoidfUserFunctionINT0();
		
	}
	else
	{
		
		/*Nothing*/
		
	}
	
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	
	
	if(NULL_POINTER!=pvoidfUserFunctionINT1)
	{
		
		pvoidfUserFunctionINT1();
		
	}
	else
	{
		
		/*Nothing*/
		
	}
	
}


void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	
	
	if(NULL_POINTER!=pvoidfUserFunctionINT2)
	{
		
		pvoidfUserFunctionINT2();
		
	}
	else
	{
		
		/*Nothing*/
		
	}
	
}

