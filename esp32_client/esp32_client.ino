/**********************************************************************
  Filename    : WiFi Station
  Description : Connect to your router using ESP32
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <WiFi.h>
#include <HTTPClient.h>
#define USE_SERIAL Serial
// Connect to wifi
const char *ssid_Router     = "Bill Wi, the Science Fi"; //Enter the router name
const char *password_Router = "Yemen101"; //Enter the router password

#include "Freenove_WS2812_Lib_for_ESP32.h"
//Set up the led strip
#define LEDS_COUNT  8
#define LEDS_PIN  2
#define CHANNEL   0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);
//THis is the address I want to hit
String address= "http://165.227.76.232:3000/afa2135/running";

void setup(){
  //Pin 27 is to output the signal to the mega to give it commands for the feathers
  pinMode(27,OUTPUT);
  USE_SERIAL.begin(115200);
  //Setting up wifi stuff. 
  //Source: Code is the Basic HTTP sample sketch
  WiFi.begin(ssid_Router, password_Router);
  USE_SERIAL.println(String("Connecting to ")+ssid_Router);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    USE_SERIAL.print(".");
  }
  USE_SERIAL.println("\nConnected, IP address: ");
  USE_SERIAL.println(WiFi.localIP());
  USE_SERIAL.println("Setup End");
  //LED strip, set it to no color
    strip.begin();
  strip.setBrightness(30);
  strip.setAllLedsColor(0,0,0);
}
 
void loop() {
  // The wifi/http code aka most of the code except the if/else statement testing if payload is false/true is SOURCED fromt he basic http request sketch example file. See that for source
  
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
                  //If I am at false, give the mega a high reading to tell it to set the feathers to 90 degrees. Also turn off the led strip
                  USE_SERIAL.println("Hitting false");
                  digitalWrite(27,HIGH);
                  strip.setAllLedsColor(0,0,0);
                }
                else if(payload.equals("true")){
                  //In this case, turn on rainbow colors and tell mega to expand the wings through its servos.
                  USE_SERIAL.println("Hitting True");
                  digitalWrite(27,LOW);
                  rainbow();

                }
                USE_SERIAL.println(payload);
                
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }
}

void rainbow(){
  // Code found from C_tutorial pdf 
    strip.setBrightness(30);

    for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(5);
  }  
}
