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

      int veriyAndConnectToWifi(char* ssid, char* password); //allows to connect to a wifi
      
      int sendDataFloat(float px); //send a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataIntegger(int px); //send a int data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataString(String px); //send a string data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure

      int sendDataBoolean(boolean px); // send a boolean data on our iot platform (https://iot.youpilab.com);return 1 in case of success and 0 in case of failure

      int executeAnAction(int led); //execute an action return 1 in case of success and 0 in case of failure

      void retrieveInformation(String TERMINAL_ID); // get info

      void countData();

      void retrieveAllData(String start, String end);

      void getInformationForTerminal();

      void sendFeedback();

      void executeTerminalTask(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION);

      String getAppKey();
      String getBaseUrl();
      String getAppId();

      void setAppKey(String key);
      void setAppUrl(String url);
      void setAppID(String id);
   
   private:
      WiFiClientSecure client;
      String _APP_ID;
      String _APP_KEY;
      String _BASE_URL;
};



#endif
