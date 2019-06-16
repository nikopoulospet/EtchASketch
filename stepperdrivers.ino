#include <Arduino.h>
#include "A4988.h"
#include "SyncDriver.h"

/*
 * Setting up stepper driver info
 */

//pretty much useless vvv
#define Motor_Steps 200
//^^^

//RPM defined here, probably going to ve a variable so it can change in the program
int RPM_X = 120;
int RPM_Y = 120;
//120 max?

//Microstepping, 1- full, 2 - half , 4 - quarter, 8 - eighth, 16 - 16th
//will need to define Pins as well as high or low, this value must correspond
// state changes?
//Pretty much useless for this application anyways, 200 steps per rev is a high enough resolution for the etch a sketch
#define Microsteps 1

//Microstepping Pins (still useless) -- because at smaller steps the motors dont have enough torque to turn the nobs, plus the etch a sketch doesnt have a high resolution anyways
#define MS1 4
#define MS2 3
#define MS3 2

//Motor wires. DIR - Green, STEP - Blue
#define DIR_X 8
#define STEP_X 9

#define DIR_Y 5
#define STEP_Y 6

/*
 * Setting up serial read
*/

char RX_byte;
String RX_str;
String Xstr;
String Ystr;
String Cstr; // -X move
String Ustr; // -Y move
int Xmove;
int Ymove;
int counter;


// 2 wire configuration
A4988 Stepper_X(Motor_Steps, DIR_X, STEP_X);
A4988 Stepper_Y(Motor_Steps, DIR_Y, STEP_Y);
//syncs motors together
SyncDriver controller(Stepper_X, Stepper_Y);

//microstepping dealt with later

void setup()
{
  Stepper_X.begin(RPM_X);
  Stepper_Y.begin(RPM_Y);

  Serial.begin(9600);
}

void grabSerial()
{
  if ((Serial.available() > 0))
  {
   
      RX_byte = Serial.read();

      if ((RX_byte >= '0') && (RX_byte <= '9'))
      {
        RX_str += RX_byte;
      }
      if (RX_byte == '-')
      {
        RX_str += RX_byte;
      }

      if (RX_byte == 'X')
      {
        Xstr = RX_str;
        Xmove = (-1)* Xstr.toInt();
        RX_str = ' ';
        //Serial.println(Xmove);
        counter += 1;
      }
      if (RX_byte == 'Y')
      {
        Ystr = RX_str;
        Ymove = (-1) * Ystr.toInt();
        RX_str = ' ';
        //Serial.println(Ymove);
        counter += 1;
      }

   
  }
}

void RESET()
{
  Xmove = 0;
  Ymove = 0;
  counter = 0;
}

void loop()
{
  grabSerial();
  if (counter >= 3){
    Serial.println(Xmove);
    Serial.println(Ymove);
    controller.move(Xmove, Ymove); // x , y
    RESET();
    }
}