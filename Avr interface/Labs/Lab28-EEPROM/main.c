/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Mohamed Samir
 */

#define F_CPU 8000000UL
/* Library Includes */
#include "LSTD_types.h"
#include "LBIT_math.h"

/* SWC Includes */


#include <util/delay.h>

#include "MDIO_interface.h"
#include "MTWI_interface.h"
#include "HLCD_interface.h"
#include "HNVM_interface.h"

int main(void)
{
	u8 L_u8B1, L_u8B2, L_u8B3, L_u8Data;
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_INPUT_PULLUP);
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_INPUT_PULLUP);
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN2,MDIO_INPUT_PULLUP);

	MDIO_stderrorSetPinDirection(MDIO_PORTC,MDIO_PIN0,MDIO_INPUT_PULLUP);
	MDIO_stderrorSetPinDirection(MDIO_PORTC,MDIO_PIN1,MDIO_INPUT_PULLUP);

	HNVM_stderrInit();
	HLCD_voidInit();
	HLCD_voidSendString("Welcome");
	_delay_ms(1000);
	HLCD_voidSendCmd(0x01);
	_delay_ms(2);
	while(1)
	{

		MDIO_stderrorGetPinValue(MDIO_PORTA,MDIO_PIN0,&L_u8B1);
		MDIO_stderrorGetPinValue(MDIO_PORTA,MDIO_PIN1,&L_u8B2);
		MDIO_stderrorGetPinValue(MDIO_PORTA,MDIO_PIN2,&L_u8B3);
		if(!L_u8B1)
		{
			HNVM_voidWrite(0x00, 'M');
			HLCD_voidSendString("Data written: M");
			_delay_ms(1000);
			HLCD_voidSendCmd(0x01);
			_delay_ms(2);
		}
		else if(!L_u8B2)
		{
			HNVM_voidWrite(0x00, 'E');
			HLCD_voidSendString("Data written: E");
			_delay_ms(1000);
			HLCD_voidSendCmd(0x01);
			_delay_ms(2);
		}
		else if(!L_u8B3)
		{
			L_u8Data = HNVM_u8Read(0x00);
			HLCD_voidSendString("Read Data: ");
			HLCD_voidSendChar(L_u8Data);
			_delay_ms(1000);
			HLCD_voidSendCmd(0x01);
			_delay_ms(2);
		}
		_delay_ms(250);
	}
	return 0;
}


