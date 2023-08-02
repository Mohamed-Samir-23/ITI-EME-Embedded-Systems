    #include"ROBOT_MOVE.h"
    Robot_Move_Class::Robot_Move_Class()
    {
      Serial.println("constructor");
    }

    void Robot_Move_Class::ROBOT_MOVE_Init(void)
    {
        Serial.println("ROBOT_MOVE_Init");
      	pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
        pinMode(ENA, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(IN4, OUTPUT);
        pinMode(ENB, OUTPUT);
        /********************************** Turn off motors-- Initial state **********************************/
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, OUTPUT_LOW_speed);
	    analogWrite(ENB, OUTPUT_LOW_speed);

    }
    void Robot_Move_Class::ROBOT_MOVE_Stop(void)
    {
        Serial.println("ROBOT_MOVE_Stop");
        analogWrite(ENA, OUTPUT_LOW_speed);
	      analogWrite(ENB, OUTPUT_LOW_speed);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        
    }
    ERROR_STATUS Robot_Move_Class::ROBOT_MOVE_FORWORD(unit8 u8_speed)
    {
        unit8 u8_Ret=E_OK;
        Serial.println("ROBOT_MOVE_FORWORD");
        if((u8_speed<=OUTPUT_MAX_speed)&&(u8_speed>=OUTPUT_LOW_speed))
        {
          analogWrite(ENA, u8_speed);
	        analogWrite(ENB, u8_speed);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
        }
        else
        {
          u8_Ret=E_NOT_OK;
        }
        return u8_Ret;
    }
    ERROR_STATUS Robot_Move_Class::ROBOT_MOVE_Backword(unit8 u8_speed)
    {
        unit8 u8_Ret=E_OK;
        Serial.println("ROBOT_MOVE_Backword");
        if((u8_speed<=OUTPUT_MAX_speed)&&(u8_speed>=OUTPUT_LOW_speed))
        {
          analogWrite(ENA, u8_speed);
	      analogWrite(ENB, u8_speed);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
        }
        else
        {
          u8_Ret=E_NOT_OK;
        }
        return u8_Ret;
    }
    void Robot_Move_Class::ROBOT_MOVE_Right(unit8 u8_speed)
    {
          Serial.println("ROBOT_MOVE_Right");
          analogWrite(ENA, u8_speed);
	      analogWrite(ENB, u8_speed);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
    }
    void Robot_Move_Class::ROBOT_MOVE_Left(unit8 u8_speed)
    {
          Serial.println("ROBOT_MOVE_Left");
          analogWrite(ENA, u8_speed);
	      analogWrite(ENB, u8_speed);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
    }
    ERROR_STATUS Robot_Move_Class::ROBOT_MOVE_ANGLE_FORWORD(unit8 u8_speed_A,unit8 u8_speed_B)
    {
        unit8 u8_Ret=E_OK;
        Serial.println("ROBOT_MOVE_ANGLE_FORWORD");
        if((u8_speed_A<=OUTPUT_MAX_speed)&&(u8_speed_B<=OUTPUT_MAX_speed)&&(u8_speed_A>=OUTPUT_LOW_speed)&&(u8_speed_B>=OUTPUT_LOW_speed))
        {
          analogWrite(ENA, u8_speed_A);
	      analogWrite(ENB, u8_speed_B);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
        }
        else
        {
          u8_Ret=E_NOT_OK;
        }
        return u8_Ret;
    }
    ERROR_STATUS Robot_Move_Class::ROBOT_MOVE_ANGLE_Backword(unit8 u8_speed_A,unit8 u8_speed_B)
    {
        unit8 u8_Ret=E_OK;
        Serial.println("ROBOT_MOVE_ANGLE_Backword");
        if((u8_speed_A<=OUTPUT_MAX_speed)&&(u8_speed_B<=OUTPUT_MAX_speed)&&(u8_speed_A>=OUTPUT_LOW_speed)&&(u8_speed_B>=OUTPUT_LOW_speed))
        {
          analogWrite(ENA, u8_speed_A);
	        analogWrite(ENB, u8_speed_B);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
        }
        else
        {
          u8_Ret=E_NOT_OK;
        }
        return u8_Ret;

    }
    void Robot_Move_Class::ROBOT_MOVE_turn_360_pos1(unit8 u8_speed)
    {
          Serial.println("ROBOT_MOVE_turn_360_pos1");
          analogWrite(ENA, u8_speed);
	      analogWrite(ENB, u8_speed);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);

    }
    void Robot_Move_Class::ROBOT_MOVE_turn_360_pos2(unit8 u8_speed)
    {
          Serial.println("ROBOT_MOVE_turn_360_pos2");
          analogWrite(ENA, u8_speed);
	      analogWrite(ENB, u8_speed);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);

    }
    Robot_Move_Class MOTOR =Robot_Move_Class();