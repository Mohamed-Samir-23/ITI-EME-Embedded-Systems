/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 21, 2023	*/
/*  Last Edit	: August 23, 2023	*/
/************************************/



/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MADC_config.h"
#include "MADC_private.h"
#include "MADC_interface.h"


static u8 MADC_u8Resolution=0;

static void (*pvoidfNotificationFunctionADC)(void) =NULL_POINTER;

static u16* pu16ADCReading =NULL_POINTER;

static u8 MADC_u8BusyState=IDEL;

STD_error_t MADC_stderrorInit
(
	u8 ARG_u8RefVoltage, 
	u8 ARG_u8PreScalar,
	u16 ARG_u8Resolution
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if((ARG_u8RefVoltage>=0&&ARG_u8RefVoltage<=3)&&(ARG_u8PreScalar>=1&&ARG_u8PreScalar<=7)&&(ARG_u8Resolution==256||ARG_u8Resolution==1024))
	{
		
		MADC_ADMUX =(MADC_ADMUX&RefVoltage_MASK)|(ARG_u8RefVoltage<<REFS0);
		
		MADC_ADCSRA =(MADC_ADCSRA&PRESCALAR_MASK)|ARG_u8PreScalar;
		
		if(ARG_u8Resolution==256)
		{
			/*LEFT*/
			SET_BIT(MADC_ADMUX,ADLAR);
			MADC_u8Resolution=1;
		}
		else
		{
			/*RIGHT*/
			CLEAR_BIT(MADC_ADMUX,ADLAR);
			MADC_u8Resolution=2;
		}
		/*ENABLE ADC*/
		SET_BIT(MADC_ADCSRA,ADEN);
		L_stderrorError=E_OK;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}



STD_error_t	MADC_stderrorStartConversionSync
(
	u16* ARG_u16pADCReading,
	u8 ARG_u8Channel
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(MADC_u8BusyState==IDEL)
	{
		MADC_u8BusyState=BUSY;
		
		if((ARG_u8Channel>=0&&ARG_u8Channel<=31)&&(MADC_u8Resolution==1||MADC_u8Resolution==2)&&(ARG_u16pADCReading!=NULL_POINTER))
		{
			u32 L_u8TimeOutCounter =0;
			MADC_ADMUX=(MADC_ADMUX&CHANNEL_MASK)|ARG_u8Channel;
			
			SET_BIT(MADC_ADCSRA,ADSC);
			
			while(((GET_BIT(MADC_ADCSRA,ADIF))==0)&&(L_u8TimeOutCounter!=MADC_TIMEOUT))
			{
				
				L_u8TimeOutCounter++;
			}
			
			if(L_u8TimeOutCounter==MADC_TIMEOUT)
			{
				
				L_stderrorError=E_TIME_OUT;
			
			}
			else
			{
				
				SET_BIT(MADC_ADCSRA,ADIF);
			
				if(1==MADC_u8Resolution)
				{
					
					*ARG_u16pADCReading=ADCH_REG;
					
				}
				else
				{
					*ARG_u16pADCReading=ADCLH_REG;	
				}
				
				MADC_u8BusyState=IDEL;
				
				L_stderrorError=E_OK;		
			}
		}
		else
		{
			if(ARG_u16pADCReading==NULL_POINTER)
			{
				
				L_stderrorError=E_NULL_POINTER;
			}
			else
			{
				L_stderrorError=E_NOK;
			}
			
		}
	}
	else
	{
		
		L_stderrorError =E_BUSY_FUNCTION;
		
	}
	
	return L_stderrorError;	
}

STD_error_t	MADC_stderrorStartConversionASync
(
	u16* ARG_u16pADCReading,
	void (*ARG_pvoidfNotificationFunction)(void),
	u8 ARG_u8Channel
)
{
	STD_error_t L_stderrorError=E_NOK;
	
	if(MADC_u8BusyState==IDEL)
	{
		
		MADC_u8BusyState=BUSY;
		if((ARG_pvoidfNotificationFunction!=NULL_POINTER)&&(ARG_u16pADCReading!=NULL_POINTER))
		{
			
			if((ARG_u8Channel>=0&&ARG_u8Channel<=31))
			{
				pvoidfNotificationFunctionADC=ARG_pvoidfNotificationFunction;
				pu16ADCReading=ARG_u16pADCReading;
				
				MADC_ADMUX=(MADC_ADMUX&CHANNEL_MASK)|ARG_u8Channel;
				SET_BIT(MADC_ADCSRA,ADSC);
				SET_BIT(MADC_ADCSRA,ADIE);
				L_stderrorError=E_OK;
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
	}
	else
	{
		
		L_stderrorError =E_BUSY_FUNCTION;
		
	}
	return L_stderrorError;	
}



void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	
	if((pvoidfNotificationFunctionADC!=NULL_POINTER)&&(pu16ADCReading!=NULL_POINTER))
	{
		if(1==MADC_u8Resolution)
		{
			*pu16ADCReading=ADCH_REG;
		}
		else
		{
			*pu16ADCReading=ADCLH_REG;	
		}
		
		MADC_u8BusyState=IDEL;
		
		pvoidfNotificationFunctionADC();
		
		/*disable Interrupt*/
		CLEAR_BIT(MADC_ADCSRA,ADIE);
	}
	else
	{
		
		/*Nothing*/
		
	}
	
}