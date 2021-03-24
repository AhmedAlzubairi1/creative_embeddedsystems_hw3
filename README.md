# Module 4: Robotic Peacock
Module 4 for Creative embedded Systems.

## Sources:
Go to https://git.io/JTz3m to download the master file. 

I used the BasicHTTPClient example sketch to handle all the wifi/http request of the code. Please see that for reference.

The code relating to making the rainbow sequence of the RGB LED module is found here:  https://github.com/Freenove/Freenove_WS2812_Lib_for_ESP32/blob/master/examples/Rainbow/Rainbow.ino

The documentation for both sources of code is found in this pdf file:  Freenove_Ultimate_Starter_Kit_for_ESP32-master\Freenove_Ultimate_Starter_Kit_for_ESP32-master\C\C_Tutorial

## What is it?

It is a maker inspired chocolate box, but this time I added music and made it portable. 
Connect the components under the chocolate box to give a unique chocolate box to your significant other this Valentine's day.
Once the enclosure has been created, you can send "left" string via bluetooth to turn on the LEDs in a clockwise direction. "Send "right" to turn the LEDs in a counter clockwise direction. Send "off" to turn off all the lights. Send "rainbow" to turn on the RGB Led module. If you make sure that you connect through bluetooth, you can play music by playing the music through your phone.

## Using the Website
See Running the app for instructions on how to run the website. After running the website, just click the center button to activate the sculpture. 

## Installation 
Go to the root directory and install using:
```
cd kinetic-sculpture-webapi
npm install
```

## Setting up Wiring
Components used:

  - Freenove 8 RGB LED Module
  - 4 Servo Motors
  - Arduino Mega
  - ESP32-WROVER
 
For the specific wiring, here is the digital connection layout for all the components:
Esp32:

    - Connect RGB LED module signal cable to 2, and connect the power to 3.3v and ground to ground 
    - Connect pin 27 of the ESP32 to pin 9 of the Arduino Mega

Arduino Mega:

    - Connect the 4 Servo Signal pins to pins 10,11,12,13 respectively. Connect their VCC and GND pins to the 5v and GND pins on the mega.

## Running the Program

Run the megaservo file on your Arduino Mega, and run the esp32_client file on your esp32. That is all you need to Set up the program. To interact with the scultpure, please use the api. See instructions:

Run the program by running:

```
node server.js
```
Then go to this website: http://165.227.76.232:3000/myuni and click the button. My uni is afa2135, so I went to http://165.227.76.232:3000/afa2135. 
When you click the button, the rainbow LED would flash and the feathers of the sculputure will expand.

## More Documentation

The code has been very well documented through comments. See for more info. 

## Demo:
https://www.youtube.com/watch?v=0ggWUWyJqHM&ab_channel=AhmedAlzubairi

## Bugs:

I initially used batteries instead of powering the microcontrollers with my computer, but I found it difficult to power everything, so I ended up just using my computer. 
So if you try to use batteries, be warned that you would need one with enough power to handle everything.
