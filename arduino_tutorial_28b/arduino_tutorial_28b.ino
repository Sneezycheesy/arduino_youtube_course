/*
 * Tutorial 28 using push buttons as toggle switch
 * https://youtu.be/aMato4olzi8
 */
const int dt = 500; // delaytime
const int boadRate = 9600;

const int btnPin = 12;
const int ledPin = 8;
int ledState = 0; // Always start led off
int btnPrevState = 0; // Initial state is always 0 with the pull down button resistor
int btnPresState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnPresState = digitalRead(btnPin);
  if (btnPrevState == 1 && btnPresState == 0) {
    ledState = !ledState;
  }
  btnPrevState = btnPresState;
  digitalWrite(ledPin, ledState);
  Serial.println(btnPresState);
}
