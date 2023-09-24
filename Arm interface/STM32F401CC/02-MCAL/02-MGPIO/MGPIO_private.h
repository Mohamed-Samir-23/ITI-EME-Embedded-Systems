/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: GPIO					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 17, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#ifndef _MGPIO_PRIVATE_H_
#define _MGPIO_PRIVATE_H_


#define GPIOA_BASE  0x40020000
#define GPIOB_BASE  0x40020400
#define GPIOC_BASE  0x40020800
#define GPIOD_BASE  0x40020C00
#define GPIOE_BASE  0x40021000
#define GPIOF_BASE  0x40021400
#define GPIOG_BASE  0x40021800
#define GPIOH_BASE  0x40021C00


/* Registers of PORTA */ 
#define GPIOA_MODER			*((uv32 *)(0x00 + GPIOA_BASE))
#define GPIOA_OTYPER		*((uv32 *)(0x04 + GPIOA_BASE))
#define GPIOA_OSPEEDR		*((uv32 *)(0x08 + GPIOA_BASE))
#define GPIOA_PUPDR         *((uv32 *)(0x0C + GPIOA_BASE))
#define GPIOA_IDR           *((uv32 *)(0x10 + GPIOA_BASE))
#define GPIOA_ODR           *((uv32 *)(0x14 + GPIOA_BASE))
#define GPIOA_BSRR          *((uv32 *)(0x18 + GPIOA_BASE))
#define GPIOA_LCKR          *((uv32 *)(0x1C + GPIOA_BASE))
#define GPIOA_AFRL          *((uv32 *)(0x20 + GPIOA_BASE))
#define GPIOA_AFRH  		*((uv32 *)(0x24 + GPIOA_BASE))

/* Registers of PORTB */ 
#define GPIOB_MODER			*((uv32 *)(0x00 + GPIOB_BASE))
#define GPIOB_OTYPER		*((uv32 *)(0x04 + GPIOB_BASE))
#define GPIOB_OSPEEDR		*((uv32 *)(0x08 + GPIOB_BASE))
#define GPIOB_PUPDR         *((uv32 *)(0x0C + GPIOB_BASE))
#define GPIOB_IDR           *((uv32 *)(0x10 + GPIOB_BASE))
#define GPIOB_ODR           *((uv32 *)(0x14 + GPIOB_BASE))
#define GPIOB_BSRR          *((uv32 *)(0x18 + GPIOB_BASE))
#define GPIOB_LCKR          *((uv32 *)(0x1C + GPIOB_BASE))
#define GPIOB_AFRL          *((uv32 *)(0x20 + GPIOB_BASE))
#define GPIOB_AFRH  		*((uv32 *)(0x24 + GPIOB_BASE))


/* Registers of PORTC */ 
#define GPIOC_MODER			*((uv32 *)(0x00 + GPIOC_BASE))
#define GPIOC_OTYPER		*((uv32 *)(0x04 + GPIOC_BASE))
#define GPIOC_OSPEEDR		*((uv32 *)(0x08 + GPIOC_BASE))
#define GPIOC_PUPDR         *((uv32 *)(0x0C + GPIOC_BASE))
#define GPIOC_IDR           *((uv32 *)(0x10 + GPIOC_BASE))
#define GPIOC_ODR           *((uv32 *)(0x14 + GPIOC_BASE))
#define GPIOC_BSRR          *((uv32 *)(0x18 + GPIOC_BASE))
#define GPIOC_LCKR          *((uv32 *)(0x1C + GPIOC_BASE))
#define GPIOC_AFRL          *((uv32 *)(0x20 + GPIOC_BASE))
#define GPIOC_AFRH  		*((uv32 *)(0x24 + GPIOC_BASE))

/* Registers of PORTD */ 
#define GPIOD_MODER			*((uv32 *)(0x00 + GPIOD_BASE))
#define GPIOD_OTYPER		*((uv32 *)(0x04 + GPIOD_BASE))
#define GPIOD_OSPEEDR		*((uv32 *)(0x08 + GPIOD_BASE))
#define GPIOD_PUPDR         *((uv32 *)(0x0C + GPIOD_BASE))
#define GPIOD_IDR           *((uv32 *)(0x10 + GPIOD_BASE))
#define GPIOD_ODR           *((uv32 *)(0x14 + GPIOD_BASE))
#define GPIOD_BSRR          *((uv32 *)(0x18 + GPIOD_BASE))
#define GPIOD_LCKR          *((uv32 *)(0x1C + GPIOD_BASE))
#define GPIOD_AFRL          *((uv32 *)(0x20 + GPIOD_BASE))
#define GPIOD_AFRH  		*((uv32 *)(0x24 + GPIOD_BASE))

/* Registers of PORTE */ 
#define GPIOE_MODER			*((uv32 *)(0x00 + GPIOE_BASE))
#define GPIOE_OTYPER		*((uv32 *)(0x04 + GPIOE_BASE))
#define GPIOE_OSPEEDR		*((uv32 *)(0x08 + GPIOE_BASE))
#define GPIOE_PUPDR         *((uv32 *)(0x0C + GPIOE_BASE))
#define GPIOE_IDR           *((uv32 *)(0x10 + GPIOE_BASE))
#define GPIOE_ODR           *((uv32 *)(0x14 + GPIOE_BASE))
#define GPIOE_BSRR          *((uv32 *)(0x18 + GPIOE_BASE))
#define GPIOE_LCKR          *((uv32 *)(0x1C + GPIOE_BASE))
#define GPIOE_AFRL          *((uv32 *)(0x20 + GPIOE_BASE))
#define GPIOE_AFRH  		*((uv32 *)(0x24 + GPIOE_BASE))

/* Registers of PORTF */ 
#define GPIOF_MODER			*((uv32 *)(0x00 + GPIOF_BASE))
#define GPIOF_OTYPER		*((uv32 *)(0x04 + GPIOF_BASE))
#define GPIOF_OSPEEDR		*((uv32 *)(0x08 + GPIOF_BASE))
#define GPIOF_PUPDR         *((uv32 *)(0x0C + GPIOF_BASE))
#define GPIOF_IDR           *((uv32 *)(0x10 + GPIOF_BASE))
#define GPIOF_ODR           *((uv32 *)(0x14 + GPIOF_BASE))
#define GPIOF_BSRR          *((uv32 *)(0x18 + GPIOF_BASE))
#define GPIOF_LCKR          *((uv32 *)(0x1C + GPIOF_BASE))
#define GPIOF_AFRL          *((uv32 *)(0x20 + GPIOF_BASE))
#define GPIOF_AFRH  		*((uv32 *)(0x24 + GPIOF_BASE))

/* Registers of PORTG */ 
#define GPIOG_MODER			*((uv32 *)(0x00 + GPIOG_BASE))
#define GPIOG_OTYPER		*((uv32 *)(0x04 + GPIOG_BASE))
#define GPIOG_OSPEEDR		*((uv32 *)(0x08 + GPIOG_BASE))
#define GPIOG_PUPDR         *((uv32 *)(0x0C + GPIOG_BASE))
#define GPIOG_IDR           *((uv32 *)(0x10 + GPIOG_BASE))
#define GPIOG_ODR           *((uv32 *)(0x14 + GPIOG_BASE))
#define GPIOG_BSRR          *((uv32 *)(0x18 + GPIOG_BASE))
#define GPIOG_LCKR          *((uv32 *)(0x1C + GPIOG_BASE))
#define GPIOG_AFRL          *((uv32 *)(0x20 + GPIOG_BASE))
#define GPIOG_AFRH  		*((uv32 *)(0x24 + GPIOG_BASE))

/* Registers of PORTH */ 
#define GPIOH_MODER			*((uv32 *)(0x00 + GPIOH_BASE))
#define GPIOH_OTYPER		*((uv32 *)(0x04 + GPIOH_BASE))
#define GPIOH_OSPEEDR		*((uv32 *)(0x08 + GPIOH_BASE))
#define GPIOH_PUPDR         *((uv32 *)(0x0C + GPIOH_BASE))
#define GPIOH_IDR           *((uv32 *)(0x10 + GPIOH_BASE))
#define GPIOH_ODR           *((uv32 *)(0x14 + GPIOH_BASE))
#define GPIOH_BSRR          *((uv32 *)(0x18 + GPIOH_BASE))
#define GPIOH_LCKR          *((uv32 *)(0x1C + GPIOH_BASE))
#define GPIOH_AFRL          *((uv32 *)(0x20 + GPIOH_BASE))
#define GPIOH_AFRH  		*((uv32 *)(0x24 + GPIOH_BASE))


#define BSRR_OFFSET			16U
#define LCKK				16U

#endif
