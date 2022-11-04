## A repository to quickly use the different features of ESP8266 or NODEMCU

We have created many functions for ESP8266.

-  allows to connect to a wifi
-  Execute an action
-  send a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
-  send a String data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
- send a int data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
-  send a boolean data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
- Get information from the created Thing on our iot platform
- You can execute a task you have written in the terminal thing using this methode 
- count the number of data received by our iot platform
- send feed back



All these functions have been properly commented to your comprehension

```

#include <YLEsp8266.h>
char*  ssid = "YOUPILAB";
char* password = "iloveyoupilab123";
int  led1= 14;
String APP_ID     = "esp91ce0";  // Equipment APP ID
String APP_KEY    = "c19071d5";  // Equipment Key
YLEsp8266  esp(APP_ID,APP_KEY);
void setup(){ 
  Serial.begin(9600);
  if(esp.veriyAndConnectToWifi(ssid,password) == 1){
    Serial.println("Connexion reussi");
  }

  pinMode(led1, OUTPUT);
}

void loop(){

   if(esp.executeAnAction(led1)== 1){
      Serial.println("led alume");
   }
   if(esp.executeAnAction(led1) ==0){
      Serial.println("led eteint");
   }
   
}
```




