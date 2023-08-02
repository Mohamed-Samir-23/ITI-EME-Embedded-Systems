#ifndef ir_sensor_h
#define ir_sensor_h
#include "STD.h"
#include "Arduino.h"
/********************************** ULTRASONIC PIN **********************************/
#define IR_RIGHT_PIN PIN10
#define IR_LEFT_PIN PIN5
#define IR_MIDDLE_PIN A3


class IR_CLASS{
  public:
    IR_CLASS();
    void IR_Init(void);
    ERROR_STATUS IR_RIGHT (unit8 *u8_color);
    ERROR_STATUS IR_MIDDLE (unit8 *u8_color);
    ERROR_STATUS IR_LEFT (unit8 *u8_color);


};

extern IR_CLASS sensor2;

#endif
