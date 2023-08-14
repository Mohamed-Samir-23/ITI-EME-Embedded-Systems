/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: EXTI				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 13, 2023	*/
/*  Last Edit	: N/V				*/
/************************************/

#ifndef _MEXTI_INTERFACE_H_
#define _MEXTI_INTERFACE_H_


#define MEXTI_INT0 				6
#define MEXTI_INT1 				7
#define MEXTI_INT2				5


#define MEXTI_MODE_LOW 			1
#define MEXTI_MODE_RISING 		2
#define MEXTI_MODE_FALLING 		3
#define MEXTI_MODE_IOC 			4


STD_error_t MEXTI_stderrorInit
(
	u8 ARG_u8InterruptNo,
	u8 ARG_u8SensMode
);


STD_error_t MEXTI_stderrorEnableInterrupt
(
	u8 ARG_u8InterruptNo
);


STD_error_t MEXTI_stderrorDisableInterrupt
(
	u8 ARG_u8InterruptNo
);


STD_error_t MEXTI_stderrorSetCallBack
(
	void (*ARG_pvoidfUserFunction)(void),
	u8 ARG_u8InterruptNo
);



#endif