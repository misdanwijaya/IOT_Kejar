void setup() {
  // put your setup code here, to run once:
  pinMode(D2,OUTPUT);

}

void loop() {
  //put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  digitalWrite(D2,HIGH);
  delay(1000);
  digitalWrite(D2,LOW);

}
