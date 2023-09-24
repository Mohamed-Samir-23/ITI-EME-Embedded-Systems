/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: GPIO					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 17, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

/* Library Include */
#include "LSTD_types.h"

/* SWC Include */
#include "MGPIO_config.h"
#include "MGPIO_private.h"
#include "MGPIO_interface.h"


STD_error_t MGPIO_stderrorPinModeSelect
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_PIN_Mode_t ARG_udtGPIOMode
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtGPIOMode <= 3)
	{
		
		switch(ARG_udtGPIOPort)
		{
			case GPIOA:
			{
				
				GPIOA_MODER =(GPIOA_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOB:
			{
				GPIOB_MODER =(GPIOB_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOC:
			{
				GPIOC_MODER =(GPIOC_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOD:
			{
				GPIOD_MODER =(GPIOD_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOE:
			{
				GPIOE_MODER =(GPIOE_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOF:
			{
				GPIOF_MODER =(GPIOF_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOG:
			{
				GPIOG_MODER =(GPIOG_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOH:
			{
				GPIOH_MODER =(GPIOH_MODER&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtGPIOMode<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			default :
			{
				/*nothing*/
				break;
			}
			
			
			
		}
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
	
}

STD_error_t MGPIO_stderrorSetOutputPintype
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPIN_Mode_t ARG_udtOutMode
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtOutMode <= 1)
	{
		
		switch(ARG_udtGPIOPort)
		{
			case GPIOA:
			{
				GPIOA_OTYPER =(GPIOA_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOB:
			{
				GPIOB_OTYPER =(GPIOB_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOC:
			{
				GPIOC_OTYPER =(GPIOC_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOD:
			{
				GPIOD_OTYPER =(GPIOD_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOE:
			{
				GPIOE_OTYPER =(GPIOE_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOF:
			{
				GPIOF_OTYPER =(GPIOF_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOG:
			{
				GPIOG_OTYPER =(GPIOG_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOH:
			{
				GPIOH_OTYPER =(GPIOH_OTYPER&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtOutMode<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			default :
			{
				/*nothing*/
				break;
			}
			
		}
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}


STD_error_t MGPIO_stderrorSetOutputPinSpeed
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPIN_Speed_t ARG_udtOutSpeed
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtOutSpeed <= 3)
	{
	
		switch(ARG_udtGPIOPort)
		{
			case GPIOA:
			{
				GPIOA_OSPEEDR =(GPIOA_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOB:
			{
				GPIOB_OSPEEDR =(GPIOB_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOC:
			{
				GPIOC_OSPEEDR =(GPIOC_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOD:
			{
				GPIOD_OSPEEDR =(GPIOD_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOE:
			{
				GPIOE_OSPEEDR =(GPIOE_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOF:
			{
				GPIOF_OSPEEDR =(GPIOF_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOG:
			{
				GPIOG_OSPEEDR =(GPIOG_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOH:
			{
				GPIOH_OSPEEDR =(GPIOH_OSPEEDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtOutSpeed<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			default :
			{
				/*nothing*/
				break;
			}
			
		}
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}


STD_error_t MGPIO_stderrorSetPinPull_Up_Down
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_PULL_t ARG_udtPullType
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtPullType <= 2)
	{
	
		switch(ARG_udtGPIOPort)
		{
			case GPIOA:
			{
				GPIOA_PUPDR =(GPIOA_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOB:
			{
				GPIOB_PUPDR =(GPIOB_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOC:
			{
				GPIOC_PUPDR =(GPIOC_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOD:
			{
				GPIOD_PUPDR =(GPIOD_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOE:
			{
				GPIOE_PUPDR =(GPIOE_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOF:
			{
				GPIOF_PUPDR =(GPIOF_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOG:
			{
				GPIOG_PUPDR =(GPIOG_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOH:
			{
				GPIOH_PUPDR =(GPIOH_PUPDR&(~(3U<<(2*ARG_udtGPIOPin))))|(ARG_udtPullType<<(2*ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			default :
			{
				/*nothing*/
				break;
			}
			
		}
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;	
}



STD_error_t MGPIO_stderrorGetPinValue
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	u8* ARG_pu8Value 
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8Value != NULL_POINTER )
	{
		
		if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 )
		{
		
			switch(ARG_udtGPIOPort)
			{
				case GPIOA:
				{
					*ARG_pu8Value =((GPIOA_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOB:
				{
					*ARG_pu8Value =((GPIOB_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOC:
				{
					*ARG_pu8Value =((GPIOC_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOD:
				{
					*ARG_pu8Value =((GPIOD_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOE:
				{
					*ARG_pu8Value =((GPIOE_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOF:
				{
					*ARG_pu8Value =((GPIOF_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOG:
				{
					*ARG_pu8Value =((GPIOG_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				case GPIOH:
				{
					*ARG_pu8Value =((GPIOH_IDR>>ARG_udtGPIOPin)&1U);
					L_stderrorError=E_OK;
					break;
				}
				default :
				{
					/*nothing*/
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

STD_error_t MGPIO_stderrorSetPinValue
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPUT_State_t ARG_udtValue
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtValue <= 1)
	{
		switch(ARG_udtGPIOPort)
		{
			case GPIOA:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOB:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOC:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOD:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOE:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOF:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOG:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			case GPIOH:
			{
				GPIOA_ODR =(GPIOA_ODR&(~(1<<(ARG_udtGPIOPin))))|(ARG_udtValue<<(ARG_udtGPIOPin));
				L_stderrorError=E_OK;
				break;
			}
			default :
			{
				/*nothing*/
				break;
			}
			
		}
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
	
}


STD_error_t MGPIO_stderrorSetPinValueBSSR
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPUT_State_t ARG_udtValue
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtValue <= 1)
	{
		
		if(ARG_udtValue==LOW)
		{
			
			switch(ARG_udtGPIOPort)
			{
				case GPIOA:
				{
					GPIOA_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOB:
				{
					GPIOB_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOC:
				{
					GPIOC_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOD:
				{
					GPIOD_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOE:
				{
					GPIOE_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOF:
				{
					GPIOF_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOG:
				{
					GPIOG_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOH:
				{
					GPIOH_BSRR |=(1<<(ARG_udtGPIOPin+BSRR_OFFSET));
					L_stderrorError=E_OK;
					break;
				}
				default :
				{
					/*nothing*/
					break;
				}
				
			}
			
		}
		else
		{
			switch(ARG_udtGPIOPort)
			{
				case GPIOA:
				{
					GPIOA_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOB:
				{
					GPIOB_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOC:
				{
					GPIOC_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOD:
				{
					GPIOD_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOE:
				{
					GPIOE_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOF:
				{
					GPIOF_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOG:
				{
					GPIOG_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOH:
				{
					GPIOH_BSRR |=(1<<(ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				default :
				{
					/*nothing*/
					break;
				}
				
			}	
		}
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	return L_stderrorError;
}


STD_error_t MGPIO_stderrorPinLock
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 )
	{
	
		switch(ARG_udtGPIOPort)
		{
			case GPIOA:
			{
				GPIOA_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOA_LCKR = (GPIOA_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOA_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOA_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOB:
			{
				GPIOB_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOB_LCKR = (GPIOB_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOB_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOB_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOC:
			{
				GPIOC_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOC_LCKR = (GPIOC_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOC_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOC_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOD:
			{
				GPIOD_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOD_LCKR = (GPIOD_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOD_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOD_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOE:
			{
				GPIOE_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOE_LCKR = (GPIOE_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOE_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOE_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOF:
			{
				GPIOF_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOF_LCKR = (GPIOF_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOF_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOF_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOG:
			{
				GPIOG_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOG_LCKR = (GPIOG_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOG_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOG_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			case GPIOH:
			{
				GPIOH_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				GPIOH_LCKR = (GPIOH_LCKR&(~(1<<(LCKK))))|(1<<(ARG_udtGPIOPin));
				GPIOH_LCKR |= ((1U <<LCKK))|((1U <<ARG_udtGPIOPin));
				if(((GPIOH_LCKR >> LCKK )&1) != 0)
				{
					L_stderrorError=E_LOCK;
					
				}
				else
				{
					L_stderrorError=E_UNLOCK;
					
				}
				break;
			}
			default :
			{
				/*nothing*/
				break;
			}
			
		}
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;	
	
}

STD_error_t MGPIO_stderrorSetPinAltFun
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin,
	MGPIO_ALT_Mode_t ARG_udtAltPinMode
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_udtGPIOPort <= 7 && ARG_udtGPIOPin <= 15 && ARG_udtAltPinMode <= 15)
	{
	
		if(ARG_udtGPIOPin<=7)
		{
			
			switch(ARG_udtGPIOPort)
			{
				case GPIOA:
				{
					
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOB:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOC:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOD:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOE:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOF:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOG:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOH:
				{
					GPIOF_AFRL =(GPIOF_AFRL&(~(15U<<(4*ARG_udtGPIOPin))))|(ARG_udtAltPinMode<<(4*ARG_udtGPIOPin));
					L_stderrorError=E_OK;
					break;
				}
				default :
				{
					/*nothing*/
					break;
				}
			}
		}
		else
		{
			
			switch(ARG_udtGPIOPort)
			{
				case GPIOA:
				{
					
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOB:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOC:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOD:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOE:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOF:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOG:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				case GPIOH:
				{
					GPIOF_AFRH =(GPIOF_AFRH&(~(15U<<(4*(ARG_udtGPIOPin%8)))))|(ARG_udtAltPinMode<<(4*(ARG_udtGPIOPin%8)));
					L_stderrorError=E_OK;
					break;
				}
				default :
				{
					/*nothing*/
					break;
				}
			}
			
		}
		
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;	
}
