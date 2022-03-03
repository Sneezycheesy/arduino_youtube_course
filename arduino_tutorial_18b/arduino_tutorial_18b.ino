/*
 * Tutorial 18 Reading numbers form the serial monitor
 * https://youtu.be/7aP5KL5clWA
 * Part 2 (floats)
 */
const int boadRate = 9600;
const String msg = "What is the radius of your circle?";
const String answer = "Your circle has an area of: ";
const float pi = 3.14;
float radius = 0.;
float area = 0.;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {
    // Do nothing until input is given
  }

  radius = Serial.parseFloat();
  area = pi * (radius * radius);
  Serial.print(answer);
  Serial.println(area);
}
