/**************************************/
/*  Author		: Mohamed Samir		  */
/*  SWC			: MTIM0				  */
/*  Layer		: MCAL				  */
/*  Version		: 1.1				  */
/*  Date		: August 26, 2023	  */
/*  Last Edit	: September 01, 2023  */
/**************************************/

#ifndef _LSTD_TYPES_H_
#define _LSTD_TYPES_H_

/********************************** Standard type for unsigned integer **********************************/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
/********************************** Standard type for signed integer ***********************************/
typedef signed char s8;
typedef signed short s16;
typedef signed long int s32;
typedef signed long long int s64;
/************************************** Standard type for floats **************************************/
typedef float f32;
typedef double f64;

/*************************************** NULL_POINTER Define *****************************************/
typedef enum 
{
	E_NOK,
	E_OK,
	E_NULL_POINTER,
	E_TIME_OUT,
	E_BUSY_FUNCTION,
	E_PARITY,
	E_OVERRUN,
	E_FRAME,
	E_WRITE_COLLISON,
	
}STD_error_t;

/*************************************** NULL_POINTER Define *****************************************/
#define NULL_POINTER (void *)0

#endif