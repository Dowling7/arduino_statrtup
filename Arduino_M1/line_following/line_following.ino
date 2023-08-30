#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
//R_sense=30k
//tape 245
//floor 52
int critical=120;

const int l_sensor =A0;
const int r_sensor =A1;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
  AFMS.begin();
  //speed range from 0 to 255
  myMotor1->setSpeed(30);
  myMotor2->setSpeed(30);
  pinMode(l_sensor, INPUT);
  pinMode(r_sensor, INPUT);
  Serial.begin(9600);


}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
  int left=0;
  int right=0;
  int turn_delay=10;
  left=analogRead(l_sensor);
  right=analogRead(r_sensor);

//motor1 left, motor2 right

  if((left-right)>100){
    Serial.println("turning right");
    myMotor1->run(BACKWARD);
    myMotor2->run(FORWARD);
    delay(turn_delay);

  }else if(left-right)<-100){
    Serial.println("turning left");
    myMotor1->run(FORWARD);
    myMotor2->run(BACKWARD);
    delay(turn_delay);
  }else if(right < 105 && left < 105){
    Serial.println("stop");
    myMotor1->run(RELEASE);
    myMotor2->run(RELEASE);
  }else if(left-right)>-100 && lleft-right)<100){
    Serial.println("going forward");
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);


}
