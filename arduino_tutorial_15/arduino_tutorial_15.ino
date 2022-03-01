/*
 * Tutorial 15 Understanding For loops
 * https://youtu.be/OdHzRbR0xHQ
 */

const int serialBaud = 9600;

const int yellowPin = 6;
const int redPin = 9;
const int yellowDelay = 500;
const int redDelay = 500;
const int yellowRepeat = 3;
const int redRepeat = 5;
int j;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialBaud);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (j = 0; j < yellowRepeat; j++) {
    digitalWrite(yellowPin, HIGH);
    delay(yellowDelay);
    digitalWrite(yellowPin, LOW);
    delay(yellowDelay);
  }

  for (j = 0; j < redRepeat; j++) {
    digitalWrite(redPin, HIGH);
    delay(redDelay);
    digitalWrite(redPin, LOW);
    delay(yellowDelay);
  }
}
