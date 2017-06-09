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
	 analogWrite(ENA,200);
	 analogWrite(ENB,200);
	 digitalWrite(in1,LOW);
	 digitalWrite(in2,HIGH);
	 digitalWrite(in3,HIGH);
	 digitalWrite(in4,LOW);
	 Serial.println("go right!");  
}

void Robot::driveLeft(){
	 analogWrite(ENA, 200); 
	 analogWrite(ENB, 200); 
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

//void Robot::followLine(){
//	// Read line detection values 
//	trackSensorLeft = digitalRead(12); 
//  trackSensorLeft = trackSensorLeft << 2;
//	trackSensorCenter = digitalRead(4);
//  trackSensorCenter = trackSensorCenter << 1;
//	trackSensorRight = digitalRead(2);
//	
//	// Follow line algorithm  
//	if((trackSensorRight == 0)&&trackSensorCenter&&trackSensorRight){
//	  	Robot::driveRight(); 
//	  	delay(2);
//	    while(1){ // Turn right until line is centered. 
//	      trackSensorCenter = digitalRead(4);
//	      if(trackSensorCenter == 1){
//	        Robot::driveRight();
//	        delay(2);  
//	      }else 
//	        break;   
//	      
//	    }
//	} else if(trackSensorRight&&trackSensorCenter&&(trackSensorLeft == 0)){
//	    Robot::driveLeft();
//		delay(2);
//		while(1){
//			trackSensorCenter = digitalRead(4);
//			if(trackSensorCenter == 1){
//				Robot::driveLeft(); 
//				delay(2); 
//			}else
//				break; 
//			
//		}
//	} else {
//		Robot::driveForward();
//		delay(2);
//	}
//}
