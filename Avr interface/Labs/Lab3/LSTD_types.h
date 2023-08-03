/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: Standard Types	*/
/*  Layer		: LIB				*/
/*  Version		: 1.1				*/
/*  Date		: August 2, 2023	*/
/*  Last Edit	: August 3, 2023	*/
/************************************/

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
	E_NULL_POINTER
	
}STD_error_t;

/*************************************** NULL_POINTER Define *****************************************/
#define NULL_POINTER (void *)0

#endif
