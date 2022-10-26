#ifndef LIBRARY_H
#define LIBRARY_H
#include <Wire.h> 
#include <ESP8266HTTPClient.h> 
//#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <WiFiClient.h>

struct YLEsp8266{
    public:
      YLEsp8266(String APP_KEY, String APP_ID);
      int addPoint(int a, int b);

      void VeriyToConnectWifi(char* ssid, char* password);
      
      void sendDataFloat(float px, String APP_ID, String APP_KEY);
      
      void dynamicExecution(int led);

      String getAppKey();
      String getBaseUrl();
      String getAppId();

      void setAppKey(String key);
      void setAppUrl(String url);
      void setAppID(String id);
   
   private:
      String _APP_ID;
      String _APP_KEY;
      String _BASE_URL;
};



#endif
