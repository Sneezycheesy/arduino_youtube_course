/*
 * Tutorial 30 understanding and using servos
 * https://youtu.be/aFHu65LiFok
 */
#include <Servo.h>

const int dt = 100; // delaytime
const int boadRate = 9600;

const int servoPin = 9;
int servoPos = 0;
Servo sally;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
  sally.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sally.write(servoPos);
  delay(dt);
}
