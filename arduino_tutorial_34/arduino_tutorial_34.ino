/*
 * Tutorial 34 simplest way to use a pushbutton switch
 * https://youtu.be/ChHNI8yt69g
 */

const int baudRate = 9600;
const int dt = 200; // delaytime

const int btnPin = 2;
int btnValue;
int btnCurrentVal = 1;
int btnPrevVal;
int btnSwitchState = 0;
String btnState = "Your button is ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  pinMode(btnPin, INPUT);
  digitalWrite(btnPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = "Your button is ";
  btnValue = digitalRead(btnPin);
  if (btnValue == 1) {
    btnState += "not ";
  }
  btnState += "pressed";
  Serial.println(btnState);

  btnCurrentVal = digitalRead(btnPin);
  if (btnPrevVal == 0 && btnCurrentVal == 1) {
    btnSwitchState = !btnSwitchState;
  }
  btnPrevVal  = btnCurrentVal;
  btnState = "Your button is ";
  if (btnSwitchState == 0) {
    btnState += "off";
  } else {
    btnState += "on";
  }
  
  Serial.println(btnState);
  delay(dt);
}
