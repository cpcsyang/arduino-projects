void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("0123456789");
  Serial.print("\0\r");
  Serial.println();
  delay(2000);
}
