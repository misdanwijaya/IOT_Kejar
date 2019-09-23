#include <WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Inixindobdg";
const char* password = "ciscomicrosoft";
const char* mqtt_server = "soldier.cloudmqtt.com";
const int mqtt_port = 14667;
const char* mqtt_user = "jvumpjzc";
const char* mqtt_pass = "E3rbQi9Dlv6N";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
void setup_wifi() {
 delay(10);
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 randomSeed(micros());
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
}
void callback(char* topic, byte* payload, unsigned int length) {
 if (strcmp(topic,"led1")==0){
 for (int i=0;i<length;i++) {
 char receivedChar = (char)payload[i];
 if (receivedChar == '1')
 digitalWrite(BUILTIN_LED, HIGH);
 if (receivedChar == '0')
 digitalWrite(BUILTIN_LED, LOW);
 }
 }
}
void reconnect() {
 while (!client.connected()) {
 Serial.print("Attempting MQTT connection...");
 String clientId = "ESP32Client-";
 clientId += String(random(0xffff), HEX);
 if (client.connect(clientId.c_str(),mqtt_user,mqtt_pass)) {
 Serial.println("connected");
 client.subscribe("led1");
 } else {
 Serial.print("failed, rc=");
 Serial.print(client.state());
 Serial.println(" try again in 5 seconds");
 delay(5000);
 }
 }
}
void setup() {
 pinMode(BUILTIN_LED, OUTPUT);
 Serial.begin(9600);
 setup_wifi();
 client.setServer(mqtt_server, mqtt_port);
 client.setCallback(callback);
}
void loop() {
 if (!client.connected()) {
 reconnect();
 }
 client.loop();
}
