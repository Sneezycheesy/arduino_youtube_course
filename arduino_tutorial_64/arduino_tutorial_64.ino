#include <IRremote.h>

const int baudRate = 9600;
const int dt = 500; // delaytime
const byte controlPin = 11;
uint32_t irCommand;
uint32_t prevIrCommand;

struct key_value {
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
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    irCommand = IrReceiver.decodedIRData.decodedRawData;
    if (irCommand == 0) {
      irCommand = prevIrCommand;
    }
    for (int j = 0; j < sizeof(commands); j++) {
      if (commands[j].value == irCommand) {
        Serial.println(commands[j].key);
      }
    }
    Serial.println(irCommand, HEX);
    delay(dt);
    prevIrCommand = irCommand;
    IrReceiver.resume();
  }
}
