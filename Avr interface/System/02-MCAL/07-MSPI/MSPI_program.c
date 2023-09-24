/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: SPI					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: August 27,2023 		*/
/*  Last Edit	: N/A					*/
/****************************************/

#include"LBIT_math.h"
#include"LSTD_typeS.h"

#include"MSPI_private.h"
#include"MSPI_interface.h"

static void  (*MSPI_pvoidfUserFunction)(void) = NULL_POINTER;

STD_error_t MSPI_stderrorInti(u8 ARG_u8Mode, u8 ARG_u8ClockPolPha, u8 ARG_u8DataOrder, u8 ARG_u8PreScalar)
{
	STD_error_t L_stderrorState = E_OK;
	if(((0 == ARG_u8Mode)||(16 == ARG_u8Mode))&&((0 == ARG_u8ClockPolPha)||(4 == ARG_u8ClockPolPha)||(8 == ARG_u8ClockPolPha)||(12 == ARG_u8ClockPolPha))&&((0 == ARG_u8DataOrder)||(32 == ARG_u8DataOrder))&&(ARG_u8PreScalar <= 6))
	{
		SPCR = (SPCR &0xC0)| ARG_u8Mode | ARG_u8ClockPolPha | ARG_u8DataOrder | (ARG_u8PreScalar & 0x03);
		SPSR = (SPSR &0xFE)| (ARG_u8PreScalar >> 2);
	}
	else
	{
		L_stderrorState = E_NOK;
	}
	return L_stderrorState;
}

void MSPI_voidEnable(void)
{
	SET_BIT(SPCR,SPE);
}

void MSPI_voidDisable(void)
{
	CLEAR_BIT(SPCR,SPE);
}

void MSPI_voidEnableInterrupt(void)
{
	SET_BIT(SPCR,SPIE);	
}

void MSPI_voidDisableInterrupt(void)
{
	CLEAR_BIT(SPCR,SPIE);
}

STD_error_t MSPI_stderrorSetCallback(void (*ARG_pvoidfUserFunction)(void))
{
	STD_error_t L_stderrorState = E_OK;
	if(ARG_pvoidfUserFunction != NULL_POINTER)
	{
		MSPI_pvoidfUserFunction = ARG_pvoidfUserFunction ;
	}
	else
	{
		L_stderrorState = E_NULL_POINTER;
	}
	return L_stderrorState ;
}

char MSPI_charTranceive(char ARG_charData)
{
	SPDR = ARG_charData;
	MSPI_voidFlagPolling();
	return SPDR ;
}

void MSPI_voidFlagPolling(void)
{
	while(!GET_BIT(SPSR,SPIF));
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	(*MSPI_pvoidfUserFunction)();
}
