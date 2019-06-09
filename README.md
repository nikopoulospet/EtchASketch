# EtchASketch
This is code to control 2 stepper motors using 2 A4988 Stepper motor drivers via the serial port on an arduino uno. 
Microstepping controls were not added for this application because with microstepping enabled, the stepper motors dont have the torque needed to turn the nobs on the Etch a Sketch. 

## Serial Input
This code takes a serial input in the form of one X command and one Y command at a time. for example: 200X600Y
This would turn the X motor 200 steps clockwise and the Y motor 600 steps clockwise as well. To turn the motors backwards use the "C" or "U" charachters to turn counter clockwise for the X and Y motors respectively. For example: 375C100Y would turn the X motor 375 steps counter clockwise and the Y motor 100 steps clockwise. 
The code runs at a Baud rate of **9600**, although it could be easily changed. 
## Wiring 
