/*
 * Tutorial 50 How to Connect and Use the DHT11 Temperature and Humidity Sensor
 * https://youtu.be/-AvF2TsB2GI
 */
#include <DHT.h>

#define Type DHT11

const int baudRate = 9600;
const int dt = 500; // delaytime

const int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  HT.begin();
  delay(dt);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", Temp: ");
  Serial.print(tempC);
  Serial.print("C/");
  Serial.print(tempF);
  Serial.println("F");
  delay(dt);
}
