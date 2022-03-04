/*
 * Tutorial 26 More fun with photo resistors
 * https://youtu.be/42ahyWUkTiU
 */
const int baudRate = 9600;
const int dt = 500;
const int readPin = A0;
const int buzzPin = 3;
int lightVal = 0;
int buzzDelay = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(readPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(readPin);
  buzzDelay = calcBuzzVal();
  Serial.print(lightVal);
  Serial.print(", ");
  Serial.println(buzzDelay);
  digitalWrite(buzzPin, HIGH);
  delay(buzzDelay);
  digitalWrite(buzzPin, LOW);
  delay(buzzDelay);
}

float calcBuzzVal() {
  return (9. / 550.) * (lightVal - 200.) + 1.;
}
