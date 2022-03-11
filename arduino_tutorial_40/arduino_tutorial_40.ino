/*
 * Tutorial 40 Controlling a DC motor with push buttons
 * https://youtu.be/fxgcnJJlTd4
 */

const int baudRate = 9600;
const int dt = 500; // delaytime
const int speedPin = 11;
const int dirPin1 = 7;
const int dirPin2 = 6;
const int stopPin = 2;
const int forwardPin = 3;
const int backwardPin = 4;
bool dir = 1; // 0 = backwards (CCW), 1 = forwards (CW)
int currentSpeed = 0;
bool stopValue;

bool stopValueCurrent = 1;
bool stopValuePrev;
bool forwardValueCurrent = 1;
bool forwardValuePrev;
bool backwardValueCurrent = 1;
bool backwardValuePrev;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  
  pinMode(stopPin, INPUT);
  digitalWrite(stopPin, HIGH);
  
  pinMode(forwardPin, INPUT);
  digitalWrite(forwardPin, HIGH);
  
  pinMode(backwardPin, INPUT);
  digitalWrite(backwardPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  stopValueCurrent = digitalRead(stopPin);
  forwardValueCurrent = digitalRead(forwardPin);
  backwardValueCurrent = digitalRead(backwardPin);

  if (stopValueCurrent == 1 && stopValuePrev == 0) {
    digitalWrite(speedPin, 0);
    currentSpeed = 0;
  } else if (forwardValueCurrent == 0 && forwardValuePrev == 1) {
    if (currentSpeed <= 0 && currentSpeed >= -165) {
      currentSpeed = 165;
    }
    if (currentSpeed < 255) {
      currentSpeed += 5;
    }
  }
  else if (backwardValueCurrent == 0 && backwardValuePrev == 1) {
    if (currentSpeed >= 0 && currentSpeed <= 165) {
      currentSpeed = (-165);
    }
    if (currentSpeed > -255) {
      currentSpeed -= 5;
    }
  }

  if (currentSpeed < 0) {
    dir = 0;
  } else {
    dir = 1;
  }

  
  
  if (!dir) {
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    analogWrite(speedPin, currentSpeed * -1);
  } else {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    analogWrite(speedPin, currentSpeed);
  }
  
  stopValuePrev = stopValueCurrent;
  forwardValuePrev = forwardValueCurrent;
  backwardValuePrev = backwardValueCurrent;
  Serial.println(currentSpeed);
}
