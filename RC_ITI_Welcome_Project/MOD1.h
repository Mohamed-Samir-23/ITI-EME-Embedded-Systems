#ifndef MOD1_h
#define MOD1_h
#include"ROBOT_MOVE.h"
#include<SoftwareSerial.h>
/********************************** RX/TX PIN **********************************/
#define RX_APP1 		PIN3
#define TX_APP1 		PIN4
/********************************** BLUETOOTH MSG **********************************/
#define FOREWORD_RC 70
#define BACKWORD_RC 66
#define RIGHT_RC 82
#define LEFT_RC 76
#define FOREWORD_RIGHT_RC 73
#define FOREWORD_LEFT_RC 71
#define BACKWORD_RIGHT_RC 74
#define BACKWORD_LEFT_RC 72
#define STOP_RC 83
/********************************** MOTOR SPEED **********************************/
#define MOTOR_SPEED_MAX_MOD1 200
#define MOTOR_SPEED_MIN_MOD1 80
#define MOTOR_SPEED_right_MOD1 250


class MOD1_CLASS{
  public:
    MOD1_CLASS();
    void MOD1_TASK_Init(void);
    ERROR_STATUS MOD1_TASK_Bluetooth_control(void);

};

extern MOD1_CLASS APP1;

#endif
