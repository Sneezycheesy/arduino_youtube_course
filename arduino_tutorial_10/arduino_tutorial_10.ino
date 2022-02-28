/* Tutorial 10: Understanding analogRead
 * https://www.youtube.com/watch?v=5TitZmA66bI&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=10
 */
const int pin = A0;
float v2 = 0;
int readVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(pin);
  v2 = (5./1023.) * readVal;
  Serial.println(v2);
  delay(500);
}
