/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 17, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef	_MTIM_PRIVATE_H_
#define _MTIM_PRIVATE_H_



#define MTIM_TCCR0 		*((volatile u8 *)0x53)
#define MTIM_F0C0 		7
#define MTIM_WGM00 		6
#define MTIM_COM01 		5
#define MTIM_COM00 		4
#define MTIM_WGM01 		3
#define MTIM_CS02 		2
#define MTIM_CS01 		1
#define MTIM_CS00 		0

#define MTIM_TCNT0 		*((volatile u8 *)0x52)

#define MTIM_OCR0 		*((volatile u8 *)0x5C)

#define MTIM_TIMSK 		*((volatile u8 *)0x59)
#define MTIM_OCIE0 		1
#define MTIM_TOIE0 		0

#define MTIM_TIFR 		*((volatile u8 *)0x58)
#define MTIM_OCF0 		1
#define MTIM_TOV0 		0



#endif 