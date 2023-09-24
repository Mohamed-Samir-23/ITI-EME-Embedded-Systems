/*
 * main.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Mohamed Samir
 */

/*Master*/

/* Library Includes */
#include "avr/io.h"
#include "LSTD_types.h"
#include "LBIT_math.h"
/* SWC Includes */
#include "MUSART_interface.h"
#include "MDIO_interface.h"
#define MSPI_SPDR 					*((volatile u8 *)0x2F)

#define MSPI_SPSR 					*((volatile u8 *)0x2E)
#define MSPI_SPIF 					7
#define MSPI_WCOL 					6
#define MSPI_SPI2X 					0

#define MSPI_SPCR 					*((volatile u8 *)0x2D)
#define MSPI_SPIE 					7
#define MSPI_SPE 					6
#define MSPI_DORD 					5
#define MSPI_MSTR 					4
#define MSPI_CPOL 					3
#define MSPI_CPHA 					2
#define MSPI_SPR1 					1
#define MSPI_SPR0 					0

#define MSPI_PORTB					*((volatile u8 *)0x38)
#define MSPI_DDRB					*((volatile u8 *)0x37)
#define MSPI_PINB					*((volatile u8 *)0x36)


void Spi_Init(void);
void Spi_SendByte(u8 Data);
u8 SPI_ReadByte(void);
u8 SPI_ExchangeData(u8 Data);


int main()
{


	MUSART_stderrorInit
	(
		MUSART_RX_MODE,
		MUSART_SINGLE_PROCESSOR ,
		MUSART_ASYNC_DOUBLE_SPEED,
		MUSART_INTERRUPT_DISABLE,
		MUSART_8BIT_DATA,
		MUSART_PARITY_DISABLE,
		MUSART_STOP_1BIT,
		MUSART_SAMPLE_DISABLE,
		9600
	);


	Spi_Init();
	while(1)
	{
		u8 L_u8data;
		MUSART_stderrorReadDataSync((u16*)&L_u8data);
		Spi_SendByte(L_u8data);


	}

	return 0;

}


void Spi_Init(void)
{
	/*disable interrupt*/
	CLEAR_BIT(MSPI_SPCR,MSPI_SPIE);
	/*MSB*/
	CLEAR_BIT(MSPI_SPCR,MSPI_DORD);
	/*master*/
	SET_BIT(MSPI_SPCR,MSPI_MSTR);
	/*mode0*/
	CLEAR_BIT(MSPI_SPCR,MSPI_CPOL);
	CLEAR_BIT(MSPI_SPCR,MSPI_CPHA);
	/*Fequancy 250khz*/
	CLEAR_BIT(MSPI_SPCR,MSPI_SPR1);
	CLEAR_BIT(MSPI_SPCR,MSPI_SPR0);
	CLEAR_BIT(MSPI_SPSR,MSPI_SPI2X);

	/*MASTER MODE*/
	/*MAKE SS OUTPUT*/
	SET_BIT(MSPI_DDRB,4);
	/*MAKE MOSI OUTPUT*/
	SET_BIT(MSPI_DDRB,5);
	/*MAKE SCK OUTPUT*/
	SET_BIT(MSPI_DDRB,7);
	/*MAKE MISO INPUT*/
	CLEAR_BIT(MSPI_DDRB,6);
	/*enable spi*/
	SET_BIT(MSPI_SPCR,MSPI_SPE);
}

void Spi_SendByte(u8 Data)
{
	MSPI_SPDR=Data;
	while(GET_BIT(MSPI_SPSR,MSPI_SPIF)==0)
	{

	}
	/*flag clear by read MSPI_SPCR */
}

u8 SPI_ReadByte(void)
{

	/*send dummy to resive data by shifting*/
	u8 Dummy =0x00;
	MSPI_SPDR=Dummy;
	while(GET_BIT(MSPI_SPSR,MSPI_SPIF)==0)
	{

	}
	return MSPI_SPDR;
}

u8 SPI_ExchangeData(u8 Data)
{
	/*send and resive*/
	MSPI_SPDR=Data;
	while(GET_BIT(MSPI_SPSR,MSPI_SPIF)==0)
	{

	}
	return MSPI_SPDR;
}
