/*
 * Tutorial 24 Understanding passive buzzers
 * https://youtu.be/dHYKRrlPNzM
 */
const int boadRate = 9600;
const int dt = 100; // delaytime
const int buzzPin = 9;
const int potPin = A3;
int potVal = 0;
float buzzOut = 0.;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  buzzOut = buzzFunc(potVal);
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzOut);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzOut);
  Serial.print(potVal);
  Serial.print(", ");
  Serial.println(buzzOut);
}

float buzzFunc(int potVal) {
  return (9940. / 1023.) * potVal + 60;
}
