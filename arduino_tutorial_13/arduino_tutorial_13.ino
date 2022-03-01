/*
 * Tutorial 13 understanding if-statements
 * https://youtu.be/ORNted-NgRM
 */

const int serialBaud = 9600;
const int delayTime = 500;
const int readPin = A0;
const int redLEDPin = 2;
int readVal = 0;
float vOut = 0;
float prevRead = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialBaud);
  pinMode(readPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(A0);
  vOut = (5./1023.) * readVal;
  Serial.print("Potentiometer voltage = ");
  Serial.println(vOut);

  if (vOut > 4.) {
    digitalWrite(redLEDPin, HIGH);
  } else if (vOut > 3.5) {
    digitalWrite(redLEDPin, HIGH);
    delay(delayTime);
    digitalWrite(redLEDPin, LOW);
  } else {
    digitalWrite(redLEDPin, LOW);
  }
  
  delay(delayTime);
  
}
