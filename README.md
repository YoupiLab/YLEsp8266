## Table of Contents
1. Presentation of YoupiLab Iot
2. General information about the YLEsp8266 library
3. Installation in the Arduino IDE
4. Uses of our YLEsp8266 library

1. Presentation of YoupiLab Iot
YoupiLab Iot (https://iot.youpilab.com/) provides hosted services in the cloud that allow you to monitor and control your remote objects.
***
2. General information about the YLEsp8266 library
Still called mcu node module, this microcontroller has a WiFi interface ideal for connected objects. Male and female side connectors allow the module to be plugged on a quick mounting plate.
3. Installation in the Arduino IDE
* To install the ESP8266 board in your Arduino IDE, follow these next instructions:

In your Arduino IDE, go to File> Preferences
* Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into the "Additional Boards Manager URLs" field as shown in the figure below. Then, click the "OK" button:

* Note: if you already have the ESP32 boards URL, you can separate the URLs with a comma as follows:

https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
Open the Boards Manager. Go to Tools > Board > Boards Manager...

* Search for ESP8266 and press install button for the "ESP8266 by ESP8266 Community":

* That's it. It should be installed after a few seconds.
* To test the ESP8266 add-on installation, let's see if we can blink an LED with the ESP8266 using the Arduino programming language.

4. Uses of our YLEsp8266 library
To use our YLEsp8266 you will have to download on github some additional libraries. 
 ESP8266HTTPClient
 ESP8266WiFi
 ESPAsyncTCP
 WiFiClient
Go to the tools folder and import the different libraries into your Arduino IDE. Go to the examples folder. You will see the example codes of the use of the library.

YLEsp8266 esp(APP_ID,APP_KEY); allows you to create an object instance called esp. APP_ID, and APP_KEY are the identifiers of the object created on the iot platform (https://iot.youpilab.com/).
esp.VeriyToConnectWifi(ssid,password); this method connects you to a wifi and makes sure that the esp8266 has been connected to the wifi.
esp.sendDataFloat(data, APP_ID, APP_KEY); sends float data to our platform in real time. 
esp.dynamicExecution(led1); This method will allow for example to turn on or off a lamp.