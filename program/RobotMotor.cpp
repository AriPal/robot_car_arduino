 /*
  * RobotMotor.cpp - Implementation 
  * Created by Dler H. June 13, 2017
 */ 
 
#include "RobotMotor.h"

// Initialize Constructor
Robot::Robot(){};

// Pin modes  
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

/* Car moves forward */
void Robot::driveForward(){
	 analogWrite(ENA,ABS);
	 analogWrite(ENB,ABS);
	 digitalWrite(in1,HIGH);
	 digitalWrite(in2,LOW);
	 digitalWrite(in3,HIGH);
	 digitalWrite(in4,LOW);
	 Serial.println("go forward!");
}

/* Car moves backward */
void Robot::driveBackward(){
	 analogWrite(ENA,ABS);
	 analogWrite(ENB,ABS);
	 digitalWrite(in1,LOW);
	 digitalWrite(in2,HIGH);
	 digitalWrite(in3,LOW);
	 digitalWrite(in4,HIGH);
	 Serial.println("go back!");
}

/* Car turns right */
void Robot::driveRight(){
	 analogWrite(ENA,wheelRotationSpeed);
	 analogWrite(ENB,wheelRotationSpeed);
	 digitalWrite(in1,LOW);
	 digitalWrite(in2,HIGH);
	 digitalWrite(in3,HIGH);
	 digitalWrite(in4,LOW);
	 Serial.println("go right!");  
}

/* Car turns left */
void Robot::driveLeft(){
	 analogWrite(ENA,wheelRotationSpeed); 
	 analogWrite(ENB,wheelRotationSpeed); 
	 digitalWrite(in1, HIGH); 
	 digitalWrite(in2, LOW); 
	 digitalWrite(in3, LOW); 
	 digitalWrite(in4, HIGH); 
	 Serial.println("Go left!");
}

/* Disables both engines */
void Robot::STOP(){
	 digitalWrite(ENA, LOW); 
	 digitalWrite(ENB, LOW); 
	 Serial.println("Stop!");
}

/* Measure & return distance */
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

/* Control Servo direction */
void Robot::setServoDegree(int degree){
  if(degree < 10){
    degree = 10;
    myservo.write(degree); 
    delay(400); 
  } else if (degree > 170){
    servorRotationDegree = 170;
    myservo.write(degree);
    delay(400); 
  } else {
    servorRotationDegree = degree;
    myservo.write(degree);
    delay(400);
  }
}

/* Servo turns right */
void Robot::servoRight(){
  myservo.write(10);
  delay(400); 
}

/* Servo turns forward*/
void Robot::servoFront(){
  myservo.write(90);
  delay(400);
}

/* Servo turns left */
void Robot::servoLeft(){
  myservo.write(170);
  delay(400); 
}

/* Return line sensors reading */
byte Robot::getLineSensorValues(){
  // Read line detection values 
  sensorLeft = digitalRead(12); 
  sensorCenter = digitalRead(4);
  sensorRight = digitalRead(2);

  // Convert to bitwise operation
  sensorLeft = sensorLeft << 2;
  sensorCenter = sensorCenter << 1;
  sensorRight = sensorRight << 0;

  // Add bits
  byte sensorValue = 0;
  sensorValue |= sensorLeft;
  sensorValue |= sensorCenter;
  sensorValue |= sensorRight; 

  return sensorValue; 
}

/* Car follows line */
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

// Set wheel speed
void Robot::setSpeed(int speed){
   ABS = speed; 
}

// Set turning speed 
void Robot::setWheelRotationSpeed(int rotSpeed){
  wheelRotationSpeed = rotSpeed; 
}
