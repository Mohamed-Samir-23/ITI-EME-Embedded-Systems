/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: DIO				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 3, 2023	*/
/*  Last Edit	: N/A				*/
/************************************/

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"

/* SWC Include */
#include "MDIO_private.h"
#include "MDIO_interface.h"


void MDIO_voidSetPortDirection
(
	u8 ARG_u8Port,
	u8 ARG_u8Direction
)
{
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->DDR=ARG_u8Direction;break;
		case MDIO_PORTB:GPIOB->DDR=ARG_u8Direction;break;
		case MDIO_PORTC:GPIOC->DDR=ARG_u8Direction;break;
		case MDIO_PORTD:GPIOD->DDR=ARG_u8Direction;break;
		default:/* MISRA RULES */break;
	}
}


void MDIO_voidSetPortValue
(
	u8 ARG_u8Port,
	u8 ARG_u8Value
)
{
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:GPIOA->PORT = ARG_u8Value ;break;
		case MDIO_PORTB:GPIOB->PORT = ARG_u8Value ;break;
		case MDIO_PORTC:GPIOC->PORT = ARG_u8Value ;break;
		case MDIO_PORTD:GPIOD->PORT = ARG_u8Value ;break;
		default:/* MISRA RULES */break;
	}
	
	
}


u8 MDIO_u8GetPortValue
(
	u8 ARG_u8Port
)
{
	u8 L_u8Value =0x00;
	switch(ARG_u8Port)
	{
		case MDIO_PORTA:L_u8Value = GPIOA->PIN ;break;
		case MDIO_PORTB:L_u8Value = GPIOB->PIN ;break;
		case MDIO_PORTC:L_u8Value = GPIOC->PIN ;break;
		case MDIO_PORTD:L_u8Value = GPIOD->PIN ;break;
		default:/* MISRA RULES */break;
	}
	return L_u8Value;
}
