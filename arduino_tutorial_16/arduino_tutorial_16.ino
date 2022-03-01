/*
 * Tutorial 16 Fun with For loops
 * https://youtu.be/5cd_8AmkI04
 */

 const int serialBaud = 9600;
 const int dt = 500; // delaytime
 int j;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(serialBaud);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (j = 1; j <= 10; j++) {
    Serial.print("J = ");
    Serial.println(j);
    delay(dt);
  }

  for (j = 9; j > 0; j--) {
    Serial.print("J = ");
    Serial.println(j);
    delay(dt);
  }
  Serial.println();
  
}
