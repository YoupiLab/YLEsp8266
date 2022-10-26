#include <YLEsp8266.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";

//create your Objet iot https://iot.youpilab.com/
String APP_ID     = "esp91ce0";  // Equipment APP ID
String APP_KEY    = "c19071d5";  // Equipment Key
YLEsp8266  esp(APP_ID,APP_KEY);
void setup(){
  Serial.begin(9600);
  
  esp.VeriyToConnectWifi(ssid,password);
  
}

void loop(){
   float po = analogRead(pho_resistance);
   Serial.println(po);
   Serial.println(esp.getAppId());
   esp.sendDataFloat(po, APP_ID, APP_KEY);
   esp.dynamicExecution(led1); // with this method you can for example turn on or off a led with our iot platform
}
