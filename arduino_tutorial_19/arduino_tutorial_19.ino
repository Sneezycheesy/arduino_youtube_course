/*
 * Tutorial 19 Reading strings for the serial monitor
 * https://youtu.be/MAnAc_t0OrM
 */
const int baudRate = 9600;
const int dt = 500; // delaytime
const int redPin = 13;
const int greenPin = 12;
const int bluePin = 11;
const String msg = "What LED would you like to light?";
const String err = "Not a valid option, try again";
String answer = "";

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
  answer = Serial.readString();
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  for (int j = 0; answer[j]; j++) {
    answer[j] = tolower(answer[j]);
  }

  if (answer == "red") {
    digitalWrite(redPin, HIGH);
  } else if (answer == "green") {
    digitalWrite(greenPin, HIGH);
  } else if (answer == "blue") {
    digitalWrite(bluePin, HIGH);
  } else if (answer == "all") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  } else {
    Serial.println(err);
  }
}
