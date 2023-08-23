/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mohamed Samir
 */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MADC_interface.h"
#include "HLCD_interface.h"
#include "MGIE_interface.h"

#include "math.h"
#include<util/delay.h>

void printtemponlcd(void);

u16 L_u16PotValue=0;

int main(void)
{
	HLCD_voidInit();
	MADC_stderrorInit(MADC_VREF_AVCC,MADC_PreScalar_128,1024);
	MGIE_voidEnableGlobalInterrupt();

	while(1)
	{

		MADC_stderrorStartConversionASync(&L_u16PotValue,printtemponlcd,MADC_SCHANNEL_ADC0);
	}

	return 0;
}



void printtemponlcd(void)
{
	HLCD_voidClear();

	u16 L_u16ReadVoltage=(u16)(((u32)L_u16PotValue*5000UL)/1024UL);
	u16	L_u8Temp=round(L_u16ReadVoltage/10.0);
	HLCD_voidSetCursor(0,0);
	HLCD_voidSendString("Tempreture");
	HLCD_voidSetCursor(1,0);
	HLCD_voidDisplayNumber(L_u8Temp);
	_delay_ms(1000);

}





