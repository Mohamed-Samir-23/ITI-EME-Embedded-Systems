#ifndef ultrasonic_h
#define ultrasonic_h
#include "STD.h"
#include "Arduino.h"
/********************************** ULTRASONIC PIN **********************************/
#define TRIG_ULTRASONIC_PIN A5
#define ECHO_ULTRASONIC_PIN A4


class ULTRASONIC_CLASS{
  public:
    ULTRASONIC_CLASS();
    void ULTRASONIC_Init(void);
    ERROR_STATUS ULTRASONIC_DISTANCE (unit16 *u16_distance);
  private:
    unsigned long int  u32_duration;

};

extern ULTRASONIC_CLASS sensor1;

#endif
