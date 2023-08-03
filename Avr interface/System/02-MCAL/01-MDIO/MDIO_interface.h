/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: DIO				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.1				*/
/*  Date		: August 3, 2023	*/
/*  Last Edit	: August 3, 2023	*/
/************************************/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA 	1
#define MDIO_PORTB 	2
#define MDIO_PORTC 	3
#define MDIO_PORTD 	4

#define MDIO_LOW 	1
#define MDIO_HIGH 	2

typedef enum
{
	MDIO_INPUT_FLOAT,
	MDIO_OUTPUT,
	MDIO_INPUT_PULLUP,
}MDIO_mode;

STD_error_t MDIO_stderrorSetPortDirection
(
	u8 ARG_u8Port,
	u8 ARG_u8Direction
);

STD_error_t MDIO_stderrorSetPortValue
(
	u8 ARG_u8Port,
	u8 ARG_u8Value
);


STD_error_t MDIO_stderrorGetPortValue
(
	u8 ARG_u8Port,
	u8* ARG_pu8pValue
);


STD_error_t MDIO_stderrorSetPinDirection
(
	u8 ARG_u8Port,
	u8 ARG_u8pin,
	MDIO_mode ARG_u8Mode
);

STD_error_t MDIO_stderrorSetPinValue
(
	u8 ARG_u8Port,
	u8 ARG_u8pin,
	u8 ARG_u8Value
);

STD_error_t MDIO_stderrorGetPinValue
(
	u8 ARG_u8Port,
	u8 ARG_u8pin,
	u8* ARG_pu8Value
);

#endif