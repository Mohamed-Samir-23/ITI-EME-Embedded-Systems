/************************************/
/*	Author	  :	Mohamed Samir		*/
/*	SWC		  : TWI					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	August 29, 2023		*/
/*	Last Edit :	N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MTWI_private.h"
#include "MTWI_interface.h"


static void (*MTWI_pvoidfUserFunction)();

STD_error_t MTWI_stderrorInit
(
	u32 ARG_u32DataRate, 
	u8 ARG_u8Prescalar
)
{
	STD_error_t L_stderrStat = E_OK ;
	switch(ARG_u8Prescalar)
	{
		case MTWI_PRESCALAR_1:  TWBR = (((F_CPU)/ARG_u32DataRate)-16)/(2*1);break;
		case MTWI_PRESCALAR_4:  TWBR = (((F_CPU)/ARG_u32DataRate)-16)/(2*4);break;
		case MTWI_PRESCALAR_16: TWBR = (((F_CPU)/ARG_u32DataRate)-16)/(2*16);break;
		case MTWI_PRESCALAR_64: TWBR = (((F_CPU)/ARG_u32DataRate)-16)/(2*64);break;
		default: L_stderrStat = E_NOK ; break;
	}
	if(ARG_u8Prescalar<=3)
	{
		TWSR = (TWSR & 0xFC) | (ARG_u8Prescalar) ;
	}
	else
	{
		L_stderrStat =E_NOK ;
	}	
	return  L_stderrStat ;
}

void MTWI_voidEnable
(
	void
)
{
	SET_BIT(TWCR, TWEN);
}
void MTWI_voidDisable
(
	void
)
{
	CLEAR_BIT(TWCR, TWEN);
}

void MTWI_voidEnableInterrupt
(
	void
)
{
	SET_BIT(TWCR, TWIE);
}

void MTWI_voidDisableInterrupt
(
	void
)
{
	CLEAR_BIT(TWCR, TWIE);
}

STD_error_t MTWI_stderrorSetcallback
(
	void(*ARG_pvoidfUserFunction)(void)
)
{
	STD_error_t L_stderrStat = E_OK ;
	if(ARG_pvoidfUserFunction != NULL_POINTER)
	{
		MTWI_pvoidfUserFunction =ARG_pvoidfUserFunction;
	}
	else{
		L_stderrStat = E_NULL_POINTER ;
	}
	return L_stderrStat;
}

void MTWI_voidStartCondition
(
	void
)
{
	TWCR = (TWCR & 0x5F) | (1<<TWINT)|(1<<TWSTA) ;
}

void MTWI_voidStopCondition
(
	void
)
{
	TWCR = (TWCR & 0x6F) | (1<<TWINT)|(1<<TWSTO) ;
}

void MTWI_voidEnableACK
(
	void
)
{
	SET_BIT(TWCR,TWEA);
}

void MTWI_voidDisableACK
(
	void
)
{
	CLEAR_BIT(TWCR,TWEA);
}

void MTWI_voidSetSlaveAddress
(
	u8 ARG_u8SlaveAddres
)
{
	TWAR = (TWAR & 0x01 ) |(ARG_u8SlaveAddres <<1) ;
}

void MTWI_voidEnableGennralCall
(
	void
)
{
	SET_BIT(TWAR,TWGCE);
}

void MTWI_voidDisableGennralCall
(
	void
)
{
	CLEAR_BIT(TWAR,TWGCE);
}

MTWI_status MTWI_twistatusCheckStatus
(
	void
)
{
	return (TWSR & TWS_MASK);  /* */
}

void MTWI_voidFlagPolly
(
	void
)
{
	while(!GET_BIT(TWCR,TWINT));
}

void MTWI_voidClearFlag
(
	void
)
{

	TWCR = (TWCR &0x4F) | (1<< TWINT );
}

void MTWI_voidLoadTWDR
(
	u8 ARG_u8Data
)
{
	TWDR = ARG_u8Data ;
}

char MTWI_charReadTWDR
(
	void
)
{
	return TWDR ;
}

void MTWI_voidSendChar
(
	u8 ARG_u8SlaveAddress, 
	char Arg_charChar
)
{
	MTWI_voidStartCondition();
	MTWI_voidFlagPolly();
	if(MTWI_twistatusCheckStatus()== MTWI_STATUS_MASTER_START_CONDITION )
	{
		MTWI_voidLoadTWDR(((ARG_u8SlaveAddress << 1) & (0xFE))|(0));
		MTWI_voidClearFlag();
		MTWI_voidFlagPolly();
		if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
		{
			MTWI_voidLoadTWDR(Arg_charChar);
			MTWI_voidClearFlag();
			MTWI_voidFlagPolly();
			if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
			{
				MTWI_voidStopCondition();
			}
		}
		else if(MTWI_STATUS_MASTER_TX_SLA_W_NACK ==  MTWI_twistatusCheckStatus())
		{
			MTWI_voidStopCondition();
		}
	}
	
}

void MTWI_voidSendMultipleChars
(
	u8 ARG_u8SlaveAddress,
	const char *ARG_ccharpChar
)
{
	MTWI_voidStartCondition();
	MTWI_voidFlagPolly();
	if(MTWI_twistatusCheckStatus()== MTWI_STATUS_MASTER_START_CONDITION )
	{
		MTWI_voidLoadTWDR(((ARG_u8SlaveAddress << 1) & (0xFE))|(0));
		MTWI_voidClearFlag();
		MTWI_voidFlagPolly();
		if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
		{
			u16 L_u16i =0 ;
			do
			{
				MTWI_voidLoadTWDR(ARG_ccharpChar[L_u16i]);
				MTWI_voidClearFlag();
				MTWI_voidFlagPolly();
				
			}while(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus() && ARG_ccharpChar[L_u16i] != '\0' );

			MTWI_voidStopCondition();

		}
		else if(MTWI_STATUS_MASTER_TX_SLA_W_NACK ==  MTWI_twistatusCheckStatus())
		{
			MTWI_voidStopCondition();
		}
	}
	
}

char MTWI_charSlaveReceive
(
	void
)
{
	u8 	L_u8DataReceive =0 ;
	MTWI_voidFlagPolly();
	if(MTWI_STATUS_SLAVE_RX_SLA_W_ACK ==  MTWI_twistatusCheckStatus())
	{
		MTWI_voidClearFlag();
		MTWI_voidFlagPolly();
		if(MTWI_STATUS_SLAVE_RX_SLA_W_DATA_ACK ==  MTWI_twistatusCheckStatus())
		{
			L_u8DataReceive =MTWI_charReadTWDR();
			if(MTWI_STATUS_SLAVE_RX_STOP_RSTART ==  MTWI_twistatusCheckStatus())
			{
				MTWI_voidClearFlag();
			}

		}
	}
	return L_u8DataReceive ;
}
