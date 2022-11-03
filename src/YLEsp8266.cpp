#include "YLEsp8266.h"
WiFiClient wifi;

HTTPClient httpClient;

int status = WL_IDLE_STATUS;

YLEsp8266::YLEsp8266(String APP_ID, String APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api"){}

/********************************************** Les SETTER ET GETTER */
String YLEsp8266::getAppKey(){
  return _APP_KEY;
}

String YLEsp8266::getAppId(){
  return _APP_ID;
}

void YLEsp8266::setAppKey(String appkey){
       _APP_KEY = appkey;
}

void YLEsp8266::setAppID(String appid){
      _APP_ID = appid;
}

String YLEsp8266::getBaseUrl(){
     return _BASE_URL;
}

//permet de verifier si la carte esp c'est bien connecter
int YLEsp8266::veriyAndConnectToWifi(char* ssid, char* password){
  delay(200); 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  }
  
   return 1;
}

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

void YLEsp8266::retrieveInformation(String TERMINAL_ID){
  client.setInsecure();

  String post_url = "https://iot.youpilab.com/api/terminal/?TERM=";
  //ok good
  post_url+=TERMINAL_ID;
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

void YLEsp8266::retrieveAllData(String start, String end){
    client.setInsecure();

    String post_url = "https://iot.youpilab.com/api/data/pull?APP_ID=";
    //ok good
    post_url+=_APP_ID;
    post_url +="&APP_KEY=";
    post_url +=_APP_KEY;
    post_url +="&start=";
    post_url +=start;
    post_url +="&end=";
    post_url +=end;

      httpClient.begin (client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        
        String payload = httpClient.getString();
        // Serial.println();
       Serial.println(payload);
      }
      else {
       
        Serial.println(httpResponseCode);
       
      }
      delay(1000);
}
void YLEsp8266::getInformationForTerminal(){
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
}

void YLEsp8266::executeTerminalTask(String TERMINAL, String TASK_ID, String RESPONSE_OF_EXECUTION){
    client.setInsecure();

    String post_url = "https://iot.youpilab.com/api/terminal/response/?TERM=";
    //ok good
    post_url+=TERMINAL;
    post_url +="&TASK_ID=";
    post_url +=TASK_ID;
    post_url +="&RESP=";
    post_url +=RESPONSE_OF_EXECUTION;
    
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
}

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
