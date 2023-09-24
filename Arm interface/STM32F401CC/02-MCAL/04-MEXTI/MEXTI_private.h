/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: EXTI					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 19, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#define _MEXTI_PRIVATE_H_
#define _MEXTI_PRIVATE_H_



#define EXTI_BASE  			0x40013C00

#ifndef	SYSCFG_BASE
#define SYSCFG_BASE  			0x40013800 
#endif

#define EXTI_IMR			*((uv32 *)(0x00 + EXTI_BASE))

#define EXTI_EMR			*((uv32 *)(0x04 + EXTI_BASE))

#define EXTI_RTSR			*((uv32 *)(0x08 + EXTI_BASE))

#define EXTI_FTSR			*((uv32 *)(0x0C + EXTI_BASE))

#define EXTI_SWIER			*((uv32 *)(0x10 + EXTI_BASE))

#define EXTI_PR				*((uv32 *)(0x14 + EXTI_BASE))


#ifndef	SCB_AIRCR
#define SYSCFG_EXTICR1			*((uv32 *)(0x08 + SYSCFG_BASE))
#endif

#ifndef	SCB_AIRCR
#define SYSCFG_EXTICR2			*((uv32 *)(0x0C + SYSCFG_BASE))
#endif

#ifndef	SCB_AIRCR
#define SYSCFG_EXTICR3			*((uv32 *)(0x10 + SYSCFG_BASE))
#endif

#ifndef	SCB_AIRCR
#define SYSCFG_EXTICR4			*((uv32 *)(0x14 + SYSCFG_BASE))
#endif

#endif