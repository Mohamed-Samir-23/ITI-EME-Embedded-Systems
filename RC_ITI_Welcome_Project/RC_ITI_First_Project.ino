/*
 * 	RC_ITI_First_Project
 *	Purpose: WELCOME PROJECT 
 *  Created on: July 08, 2023
 *  Author: Mohamed Samir
 */

#include "MOD1.h"
#include"MOD2.h"
#include"MOD3.h"
#include"MOD4.h"
#define switch_pin 2
#define MOD1_SW 0
#define MOD2_SW 1
#define MOD3_SW 2
#define MOD4_SW 3
volatile bool toggleswitch = false;
volatile unit8 MODE_SW=0;
void check_sw(void)
{
  if(digitalRead(switch_pin)==0)
  {
    if(MODE_SW==2)
    {
      MODE_SW=0;
    }
    else
    {
      MODE_SW+=1;
      
    }
  }
    return;
}

void setup() {
  Serial.begin(9600);
  APP1.MOD1_TASK_Init();
  APP2.MOD2_TASK_Init();
  APP3.MOD3_TASK_Init();
  APP4.MOD4_TASK_Init();
  pinMode(switch_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), check_sw, FALLING);
}

void loop() {
  /*
  switch(MODE_SW)
  {
    case MOD1_SW :APP1.MOD1_TASK_Bluetooth_control();Serial.println("mod1");;break;
    case MOD2_SW :APP2.MOD2_avoiding_obstacles();Serial.println("mod2");;break;
    case MOD3_SW :APP3.MOD3_LINE_FOLLOWER();Serial.println("mod3");;break;
    case MOD4_SW :APP4.MOD4_Maze_Solving();Serial.println("mod4");;break;
    default :{Serial.println("ERROR");break;}
  } 
  */
  APP3.MOD3_LINE_FOLLOWER();
}


