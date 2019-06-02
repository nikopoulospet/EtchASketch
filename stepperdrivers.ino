#include <Arduino.h>
#include "A4988.h"

#define Motor_Steps 200
//RPM defined here, probably going to ve a variable so it can change in the program
#define RPM_X 120
#define RPM_Y 120
//120 max? 


//Microstepping, 1- full, 2 - half , 4 - quarter, 8 - eighth, 16 - 16th
//will need to define Pins as well as high or low, this value must correspond
// state changes? 
#define Microsteps 1
//Microstepping Pins
#define MS1 2
#define MS2 3
#define MS3 4

//Motor wires. DIR - Green, STEP - Blue
#define DIR_X 8
#define STEP_X 9

#define DIR_Y 5
#define STEP_Y 6


// 2 wire configuration 
A4988 Stepper_X(Motor_Steps, DIR_X, STEP_X); //MS1, MS2, MS3);
A4988 Stepper_Y(Motor_Steps, DIR_Y, STEP_Y); //MS1, MS2, MS3);
//microstepping dealt with later

void setup(){
    Stepper_X.begin(RPM_X, Microsteps);
    Stepper_Y.begin(RPM_Y, Microsteps);

}

void loop(){
    Stepper_X.move(Motor_Steps*Microsteps);
    Stepper_Y.move(Motor_Steps*Microsteps);

    delay(1000);
}