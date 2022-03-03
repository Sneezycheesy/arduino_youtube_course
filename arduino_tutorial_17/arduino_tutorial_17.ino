/*
 * Tutorial 17 Understanding Arduino While loops
 * https://youtu.be/CITZIv3SmvU
 */
const int serialBaud = 9600;
const int dt = 500; // delaytime
const int potPin = A0;
const int ledPin = 7;
int potVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialBaud);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  delay(dt);

  while (potVal > 1000) {
    digitalWrite(ledPin, HIGH);
    potVal = analogRead(potPin);
  }

  digitalWrite(ledPin, LOW);
}
