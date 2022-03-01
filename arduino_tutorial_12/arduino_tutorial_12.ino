/*
 * Tutorial 12 Understanding potentiometers
 * https://youtu.be/PUte1cmJ44A
 */

const int serialPan = 9600;
const int delayTime = 500;
const int readPin = A0;
int readVal = 0;
float vOut = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialPan);
  pinMode(readPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(A0);
  vOut = (5./1023.) * readVal;
  Serial.println(vOut);
  
}
