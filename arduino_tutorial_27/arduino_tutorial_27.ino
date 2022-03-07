/*
 * Tutorial 27 understanding push buttons and pull up and pull down resistors
 * https://youtu.be/AgQW81zzR18
 */
const int dt = 500; // delaytime
const int boadRate = 9600;

const int btnPin = 12;
const int ledPin = 8;
int btnRead = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnRead = digitalRead(btnPin);
  Serial.println(btnRead);
  if (btnRead == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
  delay(dt);
}
