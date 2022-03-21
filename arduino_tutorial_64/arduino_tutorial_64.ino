#include <IRremote.h>

const int baudRate = 9600;
const int dt = 500; // delaytime
const byte controlPin = 11;
int irCommand;
IRrecv IR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  IrReceiver.begin(controlPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode() == 0) {
    
  }
  irCommand = IR.decodedIRData.decodedRawData;
  Serial.println(irCommand, HEX);
  delay(dt);
  IR.resume();
}
