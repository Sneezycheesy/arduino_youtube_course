/*
 * Tutorial 20 Understanding RGB LEDs
 * https://youtu.be/r_PexDLIfH8
 */
const int baudRate = 9600;
const int dt = 500; // delaytime
const int redPin = 12;
const int greenPin = 11;
const int bluePin = 10;
const String msg = "What color would you like?";

String colorInput = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {
    // Do nothing until input is given 
  }
  colorInput = Serial.readString();

  for (int j = 0; colorInput[j]; j++) {
    colorInput[j] = tolower(colorInput[j]);
  }

  if (colorInput == "white") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH); 
  } else if (colorInput == "red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (colorInput == "green") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if (colorInput == "blue") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (colorInput == "magenta") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (colorInput == "yellow") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if (colorInput == "cyan") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  } else if (colorInput == "orange") {
    digitalWrite(redPin, HIGH);
    analogWrite(greenPin, 165);
    digitalWrite(bluePin, LOW);
  } else if (colorInput == "off") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
