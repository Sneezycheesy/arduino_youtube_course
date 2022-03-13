/*
 * Tutorial 48 Connecting and using an LCD display
 * https://youtu.be/4BaDaGTUgIY
 */
 #include <LiquidCrystal.h>

const int baudRate = 9600;
const int dt = 500; // delaytime
// PINS
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Watch me count");
  for (int j = 1; j <= 10; j++) {
    lcd.setCursor(0, 1);
    lcd.print(j);
    delay(dt);
  }
  lcd.clear();
}
