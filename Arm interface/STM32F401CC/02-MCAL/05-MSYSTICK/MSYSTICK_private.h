/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: SYSTICK				*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 20, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#ifndef _MSYSTICK_PRIVATE_H_
#define _MSYSTICK_PRIVATE_H_


#define STK_CTRL			*((uv32 *)(0xE000E010))

#define STK_LOAD			*((uv32 *)(0xE000E014))

#define STK_VAL				*((uv32 *)(0xE000E018))

#define STK_CTRL_Flag 		7


#endif
