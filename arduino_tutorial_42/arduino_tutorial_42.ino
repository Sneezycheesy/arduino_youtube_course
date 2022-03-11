/*
 * Tutorial 42 Understanding how to use a serial to parallel shift register (74HC595)
 * https://youtu.be/n3qmQHzcgto
 */

const int baudRate = 9600;
const int dt = 250; // delaytime
const int latchPin = 11;
const int clockPin = 9;
const int dataPin = 12;

byte leds = 0x00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  leds++;
}
