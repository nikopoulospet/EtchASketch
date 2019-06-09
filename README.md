# EtchASketch
This is code to control 2 bipolar stepper motors (4 wires) using 2 A4988 Stepper motor drivers via the serial port on an arduino uno and the [Stepper Driver library written by **laurb9** found here.](https://github.com/laurb9/StepperDriver)Microstepping controls were not added for this application because with microstepping enabled, the stepper motors dont have the torque needed to turn the nobs on the Etch a Sketch. 

## Serial Input
This code takes a serial input in the form of one X command and one Y command at a time. for example: 200X600Y
This would turn the X motor 200 steps clockwise and the Y motor 600 steps clockwise as well. To turn the motors backwards use the "C" or "U" charachters to turn counter clockwise for the X and Y motors respectively. For example: 375C100Y would turn the X motor 375 steps counter clockwise and the Y motor 100 steps clockwise. 
The code runs at a Baud rate of **9600**, although it could be easily changed. 
## Wiring 
![Dual A4988 wiring diagram](https://github.com/nikopoulospet/EtchASketch/blob/master/dual%20A4988%20stepper%20driver%20circuit.png)
The A4988 Stepper Motor Driver is suseptable to voltage spikes, so you must attach at least a 47 μF electotilitic capacitor betweeen the leads of the VMOT and GND pins with the negative terminal on GND. For this application we use 100 μF capacitors. 
### Setting the current limit


### Maximising Stepper Perfomance
Maximise stepper performance by using a higher voltage. By shooting up the voltage the motor can switch its polairty faster but to do this safely the coil current must be limited so that it doesnt exceed the motors rated current. For example if you are running a 12V motor rated at 1 amp and its running off a 24 volt power supply the current must be limited to 0.5 amps per ohms law. 
