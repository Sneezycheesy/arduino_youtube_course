/*
 * Tutorial 14 dimmable led project
 * https://youtu.be/7wKdxsvXAFo
 */

const int serialBaud = 9600;
const int delayTime = 500;
const int potPin = A0;
const int ledPin = 3;
int potVal = 0;
float ledVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialBaud);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  ledVal = (255./1023.) * potVal;
  analogWrite(ledPin, ledVal);
}
