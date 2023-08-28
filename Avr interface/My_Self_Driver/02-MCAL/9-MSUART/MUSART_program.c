/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MUSART			*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 27, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"

/* SWC Include */
#include "MUSART_private.h"
#include "MUSART_config.h"
#include "MUSART_interface.h"

static u8 MUSART_u8SendBusyState=MUSART_IDEL;

static u8 MUSART_u8ReadBusyState=MUSART_IDEL;

static u8 MUSART_DataBit=20;


static void (*MUSART_pvoidfSendNotificationFunction)(void) =NULL_POINTER;

static void (*MUSART_pvoidfReceiveNotificationFunction)(void) =NULL_POINTER;

static u16* MUSART_pu16Reading =NULL_POINTER;

static u16 MUSART_pu16DataTSoend=0;




STD_error_t MUSART_stderrorInit
(
	u8 ARG_u8USARTEnableMode,
	u8 ARG_u8CommunicationTerminal,
	u8 ARG_u8CommunicationMode,
	u8 ARG_u8InterruptSource,
	u8 ARG_u8DataFrame,
	u8 ARG_u8ParityFrame,
	u8 ARG_u8StopFrame,
	u8 ARG_ClockPolarity,
	u16 ARG_u16BaudRate
)
{
	
	STD_error_t L_stderrorError=E_NOK;

	if((ARG_u8USARTEnableMode<=3)&&(ARG_u8CommunicationTerminal<=1)&&(ARG_u8CommunicationMode<=2)&&(ARG_u8InterruptSource<=7)&&(ARG_u8DataFrame<=3||ARG_u8DataFrame==7)&&(ARG_u8ParityFrame<=3&&ARG_u8ParityFrame!=1)&&(ARG_u8StopFrame<=1)&&(ARG_ClockPolarity<=1))
	{
		f32 UBRR=0;

		/*CommunicationTerminal*/
		MUSART_UCSRA=(MUSART_UCSRA&COMMUNICATIONTERMINALFLAG)|ARG_u8CommunicationTerminal;
		
		/*CommunicationMode*/
		switch(ARG_u8CommunicationMode)
		{
			case MUSART_ASYNC_NORMAL_SPEED:
			case MUSART_ASYNC_DOUBLE_SPEED:
			{
				if(ARG_u8CommunicationMode==MUSART_ASYNC_NORMAL_SPEED)
				{
					UBRR=((f32)F_CPU/(16.0*ARG_u16BaudRate))-0.5; /*add .5 to make 11.9 +.5 = 12.4 and if 11.4 +.5 = 11 so -1+.5=-.5*/
				}
				else
				{
					UBRR=((f32)F_CPU/(8.0*ARG_u16BaudRate))-0.5;
				}
				SET_BIT(MUSART_UCSRC,MUSART_URSEL);
				CLEAR_BIT(MUSART_UCSRC,MUSART_UMSEL);
				MUSART_UCSRA=(MUSART_UCSRA&COMMUNICATIONMODEFLAG)|(ARG_u8CommunicationMode<<MUSART_U2X);
				break;
			}
			case MUSART_SYNC:
			{
				SET_BIT(MUSART_UCSRC,MUSART_URSEL);
				SET_BIT(MUSART_UCSRC,MUSART_UMSEL);
				UBRR=((f32)F_CPU/(2.0*ARG_u16BaudRate))-0.5;
				break;
			}
			default:break;
		}
		
		/*InterruptSource*/
		MUSART_UCSRB=(MUSART_UCSRB&INTERRUPTSOURCEFLAG)|(ARG_u8InterruptSource<<MUSART_UDRIE);
		
		/*DataFrame-ParityFrame-StopFrame*/
		MUSART_UCSRC=(1<<MUSART_URSEL)|(MUSART_UCSRC&UCSRCFRAMEFLAG)|((ARG_u8DataFrame&ARGDATAFRAMEFLAG1)<<MUSART_UCSZ0)|(ARG_u8ParityFrame<<MUSART_UPM0)|(ARG_u8StopFrame<<MUSART_USBS)|ARG_ClockPolarity;
		MUSART_UCSRB=(MUSART_UCSRB&DATAFRAMEFLAG)|(ARG_u8DataFrame&ARGDATAFRAMEFLAG2);
		MUSART_DataBit=ARG_u8DataFrame;
		MUSART_UBRRH=(u8)((((u16)UBRR)>>8)&BaudRateFLAG);
		
		MUSART_UBRRL =(u8)UBRR;
		
		/*EnableMode*/
		MUSART_UCSRB=(MUSART_UCSRB&ENABLEMODEFLAG)|(ARG_u8USARTEnableMode<<MUSART_TXEN);
			
		L_stderrorError=E_OK;
		
	}
	else
	{
		
		L_stderrorError=E_NOK;

	
	}	
	
	return L_stderrorError;
	
}



STD_error_t	MUSART_stderrorSendDataSync
(
	u16 ARG_u16Data
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	u32 L_u8TimeOutCounter =0;
	
	while((GET_BIT(MUSART_UCSRA,MUSART_UDRE)==0)&&(L_u8TimeOutCounter!=MUSART_TIMEOUT))
	{
		
		L_u8TimeOutCounter++;
		
	}
	
	if(L_u8TimeOutCounter==MUSART_TIMEOUT)
	{
		L_stderrorError=E_TIME_OUT;
	}
	else
	{
		
		if(MUSART_DataBit==MUSART_9BIT_DATA)
		{
			
			MUSART_UCSRB=(MUSART_UCSRB&ARGDATAFRAMEFLAG3)|GET_BIT(ARG_u16Data,8);
			
			MUSART_UDR|=(u8)ARG_u16Data;
			
			L_stderrorError=E_NOK;
			
		}
		else if(MUSART_DataBit<=3)
		{
			
			MUSART_UDR=(u8)ARG_u16Data;
			
			L_stderrorError=E_NOK;
			
		}
		else
		{
			
			L_stderrorError=E_NOK;
			
		}
		
		
		
	}
	
	return L_stderrorError;
}



STD_error_t	MUSART_stderrorSendDataASync
(
	u16 ARG_u16Data,
	void (*ARG_pvoidfNotificationFunction)(void)
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(MUSART_u8SendBusyState==MUSART_IDEL)
	{
		if(ARG_pvoidfNotificationFunction!=NULL_POINTER)
		{
			MUSART_u8SendBusyState=MUSART_BUSY;
			
			MUSART_pu16DataTSoend=ARG_u16Data;
			
			MUSART_pvoidfSendNotificationFunction=ARG_pvoidfNotificationFunction;
			
			SET_BIT(MUSART_UCSRB, MUSART_UDRIE);
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




STD_error_t	MUSART_stderrorReadDataSync
(
	u16* ARG_u16Data
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u16Data!=NULL_POINTER)
	{
		u32 L_u8TimeOutCounter =0;
		
		while((GET_BIT(MUSART_UCSRA,MUSART_RXC)==0)&&(L_u8TimeOutCounter!=MUSART_TIMEOUT))
		{
			
			L_u8TimeOutCounter++;MUSART_UDR
			
		}
		
		if(L_u8TimeOutCounter==MUSART_TIMEOUT)
		{
			
			L_stderrorError=E_TIME_OUT;
			
		}
		else
		{
			if((GET_BIT(MUSART_UCSRA,MUSART_FE)==1))
			{
				L_stderrorError=E_FRAME;
			}
			else if(GET_BIT(MUSART_UCSRA,MUSART_DOR)==1)
			{
				L_stderrorError=E_OVERRUN;
			}
			else if(GET_BIT(MUSART_UCSRA,MUSART_PE)==1)
			{
				
				L_stderrorError=E_PARITY;
			}
			else
			{
				if(MUSART_DataBit==MUSART_9BIT_DATA)
				{
					*ARG_u16Data=0;
					
					*ARG_u16Data=(GET_BIT(MUSART_UCSRB,MUSART_RXB8)<<8);
					
					*ARG_u16Data|=(u16)MUSART_UDR;
					
					L_stderrorError=E_NOK;
					
				}
				else if(MUSART_DataBit<=3)
				{
					
					*ARG_u16Data=(u16)MUSART_UDR;
					
					L_stderrorError=E_NOK;
					
				}
				else
				{
					
					L_stderrorError=E_NOK;
					
				}
				
			}
			
		}
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	return L_stderrorError;
}



STD_error_t	MUSART_stderrorReadDataASync
(
	u16* ARG_u16Data,
	void (*ARG_pvoidfNotificationFunction)(void)
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(MUSART_u8ReadBusyState==MUSART_IDEL)
	{
		if(ARG_u16Data!=NULL_POINTER&&ARG_pvoidfNotificationFunction!=NULL_POINTER)
		{
			MUSART_u8ReadBusyState=MUSART_BUSY;
			
			MUSART_pvoidfReceiveNotificationFunction=ARG_pvoidfNotificationFunction;
			MUSART_pu16Reading=ARG_u16Data;
			SET_BIT(MUSART_UCSRB, MUSART_RXCIE);
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


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(MUSART_pu16Reading!=NULL_POINTER&&MUSART_pvoidfReceiveNotificationFunction!=NULL_POINTER)
	{
		MUSART_u8ReadBusyState=MUSART_IDEL;
		
		if((GET_BIT(MUSART_UCSRA,MUSART_FE)==1))
		{

		}
		else if(GET_BIT(MUSART_UCSRA,MUSART_DOR)==1)
		{

		}
		else if(GET_BIT(MUSART_UCSRA,MUSART_PE)==1)
		{
			

		}
		else
		{
			if(MUSART_DataBit==MUSART_9BIT_DATA)
			{
				*MUSART_pu16Reading=0;
				
				*MUSART_pu16Reading=(GET_BIT(MUSART_UCSRB,MUSART_RXB8)<<8);
				
				*MUSART_pu16Reading|=(u16)MUSART_UDR;

			}
			else if(MUSART_DataBit<=3)
			{
				*MUSART_pu16Reading=(u16)MUSART_UDR;
			}
			else
			{
				

				
			}
			
			MUSART_pvoidfReceiveNotificationFunction();
			/*disable Interrupt*/
			CLEAR_BIT(MUSART_UCSRB, MUSART_RXCIE);
			
		}	
	}
}


void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if(MUSART_pvoidfSendNotificationFunction!=NULL_POINTER)
	{
		MUSART_u8SendBusyState=MUSART_IDEL;
		if(MUSART_DataBit==MUSART_9BIT_DATA)
		{
			
			MUSART_UCSRB=(MUSART_UCSRB&ARGDATAFRAMEFLAG3)|GET_BIT(MUSART_pu16DataTSoend,8);
			
			MUSART_UDR|=(u8)MUSART_pu16DataTSoend;
				
		}
		else if(MUSART_DataBit<=3)
		{
			
			MUSART_UDR=(u8)MUSART_pu16DataTSoend;
			

			
		}
		else
		{
			

			
		}
		
		MUSART_pvoidfSendNotificationFunction();
		/*disable Interrupt*/
		CLEAR_BIT(MUSART_UCSRB, MUSART_UDRIE);
		
	}
}