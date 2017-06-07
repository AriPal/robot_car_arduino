 /*
  * RobotMotor.cpp - Implementation 
  * Created by Dler H. June 2, 2017
 */ 
 
#include "RobotMotor.h"

// Initialize Constructor
Robot::Robot(){};


void Robot::driveForward(){
	analogWrite(ENA,ABS);
	analogWrite(ENB,ABS);
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	digitalWrite(in3,HIGH);
	digitalWrite(in4,LOW);
	Serial.println("go forward!");
}


void Robot::STOP(){
	digitalWrite(ENA, LOW); 
	digitalWrite(ENB, LOW); 
	Serial.println("Stop!");
}

// Set pin modes 
void Robot::SETUP(){
	myservo.attach(3,600,2400);// attach servo on pin 3 to servo object
	Serial.begin(9600);     
	pinMode(Echo,INPUT);    
	pinMode(Trig,OUTPUT);  
	pinMode(in1,OUTPUT);
	pinMode(in2,OUTPUT);
	pinMode(in3,OUTPUT);
	pinMode(in4,OUTPUT);
	pinMode(ENA,OUTPUT);
	pinMode(ENB,OUTPUT);
	STOP();	
}

