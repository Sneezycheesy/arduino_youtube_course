#include <IRremote.h>

const int baudRate = 9600;
const int dt = 500; // delaytime
const byte controlPin = 11;
const byte enPin = 10;
const byte pwrPin1 = 4;
const byte pwrPin2 = 9;
uint32_t irCommand;
uint32_t prevIrCommand;
byte motorSpeed = 255;
bool motorDirection = 1; // 1 = forward, 0 = backward
bool running = 0; // when 0, motor is off
String motorCommand;

const struct key_value {
  char* key;
  uint32_t value;
} commands[] = {
  {"zero", 0xE916FF00},
  {"one", 0xF30CFF00},
  {"two", 0xE718FF00},
  {"three", 0xA15EFF00},
  {"four", 0xF708FF00},
  {"five", 0xE31CFF00},
  {"six", 0xA55AFF00},
  {"seven", 0xBD42FF00},
  {"eight", 0xAD52FF00},
  {"nine", 0xB54AFF00},
  {"pwr", 0xBA45FF00},
  {"vol+", 0xB946FF00},
  {"vol-", 0xEA15FF00},
  {"func/stop", 0xB847FF00},
  {"prev", 0xBB44FF00},
  {"next", 0xBC43FF00},
  {"play/pause", 0xBF40FF00},
  {"down", 0xF807FF00},
  {"up", 0xF609FF00},
  {"EQ", 0xE619FF00},
  {"stop/repeat", 0xF20DFF00}
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  IrReceiver.begin(controlPin);
  pinMode(pwrPin1, OUTPUT);
  pinMode(pwrPin2, OUTPUT);
  pinMode(enPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (!IrReceiver.decode()) {
    
  }
  irCommand = IrReceiver.decodedIRData.decodedRawData;
  if (irCommand == 0) {
    irCommand = prevIrCommand;
  }
  for (int j = 0; j < sizeof(commands); j++) {
    if (commands[j].value == irCommand) {
      motorCommand = commands[j].key;
    }
  }

  handleCommand();
  prevIrCommand = irCommand; 
  Serial.println(motorCommand);
  Serial.println(motorSpeed);
  delay(dt);
  IrReceiver.resume();
}

void handleCommand() {
  if (motorCommand == "pwr") {
    startStopMotor();
  } else if (motorCommand == "next") {
    motorDirection = 1;
    setDirectionMotor();
  } else if (motorCommand == "prev") {
    motorDirection = 0;
    setDirectionMotor();
  } else if (motorCommand == "vol+") {
    changeSpeed(1);
  } else if (motorCommand == "vol-") {
    changeSpeed(0);
  }
}

void startStopMotor() {
  running = !running;
  setDirectionMotor();
  if (running) {
    analogWrite(enPin, 255);
    delayMicroseconds(120);
    analogWrite(enPin, motorSpeed);
  } else {
    digitalWrite(enPin, LOW);
  }
}

void setDirectionMotor() {
  digitalWrite(enPin, LOW);
  delay(50);
  digitalWrite(pwrPin1, !motorDirection);
  digitalWrite(pwrPin2, motorDirection);
  if (running) {
    analogWrite(enPin, 255);
    delay(50);
    analogWrite(enPin, motorSpeed); 
  }
}

void changeSpeed(bool upOrDown) {
  if (upOrDown) {
    if (motorSpeed < 255) {
      motorSpeed += 5;
    }
    if (motorSpeed > 255) {
      motorSpeed = 255;
    }
  } else {
    if (motorSpeed > 90) {
      motorSpeed -= 5;
    }
    if (motorSpeed < 90) {
      motorSpeed = 90;
    }
  }
  analogWrite(enPin, motorSpeed);
}
