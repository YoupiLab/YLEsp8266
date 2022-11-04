#include "YLEsp8266.h"
WiFiClient wifi;

HTTPClient httpClient;

YLEsp8266::YLEsp8266(String APP_ID, String APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api"){}

/********************************************** Les SETTER ET GETTER */
/*
  get app key
*/
String YLEsp8266::getAppKey(){
  return _APP_KEY;
}
/*
  get app id
*/
String YLEsp8266::getAppId(){
  return _APP_ID;
}
/*
  get set app key
*/
void YLEsp8266::setAppKey(String appkey){
       _APP_KEY = appkey;
}
/*
  get app id
*/
void YLEsp8266::setAppID(String appid){
      _APP_ID = appid;
}
/*
  get base url
*/
String YLEsp8266::getBaseUrl(){
     return _BASE_URL;
}

/*
  allows to connect to a wifi
*/
int YLEsp8266::veriyAndConnectToWifi(char* ssid, char* password){
  delay(200); 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  }
  
   return 1;
}
/*
  Execute an action
*/
int YLEsp8266::executeAnAction(int led1){
    /***********recuperation des instructions a executer depuis la plateforme IoT ******/
    String post_url = "https://iot.youpilab.com/api/controls/get?APP_ID=" + _APP_ID + "&APP_KEY=" + _APP_KEY;

    client.setInsecure();
    httpClient.begin (client,post_url);
    int httpCode=httpClient.GET();
       if (httpCode==HTTP_CODE_OK){
    String etatb=httpClient.getString();
    etatb.replace("\n", "");
    etatb.replace("[", "");
    etatb.replace("]", "");
    etatb.replace(",", "");
    etatb.replace(" ", "");
    etatb.trim();
    
    char etat= etatb.charAt(0);
    int etat1 = etat -48; //convertir l'etat en entier 49 c'est que le bouton a ete appuer
    if(etat1==1)
    {
      digitalWrite(led1, HIGH);
      return 1;
    }
    else
    {
      digitalWrite(led1, LOW);
      return 0;
    }
}
}
/*
  send a float data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YLEsp8266::sendDataFloat(float px){
      client.setInsecure();
      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";

      post_url+=_APP_ID; //id of thing
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY; // key of thing
      post_url +="&P1=";
      post_url +=px;
      /*Envoie de la reqette*/
      //  Serial.println(post_url);

      httpClient.begin(client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        
        String payload = httpClient.getString();
       
        return 1;
      }
      else {
       
        return 0;
       
      }
      delay(1000);
}

/*
  /send a String data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YLEsp8266::sendDataString(String px){
      client.setInsecure();
      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";
      post_url+=_APP_ID; //id of thing
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY; // key of thing
      post_url +="&P1=";
      post_url +=px;
      /*Envoie de la reqette*/
      httpClient.begin (client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        
        String payload = httpClient.getString();
        return 1;
      }
      else {
        return 0;
      }
      delay(1000);
}
/*
  /send a int data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YLEsp8266::sendDataIntegger(int px){
      client.setInsecure();

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";

      post_url+=_APP_ID; //id of thing
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY; // key of thing
      post_url +="&P1=";
      post_url +=px;
      /*Envoie de la reqette*/
      httpClient.begin (client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        
        String payload = httpClient.getString();
        return 1;
      }
      else {
       return 0;
       
      }
      delay(1000);
}
/*
  /send a boolean data on our iot platform (https://iot.youpilab.com); return 1 in case of success and 0 in case of failure
*/
int YLEsp8266::sendDataBoolean(boolean px){
      client.setInsecure();

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";

      post_url+=_APP_ID; //id of thing
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY; // key of thing
      post_url +="&P1=";
      post_url +=px;
      /*Envoie de la reqette*/
      httpClient.begin (client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        
        String payload = httpClient.getString();
        return 1;
      }
      else {
        return 0;
       
      }
      delay(1000);
}
/*
  Get information from the created Thing
*/
void YLEsp8266::getInformationOfThingCreated(){
     client.setInsecure();

      String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";

      post_url+=_APP_ID; //id of thing
      post_url +="&APP_KEY=";
      post_url +=_APP_KEY; // key of thing
      post_url +="&P1=";
    
      /*Envoie de la reqette*/
      httpClient.begin (client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        
       String payload = httpClient.getString();
        Serial.println(payload);
      }
      else {
          Serial.println(httpResponseCode);
      }
      delay(1000);

}
/*
  You can execute a task you have written in the terminal thing using this methode 
*/
int YLEsp8266::executeTerminalTask(String TERMINAL_ID){
  client.setInsecure();

  String post_url = "https://iot.youpilab.com/api/terminal/?TERM=";
  //ok good
  post_url+=TERMINAL_ID;
  httpClient.begin (client,post_url); 
  int httpResponseCode = httpClient.GET();
  if (httpResponseCode > 0) {
    
    String payload = httpClient.getString();
    return 1;
  }
  else {
     return 0;
  }
  delay(1000);
}
/*
  count the number of data received by our iot platform
*/
void YLEsp8266::countData(){
    client.setInsecure();

    String post_url = "https://iot.youpilab.com/api/data/count?APP_ID=";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;

    httpClient.begin (client,post_url); 
    int httpResponseCode = httpClient.GET();
    if (httpResponseCode > 0) {
      // Serial.print("HTTP ");
      // Serial.println(httpResponseCode);
      String payload = httpClient.getString();
      // Serial.println();
      Serial.println(payload);
    }
    else {
      
      Serial.println(httpResponseCode);
      
    }
    delay(1000);
}

/*
  These informations must be used to execute the following request which will display the response in terminal of thing
*/
int YLEsp8266::executeAnActionWithTerminal(String TERMINAL_ID, String TASK_ID, String RESPONSE_OF_EXECUTION){
    client.setInsecure();

    String post_url = "https://iot.youpilab.com/api/terminal/response/?TERM=";
    //ok good
    post_url+=TERMINAL_ID;
    post_url +="&TASK_ID=";
    post_url +=TASK_ID;
    post_url +="&RESP=";
    post_url +=RESPONSE_OF_EXECUTION;
      
    httpClient.begin (client,post_url); 
    int httpResponseCode = httpClient.GET();
    if (httpResponseCode > 0) {
      String payload = httpClient.getString();
     return 1;
    }
    else {
      
      return 0;
      
    }
}

/*
  send feed back
*/
void YLEsp8266::sendFeedback(){
    client.setInsecure();

    String post_url = "https://iot.youpilab.com/api/controls/executed?APP_ID";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;

    httpClient.begin (client,post_url); 
    int httpResponseCode = httpClient.GET();
    if (httpResponseCode > 0) {
      // Serial.print("HTTP ");
      // Serial.println(httpResponseCode);
      String payload = httpClient.getString();

      Serial.println(payload);
    }
    else {
      
      Serial.println(httpResponseCode);
      
    }
}
