/****************************************/
/*  Author		: Mohamed Samir			*/
/*  SWC			: EXTI					*/
/*  Layer		: MCAL					*/
/*  Version		: 1.0					*/
/*  Date		: September 19, 2023	*/
/*  Last Edit	: N/A					*/
/****************************************/

#define _MEXTI_INTERFACE_H_
#define _MEXTI_INTERFACE_H_

typedef enum 
{
	
	LINE0=0,
	LINE1,
	LINE2,
	LINE3,
	LINE4,
	LINE5,
	LINE6,
	LINE7,
	LINE8,
	LINE9,
	LINE10,
	LINE11,
	LINE12,
	LINE13,
	LINE14,
	LINE15,
	
}MEXTI_LINE_t;


typedef enum 
{
	FALLING_TRIGGER=0,
	RISING_TRIGGER,
	
}MEXTI_EVENT_TYPE_t;



typedef enum 
{
	GPIOA = 0,
	GPIOB = 1,
	GPIOC = 2,
	GPIOD = 3,
	GPIOE = 4,
	GPIOH = 7,
	
}MEXTI_PORT_NAME_t;


STD_error_t MEXTI_stderrorNotMasK
(
	MEXTI_LINE_t ARG_udtLineNumber
);


STD_error_t MEXTI_stderrorMasK
(
	MEXTI_LINE_t ARG_udtLineNumber
);


STD_error_t MEXTI_stderrorEventType
(
	MEXTI_LINE_t ARG_udtLineNumber,
	MEXTI_EVENT_TYPE_t ARG_udtEventType
);

STD_error_t MEXTI_stderrorSWTrigger
(
	MEXTI_LINE_t ARG_udtLineNumber,
);

STD_error_t MEXTI_stderrorSelectPort
(
	MEXTI_LINE_t ARG_udtLineNumber,
	MEXTI_PORT_NAME_t ARG_udtPortName
);

#endif