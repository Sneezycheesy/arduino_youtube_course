/*
 * Tutorial 44 Understanding Logical Shift Left and Logical Shift Right with the 74HC595
 * https://youtu.be/3JDgL9rgVb0
 */

const int baudRate = 9600;
const int dt = 1000; // delaytime
const int latchPin = 11;
const int clockPin = 9;
const int dataPin = 12;

byte leds = 0b01000000;

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
  leds = (leds / 128) + (leds*2);
  Serial.println(leds, BIN);
}
