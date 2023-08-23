/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 15, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MADC_config.h"
#include "MADC_private.h"
#include "MADC_interface.h"



STD_error_t MADC_stderrorInit
(
	u8 ARG_u8RefVoltage, 
	u8 ARG_u8PreScalar
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(((ARG_u8RefVoltage>=1)&&(ARG_u8RefVoltage<=3))&&((ARG_u8PreScalar>=1)&&(ARG_u8PreScalar<=7)))
	{
		
		switch(ARG_u8PreScalar)
		{
			case MADC_PreScalar_2   : ADPS2=0;ADPS1=0;ADPS0=1;L_stderrorError = E_OK;break;
			case MADC_PreScalar_4   : ADPS2=0;ADPS1=1;ADPS0=0;L_stderrorError = E_OK;break;
			case MADC_PreScalar_8   : ADPS2=0;ADPS1=1;ADPS0=1;L_stderrorError = E_OK;break;
			case MADC_PreScalar_16  : ADPS2=1;ADPS1=0;ADPS0=0;L_stderrorError = E_OK;break;
			case MADC_PreScalar_32  : ADPS2=1;ADPS1=0;ADPS0=1;L_stderrorError = E_OK;break;
			case MADC_PreScalar_64  : ADPS2=1;ADPS1=1;ADPS0=0;L_stderrorError = E_OK;break;
			case MADC_PreScalar_128 : ADPS2=1;ADPS1=1;ADPS0=1;L_stderrorError = E_OK;break;
			default :L_stderrorError=E_NOK;break;
		}
		
		
		switch(ARG_u8RefVoltage)
		{
			
			case MADC_VREF_AREF  : REFS0=0;REFS0=0;L_stderrorError = E_OK;break;
			case MADC_VREF_AVCC  : REFS0=0;REFS0=1;L_stderrorError = E_OK;break;
			case MADC_VREF_2_56V : REFS0=1;REFS0=1;L_stderrorError = E_OK;break;
			default :L_stderrorError=E_NOK;break;
		}
		
		ADLAR=MADC_Enable;
		
	}
	
	return L_stderrorError;
	
}

void MADC_voidEnableADC
(
	void
)
{
	
	ADEN=MADC_Enable;
}

void MADC_voidDisableADC
(
	void
)
{
	
	ADEN=MADC_Disable;
}

void MADC_voidEnableInterrupt
(
	void
)
{
	
	ADIE=MADC_Enable;
}

void MADC_voidDisableInterrupt
(
	void
)
{
	
	ADIE=MADC_Disable;
}

STD_error_t	MADC_stderrorStartConversion
(
	u8 ARG_u8Channel
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	
	if(ARG_u8Channel>=1&&ARG_u8Channel<=31)
	{

		switch(ARG_u8Channel)
		{
			case MADC_CHANNEL_ADC0 : MUX4=0;MUX3=0;MUX2=0;MUX1=0;MUX0=0;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC1 : MUX4=0;MUX3=0;MUX2=0;MUX1=0;MUX0=1;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC2 : MUX4=0;MUX3=0;MUX2=0;MUX1=1;MUX0=0;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC3 : MUX4=0;MUX3=0;MUX2=0;MUX1=1;MUX0=1;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC4 : MUX4=0;MUX3=0;MUX2=1;MUX1=0;MUX0=0;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC5 : MUX4=0;MUX3=0;MUX2=1;MUX1=0;MUX0=1;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC6 : MUX4=0;MUX3=0;MUX2=1;MUX1=1;MUX0=0;L_stderrorError = E_OK;break;
			case MADC_CHANNEL_ADC7 : MUX4=0;MUX3=0;MUX2=1;MUX1=1;MUX0=1;L_stderrorError = E_OK;break;
			default:L_stderrorError=E_NOK;break;
		}
		
		ADSC=MADC_Enable;
	}
	else
	{
		L_stderrorError=E_NOK;
	}
	
	return L_stderrorError;
}

void MADC_voidFlagPolling
(
	void
)
{
	
	while(!ADIF);
}

void MADC_voidClearFlag
(
	void
)
{
	ADIF=MADC_Enable;
}

STD_error_t	MADC_stderrorReadADC
(
	u8* ARG_u8pADCReading,
	u8 ARG_u8Channel
)
{
	
	STD_error_t L_stderrorError=E_NOK;
	if(ARG_u8pADCReading!=NULL_POINTER)
	{
		MADC_stderrorStartConversion(ARG_u8Channel);
		MADC_voidFlagPolling();
		MADC_voidClearFlag();
		*ARG_u8pADCReading=ADCH_REG;
		L_stderrorError = E_OK;
	}
	else
	{
		L_stderrorError=E_NULL_POINTER;
	}
	
	return L_stderrorError;
}



STD_error_t MADC_voidSetTriggerSource
(
	u8 ARG_u8TriggerMode
)
{
	STD_error_t L_stderrorError=E_NOK;
	switch(ARG_u8TriggerMode)
	{
	case Free_Running_mode             :ADTS2 =0;ADTS1=0;ADTS0 =0;L_stderrorError = E_OK;break;
	case Analog_Comparator             :ADTS2 =0;ADTS1=0;ADTS0 =1;L_stderrorError = E_OK;break;
	case External_Interrupt_Request    :ADTS2 =0;ADTS1=1;ADTS0 =0;L_stderrorError = E_OK;break;
	case Timer_Counter0_Compare_Match  :ADTS2 =0;ADTS1=1;ADTS0 =1;L_stderrorError = E_OK;break;
	case Timer_Counter0_Overflow       :ADTS2 =1;ADTS1=0;ADTS0 =0;L_stderrorError = E_OK;break;
	case Timer_Counter1_Compare_MatchB :ADTS2 =1;ADTS1=0;ADTS0 =1;L_stderrorError = E_OK;break;
	case Timer_Counter1_Overflow       :ADTS2 =1;ADTS1=1;ADTS0 =0;L_stderrorError = E_OK;break;
	case Timer_Counter1_Capture_Event  :ADTS2 =1;ADTS1=1;ADTS0 =1;L_stderrorError = E_OK;break;
	default :L_stderrorError=E_NOK;break;
	}
	return L_stderrorError;
}
