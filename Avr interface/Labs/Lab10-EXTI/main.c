/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: moham
 */

/*include library*/
#include"LSTD_types.h"
#include"LBIT_math.h"

/*include SWC library*/
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "MGIE_interface.h"

void ISR_DIO_EXTI0(void);
void ISR_DIO_EXTI1(void);

int main (void)
{
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_OUTPUT);

	MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);

	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN2,MDIO_INPUT_PULLUP);
	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN3,MDIO_INPUT_PULLUP);

	/*The falling edge IN0&IN2 */
	MEXTI_stderrorInit(MEXTI_INT0,MEXTI_MODE_FALLING);
	MEXTI_stderrorInit(MEXTI_INT1,MEXTI_MODE_FALLING);
	/*Enable IN0&IN2*/
	MEXTI_stderrorEnableInterrupt(MEXTI_INT0);
	MEXTI_stderrorEnableInterrupt(MEXTI_INT1);

	/*set call back function*/
	MEXTI_stderrorSetCallBack(ISR_DIO_EXTI0,MEXTI_INT0);
	MEXTI_stderrorSetCallBack(ISR_DIO_EXTI1,MEXTI_INT1);

	/*GLOBALE */
	MGIE_voidEnableGlobalInterrupt();

	while(1)
	{

	}

	return 0;
}



void ISR_DIO_EXTI0(void)
{
	volatile static u8 L_u8StatePA0=0;
	if(L_u8StatePA0==0)
	{
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_HIGH);
		L_u8StatePA0=1;
	}
	else
	{
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
		L_u8StatePA0=0;
	}
}



void ISR_DIO_EXTI1(void)
{
	volatile static u8 L_u8StatePA1=0;
	if(L_u8StatePA1==0)
	{
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_HIGH);
		L_u8StatePA1=1;
	}
	else
	{
		MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);
		L_u8StatePA1=0;
	}
}
