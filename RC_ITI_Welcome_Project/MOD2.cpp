#include"MOD2.h"
Servo myservo;

MOD2_CLASS::MOD2_CLASS()
{


}
void MOD2_CLASS::MOD2_TASK_Init(void)
{
  MOTOR.ROBOT_MOVE_Init();
  MOTOR.ROBOT_MOVE_Stop();
  sensor1.ULTRASONIC_Init();
  myservo.attach(servo_PIN);
  myservo.write(servo_forword_pos);
  u16_distance_forward=0;
  u16_distance_right=0;
  u16_distance_left=0; 
}
ERROR_STATUS MOD2_CLASS::MOD2_avoiding_obstacles(void)
{
  unit8 u8_Ret=E_OK;
  MOD2_look_forword (&u16_distance_forward);
  delay(100);
  MOD2_look_forword (&u16_distance_forward);
  delay(100);
  MOD2_look_forword (&u16_distance_forward);
  delay(100);
  //Serial.print("u16_distance_forward: ");
  //Serial.println(u16_distance_forward);
  if(u16_distance_forward<=min_dis)
  {
    MOTOR.ROBOT_MOVE_Stop();
    delay(300);
    MOTOR.ROBOT_MOVE_Backword(MOTOR_SPEED_MAX_MOD2);
    delay(400);
    MOTOR.ROBOT_MOVE_Stop();
    delay(300);
    MOD2_look_right (&u16_distance_right);
    delay(800);
    //Serial.print("u16_distance_right: ");
    //Serial.println(u16_distance_right);
    MOD2_look_left (&u16_distance_left);
    delay(800);
    //Serial.print("u16_distance_left: ");
    //Serial.println(u16_distance_left);

    if (u16_distance_right >= u16_distance_left) 
    {
        MOTOR.ROBOT_MOVE_Right(MOTOR_SPEED_MIN_MOD2);
        delay(1000);
        MOTOR.ROBOT_MOVE_Stop();
    } 
    else 
    { // Or else carry on
        MOTOR.ROBOT_MOVE_Left(MOTOR_SPEED_MIN_MOD2);
        delay(1000);
        MOTOR.ROBOT_MOVE_Stop();
    }
  }
  else
  {
    MOTOR.ROBOT_MOVE_FORWORD(MOTOR_SPEED_MAX_MOD2);
    delay(300);
    MOTOR.ROBOT_MOVE_Stop();
  }
  return u8_Ret;
}

ERROR_STATUS MOD2_CLASS::MOD2_look_forword (unit16 *u16_distance)
{
  unit8 u8_Ret=E_OK;
  myservo.write(servo_forword_pos);
  sensor1.ULTRASONIC_DISTANCE(u16_distance);
  return u8_Ret;
}
ERROR_STATUS MOD2_CLASS::MOD2_look_right (unit16 *u16_distance)
{
  unit8 u8_Ret=E_OK;
  myservo.write(servo_right_pos);
  sensor1.ULTRASONIC_DISTANCE(u16_distance);
  delay(500);
  myservo.write(servo_forword_pos);
  return u8_Ret;

}
ERROR_STATUS MOD2_CLASS::MOD2_look_left (unit16 *u16_distance)
{
  unit8 u8_Ret=E_OK;
  myservo.write(servo_left_pos);
  sensor1.ULTRASONIC_DISTANCE(u16_distance);
  delay(500);
  myservo.write(servo_forword_pos);
  return u8_Ret;
}

MOD2_CLASS APP2=MOD2_CLASS();