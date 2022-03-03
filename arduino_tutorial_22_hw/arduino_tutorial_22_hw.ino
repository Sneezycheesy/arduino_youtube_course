/*
 * Tutorial 22 Understanding and using active buzzers
 * https://youtu.be/tuRAvlVBEl0
 */
const int baudRate = 9600;
const int buzzPin = 8;
const int dt = 500; // delaytime
const int potPin = A2;

int potVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);

  if (potVal > 1000) {
    digitalWrite(buzzPin, HIGH);
  } else if (potVal > 800) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
    delay(dt);
  } else {
    digitalWrite(buzzPin, LOW);
  }

  Serial.println(potVal);
}
