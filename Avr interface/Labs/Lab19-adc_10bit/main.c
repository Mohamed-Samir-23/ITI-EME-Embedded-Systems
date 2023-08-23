/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Mohamed Samir
 */

/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "HLCD_interface.h"
#include "math.h"
#include<util/delay.h>

int main (void)
{
	u16 L_u16PotValue=5;
	u16 L_u8ReadVoltage=0;
	u8 L_u8Temp=5;
	//MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_INPUT_FLOAT);
	MADC_stderrorInit(MADC_VREF_AVCC,MADC_PreScalar_128,1024);
	HLCD_voidInit();

	while(1)
	{
		L_u16PotValue=0;
		L_u8ReadVoltage=0;
		L_u8Temp=0;

		MADC_stderrorReadADC((u16*)&L_u16PotValue,MADC_SCHANNEL_ADC1);

		L_u8ReadVoltage=(u16)(((u32)L_u16PotValue*5000UL)/1024UL);

		L_u8Temp=round(L_u8ReadVoltage/10.0);


		HLCD_voidSetCursor(0,0);
		HLCD_voidSendString("Tempreture");

		HLCD_voidSetCursor(1,0);
		HLCD_voidDisplayNumber(L_u8Temp);

		_delay_ms(1000);
		HLCD_voidClear();

	}


	return 0;
}
