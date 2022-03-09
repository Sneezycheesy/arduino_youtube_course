/*
 * Tutorial 37 Understanding how to control dc motors
 * https://youtu.be/fPLEncYrl4Q
 */

const int baudRate = 9600;
const int dt = 100; // delaytime
const int speedPin = 11;
const int dirPin1 = 7;
const int dirPin2 = 6;
const int tiltPin = 2;
int motorSpeed = 200;
bool running = false;
bool tiltVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tiltPin);
  digitalWrite(dirPin2, HIGH);
  digitalWrite(dirPin1, LOW);
  
  if (!tiltVal) {
    if (!running) {
      analogWrite(speedPin, 255);
      delay(dt);
      running = true;
    }
    analogWrite(speedPin, motorSpeed);
  } else {
    analogWrite(speedPin, 0);
    running = false;
  }
}
