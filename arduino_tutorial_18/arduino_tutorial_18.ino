/*
 * Tutorial 18 Reading numbers form the serial monitor
 * https://youtu.be/7aP5KL5clWA
 * Part 1 (ints)
 */

const int baudRate = 9600;
const int bt = 500; // blinktime
const int ledPin = 12;
const String msg = "How many blinks would you like?";
int readNumber = 0;
int j = 0; // counter

void setup() {  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {
    // Do nothing until input is given
  }
  readNumber = Serial.parseInt();
  for(j = 1; j <= readNumber; j++) {
    digitalWrite(ledPin, HIGH);
    delay(bt);
    digitalWrite(ledPin, LOW);
    delay(bt);
  }
}
