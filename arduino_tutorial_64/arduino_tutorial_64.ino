#include <IRremote.h>

const int baudRate = 9600;
const int dt = 500; // delaytime
const byte controlPin = 11;
uint32_t irCommand;

const unsigned int cmdZero = 0xE916FF00;
const unsigned int cmdOne = 0xF30CFF00;
const unsigned int cmdTwo = 0xE718FF00;
const unsigned int cmdThree = 0xA15EFF00;
const unsigned int cmdFour = 0xF708FF00;
const unsigned int cmdFive = 0xE31CFF00;
const unsigned int cmdSix = 0xA55AFF00;
const unsigned int cmdSeven = 0xBD42FF00;
const unsigned int cmdEight = 0xAD52FF00;
const unsigned int cmdNine = 0xB54AFF00;
const unsigned int cmdPower = 0xBA45FF00;
const unsigned int cmdVolUp = 0xB946FF00;
const unsigned int cmdVolDown = 0xEA15FF00;
const unsigned int cmdFuncStop = 0xB847FF00;
const unsigned int cmdBack = 0xBB44FF00;
const unsigned int cmdPause = 0xBF40FF00;
const unsigned int cmdNext = 0xBC43FF00;
const unsigned int cmdDown = 0xF807FF00;
const unsigned int cmdUp = 0xF609FF00;
const unsigned int cmdEQ = 0xE619FF00;
const unsigned int cmdStopRepeat = 0xF20DFF00;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  IrReceiver.begin(controlPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    irCommand = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(irCommand, HEX);
    delay(dt);
    IrReceiver.resume();
  }
}
