
#include <YLEsp8266.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";
int  led1= 14;
int pho_resistance= A0;
String APP_ID     = "esp91ce0";  // Equipment APP ID
String APP_KEY    = "c19071d5";  // Equipment Key
YLEsp8266  esp(APP_ID,APP_KEY);
void setup(){ 
  Serial.begin(9600);
  if(esp.veriyAndConnectToWifi(ssid,password) == 1){
    Serial.println("Connexion reussi");
  }  

  pinMode(led1, OUTPUT);
  pinMode(pho_resistance, INPUT);
}

void loop(){
   float po = analogRead(pho_resistance);
   if(esp.sendDataFloat(po) ==1){
    Serial.println("Envoie reussi");
   }
   
}