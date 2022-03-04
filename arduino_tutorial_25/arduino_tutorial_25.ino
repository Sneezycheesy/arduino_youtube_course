/*
 * Tutorial 25 Understanding photoresistors and photo detectors
 * https://youtu.be/WMkN-uHd-Xo
 */
const int baudRate = 9600;
const int dt = 500;
const int readPin = A0;
const int redPin = 3;
const int greenPin = 2;
int lightVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(readPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(readPin);
  Serial.println(lightVal);
  delay(dt);

  if (lightVal < 300) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
}
