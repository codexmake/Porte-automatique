//==============================================================//
//                       ENVOIE DE DONNEES                      //
//==============================================================//
//Toutes les données reçues des différents capteurs seront envoyées à Domoticz //


/*
void senddomoticz(){

  unsigned long currentMillis = millis();
  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    if(WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi not connected !");
    } else {  
      Serial.println("Send data to Domoticz");
      
      /////////////////////////////////////////////////////////1/////////////////////////////////////////////////////////
      String url_temperature = "/json.htm?type=command&param=udevice&idx=9&nvalue=0&svalue=";        // ICI CHANGE L'IDX DE TON CAPTEUR
      url_temperature += String(thermistance); url_temperature += ";";
      /////////////////////////////////////////////////////////2/////////////////////////////////////////////////////////
      String url_hcsr04_1 = "/json.htm?type=command&param=udevice&idx=5&nvalue=0&svalue=";        // ICI CHANGE L'IDX DE TON CAPTEUR
      url_hcsr04_1 += String(hcsr04_1); url_hcsr04_1 += ";";
      /////////////////////////////////////////////////////////3/////////////////////////////////////////////////////////
      String url_hcsr04_2 = "/json.htm?type=command&param=udevice&idx=10&nvalue=0&svalue=";      // ICI CHANGE L'IDX DE TON CAPTEUR
      url_hcsr04_2 += String(hcsr04_2); url_hcsr04_2 += ";";
      /////////////////////////////////////////////////////////4/////////////////////////////////////////////////////////
      String url_ldr_1 = "/json.htm?type=command&param=udevice&idx=12&nvalue=0&svalue=";        // ICI CHANGE L'IDX DE TON CAPTEUR
      url_ldr_1 += String(ldr_1); url_ldr_1 += ";";
      /////////////////////////////////////////////////////////5/////////////////////////////////////////////////////////
      String url_ldr_2 = "/json.htm?type=command&param=udevice&idx=11&nvalue=0&svalue=";      // ICI CHANGE L'IDX DE TON CAPTEUR
      url_ldr_2 += String(ldr_2); url_ldr_2 += ";";


     
        send_temperature(url_temperature);
        send_hcsr04_1(url_hcsr04_1);
        send_hcsr04_2(url_hcsr04_2);
        send_ldr_1(url_ldr_1);
        send_ldr_2(url_ldr_2);
      }
    }
}

//==============================================================//
//                        ENVOIE CAPTEUR 1                      //
//==============================================================//
//                          Temperature                         //   

void send_temperature(String url_temperature){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_temperature);
  http.begin(host,port,url_temperature);
  int httpCode = http.GET();
    if (httpCode) {
      if (httpCode == 200) {
        String payload = http.getString();
        Serial.println("Domoticz response "); 
        Serial.println(payload);
    }}
  Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                        ENVOIE CAPTEUR 2                      //
//==============================================================//
//                          ULTRASONS 2                         //   

void send_hcsr04_1(String url_hcsr04_1){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_hcsr04_1);
  http.begin(host,port,url_hcsr04_1);
  int httpCode = http.GET();
    if (httpCode) {
      if (httpCode == 200) {
        String payload = http.getString();
        Serial.println("Domoticz response "); 
        Serial.println(payload);
      }}
  Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                        ENVOIE CAPTEUR 3                      //
//==============================================================//
//                          ULTRASONS 1                         // 

void send_hcsr04_2(String url_hcsr04_2){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_hcsr04_2);
  http.begin(host,port,url_hcsr04_2);
  int httpCode = http.GET();
    if (httpCode) {
      if (httpCode == 200) {
        String payload = http.getString();
        Serial.println("Domoticz response "); 
        Serial.println(payload);
      }}
  Serial.println("closing connection");
  http.end();
}



//==============================================================//
//                        ENVOIE CAPTEUR 4                      //
//==============================================================//
//                              LDR 1                           //      

void send_ldr_1(String url_ldr_1){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_ldr_1);
  http.begin(host,port,url_ldr_1);
  int httpCode = http.GET();
    if (httpCode) {
      if (httpCode == 200) {
        String payload = http.getString();
        Serial.println("Domoticz response "); 
        Serial.println(payload);
      }}
  Serial.println("closing connection");
  http.end();
}


//==============================================================//
//                        ENVOIE CAPTEUR 5                      //
//==============================================================//
//                              LDR 2                           //    

  void send_ldr_2(String url_ldr_2){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_ldr_2);
  http.begin(host,port,url_ldr_2);
  int httpCode = http.GET();
    if (httpCode) {
      if (httpCode == 200) {
        String payload = http.getString();
        Serial.println("Domoticz response "); 
        Serial.println(payload);
      }}
  Serial.println("closing connection");
  http.end();
}
*/
