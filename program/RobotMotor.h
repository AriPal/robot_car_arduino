 /*
  * RobotMotor.h - Header 
  * Created by Dler H. June 2, 2017
 */ 

// Invoke header once 
#ifndef RobotMotor_h
#define RobotMotor_h

#include <inttypes.h>
#include <Servo.h> 
#include "Arduino.h"

class Robot {
  public: 
  	// Define Constructor   
    Robot();

    // Define member initialization list  
  	Robot(int in1, int in2, int in3, int in4) : in1(in1), in2(in2), in3(in3), in4(in4){}; 
   
    // Declare driving modes 
    void driveForward();
    void driveBackward();  
    void driveRight();
    void driveLeft();
    void STOP();
     
	  // Declare pins
    void SETUP(); 

    // Set methods 
    void setSpeed(int speed); 

    // Return methods 
    int distanceTest();


  private:
    // Declare variables 
    int Echo = A4;  // Receive ultrasound 
    int Trig = A5; 
    int in1 = 9;    // if in1 high and in2 low, left wheels turn forward    
    int in2 = 8;    // if in1 low and in2 high, left wheels turn backward
    int in3 = 7;    // if in3 high and in4 low, right wheels turn forward 
    int in4 = 6;    // if in3 low and in4 high, right wheels turn backward
    int ENA = 11;   // Enable Motor A (high or low) 
    int ENB = 5;    // Enable Motor B (high or low)
    int ABS = 150;  // Max speed 0-255
    int rightDistance = 0;
    int leftDistance = 0;
    int middleDistance = 0;
    Servo myservo; // create servo object to control servo
};


#endif 
