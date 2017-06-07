 /*
  * RobotMotor.h - Header 
  * Created by Dler H. June 2, 2017
 */ 

// Call header once 
#ifndef RobotMotor_h
#define RobotMotor_h
#include <inttypes.h>
#include <Servo.h> 
#include "Arduino.h"

class Robot {
  public: 
  	// Define Constructor   
    Robot(); 
  	Robot(int in1, int in2, int in3, int in4) : in1(in1), in2(in2), in3(in3), in4(in4){}; 
	     // Declare pins
   void SETUP(); 
   // Declare driving modes 
    void driveForward();
    void setSpeed(int speed){
      ABS = speed; 
    };
    void driveBackward();  
    void driveRight();
    void driveLeft();
    void STOP(); 


  private:
    // Declare variables 
    int Echo = A4;  
    int Trig = A5; 
    int in1 = 9;  
    int in2 = 8;
    int in3 = 7;
    int in4 = 6;
    int ENA = 11; 
    int ENB = 5;
    int ABS = 150; // 0-255
    int rightDistance = 0;
    int leftDistance = 0;
    int middleDistance = 0;
    Servo myservo; // create servo object to control servo
};


#endif 
