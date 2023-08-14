/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: moham
 */
/*include library*/
#include"LSTD_types.h"
#include"LBIT_math.h"

/*include SWC library*/
#include "MDIO_interface.h"
#define  F_CPU    8000000UL
#include<util/delay.h>
#include "HLCD_interface.h"


#define IN1 MDIO_PIN0
#define IN2 MDIO_PIN1
#define IN3 MDIO_PIN2
#define IN4 MDIO_PIN3
void ccw(void);
void cw(void);
void stop(void);
int main (void)
{

	HLCD_voidInit();
	MDIO_stderrorSetPinDirection(MDIO_PORTD,IN1,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTD,IN2,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTD,IN3,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(MDIO_PORTD,IN4,MDIO_OUTPUT);
	while(1)
	{

		cw();
		stop();
		ccw();
		stop();

	}
	return 0;
}


void ccw(void)
{
	HLCD_voidClear();
	HLCD_voidSetCursor(0,0);
	HLCD_voidSendString("CCW");
	s16 volatile L_u8i=0;
	for(L_u8i=0;L_u8i<500;L_u8i++)
	{
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_HIGH);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(2);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_HIGH);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(2);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_HIGH);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(2);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_HIGH);
	_delay_ms(2);
	}


}



void cw(void)
{
	HLCD_voidClear();
	HLCD_voidSetCursor(0,0);
	HLCD_voidSendString("CW");
	s16 volatile L_u8i=0;
	for(L_u8i=0;L_u8i<500;L_u8i++)
	{
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_HIGH);
	_delay_ms(2);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_HIGH);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(2);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_HIGH);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(2);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_HIGH);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(2);
	}



}


void stop(void)
{

	MDIO_stderrorSetPinValue(MDIO_PORTD,IN1,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN2,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN3,MDIO_LOW);
	MDIO_stderrorSetPinValue(MDIO_PORTD,IN4,MDIO_LOW);
	_delay_ms(1000);

}
