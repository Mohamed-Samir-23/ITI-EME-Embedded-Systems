#ifndef MOD4_h
#define MOD4_h
#include"MOD2.h"
/********************************** MOTOR SPEED **********************************/
#define set_speed_Mod4 88
/********************************** WALL DIMENSION **********************************/
#define wall_max 20
#define front_max 15

class MOD4_CLASS{
  public:
    MOD4_CLASS();
    void MOD4_TASK_Init(void);
    ERROR_STATUS MOD4_Maze_Solving (void);
    ERROR_STATUS MOD4_SENSOR_UPDATE_VALUE (void);
    ERROR_STATUS MOD4_WALL_DETECTION (void);
  private:
    unit16 u16_distance_forward_mod4;
    unit16 u16_distance_right_mod4;
    unit16 u16_distance_left_mod4;
    unit16 u16_new_distance_forward_mod4;
    unit16 u16_new_distance_right_mod4;
    unit16 u16_new_distance_left_mod4;
    unit16 u16_old_distance_forward_mod4;
    unit16 u16_old_distance_right_mod4;
    unit16 u16_old_distance_left_mod4;
    unit8 u8_front_wall ;
    unit8 u8_left_wall ;
    unit8 u8_right_wall ;
    unit8 u8_first_turn ;
    unit8 u8_right_Wall_Follow ;
    unit8 u8_left_Wall_Follow ;
    unit8 u8_START;

};

extern MOD4_CLASS APP4;

#endif