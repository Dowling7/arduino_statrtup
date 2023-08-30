#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;

void setup() {
  myservo1.attach(3);  // attaches the servo on pin 0 to the servo object
  myservo1.attach(5);
}

void loop() {
  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    for (pos2 = 0; pos2 <= 180; pos2 += 1){
      myservo2.write(pos2);
      delay(15); 
    }
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}
