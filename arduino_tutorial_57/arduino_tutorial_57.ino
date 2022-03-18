/*
 * Tutorial 57 How to Plot Multiple Channels on the Serial Plotter
 * https://youtu.be/dh23_XQoCAQ
 */
const int baudRate = 9600;
const int dt = 10; // delaytime
float sinVal;
float cosVal;
float j;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (j=0.; j <= 2*PI; j += .01) {
    sinVal = sin(j);
    cosVal = cos(j);
    Serial.print(sinVal);
    Serial.print(',');
    Serial.println(cosVal);
  }
}
