/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
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
YoupilabIot::YoupilabIot(string APP_ID, string APP_KEY, string BASE_URL): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("")
{}

void YoupilabIot::VeriyToConnectWifi(char* ssid, char* password){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed!");
    return;
  }
}

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
