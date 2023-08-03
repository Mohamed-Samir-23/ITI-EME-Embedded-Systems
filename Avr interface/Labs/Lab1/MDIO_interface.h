/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: DIO				*/
/*  Layer		: MCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 3, 2023	*/
/*  Last Edit	: N/A				*/
/************************************/

#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

void MDIO_voidSetPortDirection
(
	u8 ARG_u8Port,
	u8 ARG_u8Direction
);

void MDIO_voidSetPortValue
(
	u8 ARG_u8Port,
	u8 ARG_u8Value
);


u8 MDIO_u8GetPortValue
(
	u8 ARG_u8Port
);

#endif
