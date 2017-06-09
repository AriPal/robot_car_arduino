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

enum LineValue
{
  None = 0,
  Right = 1,  
  Center = 2,
  CenterRight = 3,
  Left = 4,
  CenterLeft = 6
}

byte lineValue = LineValue::None;

lineValue |= trackSenorLeft;
lineValue |= trackSensorCenter;
lineValue |= trackSensorRight;

//switch(lineValue)
//{
//  case LineValue::Right:
//  case LineValue::CenterRight: 
//    // Turn Right
//    break;
//  case LineValue::Left:
//  case LineValue::CenterLeft:
//    // Turn left
//    break;
//  default // Drive forward;
//  
//}

}



