/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: moham
 */

/*all library*/
#include"LSTD_types.h"
#include"LBIT_math.h"

/*SWC library*/
#include "MDIO_interface.h"
#define  F_CPU    8000000UL
#include<util/delay.h>

#define LCD_CONTROL_PORT    MDIO_PORTB
#define LCD_DATA_PORT       MDIO_PORTA
#define LCD_RS_PIN          MDIO_PIN1
#define LCD_RW_PIN          MDIO_PIN2
#define LCD_E_PIN           MDIO_PIN3

void LCD_init(void);
void LCD_sendData(u8 ARG_u8Data);
void LCD_sendCmd(u8 ARG_u8Cmd);
void LCD_sendsting(const char* ARG_ccharStr);

int main(void)
{
	LCD_init();
	/*
	LCD_sendData('S');
	LCD_sendData('A');
	LCD_sendData('M');
	LCD_sendData('I');
	LCD_sendData('R');
	 */
	LCD_sendsting("MOHAMED SAMIR");
	while(1)
	{

	}
	return 0;
}

void LCD_init(void)
{
	MDIO_stderrorSetPortDirection(LCD_DATA_PORT,0xFF);
	MDIO_stderrorSetPortValue(LCD_DATA_PORT,MDIO_LOW);
	MDIO_stderrorSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,MDIO_OUTPUT);
	MDIO_stderrorSetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_OUTPUT);
	LCD_sendCmd(0x33);   /* Send command 0x33*/
	LCD_sendCmd(0x32);   /* Send command 0x32*/
	LCD_sendCmd(0x38);
	_delay_us(50);
	LCD_sendCmd(0x0C);
	_delay_us(50);
	LCD_sendCmd(0x01);
	_delay_ms(2);
	LCD_sendCmd(0x06);
}
void LCD_sendCmd(u8 ARG_u8Cmd)
{
	/*control prepration*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,MDIO_LOW);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,MDIO_LOW);

	/*enable prepration*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_stderrorSetPortValue(LCD_DATA_PORT,ARG_u8Cmd);
	_delay_ms(1);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_LOW);
}

void LCD_sendData(u8 ARG_u8Data)
{
	/*control prepration*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,MDIO_HIGH);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,MDIO_LOW);
	_delay_ms(1);
	/*enable prepration*/
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_HIGH);
	_delay_ms(1);
	MDIO_stderrorSetPortValue(LCD_DATA_PORT,ARG_u8Data);
	_delay_ms(1);
	MDIO_stderrorSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,MDIO_LOW);
	_delay_ms(2);
}


void LCD_sendsting(const char* ARG_ccharStr)
{
	if(ARG_ccharStr != '\0')
	{
		u8 i=0;
		do{
			LCD_sendData(ARG_ccharStr[i]);
			i++;
		}while(ARG_ccharStr[i] != '\0' );
	}
}
