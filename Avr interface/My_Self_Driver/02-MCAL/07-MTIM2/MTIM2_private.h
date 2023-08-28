/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM0				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 26, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef	_MTIM2_PRIVATE_H_
#define _MTIM2_PRIVATE_H_



#define MTIM0_TCCR0 			*((volatile u8 *)0x53)
#define MTIM0_F0C0 				7
#define MTIM0_WGM00 			6
#define MTIM0_COM01 			5
#define MTIM0_COM00 			4
#define MTIM0_WGM01 			3
#define MTIM0_CS02 				2
#define MTIM0_CS01 				1
#define MTIM0_CS00 				0

#define MTIM0_TCNT0 			*((volatile u8 *)0x52)

#define MTIM0_OCR0 				*((volatile u8 *)0x5C)

#ifndef MTIM0_TIMSK
#define MTIM0_TIMSK 			*((volatile u8 *)0x59)
#endif
#define MTIM0_OCIE0 			1
#define MTIM0_TOIE0 			0



#define MTIM0_TIFR 				*((volatile u8 *)0x58)
#define MTIM0_OCF0 				1
#define MTIM0_TOV0 				0

#define MTIM0_HWPINFLAG 		0xCF

#define MTIM0_ClOCKFLAG 		0xF8

#endif 