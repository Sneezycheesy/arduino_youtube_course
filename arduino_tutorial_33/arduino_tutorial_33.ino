/*
 * Tutorial 33 understanding how to control servos with a joystick
 * https://youtu.be/KCdoRDDLWgo
 */
#include <Servo.h>

const int baudRate = 9600;
const int dt = 200; // delaytime
const int xPin = A0;
const int yPin = A1;
const int swPin = 3;
const int servoPin = 6;
int xVal;
int yVal;
int swVal;
int servoPos;
Servo sally;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT);
  sally.attach(servoPin);
  digitalWrite(swPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  swVal = digitalRead(swPin);
  delay(dt);
  servoPos = calculateServoPos(xVal);
  sally.write(servoPos);
  Serial.println(servoPos);
}

float calculateServoPos(int joyStickVal) {
  return (180. / 1023.) * joyStickVal;
}
