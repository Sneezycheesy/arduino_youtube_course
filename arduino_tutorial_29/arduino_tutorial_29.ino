/*
 * Tutorial 29 using push buttons to create a dimmable led
 * https://youtu.be/XWL6Ydsmi0s
 */
const int dt = 100; // delaytime
const int boadRate = 9600;

const int btnIncreasePin = 8;
const int btnDecreasePin = 12;
const int buzzPin = 6;
const int ledPin = 3;
int ledState = 0; // Always start led off
int btnIncreasePrevState = 1; 
int btnIncreaseCurrentState;
int btnDecreasePrevState = 1; 
int btnDecreaseCurrentState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boadRate);
  pinMode(ledPin, OUTPUT);
  pinMode(btnIncreasePin, INPUT);
  pinMode(btnDecreasePin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnIncreaseCurrentState = digitalRead(btnIncreasePin);
  btnDecreaseCurrentState = digitalRead(btnDecreasePin);
  if (btnIncreaseCurrentState == 0 && ledState <= 256) {
      ledState++;
  }
  if (btnDecreaseCurrentState == 0 && ledState >= -1) {
      ledState--;
  }

  if (ledState > 255) {
    ledState = 255;
    buzz();
  }

  if (ledState < 0) {
    ledState = 0;
    buzz();
  }
   
  analogWrite(ledPin, ledState);
  Serial.print("Decreasing pin: ");
  Serial.print(btnDecreaseCurrentState);
  Serial.print(", Increasing pin: ");
  Serial.println(btnIncreaseCurrentState);
}

void buzz() {
  digitalWrite(buzzPin, HIGH);
  delay(dt);
  digitalWrite(buzzPin, LOW);
  delay(dt);
  digitalWrite(buzzPin, HIGH);
  delay(dt);
  digitalWrite(buzzPin, LOW);
  delay(dt);
  digitalWrite(buzzPin, HIGH);
  delay(dt);
  digitalWrite(buzzPin, LOW);
}
