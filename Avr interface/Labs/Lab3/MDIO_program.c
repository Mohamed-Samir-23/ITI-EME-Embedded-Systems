/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: DIO				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.1				*/
/*  Date		: August 3, 2023	*/
/*  Last Edit	: August 3, 2023	*/
/************************************/


/* Library Include */
#include "LSTD_types.h"
#include "LBIT_math.h"



/* SWC Include */
#include "MDIO_private.h"
#include "MDIO_interface.h"


STD_error_t MDIO_stderrorSetPortDirection
(
	u8 ARG_u8Port,
	u8 ARG_u8Direction
)
{
	STD_error_t L_stderrorError=E_NOK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->DDR = ARG_u8Direction;L_stderrorError = E_OK;break;
		case MDIO_PORTB:GPIOB->DDR = ARG_u8Direction;L_stderrorError = E_OK;break;
		case MDIO_PORTC:GPIOC->DDR = ARG_u8Direction;L_stderrorError = E_OK;break;
		case MDIO_PORTD:GPIOD->DDR = ARG_u8Direction;L_stderrorError = E_OK;break;
		default:L_stderrorError = E_NOK;break;
	}
	return L_stderrorError;
}


STD_error_t MDIO_voidSetPortValue
(
	u8 ARG_u8Port,
	u8 ARG_u8Value
)
{
	STD_error_t L_stderrorError=E_NOK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT = ARG_u8Value;L_stderrorError = E_OK;break;
		case MDIO_PORTB:GPIOB->PORT = ARG_u8Value;L_stderrorError = E_OK;break;
		case MDIO_PORTC:GPIOC->PORT = ARG_u8Value;L_stderrorError = E_OK;break;
		case MDIO_PORTD:GPIOD->PORT = ARG_u8Value;L_stderrorError = E_OK;break;
		default:L_stderrorError = E_NOK;break;
	}
	return L_stderrorError;
}


STD_error_t MDIO_stderrorGetPortValue
(
	u8 ARG_u8Port,
	u8* ARG_pu8Value
)
{
	STD_error_t L_stderrorError=E_NOK;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA: *ARG_pu8Value= GPIOA->PIN;L_stderrorError = E_OK;break;
		case MDIO_PORTB: *ARG_pu8Value= GPIOB->PIN;L_stderrorError = E_OK;break;
		case MDIO_PORTC: *ARG_pu8Value= GPIOC->PIN;L_stderrorError = E_OK;break;
		case MDIO_PORTD: *ARG_pu8Value= GPIOD->PIN;L_stderrorError = E_OK;break;
		default:L_stderrorError = E_NOK;break;
	}
	return L_stderrorError;
}

STD_error_t MDIO_stderrorSetPinDirection
(
	u8 ARG_u8Port,
	u8 ARG_u8pin,
	MDIO_mode ARG_u8Mode
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	if ((ARG_u8pin>=0)&&(ARG_u8pin<=7))
	{
		if(ARG_u8Mode==MDIO_INPUT_FLOAT)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:CLEAR_BIT(GPIOA->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTB:CLEAR_BIT(GPIOB->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTC:CLEAR_BIT(GPIOC->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTD:CLEAR_BIT(GPIOD->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				default:L_stderrorError = E_NOK;break;
			}
		}
		else if(ARG_u8Mode==MDIO_OUTPUT)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:SET_BIT(GPIOA->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTB:SET_BIT(GPIOB->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTC:SET_BIT(GPIOC->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTD:SET_BIT(GPIOD->DDR, ARG_u8pin);L_stderrorError = E_OK;break;
				default:L_stderrorError = E_NOK;break;
			}
		}
		else if(ARG_u8Mode==MDIO_INPUT_PULLUP)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:CLEAR_BIT(GPIOA->DDR, ARG_u8pin);SET_BIT(GPIOA->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTB:CLEAR_BIT(GPIOB->DDR, ARG_u8pin);SET_BIT(GPIOB->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTC:CLEAR_BIT(GPIOC->DDR, ARG_u8pin);SET_BIT(GPIOC->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTD:CLEAR_BIT(GPIOD->DDR, ARG_u8pin);SET_BIT(GPIOD->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				default:L_stderrorError = E_NOK;break;
			}
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
	
	return L_stderrorError;
}

STD_error_t MDIO_stderrorSetPinValue
(
	u8 ARG_u8Port,
	u8 ARG_u8pin,
	u8 ARG_u8Value
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	if ((ARG_u8pin>=0)&&(ARG_u8pin<=7))
	{
		if(ARG_u8Value==MDIO_HIGH)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:SET_BIT(GPIOA->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTB:SET_BIT(GPIOB->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTC:SET_BIT(GPIOC->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTD:SET_BIT(GPIOD->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				default:L_stderrorError = E_NOK;break;
			}
		}
		else if(ARG_u8Value==MDIO_LOW)
		{
			switch(ARG_u8Port)
			{
				case MDIO_PORTA:CLEAR_BIT(GPIOA->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTB:CLEAR_BIT(GPIOB->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTC:CLEAR_BIT(GPIOC->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				case MDIO_PORTD:CLEAR_BIT(GPIOD->PORT, ARG_u8pin);L_stderrorError = E_OK;break;
				default:L_stderrorError = E_NOK;break;
			}
		}
			
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	return L_stderrorError;
}

STD_error_t MDIO_stderrorGetPinValue
(
	u8 ARG_u8Port,
	u8 ARG_u8pin,
	u8* ARG_pu8Value
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_pu8Value==NULL_POINTER)
	{
		L_stderrorError=E_NULL_POINTER;
	}
	else if ((ARG_u8pin>=0)&&(ARG_u8pin<=7))
	{
		switch(ARG_u8Port)
		{
			case MDIO_PORTA: *ARG_pu8Value= GET_BIT(GPIOA->PIN, ARG_u8pin);L_stderrorError = E_OK;break;
			case MDIO_PORTB: *ARG_pu8Value= GET_BIT(GPIOB->PIN, ARG_u8pin);L_stderrorError = E_OK;break;
			case MDIO_PORTC: *ARG_pu8Value= GET_BIT(GPIOC->PIN, ARG_u8pin);L_stderrorError = E_OK;break;
			case MDIO_PORTD: *ARG_pu8Value= GET_BIT(GPIOD->PIN, ARG_u8pin);L_stderrorError = E_OK;break;
			default:L_stderrorError = E_NOK;break;
		}
	}
	else
	{
		
		L_stderrorError=E_NOK;
		
	}
	
	return L_stderrorError;
}
