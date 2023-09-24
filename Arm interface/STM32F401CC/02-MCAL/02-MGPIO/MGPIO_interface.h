/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: GPIO					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 17, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#ifndef _MGPIO_INTERFACE_H_
#define _MGPIO_INTERFACE_H_

typedef enum 
{
	GPIOA = 0,
	GPIOB = 1,
	GPIOC = 2,
	GPIOD = 3,
	GPIOE = 4,
	GPIOF = 5,
	GPIOG = 6,
	GPIOH = 7,
	
}MGPIO_PORT_Name_t;

typedef enum
{
	PIN0  = 0,
	PIN1  = 1,
	PIN2  = 2,
	PIN3  = 3,
	PIN4  = 4,
	PIN5  = 5,
	PIN6  = 6,
	PIN7  = 7,
	PIN8  = 8,
	PIN9  = 9,
	PIN10 = 10,
	PIN11 = 11,
	PIN12 = 12,
	PIN13 = 13,
	PIN14 = 14,
	PIN15 = 15,
	
}MGPIO_PIN_Number_t;


typedef enum 
{
	INPUT 	= 0,
	OUTPUT 	= 1,
	ALTFUN 	= 2,
	ANALOG 	= 3,
	
}MGPIO_PIN_Mode_t;

typedef enum 
{
	PUSH_PULL 	= 0,
	OPEN_DRAIN 	= 1,

}MGPIO_OUTPIN_Mode_t;

typedef enum 
{
	LOW_SPEED 		= 0,
	MEDIUM_SPEED 	= 1,
	HIGH_SPEED 		= 2,
	VERY_HIGH_SPEED	= 3,
	
}MGPIO_OUTPIN_Speed_t;

typedef enum 
{
	NO_PULL 	= 0,
	PULL_UP 	= 1,
	PULL_DOWN 	= 2,

}MGPIO_PULL_t;


typedef enum
{
	LOW 	= 0,
	HIGH 	= 1,
	
}MGPIO_OUTPUT_State_t;



typedef enum 
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}MGPIO_ALT_Mode_t;

STD_error_t MGPIO_stderrorPinModeSelect
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_PIN_Mode_t ARG_udtGPIOMode
);

STD_error_t MGPIO_stderrorSetOutputPintype
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPIN_Mode_t ARG_udtOutMode
);

STD_error_t MGPIO_stderrorSetOutputPinSpeed
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPIN_Speed_t ARG_udtOutSpeed
);

STD_error_t MGPIO_stderrorSetPinPull_Up_Down
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_PULL_t ARG_udtPullType
);


STD_error_t MGPIO_stderrorGetPinValue
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	u8* ARG_pu8Value
);

STD_error_t MGPIO_stderrorSetPinValue
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPUT_State_t ARG_udtValue
);

STD_error_t MGPIO_stderrorSetPinValueBSSR
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin, 
	MGPIO_OUTPUT_State_t ARG_udtValue
);

STD_error_t MGPIO_stderrorPinLock
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin
);

STD_error_t MGPIO_stderrorSetPinAltFun
(
	MGPIO_PORT_Name_t ARG_udtGPIOPort, 
	MGPIO_PIN_Number_t ARG_udtGPIOPin,
	MGPIO_ALT_Mode_t ARG_udtAltPinMode
);


#endif
