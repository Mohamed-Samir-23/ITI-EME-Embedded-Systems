#ifndef MOD2_h
#define MOD2_h
#include <Servo.h>
#include "Ultrasonic.h"
#include"ROBOT_MOVE.h"
/********************************** SERVO PIN/pos **********************************/
#define servo_PIN 		PIN9
#define servo_forword_pos 		90
#define servo_left_pos 		180
#define servo_right_pos 		0
/********************************** ULTRASONIC Min distance **********************************/
#define min_dis 15 //15 cm
/********************************** MOTRO SPEED **********************************/
#define MOTOR_SPEED_MAX_MOD2 150
#define MOTOR_SPEED_MIN_MOD2 150
class MOD2_CLASS{
  public:
    MOD2_CLASS();
    void MOD2_TASK_Init(void);
    ERROR_STATUS MOD2_avoiding_obstacles(void);
    ERROR_STATUS MOD2_look_forword (unit16 *u16_distance);
    ERROR_STATUS MOD2_look_right (unit16 *u16_distance);
    ERROR_STATUS MOD2_look_left (unit16 *u16_distance);
  private:
    unit16 u16_distance_forward;
    unit16 u16_distance_right;
    unit16 u16_distance_left;


};

extern MOD2_CLASS APP2;

#endif
