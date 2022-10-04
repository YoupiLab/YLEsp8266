/*
  YoupilabIot.cpp - Library for flashing Morse code.
  Created by YoupilabIot
*/

#include <Wire.h> 
#include <ESP8266HTTPClient.h> 
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include<iostream>
#include<string>
#include <Arduino.h>
#include "YoupilabIot.h"
HTTPClient httpClient; //important

using namespace std;
YoupilabIot::YoupilabIot(string APP_ID, string APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api") //constructeur
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



//recevoir les donnees
