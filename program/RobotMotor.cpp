 /*
  * RobotMotor.cpp - Implementation 
  * Created by Dler H. June 2, 2017
 */ 
 

#include "RobotMotor.h"

// Init Constructor
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

void Robot::driveBackward(){
	 analogWrite(ENA,ABS);
	 analogWrite(ENB,ABS);
	 digitalWrite(in1,LOW);
	 digitalWrite(in2,HIGH);
	 digitalWrite(in3,LOW);
	 digitalWrite(in4,HIGH);
	 Serial.println("go back!");
}

void Robot::driveRight(){
	 analogWrite(ENA,130);
	 analogWrite(ENB,130);
	 digitalWrite(in1,LOW);
	 digitalWrite(in2,HIGH);
	 digitalWrite(in3,HIGH);
	 digitalWrite(in4,LOW);
	 Serial.println("go right!");  
}

void Robot::driveLeft(){
	 analogWrite(ENA, 130); 
	 analogWrite(ENB, 130); 
	 digitalWrite(in1, HIGH); 
	 digitalWrite(in2, LOW); 
	 digitalWrite(in3, LOW); 
	 digitalWrite(in4, HIGH); 
	 Serial.println("Go left!");
}

void Robot::STOP(){
	 digitalWrite(ENA, LOW); 
	 digitalWrite(ENB, LOW); 
	 Serial.println("Stop!");
}

void Robot::setSpeed(int speed){
	 ABS = speed; 
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

int Robot::measureDistance(){
	digitalWrite(Trig, LOW);   
	delayMicroseconds(2);
	digitalWrite(Trig, HIGH);  
	delayMicroseconds(20);
	digitalWrite(Trig, LOW);   
	float Fdistance = pulseIn(Echo, HIGH);  
	Fdistance = Fdistance/58;       
	return (int)Fdistance;	
}

byte Robot::getLineSensorValues(){
  // Read line detection values 
  sensorLeft = digitalRead(12); 
  sensorCenter = digitalRead(4);
  sensorRight = digitalRead(2);

  // Convert to bitwise operation
  sensorLeft = sensorLeft << 2;
  sensorCenter = sensorCenter << 1;

  byte sensorValue = 0;
  sensorValue |= sensorLeft;
  sensorValue |= sensorCenter;
  sensorValue |= sensorRight; 

  return sensorValue; 
}


void Robot::followLine(){
  byte sensorValue = getLineSensorValues(); 
  state = sensorValue; 
  
  switch(state){
    case idle:
      Serial.print("Idle");
      break;

    case goForward:
      Serial.println("Go forward");
      driveForward();

      break;

    case goCenterRight:
    case goRight:
      Serial.println("Go Right");
      driveRight(); 
      break;

    case goCenterLeft: 
    case goLeft: 
      Serial.println("Go Left");      
      driveLeft(); 
      break; 

    default:
      Serial.println("Default state");
      driveLeft(); 
  } 
}
