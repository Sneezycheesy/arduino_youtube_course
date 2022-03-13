/*
 * Tutorial 48 Connecting and using an LCD display
 * https://youtu.be/4BaDaGTUgIY
 */
 #include <LiquidCrystal.h>

const int baudRate = 9600;
const int dt = 5000; // delaytime
// PINS
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

int numberOne;
int numberTwo;
char operatorU;
float answer;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Enter your first");
  lcd.setCursor(0,1);
  lcd.print("number:");
  while (Serial.available() == 0) {
    
  }
  numberOne = Serial.parseFloat();
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Enter your sec-");
  lcd.setCursor(0,1);
  lcd.print("ond number:");
  while (Serial.available() == 0) {
    
  }
  numberTwo = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enter operator");
  lcd.setCursor(0,1);
  lcd.print("/ | * | + | -");
  while (Serial.available() == 0) {
    
  }
  operatorU = Serial.read();
  Serial.println(operatorU);
  lcd.clear();

  if (operatorU == '/' && numberTwo != 0.) {
    answer = (1.0 * numberOne) / ( 1.0 * numberTwo);
  } else if (operatorU == '*') {
    answer = numberOne * numberTwo;
  } else if (operatorU == '+') {
    answer = numberOne + numberTwo;
  } else if (operatorU == '-') {
    answer = numberOne - numberTwo;
  }

  lcd.setCursor(0,0);
  lcd.print("The answer is:");
  lcd.setCursor(0,1);
  lcd.print(numberOne);
  lcd.print(" ");
  lcd.print(operatorU);
  lcd.print(" ");
  lcd.print(numberTwo);
  lcd.print(" = ");
  lcd.print(answer);
  delay(dt);
  lcd.clear();
}
