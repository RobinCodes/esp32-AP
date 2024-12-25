#include <WiFi.h>  // Wifi module
#include <WebServer.h>  // webserver module

const char *ssid = "AP_NAME_HERE";  // SSID for the AP goes here
const char *password = "PASSWORD_HERE";  // password for the AP goes here
WebServer server(80);  // servers on port 80

void setup() {
  Serial.begin(115200);

  // Set up the AP
  WiFi.softAP(ssid, password);
  Serial.println("Starting AP, Please Wait...");
  
  Serial.println("Serving on: "); //this displays the IP (this is what the user will connect to when they have connected to the network)
  Serial.println(WiFi.softAPIP());

  // basic HTML page to display on connect
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", "<html><body><p>Hello World</p></body></html>");
  });

  // This starts the server
  server.begin();

  Serial.println("ESP32 Access Point Online!"); //simply tells the user the server is online
}

void loop() {
  server.handleClient();
}
