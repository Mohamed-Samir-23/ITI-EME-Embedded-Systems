/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Mohamed Samir
 */


/*include library*/
#include"LSTD_types.h"
#include"LBIT_math.h"

/*include SWC library*/
#include "MDIO_interface.h"

#define MCUCR *((volatile u8*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR *((volatile u8*)0x54)
#define ISC2 6

#define GICR *((volatile u8*)0x5B)/*PIE*/

#define INT2 5
#define INT0 6
#define INT1 7

#define GIFR *((volatile u8*)0x5A)/*PIF*/

#define INTF2 5
#define INTF0 6
#define INTF1 7


#define SREG *((volatile u8*)0x5F)/*global*/
#define IBIT 7


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
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

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
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

int main (void)
{
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTA,MDIO_PIN1,MDIO_OUTPUT);

	MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTA,MDIO_PIN1,MDIO_LOW);

	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN2,MDIO_INPUT_PULLUP);
	MDIO_stderrorSetPinDirection(MDIO_PORTD,MDIO_PIN3,MDIO_INPUT_PULLUP);

	/*The falling edge IN0&IN2 */
	SET_BIT(MCUCR,ISC01);
	CLEAR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC11);
	CLEAR_BIT(MCUCR,ISC10);

	/*Enable IN0&IN2*/
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);

	/*GLOBALE */
	SET_BIT(SREG,IBIT);

	while(1)
	{

	}

	return 0;
}
