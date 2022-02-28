// Tutorial 7
// https://www.youtube.com/watch?v=6CRhpUV92ww&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=7

const int pin = 3;
int brightness = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(brightness <= 255) {
    analogWrite(pin, brightness);
    delay(20);
    brightness++;
  }
  brightness = 0;
}
