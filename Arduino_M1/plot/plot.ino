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
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");



}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
  int left=0;
  int right=0;
  int turn_delay=10;
  left=analogRead(l_sensor);
  right=analogRead(r_sensor);
  Serial.print("( ");
  Serial.print(left);
  Serial.print(" ");
  Serial.print(right);
  Serial.print(" ");
  Serial.print(" )");



//motor1 left, motor2 right

  if((left-right)>100){
    Serial.print("turning right");
    myMotor1->run(BACKWARD);
    myMotor2->setSpeed(10);
    myMotor2->run(FORWARD);
    Serial.println("(30, -10) ");
    delay(turn_delay);
    myMotor2->setSpeed(30);

  }else if(left-right)<-100){
    Serial.print("turning left");
    myMotor1->setSpeed(10);
    myMotor1->run(FORWARD);
    myMotor2->run(BACKWARD);
    Serial.println("(-10, -30) ");
    delay(turn_delay);
    myMotor1->setSpeed(30);
    
  }else if(right < 105 && left < 105){
    Serial.print("stop");
    myMotor1->run(RELEASE);
    myMotor2->run(RELEASE);
    Serial.println("(0, 0) ");

  }else if(left-right)>-100 && (left-right)<100){
    Serial.print("going forward");
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);
    Serial.println("(30, 30) ");



}
