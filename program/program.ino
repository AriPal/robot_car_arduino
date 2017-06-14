 /*
  * Program.ino - Performance 
  * Created by Dler H. June 13, 2017
 */ 

#include "Arduino.h"
#include "RobotMotor.h"


// Create object of class Robot
Robot robot; 


/* Available methods
  
 # Control Car 
 * driveForward
 * driveBackward
 * driveRight
 * driveLeft
 * STOP
 * setSpeed
 * setRotationSpeed


 # Control Servo
 * servoFront
 * servoRight
 * servoLeft
 * measureDistance
 
 # Autonomous Line Tracker 
 * followLine

 */


void setup() {
  // put your setup code here, to run once:
  robot.SETUP(); 
}

void loop() {

  /*I DON'T WRITE CODE LIKE THIS!*/

  robot.driveForward();
  delay(1000);
  robot.setSpeed(255); 
  delay(1000);
  robot.setServoDegree(180); 
  delay(1000);
  robot.setServoDegree(0);
  delay(1000);
  robot.driveLeft(); 
  delay(1000);
  robot.setWheelRotationSpeed(115);
  delay(1000);
  robot.driveLeft(); 
  delay(1000);
  robot.driveLeft(); 
  delay(1000);
  robot.setWheelRotationSpeed(250);
  delay(1000);

//  int rightDistance = 0;
//  int leftDistance = 0;
//  int middleDistance = 0;   
//
//  // Servor direction: Forward
//  robot.servoFront(); 
//
//  middleDistance = robot.measureDistance(); 
//  
//  #ifdef send
//  Serial.print("middleDistance=");
//  Serial.println(middleDistance);
//  #endif
//
//  if(middleDistance <=20){
//    robot.STOP(); 
//    robot.servoRight(); 
//    delay(500);
//    rightDistance = robot.measureDistance(); 
//  
//    #ifdef send
//    Serial.print("rightDistance=");
//    Serial.println(rightDistance);
//    #endif
//  
//    robot.servoLeft(); 
//    leftDistance = robot.measureDistance(); 
//  
//    #ifdef send
//    Serial.print("leftDistance=");
//    Serial.println(leftDistance);
//    #endif  
//
//  if(rightDistance > leftDistance){
//    robot.driveRight(); 
//    delay(360);
//  }else if(rightDistance < leftDistance){
//    robot.driveLeft(); 
//    delay(360);
//  }else if((rightDistance <=20 )||(leftDistance <=20)){
//    robot.driveBackward();
//    delay(180); 
//  }else {
//    robot.driveForward(); 
//  }
// }else
//    robot.driveForward(); 
    
} // end loop




