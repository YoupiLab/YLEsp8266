#include <YLEsp8266.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";
int pho_resistance= A0;
int led1= 14;
float datas = 2.34;
String APP_ID     = "esp91ce0";  // Equipment APP ID
String APP_KEY    = "c19071d5";  // Equipment Key

YLEsp8266  esp(APP_ID,APP_KEY); //
void setup(){
  Serial.begin(9600);
  //int result = addPoint(6,4 );
  esp.VeriyToConnectWifi(ssid,password);
  pinMode(led1, OUTPUT);
  pinMode(pho_resistance, INPUT);
}

void loop(){
   float po = analogRead(pho_resistance);
   Serial.println(po);
   Serial.println(esp.getAppId()); //getAppId() is method to display APPID
   esp.sendDataFloat(po); //send float information to our iot platform (https://iot.youpilab.com) 
   esp.dynamicExecution(led1); //This method will allow for example to turn on or off a lamp.
   
}
