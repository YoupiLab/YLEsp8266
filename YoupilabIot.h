/*
  YoupilabIot.h - Library for youpilab .
  Created by Josue A. and Stephane A., Octobre, 2022.
  Youpilab Iot
*/
#ifndef YoupilabIot_h
#define YoupilabIot_h
#include<iostream>
#include <string>

using namespace std;

struct YoupilabIot
{

  public:
    YoupilabIot(string APP_KEY, string APP_ID);
    YoupilabIot(string APP_KEY, string APP_ID, string BASE_URL);

 
    void VeriyToConnectWifi(char* s, char* p);
    string sendDataFloat(float px , int number);

    void DynamicExecution();

    string getBaseUrl();
    string getAppKey();
    string getAppId();

    void setAppKey(string app_key);
    void setAppID(string app_id);
    void setBaseUrl(string url);

  private:
    int _pin;
    string _APP_ID;
    string _APP_KEY;
    string _BASE_URL;

};


#endif