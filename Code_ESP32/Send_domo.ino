//==============================================================//
//                       ENVOIE DE DONNEES                      //
//==============================================================//
//Toutes les données reçues des différents capteurs seront envoyées à Domoticz //

void senddomoticz(){
  unsigned long currentMillis = millis();
  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    if(WiFi.status() != WL_CONNECTED) {
     Serial.println("WiFi not connected !");
    }
    else {  
      Serial.println("ENVOI DE DONNER A DOMOTICZ !");
      /////////////////////////////////////////////////////////1/////////////////////////////////////////////////////////
      String url_distance_av = "/json.htm?type=command&param=udevice&idx=5&nvalue=0&svalue="; // ICI CHANGE L'IDX DE TON CAPTEUR
      String url_distance_ar = "/json.htm?type=command&param=udevice&idx=10&nvalue=0&svalue="; // ICI CHANGE L'IDX DE TON CAPTEUR
      String url_temp = "/json.htm?type=command&param=udevice&idx=9&nvalue=0&svalue="; // ICI CHANGE L'IDX DE TON CAPTEUR
      String url_ldr1 = "/json.htm?type=command&param=udevice&idx=11&nvalue=0&svalue="; // ICI CHANGE L'IDX DE TON CAPTEUR
      String url_ldr2 = "/json.htm?type=command&param=udevice&idx=12&nvalue=0&svalue="; // ICI CHANGE L'IDX DE TON CAPTEUR
      String url_motor = "/json.htm?type=command&param=udevice&idx=20&nvalue=0&svalue="; // ICI CHANGE L'IDX DE TON CAPTEUR
      ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      url_distance_av += String(distance1); url_distance_av += ";";
      url_distance_ar += String(distance2); url_distance_ar += ";";
      url_temp += String(T); url_temp += ";";
      url_ldr1 += String(sensorValue1); url_ldr1 += ";";
      url_ldr2+= String(sensorValue2); url_ldr2 += ";";
      //url_motor+= String(val); url_motor += ";";
      ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      send_distance_av(url_distance_av);
      send_distance_ar(url_distance_ar);
      send_temp(url_temp);
      send_ldr1(url_ldr1);
      send_ldr2(url_ldr2);
      send_motor(url_motor);
     }
  }
}

//==============================================================//
//                  ENVOIE CAPTEUR : DISTANCE 1                 //
//==============================================================//

void send_distance_av(String url_distance_av){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_distance_av);
  http.begin(host,port,url_distance_av);
  int httpCode = http.GET();
  if (httpCode) {
    if (httpCode == 200) {
      String payload = http.getString();
      //Serial.println("Domoticz response "); 
      //Serial.println(payload);
    }
  }
  Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                  ENVOIE CAPTEUR : DISTANCE 2                 //
//==============================================================// 

void send_distance_ar(String url_distance_ar){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_distance_ar);
  http.begin(host,port,url_distance_ar);
  int httpCode = http.GET();
  if (httpCode) {
    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Domoticz response "); 
      Serial.println(payload);
    }
  }
  Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                   ENVOIE CAPTEUR : TEMPERTURE                //
//==============================================================//

void send_temp(String url_temp){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_temp);
  http.begin(host,port,url_temp);
  int httpCode = http.GET();
  if (httpCode) {
    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Domoticz response "); 
      Serial.println(payload);
    }
  }
  Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                      ENVOIE CAPTEUR : LDR 1                  //
//==============================================================//

void send_ldr1(String url_ldr1){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_ldr1);
  http.begin(host,port,url_ldr1);
  int httpCode = http.GET();
  if (httpCode) {
    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Domoticz response "); 
      Serial.println(payload);
    }
  }
  Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                      ENVOIE CAPTEUR : LDR 2                  //
//==============================================================//

void send_ldr2(String url_ldr2){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_ldr2);
  http.begin(host,port,url_ldr2);
  int httpCode = http.GET();
  if (httpCode) {
    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Domoticz response "); 
      Serial.println(payload);
    }
  }
  //Serial.println("closing connection");
  http.end();
}

//==============================================================//
//                      ENVOIE CAPTEUR : Moteur                 //
//==============================================================//

void send_motor(String url_motor){
  Serial.print("connecting to ");
  Serial.println(host);
  Serial.print("Requesting URL: ");
  Serial.println(url_motor);
  http.begin(host,port,url_motor);
  int httpCode = http.GET();
  if (httpCode) {
    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Domoticz response "); 
      Serial.println(payload);
    }
  }
  Serial.println("closing connection");
  http.end();
}

///////////////////////////////FIN////////////////////////////////
