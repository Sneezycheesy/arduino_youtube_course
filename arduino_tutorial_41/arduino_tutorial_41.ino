/* 
 *  Tutorial 41 Understanding hexadecimal numbers
 *  https://youtu.be/-RSI0z5zbqI
 */

const int baudRate = 9600;
const int dt = 500;
byte myByte = 0x00;
int myInt1 = 0xA0;
int myInt2 = 0xCB;
int sum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baudRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  sum = myInt1 + myInt2;
  Serial.print("Decimal: ");
  Serial.print(sum, DEC);
  Serial.print(", Hexadecimal: ");
  Serial.print(sum, HEX);
  Serial.print(", Binary: ");
  Serial.println(sum, BIN);
  myInt1++;
  delay(dt);
}
