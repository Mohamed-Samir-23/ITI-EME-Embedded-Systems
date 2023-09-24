/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: UART					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: August 24,2023		*/
/*  Last Edit	: N/A					*/
/****************************************/

#include"LBIT_math.h"
#include"LSTD_types.h"

#include"MUART_interface.h"
#include"MUART_private.h"

void (*MUART_pvoidfUserFunctionRxC)(void) = NULL_POINTER;
void (*MUART_pvoidfUserFunctionTxC)(void) = NULL_POINTER;
void (*MUART_pvoidfUserFunctionUDREmpty)(void) = NULL_POINTER;

STD_error_t  MUART_stderrorInit(u32 ARG_u32BaudRate, u8 ARG_u8DataBits, u8 ARG_u8Parity, u8 ARG_u8StopBits)
{
	STD_error_t L_stderrorState = E_OK;
	if(((ARG_u8DataBits<=3)||(ARG_u8DataBits ==7))&&((0 == ARG_u8Parity)||(32 == ARG_u8Parity)||(48 == ARG_u8Parity))&&((0 == ARG_u8StopBits)||(8 == ARG_u8StopBits)))
	{
		u16 UBRR = (F_CPU/(16*ARG_u32BaudRate))-1;
		UBRRL=(u8)UBRR;
		UBRRH=(u8)((UBRR>>8) & 0x0F);
		UCSRB = (UCSRB & 0xFB) | (ARG_u8DataBits & 0x04);
		UCSRC = (1<<URSEL)|((UCSRC&0xC1)|((ARG_u8DataBits&0x03)<<1)|ARG_u8Parity|ARG_u8StopBits);
	}
	else
	{
		L_stderrorState = E_NOK;
	}
	return L_stderrorState;
}

void  MUART_voidEnableTx(void)
{
	SET_BIT(UCSRB, TXEN);
}

void  MUART_voidDisableTx(void)
{
	MUART_voidTxFlagPolling();
	CLEAR_BIT(UCSRB, TXEN);
}

void  MUART_voidEnableRx(void)
{
	SET_BIT(UCSRB, RXEN);
}

void  MUART_voidDisableRx(void)
{
	CLEAR_BIT(UCSRB, RXEN);
}

void MUART_voidTxFlagPolling(void)
{
	while(!GET_BIT(UCSRA,TXC));
}

void MUART_voidRxFlagPolling(void)
{
	while(!GET_BIT(UCSRA,RXC));
}

void MUART_voidUDREFlagPolling(void)
{
	while(!GET_BIT(UCSRA,UDRE));
}

void MUART_voidSendChar(char ARG_charChar)
{
		MUART_voidUDREFlagPolling();
		UDR= ARG_charChar ;
}

void MUART_voidSendString(const char* ARG_ccharpSrring)
{
	u32 L_u32i = 0 ;
	do
	{
		MUART_voidSendChar(ARG_ccharpSrring[L_u32i]);
		L_u32i++;
	}while(ARG_ccharpSrring[L_u32i] != '\0');
}

char MUART_charReceiveChar(void)
{
	MUART_voidRxFlagPolling();
	return UDR ;
}

void MUART_voidRecieveStringUntil(char* ARG_charpString , char ARG_charTerminnator)
{
	u32 L_u32i = 0;
	do
	{
		ARG_charpString[L_u32i] = MUART_charReceiveChar();
		L_u32i++;
	}while(ARG_charpString[L_u32i - 1] != ARG_charTerminnator);
	ARG_charpString[L_u32i - 1]  = '\0';
}

STD_error_t MUART_stderrorEnableInterrupt(u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrorState = E_OK;
	if((ARG_u8InterruptSource >= 5)&&(ARG_u8InterruptSource <= 7))
	{
		SET_BIT(UCSRB , ARG_u8InterruptSource);
	}
	else
	{
		L_stderrorState = E_NOK;
	}
	return L_stderrorState;
}

STD_error_t MUART_stderrorDisableInterrupt(u8 ARG_u8InterruptSource);
{
	STD_error_t L_stderrorState = E_OK;
	if((ARG_u8InterruptSource >= 5)&&(ARG_u8InterruptSource <= 7))
	{
		CLEAR_BIT(UCSRB , ARG_u8InterruptSource);
	}
	else
	{
		L_stderrorState = E_NOK;
	}
	return L_stderrorState;
}

STD_error_t MUART_stderrorSetCallbavk(void (*ARG_pvoidfUserFunction)(void), u8 ARG_u8InterruptSource)
{
	STD_error_t L_stderrorState = E_OK;
	switch( ARG_u8InterruptSource )
	{
		case MUART_INTERRUPT_RXC : MUART_pvoidfUserFunctionRxC = ARG_pvoidfUserFunction; break;
		case MUART_INTERRUPT_TXC : MUART_pvoidfUserFunctionTxC = ARG_pvoidfUserFunction; break;
		case MUART_INTERRUPT_UDR_EMPTY : MUART_pvoidfUserFunctionUDREmpty = ARG_pvoidfUserFunction; break;
		default: L_stderrorState = E_NOK; break;
	}
	return L_stderrorState;
}

void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
	(*MUART_pvoidfUserFunctionRxC)();
}

void __vector_14(void)  __attribute__((signal));
void __vector_14(void)
{
	(*MUART_pvoidfUserFunctionUDREmpty)();
}

void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{
	(*MUART_pvoidfUserFunctionTxC)();
}
