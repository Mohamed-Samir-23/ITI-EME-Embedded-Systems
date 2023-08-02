#ifndef robot_move_h
#define robot_move_h
#include "STD.h"
#include "Arduino.h"
/********************************** LEFT MOTOR **********************************/
#define IN1 		PIN13
#define IN2 		PIN12
#define ENA 		PIN11
/********************************** RIGHT MOTOR **********************************/
#define IN3 		PIN8
#define IN4 		PIN7
#define ENB 		PIN6
/********************************** SPEED MOTOR **********************************/
#define OUTPUT_MAX_speed 255
#define OUTPUT_LOW_speed 0

class Robot_Move_Class{
  public:
    Robot_Move_Class();
    void ROBOT_MOVE_Init(void);
    void ROBOT_MOVE_Stop(void);
    ERROR_STATUS ROBOT_MOVE_FORWORD(unit8 u8_speed);
    ERROR_STATUS ROBOT_MOVE_Backword(unit8 u8_speed);
    void ROBOT_MOVE_Right(unit8 u8_speed);
    void ROBOT_MOVE_Left(unit8 u8_speed);
    ERROR_STATUS ROBOT_MOVE_ANGLE_FORWORD(unit8 u8_speed_A,unit8 u8_speed_B);
    ERROR_STATUS ROBOT_MOVE_ANGLE_Backword(unit8 u8_speed_A,unit8 u8_speed_B);
    void ROBOT_MOVE_turn_360_pos1(unit8 u8_speed);
    void ROBOT_MOVE_turn_360_pos2(unit8 u8_speed);
    
};

extern Robot_Move_Class MOTOR;

#endif