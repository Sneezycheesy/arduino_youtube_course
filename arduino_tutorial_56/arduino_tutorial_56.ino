/*
 * Tutorial 56 How to Graph Live Data Using the Serial Plotter
 * https://youtu.be/dw1Lqjc1lCk
 */
const int baudRate = 9600;
const int dt = 10; // delaytime

const byte echoPin = 11;
const byte triggerPin = 12;
float pingTravelTime;
float distance;
float distancecm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  Serial.print(0);
  Serial.print(',');
  Serial.print(distancecm);
  Serial.print(',');
  Serial.println(20);
  
  delay(250);
}
