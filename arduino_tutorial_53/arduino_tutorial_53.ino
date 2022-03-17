/*
 * Tutorial 53 Understanding and connecting the hc-sr04 sensor
 * https://youtu.be/M-UKXCUI0rE
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

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(dt);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(dt);
  digitalWrite(triggerPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH); // microSeconds
  distance = ((767. * 12 * 5280 / 3600 / 1000000) * pingTravelTime) / 2; // convert miles/hour to inches
  distancecm = ((343. * 100 / 1000000) * pingTravelTime) / 2; // convert meters/second to cm
  Serial.print("ping: ");
  Serial.print(distance);
  Serial.print(" inches | ");
  Serial.print(distancecm);
  Serial.println(" cm"); 
  delay(250);
}
