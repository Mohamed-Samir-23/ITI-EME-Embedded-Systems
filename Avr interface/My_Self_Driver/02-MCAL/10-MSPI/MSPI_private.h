/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MSPI				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 28, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/



#ifndef _MSPI_PRIVATE_H_
#define _MSPI_PRIVATE_H_



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


#define MSPI_IDEL 				0
#define MSPI_BUSY 				1

#endif