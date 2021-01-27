# ArduinoArm
C++ code to control a robotic arm using an Arduino circuitboard, servo motors, and a potentiometer(pot).
I used a single potentiometer to control 4-5 different servos(both continuos and 180º). The code allows you to type in the number of servo you would like to control and then move the potentiometer to set it to that position(using c++ map() function). The last servo in the array is a 360º servo, it reacts to the potentiometer differently than 180º servos because it does not save its position as an angle. I also added a short delay in between each change of servo so that yo dont accidentally move them. 
Things to note: 
This code does not have a main() function because it is made to be run using the Arduino IDE on an Arduino Uno, in the IDE there is a built in main() function which calls loop() in an infinite loop and setup() once. 
