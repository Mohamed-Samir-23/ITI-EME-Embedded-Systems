/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: moham
 */


#define F_CPU 8000000UL
/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */


#include <util/delay.h>

#include "MDIO_interface.h"



int main(void)
{
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN2,MDIO_OUTPUT);

	while(1)
	{
		_delay_ms(250);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_TOGGLE);
		_delay_ms(250);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_TOGGLE);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_TOGGLE);
		_delay_ms(250);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_TOGGLE);
		_delay_ms(250);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN2,MDIO_TOGGLE);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_TOGGLE);
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_TOGGLE);
	}


	return 0;
}
