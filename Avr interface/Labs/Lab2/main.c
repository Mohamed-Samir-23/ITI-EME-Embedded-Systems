/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Mohamed samir
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
	MDIO_voidSetPortDirection(MDIO_PORTB,LOW);
	MDIO_voidSetPortValue(MDIO_PORTB,HIGH);


	while(1)
	{
		if(MDIO_u8GetPortValue(MDIO_PORTB)==127)
		{

			MDIO_voidSetPortValue(MDIO_PORTA,LOW);

		}
		else
		{

			MDIO_voidSetPortValue(MDIO_PORTA,HIGH);
		}

	}

	return 0;
}

