/************************************/
/*	Author	  :	Mostafa Tawfik		*/
/*	SWC		  : TWI					*/
/*  Layer	  : MCAL				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	August 29, 2023		*/
/*	Last Edit :	N/A					*/
/************************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MTWI_interface.h"

#include "HNVM_config.h"
#include "HNVM_private.h"
#include "HNVM_interface.h"


STD_error_t HNVM_stderrInit(void)
{
	STD_error_t L_stderrStat = E_OK ;
	L_stderrStat = MTWI_stderrInit(HNVM_BIT_RATE ,HNVM_PRESCALAR);
	MTWI_voidEnable();
	return L_stderrStat ;
}

void HNVM_voidWrite(u16 ARG_u16Address , u8 ARG_u8Data)
{
	u8 L_u8SlaveAddress , L_u8Block ;
	L_u8Block = ARG_u16Address >> 8 ; /* */
	L_u8SlaveAddress = (0b1010000) | (L_u8Block) ;
	MTWI_voidStartCondition();
	MTWI_voidFlagPolly();
	if(MTWI_twistatusCheckStatus()== MTWI_STATUS_MASTER_START_CONDITION )
	{
		MTWI_voidLoadTWDR(((L_u8SlaveAddress << 1) & (0xFE))|(0));
		MTWI_voidClearFlag();
		MTWI_voidFlagPolly();
		if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
		{
			MTWI_voidLoadTWDR((u8)ARG_u16Address);
			MTWI_voidClearFlag();
			MTWI_voidFlagPolly();
			
			if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
			{
				MTWI_voidLoadTWDR(ARG_u8Data);
				MTWI_voidClearFlag();
				MTWI_voidFlagPolly();
				if(MTWI_STATUS_MASTER_TX_DATA_ACK == MTWI_twistatusCheckStatus())
				{
					MTWI_voidStopCondition();
				}
			}
		}
		else if(MTWI_STATUS_MASTER_TX_SLA_W_NACK ==  MTWI_twistatusCheckStatus())
		{
			MTWI_voidStopCondition();
		}
	}
	
	
}

u8 	HNVM_u8Read(u16 ARG_u16Address)
{
	u8 L_u8SlaveAddress , L_u8Block  , L_u8Data;
	L_u8Block = ARG_u16Address >> 8 ; /* */
	L_u8SlaveAddress = (0b1010000) | (L_u8Block) ;
	MTWI_voidStartCondition();
	MTWI_voidFlagPolly();
	if(MTWI_twistatusCheckStatus()== MTWI_STATUS_MASTER_START_CONDITION )
	{
		MTWI_voidLoadTWDR(((L_u8SlaveAddress << 1) & (0xFE))|(0));
		MTWI_voidClearFlag();
		MTWI_voidFlagPolly();
		if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
		{
			MTWI_voidLoadTWDR((u8)ARG_u16Address);
			MTWI_voidClearFlag();
			MTWI_voidFlagPolly();
			if(MTWI_STATUS_MASTER_TX_SLA_W_ACK == MTWI_twistatusCheckStatus())
			{
				MTWI_voidStartCondition();
				MTWI_voidFlagPolly();
				if(MTWI_twistatusCheckStatus()== MTWI_STATUS_MASTER_RSTART_CONDITION )
				{
					MTWI_voidLoadTWDR(((L_u8SlaveAddress << 1) & (0xFE))|(1));
					MTWI_voidClearFlag();
					MTWI_voidFlagPolly();
					if(MTWI_STATUS_MASTER_RX_SLA_R_ACK == MTWI_twistatusCheckStatus())
					{
						MTWI_voidClearFlag();
						MTWI_voidFlagPolly();
						if(MTWI_STATUS_MASTER_RX_DATA_NACK == MTWI_twistatusCheckStatus())
						{
							L_u8Data = MTWI_charReadTWDR();
							MTWI_voidStopCondition();
						}
					}
				}
			}
		}
	}
	return L_u8Data ;
}