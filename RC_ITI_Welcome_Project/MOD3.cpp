#include"MOD3.h"
#include "IR_sensor.h"
MOD3_CLASS::MOD3_CLASS()
{

}
void MOD3_CLASS::MOD3_TASK_Init(void)
{
  MOTOR.ROBOT_MOVE_Init();
  MOTOR.ROBOT_MOVE_Stop();
  sensor2.IR_Init();
  u8_ir_right=0;
  u8_ir_left=0;
  u8_ir_middle=0;
}

void MOD3_CLASS::MOD3_get_ir_value(void)
{
  sensor2.IR_RIGHT(&u8_ir_right);
  sensor2.IR_MIDDLE(&u8_ir_middle);
  sensor2.IR_LEFT(&u8_ir_left);
  /*
  Serial.print("IR_RIGHT_PIN : ");
  Serial.println(u8_ir_right);
  Serial.print("IR_MIDDLE_PIN : ");
  Serial.println(u8_ir_middle);
  Serial.print("IR_LEFT_PIN : ");
  Serial.println(u8_ir_left);
  */
}

ERROR_STATUS MOD3_CLASS::MOD3_LINE_FOLLOWER(void)
{
  MOD3_get_ir_value();
  if((u8_ir_right == 0)&&(u8_ir_middle == 1)&&(u8_ir_left == 0))
  {
    //Serial.println("ROBOT_forward 1");
    MOTOR.ROBOT_MOVE_FORWORD(MOTOR_SPEED);
    delay(5);
    MOTOR.ROBOT_MOVE_Stop();
    u8_ir_left_error=0;  
    u8_ir_right_error=0;
    u8_ir_medal_error=1;
  }
  else
  {
    
  } 
  //---------------------------------------------------------------
  //MOTOR.ROBOT_MOVE_Stop();
  MOD3_get_ir_value();
  if((u8_ir_right == 1)&&(u8_ir_middle == 1)&&(u8_ir_left == 0))
  {
    Serial.println("ROBOT_right 1");
    //MOTOR.ROBOT_MOVE_Right(255);
    MOTOR.ROBOT_MOVE_turn_360_pos2(MOTOR_SPEED);
    delay(200);
    MOTOR.ROBOT_MOVE_Stop();
    u8_ir_left_error=0;  
    u8_ir_right_error=1;
    u8_ir_medal_error=0;
  }
  else
  {

  }
  //---------------------------------------------------------------
  //MOTOR.ROBOT_MOVE_Stop();
  MOD3_get_ir_value();
  if((u8_ir_right == 1)&&(u8_ir_middle == 0)&&(u8_ir_left == 0))
  {
    Serial.println("ROBOT_right 2");
    //MOTOR.ROBOT_MOVE_Right(255);
    MOTOR.ROBOT_MOVE_turn_360_pos2(MOTOR_SPEED);
    delay(200);
    MOTOR.ROBOT_MOVE_Stop();
    u8_ir_left_error=0;  
    u8_ir_right_error=1;
    u8_ir_medal_error=0;
  }
  else
  {

  } 
  //---------------------------------------------------------------
  //MOTOR.ROBOT_MOVE_Stop();
  MOD3_get_ir_value();
  if((u8_ir_right == 0)&&(u8_ir_middle == 1)&&(u8_ir_left == 1))//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
  {
    //MOTOR.ROBOT_MOVE_Left(255);
    Serial.println("ROBOT_left 1");
    MOTOR.ROBOT_MOVE_turn_360_pos1(MOTOR_SPEED);
    delay(300);
    MOTOR.ROBOT_MOVE_Stop();
    u8_ir_left_error=1;  
    u8_ir_right_error=0;
    u8_ir_medal_error=0;
  }
  else
  {
    
  }
  //MOTOR.ROBOT_MOVE_Stop();
  MOD3_get_ir_value();
  if((u8_ir_right == 0)&&(u8_ir_middle == 0)&&(u8_ir_left == 1))
  {
    //MOTOR.ROBOT_MOVE_Left(255);
    Serial.println("ROBOT_left 2");
    MOTOR.ROBOT_MOVE_turn_360_pos1(MOTOR_SPEED);
    delay(200);
    MOTOR.ROBOT_MOVE_Stop();
    u8_ir_left_error=1;  
    u8_ir_right_error=0;
    u8_ir_medal_error=0;
  }
  else
  {
    
  }
  //---------------------------------------------------------------
  //MOTOR.ROBOT_MOVE_Stop();
  MOD3_get_ir_value();
  if((u8_ir_right == 1)&&(u8_ir_middle == 1)&&(u8_ir_left == 1))
  {
    Serial.println("ROBOT_stop 1");
    MOTOR.ROBOT_MOVE_Stop();
    u8_ir_left_error=0;  
    u8_ir_right_error=0;
    u8_ir_medal_error=0;

  }
  else
  {
   
  }
  //---------------------------------------------------------------
 // MOTOR.ROBOT_MOVE_Stop();
  MOD3_get_ir_value();
  if((u8_ir_right == 0)&&(u8_ir_middle == 0)&&(u8_ir_left == 0))
  {
    
    Serial.println("ROBOT_out");
    if(u8_ir_left_error ==1)
    {
      MOTOR.ROBOT_MOVE_turn_360_pos2(MOTOR_SPEED);
      delay(300);
      MOTOR.ROBOT_MOVE_Stop();
    }
    else if(u8_ir_right_error ==1)
    {
      MOTOR.ROBOT_MOVE_turn_360_pos1(MOTOR_SPEED);
      delay(200);
      MOTOR.ROBOT_MOVE_Stop();
    }
    else if(u8_ir_medal_error==1)
    {
      MOTOR.ROBOT_MOVE_Backword(MOTOR_SPEED);
      delay(5);
      MOTOR.ROBOT_MOVE_turn_360_pos1(MOTOR_SPEED);
      delay(2);
      MOTOR.ROBOT_MOVE_Stop();
    }
    //MOTOR.ROBOT_MOVE_FORWORD(110);
    //delay(500);
  }
  else
  {
    
  }
  //MOTOR.ROBOT_MOVE_Stop();
}

MOD3_CLASS APP3=MOD3_CLASS ();
