#include "IR_sensor.h"

IR_CLASS::IR_CLASS()
{

}
void IR_CLASS::IR_Init(void)
{
  pinMode(IR_RIGHT_PIN, INPUT);
  pinMode(IR_MIDDLE_PIN, INPUT);
  pinMode(IR_LEFT_PIN, INPUT);
}
ERROR_STATUS IR_CLASS::IR_RIGHT (unit8 *u8_color)
{
  unit8 u8_Ret=E_OK;
  *u8_color=digitalRead(IR_RIGHT_PIN);
  if(*u8_color>1)
  {
    *u8_color=0;
    u8_Ret=E_NOT_OK;
  }
  return u8_Ret;
}
ERROR_STATUS IR_CLASS::IR_MIDDLE (unit8 *u8_color)
{
  unit8 u8_Ret=E_OK;
  *u8_color=digitalRead(IR_MIDDLE_PIN);
  if(*u8_color>1)
  {
    *u8_color=0;
    u8_Ret=E_NOT_OK;
  }
  return u8_Ret;
}

ERROR_STATUS IR_CLASS::IR_LEFT (unit8 *u8_color)
{
  unit8 u8_Ret=E_OK;
  *u8_color=digitalRead(IR_LEFT_PIN);
  if(*u8_color>1)
  {
    *u8_color=0;
    u8_Ret=E_NOT_OK;
  }
  return u8_Ret;
}

IR_CLASS sensor2=IR_CLASS();