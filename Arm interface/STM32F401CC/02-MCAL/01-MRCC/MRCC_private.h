/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: RCC					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 15, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/


#ifndef _MRCC_PRIVATE_H_
#define _MRCC_PRIVATE_H_

#define RCC_OFFSET			(0x40023800)

#define RCC_CR				*((uv32*)(0x00+RCC_OFFSET))
#define PLLRDY				25U
#define PLLRON				24U
#define HSEBYP				18U
#define HSERDY				17U
#define HSEON				16U
#define HSIRDY				1U
#define HSION				0U

#define RCC_PLLCFGR			*((uv32*)(0x04+RCC_OFFSET))
#define PLLQ				24U
#define PLLSRC				22U
#define PLLP				16U
#define PLLN				6U
#define PLLM				0U

#define RCC_CFGR			*((uv32*)(0x08+RCC_OFFSET))
#define PPRE2				13U
#define PPRE1				10U
#define HPRE				4U
#define SWS					2U
#define SW					0U

#define RCC_CIR				*((uv32*)(0x0C+RCC_OFFSET))
#define RCC_AHB1RSTR		*((uv32*)(0x10+RCC_OFFSET))
#define RCC_AHB2RSTR		*((uv32*)(0x14+RCC_OFFSET))
#define RCC_APB1RSTR		*((uv32*)(0x20+RCC_OFFSET))
#define RCC_APB2RSTR		*((uv32*)(0x24+RCC_OFFSET))
#define RCC_AHB1ENR			*((uv32*)(0x30+RCC_OFFSET))
#define RCC_AHB2ENR			*((uv32*)(0x34+RCC_OFFSET))
#define RCC_APB1ENR			*((uv32*)(0x40+RCC_OFFSET))
#define RCC_APB2ENR			*((uv32*)(0x44+RCC_OFFSET))
#define RCC_AHB1LPENR		*((uv32*)(0x50+RCC_OFFSET))
#define RCC_AHB2LPENR		*((uv32*)(0x54+RCC_OFFSET))
#define RCC_APB1LPENR		*((uv32*)(0x60+RCC_OFFSET))
#define RCC_APB2LPENR		*((uv32*)(0x64+RCC_OFFSET))
#define RCC_BDCR			*((uv32*)(0x70+RCC_OFFSET))
#define RCC_CSR				*((uv32*)(0x74+RCC_OFFSET))
#define RCC_SSCGR			*((uv32*)(0x80+RCC_OFFSET))
#define RCC_PLLI2SCFGRR		*((uv32*)(0x84+RCC_OFFSET))
#define RCC_DCKCFGR			*((uv32*)(0x8C+RCC_OFFSET))

#define AHB_FLAG			0xFFFFFF0F
#define APB1_FLAG			0xFFFFE3FF
#define APB2_FLAG			0xFFFF1FFF
#define PLL_FLAG			0xF0FC0000

#define HSE_FLAG			0X01
#define PLL_SYS_FLAG		0X02


#endif