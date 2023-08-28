/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM0				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 26, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef	_MTIM1_PRIVATE_H_
#define _MTIM1_PRIVATE_H_



#define MTIM1_TCCR1A 		*((volatile u8 *)0x4F)
#define MTIM1_COM1A1 		7
#define MTIM1_COM1A0 		6
#define MTIM1_COM1B1 		5
#define MTIM1_COM1B0 		4
#define MTIM1_FOC1A 		3
#define MTIM1_FOC1B  		2
#define MTIM1_WGM11 		1
#define MTIM1_WGM10 		0

#define MTIM1_TCCR1B 		*((volatile u8 *)0x4E)
#define MTIM1_ICNC1	 		7
#define MTIM1_ICES1 		6
#define MTIM1_WGM13 		4
#define MTIM1_WGM12 		3
#define MTIM1_CS12	  		2
#define MTIM1_CS11 			1
#define MTIM1_CS10 			0

#define MTIM_TCNT1L 		*((volatile u16 *)0x4C)

#define MTIM_OCR1AL 		*((volatile u16 *)0x4A)

#define MTIM_OCR1BL 		*((volatile u16 *)0x48)



#ifndef MTIM_TIMSK
#define MTIM_TIMSK 			*((volatile u8 *)0x59)
#endif
#define MTIM0_OCIE0 			1
#define MTIM0_TOIE0 			0



#define MTIM0_TIFR 				*((volatile u8 *)0x58)
#define MTIM0_OCF0 				1
#define MTIM0_TOV0 				0

#define MTIM0_HWPINFLAG 		0xCF

#define MTIM0_ClOCKFLAG 		0xF8

#endif 