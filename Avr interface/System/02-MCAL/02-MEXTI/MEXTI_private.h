/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: EXTI				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 13, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef _MEXTI_PRIVATE_H_
#define _MEXTI_PRIVATE_H_

#define MEXTI_MCUCR 		*((volatile u8*)0x55)
#define MEXTI_ISC00 		0
#define MEXTI_ISC01 		1
#define MEXTI_ISC10 		2
#define MEXTI_ISC11 		3
#define MEXTI_MCUCSR 		*((volatile u8*)0x54)
#define MEXTI_ISC2 			6
#define MEXTI_GICR 			*((volatile u8*)0x5B)/*PIE*/
#define MEXTI_INT2_PV 		5
#define MEXTI_INT0_PV 		6
#define MEXTI_INT1_PV 		7
#define MEXTI_GIFR 			*((volatile u8*)0x5A)/*PIF*/
#define MEXTI_INTF2 		5
#define MEXTI_INTF0 		6
#define MEXTI_INTF1 		7
#define MEXTI_SREG 			*((volatile u8*)0x5F)/*global*/
#define MEXTI_IBIT 			7

#endif