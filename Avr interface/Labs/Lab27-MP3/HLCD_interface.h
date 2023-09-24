/************************************/
/*  Author		: Mohamed Samir		*/
/*  SWC			: LCD				*/
/*  Layer		: HCAL				*/
/*  Version		: 1.1				*/
/*  Date		: August 8, 2023	*/
/*  Last Edit	: August 9, 2023	*/
/************************************/


#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_


void HLCD_voidInit(void);
void HLCD_voidSendCmd(u8 ARG_u8Cmd);
void HLCD_voidSendChar(char ARG_u8Data);
void HLCD_voidSendString(const char * ARG_ccharpString);
void HLCD_voidSetCursor(u8 ARG_u8Row,u8 ARG_u8Col);
void HLCD_voidWriteCustom(const char * ARG_ccharpString,u8 ARG_u8Location);
void HLCD_voidClear(void);
void HLCD_voidDisplayNumber(u16 ARG_u8Num);


#endif
