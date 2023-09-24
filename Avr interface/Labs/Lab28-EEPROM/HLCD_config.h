/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: LCD				*/
/*  Layer		: HCAL				*/
/*  Version		: 1.0				*/
/*  Date		: August 8, 2023	*/
/*  Last Edit	: N/A				*/
/************************************/

#ifndef _HLCD_CONFIG_H_
#define _HLCD_CONFIG_H_
#define  F_CPU    8000000UL

#define LCD_DATA_PORT       MDIO_PORTD
#define LCD_CONTROL_PORT    MDIO_PORTB
#define LCD_RS_PIN          MDIO_PIN1
#define LCD_RW_PIN          MDIO_PIN2
#define LCD_E_PIN           MDIO_PIN3

#endif
