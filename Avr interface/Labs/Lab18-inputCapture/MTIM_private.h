/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: MTIM				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 17, 2023	*/
/*  Last Edit	: August 21, 2023	*/
/************************************/

#ifndef	_MTIM_PRIVATE_H_
#define _MTIM_PRIVATE_H_



#define MTIM_TCCR0 			*((volatile u8 *)0x53)
#define MTIM_F0C0 			7
#define MTIM_WGM00 			6
#define MTIM_COM01 			5
#define MTIM_COM00 			4
#define MTIM_WGM01 			3
#define MTIM_CS02 			2
#define MTIM_CS01 			1
#define MTIM_CS00 			0

#define MTIM_TCNT0 			*((volatile u8 *)0x52)

#define MTIM_OCR0 			*((volatile u8 *)0x5C)

#define MTIM_TIMSK 			*((volatile u8 *)0x59)

#define MTIM_TICIE1 		5
#define MTIM_OCIE1A 		4
#define MTIM_OCIE1B 		3
#define MTIM_TOIE1 			2
#define MTIM_OCIE0 			1
#define MTIM_TOIE0 			0



#define MTIM_TIFR 			*((volatile u8 *)0x58)
#define MTIM_OCF0 			1
#define MTIM_TOV0 			0

#define MTIM_TCCR1A 		*((volatile u8 *)0x4F)
#define MTIM_COM1A1 		7
#define MTIM_COM1A0 		6
#define MTIM_COM1B1 		5
#define MTIM_COM1B0 		4
#define MTIM_FOC1A 			3
#define MTIM_FOC1B  		2
#define MTIM_WGM11 			1
#define MTIM_WGM10 			0


#define MTIM_TCCR1B 		*((volatile u8 *)0x4E)
#define MTIM_ICNC1	 		7
#define MTIM_ICES1 			6

#define MTIM_WGM13 			4
#define MTIM_WGM12 			3
#define MTIM_CS12	  		2
#define MTIM_CS11 			1
#define MTIM_CS10 			0


#define MTIM_TCNT1L 		*((volatile u16 *)0x4C)

#define MTIM_OCR1AL 		*((volatile u16 *)0x4A)

#define MTIM_OCR1BL 		*((volatile u16 *)0x48)

#define MTIM_OCR1BL 		*((volatile u16 *)0x48)

#define MTIM_ICR1L	 		*((volatile u16 *)0x46)

#endif 