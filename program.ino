 /*
  * Program.ino - Performance 
  * Created by Dler H. June 13, 2017
 */ 

#include "Arduino.h"
#include "RobotMotor.h"

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

// Create object of class Robot
Robot robot; 


void setup() {
  // Define pinmodes
  robot.SETUP(); 
}

void loop() {

  /*I DON'T WRITE CODE LIKE THIS!*/

  int rightDistance = 0;
  int leftDistance = 0;
  int middleDistance = 0;   

  // Servo direction: Forward
  robot.servoFront(); 

  middleDistance = robot.measureDistance(); 
  
  #ifdef send
  Serial.print("middleDistance=");
  Serial.println(middleDistance);
  #endif

  if(middleDistance <=20){
    robot.STOP(); 
    robot.servoRight(); 
    delay(500);
    rightDistance = robot.measureDistance(); 
  
    #ifdef send
    Serial.print("rightDistance=");
    Serial.println(rightDistance);
    #endif
  
    robot.servoLeft(); 
    leftDistance = robot.measureDistance(); 
  
    #ifdef send
    Serial.print("leftDistance=");
    Serial.println(leftDistance);
    #endif  

  if(rightDistance > leftDistance){
    robot.driveRight(); 
    delay(360);
  }else if(rightDistance < leftDistance){
    robot.driveLeft(); 
    delay(360);
  }else if((rightDistance <=20 )||(leftDistance <=20)){
    robot.driveBackward();
    delay(180); 
  }else {
    robot.driveForward(); 
  }
 }else
    robot.driveForward(); 
    
} // end loop




