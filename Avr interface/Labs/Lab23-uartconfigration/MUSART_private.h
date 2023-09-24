/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MUSART			*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 27, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/


#ifndef _MUSART_PRIVATE_H_
#define _MUSART_PRIVATE_H_

#define MUSART_UDR 					*((volatile u8 *)0x2C)

#define MUSART_UCSRA 				*((volatile u8 *)0x2B)
#define MUSART_RXC   				7
#define MUSART_TXC   				6
#define MUSART_UDRE   				5
#define MUSART_FE   				4
#define MUSART_DOR   				3
#define MUSART_PE   				2
#define MUSART_U2X   				1
#define MUSART_MPCM   				0

#define MUSART_UCSRB 				*((volatile u8 *)0x2A)
#define MUSART_RXCIE   				7
#define MUSART_TXCIE   				6
#define MUSART_UDRIE   				5
#define MUSART_RXEN   				4
#define MUSART_TXEN   				3
#define MUSART_UCSZ2   				2
#define MUSART_RXB8   				1
#define MUSART_TXB8   				0

#define MUSART_UCSRC 				*((volatile u8 *)0x40)
#define MUSART_URSEL   				7
#define MUSART_UMSEL   				6
#define MUSART_UPM1   				5
#define MUSART_UPM0   				4
#define MUSART_USBS   				3
#define MUSART_UCSZ1   				2
#define MUSART_UCSZ0   				1
#define MUSART_UCPOL   				0

#define MUSART_UBRRH 				*((volatile u8 *)0x40)

#define MUSART_UBRRL 				*((volatile u8 *)0x29)


#define ENABLEMODEFLAG 				0xE7

#define DISABLEFLAG					0

#define COMMUNICATIONTERMINALFLAG 	0xFE

#define COMMUNICATIONMODEFLAG 		0xFD

#define INTERRUPTSOURCEFLAG 		0x1F

#define UCSRCFRAMEFLAG	 			0xC0

#define ARGDATAFRAMEFLAG1 			0x03

#define DATAFRAMEFLAG 				0xFB

#define ARGDATAFRAMEFLAG2 			0x04

#define ARGDATAFRAMEFLAG3 			0xFE

#define BaudRateFLAG 				0x0F

#define MUSART_IDEL					1

#define MUSART_BUSY					2



#endif