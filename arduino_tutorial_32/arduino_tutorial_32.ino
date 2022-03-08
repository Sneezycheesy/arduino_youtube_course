/*
 * Tutorial 32 Understanding and using joysticks
 * https://youtu.be/B6YEQj4d5WU
 */

const int baudRate = 9600;
const int dt = 200; // delaytime
const int xPin = A0;
const int yPin = A1;
const int swPin = 3;
int xVal;
int yVal;
int swVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  swVal = digitalRead(swPin);
  delay(dt);
  Serial.print("xVal: ");
  Serial.print(xVal);
  Serial.print(", yVal: ");
  Serial.print(yVal);
  Serial.print(", swVal: ");
  Serial.println(swVal);  
}
