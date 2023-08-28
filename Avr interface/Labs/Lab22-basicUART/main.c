/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Mohamed Samir
 */


#include "LSTD_types.h"
#include "LBIT_math.h"


#define MUSART_UDR 		*((volatile u8 *)0x2C)

#define MUSART_UCSRA 	*((volatile u8 *)0x2B)
#define MUSART_RXC   	7
#define MUSART_TXC   	6
#define MUSART_UDRE   	5
#define MUSART_FE   	4
#define MUSART_DOR   	3
#define MUSART_PE   	2
#define MUSART_U2X   	1
#define MUSART_MPCM   	0

#define MUSART_UCSRB 	*((volatile u8 *)0x2A)
#define MUSART_RXCIE   	7
#define MUSART_TXCIE   	6
#define MUSART_UDRIE   	5
#define MUSART_RXEN   	4
#define MUSART_TXEN   	3
#define MUSART_UCSZ2   	2
#define MUSART_RXB8   	1
#define MUSART_TXB8   	0

#define MUSART_UCSRC 	*((volatile u8 *)0x40)
#define MUSART_URSEL   	7
#define MUSART_UMSEL   	6
#define MUSART_UPM1   	5
#define MUSART_UPM0   	4
#define MUSART_USBS   	3
#define MUSART_UCSZ1   	2
#define MUSART_UCSZ0   	1
#define MUSART_UCPOL   	0

#define MUSART_UBRRH 	*((volatile u8 *)0x40)

#define MUSART_UBRRL 	*((volatile u8 *)0x29)


void init_uart(void);

void send_byte_uart(u8 ARG_Byte);

u8 RESIVE_byte_uart(void);


int main (void)
{
	init_uart();
	u8 data='a';

	while(1)
	{
		send_byte_uart(data);
		data=RESIVE_byte_uart();
	}


	return 0;
}




void init_uart(void)
{
	/*TX Complete Interrupt Enable*/
	SET_BIT(MUSART_UCSRA,MUSART_U2X);
	/*select UBRRH to write */
	CLEAR_BIT(MUSART_UCSRC,MUSART_URSEL);
	/*set Baud Rate*/
	MUSART_UBRRH=0;
	MUSART_UBRRL=12;
	/*select UCSRC to write */
	SET_BIT(MUSART_UCSRC,MUSART_URSEL);
	/*mode*/
	CLEAR_BIT(MUSART_UCSRC,MUSART_UMSEL);
	/*Disabled Parity*/
	CLEAR_BIT(MUSART_UCSRC,MUSART_UPM0);
	CLEAR_BIT(MUSART_UCSRC,MUSART_UPM1);
	/*1bit for stop*/
	CLEAR_BIT(MUSART_UCSRC,MUSART_USBS);
	/*send 7bit-Data*/
	CLEAR_BIT(MUSART_UCSRB,MUSART_UCSZ2);
	SET_BIT(MUSART_UCSRC,MUSART_UCSZ1);
	CLEAR_BIT(MUSART_UCSRC,MUSART_UCSZ0);
	/*RX Complete Interrupt Enable */
	SET_BIT(MUSART_UCSRB,MUSART_RXEN);
	/*TX Complete Interrupt Enable*/
	SET_BIT(MUSART_UCSRB,MUSART_TXEN);
}


void send_byte_uart(u8 ARG_Byte)
{

	while(GET_BIT(MUSART_UCSRA,MUSART_UDRE)==0)
	{

	}

	MUSART_UDR =ARG_Byte;
}


u8 RESIVE_byte_uart(void)
{

	while(GET_BIT(MUSART_UCSRA,MUSART_RXC)==0)
	{

	}

	return MUSART_UDR;
}
