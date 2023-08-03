/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Mohamed Samir
 */
#define F_CPU 8000000L
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include <util/delay.h>
#define FOREVER (u8)1u
#define HIGH 	0xFF
#define LOW		0x00
int main ()
{
	MDIO_voidSetPortDirection(MDIO_PORTA,HIGH);
	while(FOREVER)
	{

		MDIO_voidSetPortValue(MDIO_PORTA,HIGH);
		_delay_ms(1000);
		MDIO_voidSetPortValue(MDIO_PORTA,LOW);
		_delay_ms(1000);

	}

	return 0;
}
