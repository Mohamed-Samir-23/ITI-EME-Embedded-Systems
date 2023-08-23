/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MGIE				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 13, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"

/* SWC Include */
#include "MGIE_private.h"



void MGIE_voidEnableGlobalInterrupt(void)
{
	
	SET_BIT(MGIE_SREG,MGIE_IBIT);
	
}

void MGIE_voidDisableGlobalInterrupt(void)
{
	
	CLEAR_BIT(MGIE_SREG,MGIE_IBIT);
}