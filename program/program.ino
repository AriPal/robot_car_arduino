#include "Arduino.h"
#include "RobotMotor.h"


// Create object of class Robot
Robot robot; 

void setup() {
  // put your setup code here, to run once:
  robot.SETUP(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  robot.driveForward();
  delay(1000);
  robot.STOP();
  delay(1000);
  robot.setSpeed(200); 
  delay(1000);
}
