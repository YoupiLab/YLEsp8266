/*
  YoupilabIot.cpp - Library for flashing Morse code.
  Created by YoupilabIot
*/

#include <Wire.h> 
#include<iostream>
#include<string>
#include <Arduino.h>

#include <ESP8266HTTPClient.h> 
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>

//#include <WiFiClient.h>

#include "YoupilabIot.h"

using namespace std;
YoupilabIot::YoupilabIot(string APP_ID, string APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api") //constructeur
{}
YoupilabIot::YoupilabIot(string APP_ID, string APP_KEY, string BASE_URL): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL(BASE_URL) //constructeur
{}
/********************************************** Les SETTER ET GETTER */
string YoupilabIot::getAppKey(){
  return _APP_KEY;
}

string YoupilabIot::getAppId(){
  return _APP_ID;
}

void YoupilabIot::setAppKey(string appkey){
       _APP_KEY = appkey;
}

void YoupilabIot::setAppID(string appid){
      _APP_ID = appid;
}

string YoupilabIot::getBaseUrl(){
     return _BASE_URL;
}

void YoupilabIot::setBaseUrl(string url){
      _BASE_URL = url;
}

//permet de verifier si la carte esp c'est bien connecter
void YoupilabIot::VeriyToConnectWifi(char* ssid, char* password){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed!");
    return;
  }
}

//envoie de donnee sur la plateforme
string YoupilabIot::sendDataFloat(float px , int number){
  WiFiClientSecure client;
  client.setInsecure();
  String post_url = getBaseUrl() + "/data/send?" + "APP_ID=" + getAppId() + "&APP_KEY=" + getAppKey();
         post_url +="&P1="+number;
         post_url +=px;

  /*Envoie de la reqette*/
  httpClient.begin (client,post_url);                 //ESP se connecte en suivant le lien post_url
  int httpCode=httpClient.GET();                     //Code erreur http 
   if (httpCode==HTTP_CODE_OK){
   String requette=httpClient.getString();
      Serial.print("Response == ");
      Serial.println(requette);
      if((requette.indexOf("</id><v>0</v></t>"))== -1){
        Serial.println("Envoi réussi");
      }else {
        Serial.println("Echec");
      }
   }
   else
   {
    Serial.print("Erreur code :");
    Serial.println(httpCode); 
   }
}


// https://techtutorialsx.com/2018/11/19/esp32-arduino-http-2-get-request/
//    else
//    {
//      Serial.print("Error == ");
//      Serial.print(httpCode); ; 
//    }
// }


// ############# HTTP REQUEST ################ //

// void YoupilabIot::sendDataFloat(string path)
// {
//   string payload = makeRequest(path);

//   if (!payload) {
//     return;
//   }

//  // Serial.println("##[RESULT]## ==> " + payload);

// }

// string YoupilabIot::makeRequest(String path)
// {
//   http.begin(getBaseUrl + path);
//   int httpCode = http.GET();

//   if (httpCode < 0) {
//     Serial.println("request error - " + httpCode);
//     return "";

//   }

//   if (httpCode != HTTP_CODE_OK) {
//     return "";
//   }

//   string response =  http.getString();
//   http.end();

//   return response;
// }

// ###################################### //

// implementacao dos prototypes
//recevoir les donnees
