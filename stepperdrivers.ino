#include <Arduino.h>
#include "A4988.h"
#include "SyncDriver.h"

//pretty much useless vvv
#define Motor_Steps 200
//^^^

//RPM defined here, probably going to ve a variable so it can change in the program
#define RPM_X 120
#define RPM_Y 120
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


// 2 wire configuration 
A4988 Stepper_X(Motor_Steps, DIR_X, STEP_X);
A4988 Stepper_Y(Motor_Steps, DIR_Y, STEP_Y);
//syncs motors together
SyncDriver controller(Stepper_X, Stepper_Y);

//microstepping dealt with later

void setup(){
    Stepper_X.begin(RPM_X);
    Stepper_Y.begin(RPM_Y);
    
    Serial.begin(9600);
    delay(1000);
    Serial.print("test");
}

int X_move = 0;
int Y_move = 0;


void grabSerial(){
    if(Serial.available()){
        String input = String(Serial.read());
        input.substring(0,4) = X_move;
        input.substring(5,10) = Y_move;
        
    }
    //return X_move , Y_move;
}

void loop(){
    grabSerial();
    Serial.print(X_move);
    Serial.print(Y_move);
    
//    controller.move(200, -200); // x , y

    delay(1000);
}