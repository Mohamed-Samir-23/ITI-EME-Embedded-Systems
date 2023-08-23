/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mohamed Samir
 */


/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"
#include<util/delay.h>
/* SWC Include */
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MTIM_interface.h"

int main (void)
{
	u8 L_u8ADCValue=0;
	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);
	MADC_stderrorInit(MADC_VREF_AVCC,MADC_PreScalar_128);
	MADC_voidSetTriggerSource(Free_Running_mode);
	MADC_voidEnableADC();
	MTIM_stderrorIint(MTIM_TIMER0,MTIM_CS_PRESCALAR_256,MTIM_MODE_PHASECORRECTPWM,MTIM_HWPIN_NOVINVERTING_PWM);
	MTIM_stderrorStartTimer(MTIM_TIMER0);
	while(1)
	{
		MADC_stderrorReadADC(&L_u8ADCValue,MADC_CHANNEL_ADC0);
		L_u8ADCValue=((L_u8ADCValue*15)/255)+16;
		MTIM_stderrorSetOCR(MTIM_TIMER0,L_u8ADCValue);
	}
	return 0;
}
