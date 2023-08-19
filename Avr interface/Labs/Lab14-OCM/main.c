/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mohamed Samir
 */


/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include<util/delay.h>

/* SWC Include */
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MADC_interface.h"
#include "MTIM_interface.h"

void FrequencyGenerator(void);

int main(void)
{
	u8 L_u8ADCValue=0;
	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN7,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);
	MADC_stderrorInit(MADC_VREF_AVCC,MADC_PreScalar_2);
	MADC_voidSetTriggerSource(Free_Running_mode);
	MADC_voidEnableADC();
	MTIM_stderrorIint(MTIM_TIMER0,MTIM_CS_PRESCALAR_64,MTIM_MODE_CTC,MTIM_HWPIN_TOGGLE);
	MTIM_stderrorSetCallBack(MTIM_INTERRUPT_T0_OCM,FrequencyGenerator);
	MTIM_stderrorEnableInterrupt(MTIM_INTERRUPT_T0_OCM);
	MGIE_voidEnableGlobalInterrupt();
	MTIM_stderrorStartTimer(MTIM_TIMER0);

	while(1)
	{
		MADC_stderrorReadADC(&L_u8ADCValue,MADC_CHANNEL_ADC0);
		MTIM_stderrorSetOCR(MTIM_TIMER0,L_u8ADCValue);
		//MTIM_stderrorSetOCR(MTIM_TIMER0,250);
		//_delay_ms(1000);



	}
	return 0;
}



void FrequencyGenerator(void)
{

	volatile static u8 L_u8Flag=0;
	if(0==L_u8Flag)
	{

		MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN7,MDIO_LOW);
		L_u8Flag=1;
	}
	else
	{

		MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN7,MDIO_HIGH);
		L_u8Flag=0;

	}
}


