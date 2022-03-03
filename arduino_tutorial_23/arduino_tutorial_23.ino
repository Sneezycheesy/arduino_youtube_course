/*
 * Tutorial 23 Changing tone of an active buzzer
 * https://youtu.be/W5AApP9P-b0
 */
const int boadRate = 9600;
const int dt = 500; // delaytime
const int buzzPin = 8;
const int dt1 = 1;
const int dt2 = 2;
int j = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (j=1; j <= 100; j++) {
    digitalWrite(buzzPin, HIGH);
    delay(dt1);
    digitalWrite(buzzPin, LOW);
    delay(dt1);
  }

  for (j=1; j<= 100; j++) {
    digitalWrite(buzzPin, HIGH);
    delay(dt2);
    digitalWrite(buzzPin, LOW);
    delay(dt2);
  }
}
