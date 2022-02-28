// From tutorial 7
// https://www.youtube.com/watch?v=6CRhpUV92ww&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=7

const int pin = 3;
const int brightOff = 0;
const int broghtLow = 5;
const int brightMed = 130;
const int brightHigh = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin, brightLow);
  delay(5000);
  analogWrite(pin, brightMed);
  delay(5000);
  analogWrite(pin, brightHigh);
  delay(5000);
  analogWrite(pin, brightOff);
  delay(5000);
}
