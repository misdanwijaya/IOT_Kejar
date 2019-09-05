/*#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  dht.begin();
  Serial.println("Checkt DHT Sensor");
}

void loop(){
  delay(1000);
  float temperature = dht.readTemperature();
  float humadity = dht.readHumidity();

    if(isnan(humadity) || isnan(temperature)){
      Serial.println("Failed to read from DHT sensor");
      return;
    }

    float hic = dht.computeHeatIndex(temperature,humadity,false);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("c \t");
    Serial.print("Humadity: ");
    Serial.print(humadity);
    Serial.print("%");
    Serial.println("");
    delay(1000);
      
}*/

#define trigPin 13
#define echoPin 12
#define led1 14

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1,OUTPUT);  
}

void loop(){
  long duration, distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  
  distance = (duration/2)/29.1;
  Serial.println(distance);

  if(distance <= 50){
    digitalWrite(led1,HIGH);
  }
  else{
    digitalWrite(led1,LOW);
  }
   
 }
