#include "Arduino.h"
#include "RobotMotor.h"


// Create object of class Robot
Robot robot; 

void setup() {
  // put your setup code here, to run once:
  robot.SETUP(); 
}

void loop() {
  // put your main code here

  robot.followLine();

}



