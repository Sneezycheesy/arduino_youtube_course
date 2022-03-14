/*
 * Tutorial 50 How to Connect and Use the DHT11 Temperature and Humidity Sensor
 * https://youtu.be/-AvF2TsB2GI
 */
#include <DHT.h>
#include <LiquidCrystal.h>

#define Type DHT11

const int baudRate = 9600;
const int dt = 500; // delaytime

//Button
const int btnPin = 4;
bool btnCurrentValue;
bool btnPrevValue;
// LCD
const int columns = 16;
const int rows = 2;
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Temp sensor
const int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float temp;
char tempPrec[3];
float humidityOld;
float tempOld;
bool unit = true; // Use Celsius (0) or Fahrenheit (1)
bool unitOld = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  HT.begin();
  lcd.begin(columns, rows);
  pinMode(btnPin, INPUT);
  digitalWrite(btnPin, HIGH);
  delay(dt);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  temp = HT.readTemperature(unit);

  if (humidity != humidityOld || temp != tempOld || unit == unitOld) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("H: ");
    lcd.print(humidity);
    lcd.print("%");
  
    lcd.setCursor(0,1);
    lcd.print("T: ");

    dtostrf(temp, 4, 1, tempPrec); // Convert temp to 1 decimal precision
    lcd.print(tempPrec);
  
    if (!unit) {
     lcd.print(" C"); 
    } else {
      lcd.print(" F");
    }

    tempOld = temp;
    humidityOld = humidity;
  }

  btnCurrentValue = digitalRead(btnPin);
  if (btnCurrentValue == 0 && btnPrevValue == 1) {
    unitOld = unit;
    unit = !unit;
  }
  btnPrevValue = btnCurrentValue;
}
