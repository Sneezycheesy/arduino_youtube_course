/*
 * Tutorial 22 Understanding and using active buzzers
 * https://youtu.be/tuRAvlVBEl0
 */
const int baudRate = 9600;
const int buzzPin = 8;
const int dt = 500; // delaytime
const String msg = "Please input your number: ";

int userInput = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {
    // Do nothing till value is given
  }
  userInput = Serial.parseInt();

  if (userInput > 10) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
  } else if (userInput > 5) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
    delay(dt);
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
  }
}
