#include <WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Inixindobdg";
const char* password = "ciscomicrosoft";
const char* mqttServer = "soldier.cloudmqtt.com";
const int mqttPort = 14667;
const char* mqttUser = "jvumpjzc";
const char* mqttPassword = "E3rbQi9Dlv6N";
int sensor = 33;
WiFiClient espClient;
PubSubClient client(espClient);
void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.println("Connecting to WiFi..");
 }
 Serial.println("Connected to the WiFi network");
 client.setServer(mqttServer, mqttPort);
 while (!client.connected()) {
 Serial.println("Connecting to MQTT...");
 if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
 Serial.println("connected");
 } else {
 Serial.print("failed with state ");
 Serial.print(client.state());
 delay(2000);
 }
 }
 pinMode(sensor,INPUT);
}
void loop() {
 client.loop();
 int SensorLDR=analogRead(sensor);
 char hasil[4];
 dtostrf(SensorLDR, 4, 0, hasil);
 Serial.println(SensorLDR);
 client.publish("cahaya", hasil);
 delay (5000);
}
