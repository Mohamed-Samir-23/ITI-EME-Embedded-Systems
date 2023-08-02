#include "MOD1.h"
SoftwareSerial TEXT_BT(TX_APP1, RX_APP1);  //Tx-3 Rx-4 bt(3,4);
unit8 u8_Bluetooth_text;
MOD1_CLASS::MOD1_CLASS() {
}
void MOD1_CLASS::MOD1_TASK_Init(void) {
  pinMode(TX_APP1, INPUT);
  pinMode(RX_APP1, OUTPUT);
  TEXT_BT.begin(9600);
  MOTOR.ROBOT_MOVE_Init();
  MOTOR.ROBOT_MOVE_Stop();
}

ERROR_STATUS MOD1_CLASS::MOD1_TASK_Bluetooth_control(void) {
  unit8 u8_Ret=E_OK;
  if (TEXT_BT.available())
    {
      //Serial.println(TEXT_BT.read());
      u8_Bluetooth_text=TEXT_BT.read();
      switch(u8_Bluetooth_text)
      {
        case FOREWORD_RC :MOTOR.ROBOT_MOVE_FORWORD(MOTOR_SPEED_MAX_MOD1);break;
        case BACKWORD_RC :MOTOR.ROBOT_MOVE_Backword(MOTOR_SPEED_MAX_MOD1);break;
        case RIGHT_RC :MOTOR.ROBOT_MOVE_Right(MOTOR_SPEED_right_MOD1);break;
        case LEFT_RC :MOTOR.ROBOT_MOVE_Left(MOTOR_SPEED_MIN_MOD1);break;
        case FOREWORD_RIGHT_RC :MOTOR.ROBOT_MOVE_ANGLE_FORWORD(MOTOR_SPEED_MIN_MOD1,MOTOR_SPEED_MAX_MOD1);break;//a-left
        case FOREWORD_LEFT_RC :MOTOR.ROBOT_MOVE_ANGLE_FORWORD(MOTOR_SPEED_MAX_MOD1,MOTOR_SPEED_MIN_MOD1);break;
        case BACKWORD_RIGHT_RC :MOTOR.ROBOT_MOVE_ANGLE_Backword(MOTOR_SPEED_MIN_MOD1,MOTOR_SPEED_MAX_MOD1);break;
        case BACKWORD_LEFT_RC :MOTOR.ROBOT_MOVE_ANGLE_Backword(MOTOR_SPEED_MAX_MOD1,MOTOR_SPEED_MIN_MOD1);break;
        case STOP_RC:MOTOR.ROBOT_MOVE_Stop();break;
        default :{Serial.println("this masg not handling");u8_Ret=E_NOT_OK;break;}
      }
    }
    else
    {
      //Serial.println("Bluetooth Not connected");
      u8_Ret=E_NOT_OK;
    }
    return u8_Ret;
}

MOD1_CLASS APP1 = MOD1_CLASS();