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

int main (void)
{
	u8 L_u8I=0;
	f32 L_u8ReadVoltage;
	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN0,MDIO_OUTPUT);//RED
	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN1,MDIO_OUTPUT);//YELLOW
	MDIO_stderrorSetPinDirection(MDIO_PORTB,MDIO_PIN2,MDIO_OUTPUT);//GREAN
	MDIO_stderrorSetPortDirection(MDIO_PORTD,0xFF);
	MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN2,MDIO_LOW);

	MSFIOR_voidSetTriggerSource(Free_Running_mode);
	MADC_stderrorInit(MADC_VREF_AVCC, MADC_PreScalar_2);
	MADC_voidEnableADC();

	while(1)
	{

		MADC_stderrorReadADC(&L_u8I,MADC_CHANNEL_ADC0);
		MDIO_stderrorSetPortValue(MDIO_PORTD,L_u8I);
		L_u8ReadVoltage= (L_u8I / 255.0) * 5;

		if((L_u8ReadVoltage>=0)&&(L_u8ReadVoltage<=1.5))
		{

			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_HIGH);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN1,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN2,MDIO_LOW);
		}
		else if((L_u8ReadVoltage>1.5)&&(L_u8ReadVoltage<=3))
		{

			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN1,MDIO_HIGH);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN2,MDIO_LOW);

		}
		else if((L_u8ReadVoltage>3))
		{
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN1,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN2,MDIO_HIGH);
		}
		else
		{
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN1,MDIO_LOW);
			MDIO_stderrorSetPinValue(MDIO_PORTB,MDIO_PIN2,MDIO_LOW);
		}


	}
	return 0;

}
