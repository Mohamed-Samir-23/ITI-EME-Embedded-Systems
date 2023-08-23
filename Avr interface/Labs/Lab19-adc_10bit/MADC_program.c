/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MADC				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 21, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MADC_config.h"
#include "MADC_private.h"
#include "MADC_interface.h"

static u8 MADC_u8Resolution=0;

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



STD_error_t	MADC_stderrorReadADC
(
	u16* ARG_u8pADCReading,
	u8 ARG_u8Channel
)
{

STD_error_t L_stderrorError=E_NOK;

if((ARG_u8Channel>=0&&ARG_u8Channel<=31)&&(MADC_u8Resolution==1||MADC_u8Resolution==2))
{

	MADC_ADMUX=(MADC_ADMUX&CHANNEL_MASK)|ARG_u8Channel;

	SET_BIT(MADC_ADCSRA,ADSC);

	while((GET_BIT(MADC_ADCSRA,ADIF))==0)
	{


	}


	SET_BIT(MADC_ADCSRA,ADIF);

	if(1==MADC_u8Resolution)
	{
		*ARG_u8pADCReading=ADCH_REG;
	}
	else
	{
		*ARG_u8pADCReading=ADCLH_REG;
//		MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN3,MDIO_OUTPUT);
//		MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN3,MDIO_HIGH);
	}
	L_stderrorError=E_OK;
}
else
{
	L_stderrorError=E_NOK;
}

return L_stderrorError;
}


