#include <LiquidCrystal.h>
const int baudRate = 9600;
const int dt = 10; // delaytime
const int echoPin = 3;
const int triggerPin = 2;
const int rs = 8;
const int en = 7;
const int d4 = 12;
const int d5 = 11;
const int d6 = 10;
const int d7 = 9;
const int btnPin = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float traveltimeTwoWays;
bool btnState;
float distance;

void setup() { 
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  lcd.begin(16, 2);
  pinMode(btnPin, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  digitalWrite(btnPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(btnPin);
  lcd.clear();
  while (btnState) {
    lcd.setCursor(0, 0);
    lcd.print("Press to start");    
    btnState = digitalRead(btnPin);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Measuring...");

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  traveltimeTwoWays = pulseIn(echoPin, HIGH);
  Serial.println(traveltimeTwoWays);
  distance = (343. * 100 / 1000000) * (traveltimeTwoWays / 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance to object:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(2000);
}
