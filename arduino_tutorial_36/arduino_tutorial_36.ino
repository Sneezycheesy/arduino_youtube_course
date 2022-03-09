/*
 * Tutorial 36 Understanding tilt switches
 * https://youtu.be/SYDuRyweeLA
 */

const int baudRate = 9600;
const int dt = 200; // delaytime
const int tiltPin = 12;
const int redLedPin = 2;
const int greenLedPin = 3;
const int buzzPin = 13;
const int defaultWarning = 3;
int tiltValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(tiltPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltValue = digitalRead(tiltPin);
  Serial.println(tiltValue);
  if (tiltValue != 0) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);

    buzzWarning(defaultWarning);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }
  delay(dt);
}

void buzzWarning(int amount) {
  int j = 0;
  while (j < amount) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
    delay(dt);
    j++;
  }
}
