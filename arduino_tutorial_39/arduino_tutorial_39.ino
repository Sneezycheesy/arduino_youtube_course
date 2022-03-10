/*
 * Tutorial 39 Using a joystick with a DC motor
 * https://youtu.be/wSjZIHMDczk
 */

const int baudRate = 9600;
const int dt = 500; // delaytime
const int speedPin = 11;
const int dirPin1 = 7;
const int dirPin2 = 6;
const int joystickYPin = A1;
bool dir; // 0 = backwards (CCW), 1 = forwards (CW)
int joystickYValue;
float joystickYWriteValue;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(joystickYPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  joystickYValue = analogRead(joystickYPin);
  if (joystickYValue > 515) {
    dir = true;
  } else {
    dir = false;
  }
  
  if (!dir) {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    joystickYWriteValue = -(255. / 512.) * (joystickYValue - 512);
  } else {
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    joystickYWriteValue = (255. / 512.) * (joystickYValue - 512);
  }

  
  if (joystickYValue >= 505 && joystickYValue <= 515) {
    digitalWrite(speedPin, LOW);
  } else {
    analogWrite(speedPin, joystickYWriteValue);
  }
}
