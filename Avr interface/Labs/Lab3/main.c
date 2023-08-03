/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Mohamed Samir
 */


#define F_CPU 8000000L
#include <util/delay.h>

/* Library Include */
#include "LBIT_math.h"
#include "LSTD_types.h"

/* SWC Include */
#include "MDIO_interface.h"


int main()
{
	s8 i;
	for(i=0;i<8;i++)
	{
		MDIO_stderrorSetPinDirection(MDIO_PORTA,i,MDIO_OUTPUT);
	}
	MDIO_stderrorSetPinDirection(MDIO_PORTB,7,MDIO_INPUT_PULLUP);

	while(1)
	{
		u8 key=0;
		MDIO_stderrorGetPinValue(MDIO_PORTB,7,&key);
		if(key==1)
		{
			for(i=0;i<8;i++)
			{
				MDIO_stderrorSetPinValue(MDIO_PORTA,i,MDIO_HIGH);
				_delay_ms(1000);
				MDIO_stderrorSetPinValue(MDIO_PORTA,i,MDIO_LOW);
			}
		}
		else
		{
			for(i=7;i>=0;i--)
			{
				MDIO_stderrorSetPinValue(MDIO_PORTA,i,MDIO_HIGH);
				_delay_ms(1000);
				MDIO_stderrorSetPinValue(MDIO_PORTA,i,MDIO_LOW);
			}

		}
	}

	return 0;
}
