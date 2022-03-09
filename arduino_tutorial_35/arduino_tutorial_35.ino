/*
 * Tutorial 35 Understanding how to use a stepper motor
 * https://youtu.be/CEz1EeDlpbs
 */
#include <Stepper.h>

const int baudRate = 9600;
const int dt = 200; // delaytime
const int stepsPerRevolution = 2048;
const int motSpeed = 10;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(stepsPerRevolution / 2);
  delay(dt);
  myStepper.step(-stepsPerRevolution / 2);
  delay(dt);
}
