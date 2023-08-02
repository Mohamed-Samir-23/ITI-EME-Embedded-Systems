#include "Ultrasonic.h"

ULTRASONIC_CLASS::ULTRASONIC_CLASS()
{

}

void ULTRASONIC_CLASS::ULTRASONIC_Init(void)
{
  pinMode(TRIG_ULTRASONIC_PIN, OUTPUT); 
  pinMode(ECHO_ULTRASONIC_PIN, INPUT); 
}


ERROR_STATUS ULTRASONIC_CLASS::ULTRASONIC_DISTANCE (unit16 *u16_distance)
{
  unit8 u8_Ret=E_OK;
  digitalWrite(TRIG_ULTRASONIC_PIN, LOW);// Clears the trig
  delayMicroseconds(2);// Sets the trig on HIGH state for 10 micro seconds
  digitalWrite(TRIG_ULTRASONIC_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_ULTRASONIC_PIN, LOW);
  u32_duration = pulseIn(ECHO_ULTRASONIC_PIN, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  *u16_distance = u32_duration * 0.034 / 2;// Calculating the distance
  if (0==(*u16_distance))
  {
    *u16_distance=250;
  }
  else
  {

  }
  return u8_Ret;
}
ULTRASONIC_CLASS sensor1 = ULTRASONIC_CLASS();