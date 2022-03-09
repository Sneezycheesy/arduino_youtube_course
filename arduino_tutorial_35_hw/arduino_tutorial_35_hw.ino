/*
 * Tutorial 35 Understanding how to use a stepper motor
 * https://youtu.be/CEz1EeDlpbs
 */
#include <Stepper.h>

const int baudRate = 9600;
const int dt = 200; // delaytime
const int btnPin = 2;
const int stepsPerRevolution = 2048;
int currentStepsPerRevolution = 1;
const int motSpeed = 10;
int btnCurrentState = 1;
int btnPrevState;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(btnPin, INPUT);
  digitalWrite(btnPin, HIGH);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
    btnCurrentState = digitalRead(btnPin);
  if (btnCurrentState == 0 && btnPrevState == 1) {
    currentStepsPerRevolution *= -1;
  }
  myStepper.step(currentStepsPerRevolution);
  btnPrevState = btnCurrentState;
  Serial.print(btnCurrentState);
  Serial.print(", ");
  Serial.println(currentStepsPerRevolution);
  
}
