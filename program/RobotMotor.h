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
    void followLine();
    byte getLineSensorValues();
	  // Declare pins
    void SETUP(); 

    // Set methods 
    void setSpeed(int speed); 

    // Return methods 
    int measureDistance();


  private:
    // Declare variables 
    Servo myservo;  // create servo object to control servo
    int Echo = A4;  // Receive ultrasound 
    int Trig = A5;  
    int in1 = 9;    // if in1 high and in2 low, left wheels turn forward    
    int in2 = 8;    // if in1 low and in2 high, left wheels turn backward
    int in3 = 7;    // if in3 high and in4 low, right wheels turn forward 
    int in4 = 6;    // if in3 low and in4 high, right wheels turn backward
    int ENA = 11;   // Enable Motor A (high or low) 
    int ENB = 5;    // Enable Motor B (high or low)
    int ABS = 115;  // Max speed 0-255
    int rightDistance = 0;
    int leftDistance = 0;
    int middleDistance = 0;
    int sensorLeft; // If value 1, line is detected. 
    int sensorCenter; // If value 2, line is detected.
    int sensorRight; // If value 3, line is detected.
   
    /* Line Detection States 
     * 0 - 000 = monitor
     * 1 - 001 = Go Right
     * 2 - 010 = Go Foward
     * 3 - 011 = Go Right
     * 4 - 100 = Go Left
     * 5 = 101 = monitor 
     * 6 = 110 = Go Left
     * 7 = 111 = monitor
     */
    enum states{
          idle = 0,
          goRight = 1,
          goForward = 2,
          goCenterRight = 3,
          goLeft = 4, 
          goCenterLeft = 6     
   } state;  
};


#endif 
