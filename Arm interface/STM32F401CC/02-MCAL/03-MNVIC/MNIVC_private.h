/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: NIVC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 18, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#define _MNIVC_PRIVATE_H_
#define _MNIVC_PRIVATE_H_



#define NIVC_BASE  			0xE000E100

#ifndef	SCB_BASE
#define SCB_BASE  			0xE000ED00 
#endif



/* Registers of NVIC0 */ 


#define NVIC_ISER0			*((uv32 *)(0x100 + NIVC_BASE))
#define NVIC_ISER1			*((uv32 *)(0x104 + NIVC_BASE))
#define NVIC_ISER2			*((uv32 *)(0x108 + NIVC_BASE))
#define NVIC_ISER3			*((uv32 *)(0x10C + NIVC_BASE))
#define NVIC_ISER4			*((uv32 *)(0x110 + NIVC_BASE))
#define NVIC_ISER5			*((uv32 *)(0x114 + NIVC_BASE))
#define NVIC_ISER6			*((uv32 *)(0x118 + NIVC_BASE))
#define NVIC_ISER7			*((uv32 *)(0x11C + NIVC_BASE))

#define NVIC_ICER0			*((uv32 *)(0x180 + NIVC_BASE))
#define NVIC_ICER1			*((uv32 *)(0x184 + NIVC_BASE))
#define NVIC_ICER2			*((uv32 *)(0x188 + NIVC_BASE))
#define NVIC_ICER3			*((uv32 *)(0x18C + NIVC_BASE))
#define NVIC_ICER4			*((uv32 *)(0x190 + NIVC_BASE))
#define NVIC_ICER5			*((uv32 *)(0x194 + NIVC_BASE))
#define NVIC_ICER6			*((uv32 *)(0x198 + NIVC_BASE))
#define NVIC_ICER7			*((uv32 *)(0x19C + NIVC_BASE))


#define NVIC_ISPR0			*((uv32 *)(0x200 + NIVC_BASE))
#define NVIC_ISPR1			*((uv32 *)(0x204 + NIVC_BASE))
#define NVIC_ISPR2			*((uv32 *)(0x208 + NIVC_BASE))
#define NVIC_ISPR3			*((uv32 *)(0x20C + NIVC_BASE))
#define NVIC_ISPR4			*((uv32 *)(0x210 + NIVC_BASE))
#define NVIC_ISPR5			*((uv32 *)(0x214 + NIVC_BASE))
#define NVIC_ISPR6			*((uv32 *)(0x218 + NIVC_BASE))
#define NVIC_ISPR7			*((uv32 *)(0x21C + NIVC_BASE))



#define NVIC_ICPR0			*((uv32 *)(0x280 + NIVC_BASE))
#define NVIC_ICPR1			*((uv32 *)(0x284 + NIVC_BASE))
#define NVIC_ICPR2			*((uv32 *)(0x288 + NIVC_BASE))
#define NVIC_ICPR3			*((uv32 *)(0x28C + NIVC_BASE))
#define NVIC_ICPR4			*((uv32 *)(0x290 + NIVC_BASE))
#define NVIC_ICPR5			*((uv32 *)(0x294 + NIVC_BASE))
#define NVIC_ICPR6			*((uv32 *)(0x298 + NIVC_BASE))
#define NVIC_ICPR7			*((uv32 *)(0x29C + NIVC_BASE))



#define NVIC_IABR0			*((uv32 *)(0x300 + NIVC_BASE))
#define NVIC_IABR1			*((uv32 *)(0x304 + NIVC_BASE))
#define NVIC_IABR2			*((uv32 *)(0x308 + NIVC_BASE))
#define NVIC_IABR3			*((uv32 *)(0x30C + NIVC_BASE))
#define NVIC_IABR4			*((uv32 *)(0x310 + NIVC_BASE))
#define NVIC_IABR5			*((uv32 *)(0x314 + NIVC_BASE))
#define NVIC_IABR6			*((uv32 *)(0x318 + NIVC_BASE))
#define NVIC_IABR7			*((uv32 *)(0x31C + NIVC_BASE))


#define NVIC_IPR0			((uv8 *)(0x400 + NIVC_BASE))


#define NVIC_STIR			*((uv32 *)(0xE00 + NIVC_BASE))

#define VECTKEY				0x5FA

#ifndef	SCB_AIRCR
#define SCB_AIRCR			*((uv32 *)(0x0C + SCB_BASE))
#endif

#endif