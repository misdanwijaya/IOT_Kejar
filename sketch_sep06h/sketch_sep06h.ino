#include <WiFi.h>
#define PORT 8080
#define LED_BUILTIN 2

const char *SSID = "Inixindobdg";
const char *PASSWORD = "ciscomicrosoft";
String header= "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body>";
String body ="<p><a href=\"blink\">LED Blinking</a></p><p><a href=\"on\">LED ON</a></p><p><a href=\"off\">LED OFF</a></p>";
String tailer= "</body></html>";

WiFiServer server(8080);
WiFiClient client;
bool blinking=false;
bool ledOn= false;
String s;
String cmd;

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("Web Server active: ");
  Serial.println( WiFi.localIP() );
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  client= server.available(); //tunggu client
  Serial.println("waiting for client ");
  if (client) { // dapat client baru
   Serial.println("got a new client");
    while (client.connected() ) {
      if ( client.available()) {
      //Serial.println("Data can be read");
      s = client.readString();
      cmd= getCommand(s);
      response(cmd);
      
      if (cmd.equals("")) {
        Serial.println("HOMEPAGE");
      } else if(cmd.equals("blink")) {
        blinking= true;
        ledOn= false;
      } else if(cmd.equals("on") ){
        blinking= false;
        ledOn= true;
      } else if(cmd.equals("off")) {
        blinking= false;
        ledOn= false;
      } else { // unknown command
        response(s);
      client.stop();
      }
      //client.stop();
      Serial.println(cmd);
      //delay(100);
    }
     else {
       client.stop();
     }
   }
 
    //client.stop();
  }
  else {
  //Serial.println("No client yet ");
  }
  
  if (blinking || ledOn) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  if (blinking || ! ledOn) {
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
   }
}

void response(String konten) {
  //Serial.println(header);
  //Serial.println(konten);
  //Serial.println(tailer);
  client.println(header);
  client.println(konten);
  client.println(body);
  client.println(tailer);
}

String getCommand(String s) {
    return (s.substring(5, s.indexOf(' ',5)));
}
