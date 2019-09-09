#include <WiFi.h>
const char *SSID = "Inixindobdg";
const char *PASSWORD = "ciscomicrosoft";

void setup() {
 Serial.begin(921600);
 delay(1000);
 WiFi.disconnect(true);
 connectToHotSpot();
}

void connectToHotSpot() {
 WiFi.begin( SSID, PASSWORD );
 Serial.print("Trying to establish connection to WiFi Router");
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println();
 Serial.println("Connected! IP: ");
 Serial.println(WiFi.localIP());
}

void loop() {
 // nothing here
}
