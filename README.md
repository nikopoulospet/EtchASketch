# EtchASketch
This is code to control 2 bipolar stepper motors (4 wires) using 2 A4988 Stepper motor drivers via the serial port on an Arduino Uno and the [Stepper Driver library written by **laurb9** found here.](https://github.com/laurb9/StepperDriver) Microstepping controls were not added for this application because with microstepping enabled, the stepper motors don’t have the torque needed to turn the nobs on the Etch a Sketch. 

## Serial Input
This code takes a serial input in the form of one X command and one Y command at a time. for example: 200X600Y
This would turn the X motor 200 steps clockwise and the Y motor 600 steps clockwise as well. To turn the motors backwards use a negative number like "-100X-100Y". The code runs at a Baud rate of **9600**, although it could be easily changed. 
## Wiring 
![Dual A4988 wiring diagram](https://github.com/nikopoulospet/EtchASketch/blob/master/dual%20A4988%20stepper%20driver%20circuit.png)
The A4988 Stepper Motor Driver is susceptible to voltage spikes, so you must attach at least a 47 μF electrolytic capacitor between the leads of the VMOT and GND pins with the negative terminal on GND. For this application we use 100 μF capacitors. 
### Setting the current limit
Make sure to set the current limit before attaching the motors. Max current = Vref * 2. Vref is measured through the Vref pot on the A4988 board. Attach the - probe of a multimeter to the chip ground and the + probe to the pot on the chip to read the Vref value. In full step mode the current is limited to 70% of the current limit, so in full step mode the current can be set 30% higher for more torque.
### Maximizing Stepper Performance
Maximize stepper performance by using a higher voltage. By shooting up the voltage the motor can switch its polarity faster but to do this safely the coil current must be limited so that it doesn’t exceed the motors rated current. For example, if you are running a 12V motor rated at 1 amp and its running off a 24 volt power supply the current must be limited to 0.5 amps per ohms law.
#
![Finished EtchASketch](https://github.com/nikopoulospet/EtchASketch/blob/master/IMG_9198.JPG)
