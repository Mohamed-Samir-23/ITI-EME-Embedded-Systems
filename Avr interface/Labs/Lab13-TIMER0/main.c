/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Mohamed Samir
 */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MTIM_interface.h"
void light (void);

int main(void)
{
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MTIM_stderrorIint(MTIM_TIMER0, MTIM_CS_PRESCALAR_1024, MTIM_MODE_NORMAL, MTIM_HWPIN_DISCONNECTED);
	MTIM_stderrorSetCallBack(MTIM_INTERRUPT_T0_OVF, light);
	MTIM_stderrorTimerDelay(MTIM_TIMER0,2000);
	MTIM_stderrorEnableInterrupt(MTIM_INTERRUPT_T0_OVF);
	MGIE_voidEnableGlobalInterrupt();
	MTIM_stderrorStartTimer(MTIM_TIMER0);
	while(1);
	return 0;
}


void light (void)
{

	volatile static u8 Flag=0;
	if(0==Flag)
	{
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_HIGH);
		Flag=1;
	}
	else if(1==Flag)
	{

		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
		Flag=0;
	}
	else
	{

	}

}
