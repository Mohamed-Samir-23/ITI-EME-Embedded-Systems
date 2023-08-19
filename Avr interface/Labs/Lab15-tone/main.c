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
#include "MTIM_interface.h"

void FrequencyGenerator(void);
u8 i=0;
u16 arrnote[]={196,196,220,196,247};

int main(void)
{

	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN3,MDIO_OUTPUT);
	MTIM_stderrorIint(MTIM_TIMER0,MTIM_CS_PRESCALAR_64,MTIM_MODE_CTC,MTIM_HWPIN_TOGGLE);
	MTIM_stderrorSetCallBack(MTIM_INTERRUPT_T0_OCM,FrequencyGenerator);
	MTIM_stderrorEnableInterrupt(MTIM_INTERRUPT_T0_OCM);
	MGIE_voidEnableGlobalInterrupt();
	MTIM_stderrorStartTimer(MTIM_TIMER0);

	while(1)
	{
		while(i<5)
		{
			MTIM_stderrorSetOCR(MTIM_TIMER0,arrnote[i]);
			_delay_ms(500);
			MTIM_stderrorSetOCR(MTIM_TIMER0,(250-(10*i)));
			_delay_ms(500);
			i++;
		}

		i=0;

		while(i<5)
		{
			MTIM_stderrorSetOCR(MTIM_TIMER0,arrnote[i]);
			_delay_ms(500);
			MTIM_stderrorSetOCR(MTIM_TIMER0,(80+(10*i)));
			_delay_ms(500);
			i++;
		}

		i=0;

		while(i<5)
		{
			MTIM_stderrorSetOCR(MTIM_TIMER0,arrnote[i]);
			_delay_ms(500);
			MTIM_stderrorSetOCR(MTIM_TIMER0,(255-(10*i)));
			_delay_ms(500);
			i++;
		}

		i=0;

	}
	return 0;
}



void FrequencyGenerator(void)
{

}


