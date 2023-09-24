/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MSPI				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 28, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"

/* SWC Include */

#include "MSPI_config.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

static u8 MSPI_u8ReadBusyState==MSPI_IDEL;

static void (*MSPI_pvoidfReceiveNotificationFunction)(void) =NULL_POINTER;

static u8* MSPI_pu8Reading =NULL_POINTER;

STD_error_t MSPI_stderrorError=E_NOK;


STD_error_t MUSART_stderrorInit
(
	u8 ARG_u8MEnableControl,
	u8 ARG_u8InterruptState,
	u8 ARG_u8Mode,
	u8 ARG_u8ClockMode,
	u8 ARG_u8DataOrder,
	u8 ARG_u8Freq
)
{
	STD_error_t L_stderrorError=E_NOK;
	if((ARG_u8MEnableControl<=1)&&(ARG_u8Mode<=1)&&(ARG_u8DataOrder<=1)&&(ARG_u8InterruptState<=1)&&(ARG_u8Freq<=6)&&(ARG_u8ClockMode<=3))
	{
		
		MSPI_SPSR=((ARG_u8Freq&0x04)<<MSPI_SPIF);
		MSPI_SPCR=(ARG_u8InterruptState<<MSPI_SPIE)|(ARG_u8MEnableControl<<MSPI_SPE)|(ARG_u8DataOrder<<MSPI_DORD)|(ARG_u8Mode<<MSPI_MSTR)|(ARG_u8ClockMode<<MSPI_CPHA)|((ARG_u8Freq&0x03)<<MSPI_SPR0);
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
}


u8 MSPI_ReadWrite_Sync
(
	u8  ARG_u8Data
)
{
	
	if(ARG_pu8Data!=NULL_POINTER)
	{
		MSPI_SPDR=ARG_pu8Data;
		u32 L_u8TimeOutCounter =0;
		
		if ( GET_BIT(MSPI_SPSR,MSPI_WCOL) == 1)
		{
			MSPI_stderrorError = E_WRITE_COLLISON;
		}
		else
		{
			MSPI_stderrorError = E_OK;
		}
		
		while((GET_BIT(MSPI_SPSR,MSPI_SPIF)==0)&&(L_u8TimeOutCounter!=MSPI_TIMEOUT))
		{
			//L_u8TimeOutCounter++;
		}
		
		if(L_u8TimeOutCounter==MSPI_TIMEOUT)
		{
			MSPI_stderrorError = E_TIME_OUT;
		}
		else
		{
			ARG_u8Data=MSPI_SPDR;
		}
		
	}
	else
	{

		MSPI_stderrorError=E_NULL_POI
		
	}
	
	return ARG_u8Data;
}

STD_error_t MSPI_ReadWrite_ASync
(
	u8 * ARG_pu8Data,
	void (*ARG_pvoidfNotificationFunction)(void)
)
{
	
	STD_error_t L_stderrorError=E_NOK;

	if(MSPI_u8ReadBusyState==MSPI_IDEL)
	{
		if(ARG_pu8Data!=NULL_POINTER&&ARG_pvoidfNotificationFunction!=NULL_POINTER)
		{
			MSPI_u8ReadBusyState=MUSART_BUSY;

			MSPI_pvoidfReceiveNotificationFunction=ARG_pvoidfNotificationFunction;
			
			MSPI_pu8Reading=ARG_pu8Data;
			
			/*enable interrupt*/
			SET_BIT(MSPI_SPCR, MSPI_SPIE);
		}
		else
		{
			L_stderrorError=E_NULL_POINTER;
		}

	}
	else
	{


		L_stderrorError =E_BUSY_FUNCTION;

	}


	return L_stderrorError;
	
}


void MSPI_voidSendString
(
	const char* ARG_ccharpString
)
{
	
	
	u32 L_u32i=0;
	do
	{
		
		MSPI_ReadWrite_Sync(ARG_ccharpString[L_u32i]);
		L_u32i++;
		
	}while(ARG_ccharpString[L_u32i]!='\0');
	
	
	
}



void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(MSPI_pvoidfReceiveNotificationFunction!=NULL_POINTER)
	{
		MUSART_u8SendBusyState=MUSART_IDEL;
		
		*MSPI_pu8Reading=MSPI_SPDR;
		
		MSPI_pvoidfReceiveNotificationFunction();
		
		/*disable Interrupt*/
		CLEAR_BIT(MSPI_SPCR, MSPI_SPIE);

	}
	else
	{
		
		/*nothing*/
		
	}
}