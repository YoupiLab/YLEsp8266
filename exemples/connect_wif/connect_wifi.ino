
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

}

void loop(){
   float po = analogRead(pho_resistance);
   
   if(esp.sendDataFloat(po) ==1){
    Serial.println("Envoie reussi");
   }

   if(esp.executeAnAction(led1)== 1){
      Serial.println("led alume");
   }
   if(esp.executeAnAction(led1) ==0){
      Serial.println("led eteint");
   }
   
}