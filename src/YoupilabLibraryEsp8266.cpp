#include "YoupilabLibraryEsp8266.h"
WiFiClient wifi;

HTTPClient httpClient;

int status = WL_IDLE_STATUS;

YoupilabLibraryEsp8266::YoupilabLibraryEsp8266(String APP_ID, String APP_KEY): _APP_ID(APP_ID), _APP_KEY(APP_KEY), _BASE_URL("https://iot.youpilab.com/api"){}
int YoupilabLibraryEsp8266::addPoint(int a, int b){
	return a+ b;
} 

/********************************************** Les SETTER ET GETTER */
String YoupilabLibraryEsp8266::getAppKey(){
  return _APP_KEY;
}

String YoupilabLibraryEsp8266::getAppId(){
  return _APP_ID;
}

void YoupilabLibraryEsp8266::setAppKey(String appkey){
       _APP_KEY = appkey;
}

void YoupilabLibraryEsp8266::setAppID(String appid){
      _APP_ID = appid;
}

String YoupilabLibraryEsp8266::getBaseUrl(){
     return _BASE_URL;
}

//permet de verifier si la carte esp c'est bien connecter
void YoupilabLibraryEsp8266::VeriyToConnectWifi(char* ssid, char* password){
  delay(200); 
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
      Serial.println("tentative de connexion au wifi");
      Serial.println(ssid);
    delay(200); 
  }
    Serial.println("Connexion resussi !!");
    Serial.println("********** Votre adresse ID*************");
    Serial.print("Votre adresse Ip est : ");
    Serial.println(WiFi.localIP());
}




void YoupilabLibraryEsp8266::sendDataFloat(float px, String APP_ID, String APP_KEY){
   WiFiClientSecure client;
   client.setInsecure();

   // String post_url = "https://test.iot.generalinvasion.com/api";
   // String post_url = "https://test.iot.generalinvasion.com/api/data/send?APP_ID=" + APP_ID + "&APP_KEY=" + APP_KEY;
         String post_url = "https://iot.youpilab.com/api/data/send?APP_ID=";

        post_url+=APP_ID;
        post_url +="&APP_KEY=";
        post_url +=APP_KEY;
        post_url +="&P1=";
        post_url +=px;
    //         post_url +="&P2=";
    //         post_url +=p2;                         
      Serial.println(post_url);
      /*Envoie de la reqette*/
      httpClient.begin (client,post_url); 
      int httpResponseCode = httpClient.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP ");
        Serial.println(httpResponseCode);
        String payload = httpClient.getString();
        Serial.println();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        Serial.println(":-(");
      }
      delay(1000);
}

void YoupilabLibraryEsp8266::dynamicExecution(int led1){
    /***********recuperation des instructions a executer depuis la plateforme IoT ******/
    String post_url = "https://iot.youpilab.com/api/controls/get?APP_ID=" + _APP_ID + "&APP_KEY=" + _APP_KEY;
        //String post_url = "https://test.iot.generalinvasion.com/api";

     WiFiClientSecure client;
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
      Serial.println("Equiment démarrer ");
    }
    else
    {
      digitalWrite(led1, LOW);
      Serial.println("Equipement Eteint ");
    }
}
}
