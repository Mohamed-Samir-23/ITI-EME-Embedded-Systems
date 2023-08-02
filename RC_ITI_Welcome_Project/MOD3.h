#ifndef MOD3_h
#define MOD3_h
#include"ROBOT_MOVE.h"

/********************************** MOTRO SPEED **********************************/
#define MOTOR_SPEED_MAX_MOD3 150
#define MOTOR_SPEED_MIN_MOD3 150
#define time_move 100
#define MOTOR_SPEED 150

class MOD3_CLASS{
  public:
    MOD3_CLASS();
    void MOD3_TASK_Init(void);
    ERROR_STATUS MOD3_LINE_FOLLOWER(void);
  private:
    void MOD3_get_ir_value(void);
    unit8 u8_ir_right;
    unit8 u8_ir_middle;
    unit8 u8_ir_left;
    unit8 u8_ir_left_error=0;  
    unit8 u8_ir_right_error=0;
    unit8 u8_ir_medal_error=0;

};

extern MOD3_CLASS APP3;

#endif