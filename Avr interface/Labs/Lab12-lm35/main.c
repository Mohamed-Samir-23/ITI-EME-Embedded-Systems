/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mohamed Samir
 */


/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MSFIOR_interface.h"
#include "HLCD_interface.h"
#include<util/delay.h>

int main (void)
{
	u8 L_u8I=0;
	f32 L_u8ReadVoltage;
	f32 L_u8ReadTemp;
	HLCD_voidInit();
	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN0,MDIO_OUTPUT);//RED
	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN1,MDIO_OUTPUT);//YELLOW

	MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN0,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN1,MDIO_LOW);


//	MSFIOR_voidSetTriggerSource();
	MADC_stderrorInit(MADC_VREF_AVCC, MADC_PreScalar_2);
	MADC_voidEnableADC();
			MADC_stderrorStartConversion(1);

	while(1)
	{

		MADC_stderrorReadADC(&L_u8I,MADC_CHANNEL_ADC0);
		//MDIO_stderrorSetPortValue(MDIO_PORTD,L_u8I);
		L_u8ReadVoltage= (L_u8I / 255.0) * 5;
		L_u8ReadTemp=L_u8ReadVoltage/0.01;
		HLCD_voidSetCursor(0,0);
		HLCD_voidSendString("temperature is : ");
		HLCD_voidSetCursor(1,0);
		HLCD_voidDisplayNumber(L_u8ReadTemp);
		HLCD_voidSendChar('C');
		if((L_u8ReadTemp>30))
		{

			MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN0,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN1,MDIO_HIGH);

		}
		else
		{

			MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN0,MDIO_HIGH);
			MDIO_stderrorSetPinValue(MDIO_PORTD,MDIO_PIN1,MDIO_LOW);
		}

		_delay_ms(1000);
		HLCD_voidClear();
	}
	return 0;

}
