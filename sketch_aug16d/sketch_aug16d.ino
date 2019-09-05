void hidup(int waktu){
  digitalWrite(LED_BUILTIN,HIGH);
  delay(waktu);
}

void mati(int waktu){
  digitalWrite(LED_BUILTIN,LOW);
  delay(waktu);
 }

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  hidup(2000);
  mati(3000);
}
