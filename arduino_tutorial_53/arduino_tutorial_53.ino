/*
 * Tutorial 53 Understanding and connecting the hc-sr04 sensor
 * https://youtu.be/M-UKXCUI0rE
 */
const int baudRate = 9600;
const int dt = 10; // delaytime

const byte echoPin = 11;
const byte triggerPin = 12;
const byte ledPin = 8;
float pingTravelTime;
float distance;
float distancecm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(dt);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(dt);
  digitalWrite(triggerPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH); // microSeconds
  distance = convertPingTravelTimeToInches(pingTravelTime); // convert miles/hour to inches
  distancecm = convertPingTravelTimeToCentimeters(pingTravelTime); // convert meters/second to cm
  Serial.print("ping: ");
  Serial.print(distance);
  Serial.print(" inches | ");
  Serial.print(distancecm);
  Serial.println(" cm");

  if (distancecm <= 5.00) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(250);
}

float convertPingTravelTimeToCentimeters(float traveltime) {
  float speedOfSoundMetersPerSecond = 343.;
  float speedOfSoundCentimetersPerMicrosecond = speedOfSoundMetersPerSecond * 100 / 1000000;
  float traveltimeOneWay = traveltime / 2;
  return speedOfSoundCentimetersPerMicrosecond * traveltimeOneWay;
}

float convertPingTravelTimeToInches(float traveltime) {
  float traveltimeOneWay = traveltime / 2;
  float speedOfSoundMilesPerHour = 767.;
  float speedOfSoundInchesPerMicrosecond = speedOfSoundMilesPerHour * 12 * 5280 / 3600 / 1000000;
  return speedOfSoundInchesPerMicrosecond * traveltimeOneWay;
}
