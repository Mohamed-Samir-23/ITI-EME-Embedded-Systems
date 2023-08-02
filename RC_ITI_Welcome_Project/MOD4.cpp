#include"MOD4.h"
MOD4_CLASS::MOD4_CLASS()
{

}
void MOD4_CLASS::MOD4_TASK_Init(void)
{
  APP2.MOD2_TASK_Init();
  u16_distance_forward_mod4=0;
  u16_distance_right_mod4=0;
  u16_distance_left_mod4=0;
  u16_new_distance_forward_mod4=0;
  u16_new_distance_right_mod4=0;
  u16_new_distance_left_mod4=0;
  u16_old_distance_forward_mod4=0;
  u16_old_distance_right_mod4=0;
  u16_old_distance_left_mod4=0;
  u8_right_Wall_Follow=0;
  u8_left_Wall_Follow=0;
  u8_START=0;
}
ERROR_STATUS MOD4_CLASS::MOD4_Maze_Solving (void)
{
  unsigned char u8_Ret=E_OK;
  APP4.MOD4_SENSOR_UPDATE_VALUE();
  APP4.MOD4_WALL_DETECTION();

  if (u8_left_wall == 1 && u8_right_wall == 0 && u8_front_wall == 1 )
  {
    MOTOR.ROBOT_MOVE_Right(set_speed_Mod4);
  }
  if (u8_left_wall == 0 && u8_right_wall == 1 && u8_front_wall == 1 )
  {
    MOTOR.ROBOT_MOVE_Left(set_speed_Mod4);
  }
  if (u8_left_wall == 1 && u8_right_wall == 1 && u8_front_wall == 0 )
  {
    MOTOR.ROBOT_MOVE_FORWORD(set_speed_Mod4);
  }
  if ( u16_distance_left_mod4 == 0 || u16_distance_left_mod4 > 100 && u16_distance_right_mod4 == 0 || u16_distance_right_mod4 > 100 && u16_distance_forward_mod4 == 0 || u16_distance_forward_mod4 > 100 ) {

    MOTOR.ROBOT_MOVE_Stop();
  }
  return u8_Ret;
}

ERROR_STATUS MOD4_CLASS::MOD4_SENSOR_UPDATE_VALUE (void)
{

  unsigned char u8_Ret=E_OK;
  APP2.MOD2_look_right(&u16_new_distance_right_mod4);
  APP2.MOD2_look_left(&u16_new_distance_left_mod4);
  APP2.MOD2_look_forword(&u16_new_distance_forward_mod4);
  
  u16_distance_forward_mod4=(u16_new_distance_forward_mod4+u16_old_distance_forward_mod4)/2;
  u16_distance_right_mod4=(u16_new_distance_right_mod4+u16_old_distance_right_mod4)/2;
  u16_distance_left_mod4=(u16_new_distance_left_mod4+u16_old_distance_left_mod4)/2;

  u16_old_distance_forward_mod4=u16_distance_forward_mod4;
  u16_old_distance_right_mod4=u16_distance_right_mod4;
  u16_old_distance_left_mod4=u16_distance_left_mod4;

  return u8_Ret;

}

//#define wall_max 20
//#define front_max 15
//u8_front_wall ;
//u8_left_wall ;
//u8_right_wall ;
ERROR_STATUS MOD4_CLASS::MOD4_WALL_DETECTION (void)
{
  unsigned char u8_Ret=E_OK;
  if ( u16_distance_left_mod4 < wall_max ) 
  {
    u8_left_wall = 1 ;
  }
  else 
  {
    u8_left_wall = 0 ;
  }


  if ( u16_distance_right_mod4 < wall_max ) 
  {
    u8_right_wall = 1 ;
  }
  else 
  {
    u8_right_wall = 0 ;

  } 
  if ( u16_distance_forward_mod4 < front_max ) 
  {
    u8_front_wall = 1 ;
  }
  else 
  {
    u8_front_wall = 0 ;
  }

  return u8_Ret;

}


MOD4_CLASS APP4=MOD4_CLASS();