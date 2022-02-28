// From tutorial 2
// https://www.youtube.com/watch?v=9uHZB7-T_XA&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=2
const int redLedPin = 5;
const int greenLedPin = 4;
const int blueLedPin = 3;
int pin;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* Blink RED LED 5 times 
     GREEN LED 10 times
     BLUE LED 15 times
   */

   // With 1 for loop
   for (int i = 1; i < 4; i++) {
    // Check what pin need to be activated
    int repeats = i * 5;
    if (repeats >= 15) {
      pin = blueLedPin;
    } else if (repeats >= 10) {
      pin = greenLedPin;
    } else {
      pin = redLedPin;
    }
    for (int j = 1; j <= repeats; j++) {
      digitalWrite(pin, HIGH);
      delay(500);
      digitalWrite(pin, LOW);
      delay(500);
    }
   }

   // Each LED its own
   for (int i = 0; i < 5; i++) {
    digitalWrite(redLedPin, HIGH);
    delay(500);
    digitalWrite(redLedPin, LOW);
    delay(500);
   }

   for (int i = 0; i < 10; i++) {
    digitalWrite(greenLedPin, HIGH);
    delay(500);
    digitalWrite(greenLedPin, LOW);
    delay(500);
   }

   for (int i = 0; i < 15; i++) {
    digitalWrite(blueLedPin, HIGH);
    delay(500);
    digitalWrite(blueLedPin, LOW);
    delay(500);
   }
   
}
