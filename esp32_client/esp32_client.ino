/**********************************************************************
  Filename    : WiFi Station
  Description : Connect to your router using ESP32
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <WiFi.h>
#include <HTTPClient.h>

#define USE_SERIAL Serial

const char *ssid_Router     = "Bill Wi, the Science Fi"; //Enter the router name
const char *password_Router = "Yemen101"; //Enter the router password
void setup(){
  Serial.begin(115200);
  delay(2000);
  Serial.println("Setup start");
  WiFi.begin(ssid_Router, password_Router);
  Serial.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Setup End");
}
  String address= "http://165.227.76.232:3000/afa2135/running";
 
void loop() {
  // http://165.227.76.232:3000/afa2135/running
  
    if((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin(address); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                if(payload.equals("false")){
                  USE_SERIAL.println("Hitting false");
                }
                else if(payload.equals("true")){
                  USE_SERIAL.println("Hitting True");
                }
                USE_SERIAL.println(payload);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(5000);

}
