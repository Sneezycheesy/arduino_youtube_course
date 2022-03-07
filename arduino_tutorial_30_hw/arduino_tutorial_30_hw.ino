/*
 * Tutorial 31 using servo in a simple project
 * https://youtu.be/4cdFHZ_Z-_Q
 */
#include <Servo.h>

const int dt = 500; // delaytime
const int boadRate = 9600;

const int servoPin = 9;
const int readPin = A0;
int readVal = 0;
float servoPos = 0;
Servo sally;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
  sally.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin);
  servoPos = calcServoPos();
  sally.write(servoPos);
  Serial.println(servoPos);
  delay(dt);
}

float calcServoPos() {
  return -(16. / 63.) * readVal + ((16. * 780.) / 63.);
}
