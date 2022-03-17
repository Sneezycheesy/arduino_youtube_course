/*
 * Tutorial 53 Understanding and connecting the hc-sr04 sensor
 * https://youtu.be/M-UKXCUI0rE
 */
const int baudRate = 9600;
const int dt = 10; // delaytime

const byte echoPin = 11;
const byte triggerPin = 12;
int pingTravelTime;

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

  pingTravelTime = pulseIn(echoPin, HIGH);
  Serial.print("ping: ");
  Serial.print(pingTravelTime);
  Serial.println("microseconds");
  delay(250);
}
