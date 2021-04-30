#include <Servo.h>
Servo myservo;

int potpin = 0;
int val;

void setup(){
  myservo.attach(9);//attach myservo to digital PWM 9
}

void loop(){
  val = analogRead(0);//analog read the vlaue at A0
  val = map(val,0,1023,0,179); // scale the value at A0 to angle 0 to 179 degrees
  myservo.write(val); // write this value to myservo
  delay(15);
}
