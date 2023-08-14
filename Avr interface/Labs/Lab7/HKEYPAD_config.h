/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: KEYPAD			*/
/*  Layer		: HCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 9, 2023	*/
/*  Last Edit	: N/A				*/
/************************************/

#ifndef _HKEYPAD_CONFIG_H_
#define _HKEYPAD_CONFIG_H_

#define KPD_BUTTONS {\
						{'1','2','3','+'},\
						{'4','5','6','-'},\
						{'7','8','9','*'},\
						{'.','0','=','/'},\
					}
#define KPD_BUTTONS_NUM {\
						{7,8,9,'+'},\
						{4,5,6,'-'},\
						{1,2,3,'*'},\
						{'.',0,'=','/'},\
						}

#define KEYPAD_R0_PIN		MDIO_PORTC,	MDIO_PIN0
#define KEYPAD_R1_PIN		MDIO_PORTC,	MDIO_PIN1
#define KEYPAD_R2_PIN		MDIO_PORTC,	MDIO_PIN2
#define KEYPAD_R3_PIN		MDIO_PORTC,	MDIO_PIN3

#define KEYPAD_C0_PIN		MDIO_PORTC,	MDIO_PIN4
#define KEYPAD_C1_PIN		MDIO_PORTC,	MDIO_PIN5
#define KEYPAD_C2_PIN		MDIO_PORTC,	MDIO_PIN6
#define KEYPAD_C3_PIN		MDIO_PORTC,	MDIO_PIN7


#endif
