//==============================================================//
//                          CODE X MAKE                         //
//==============================================================//
//                         LE 17/07/2021                        //
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <EasyNTPClient.h>
#include <Timezone.h>             // by JACK
#include <ArduinoOTA.h>
#include <Adafruit_NeoPixel.h>
#include <HTTPClient.h>

#define LED_PIN_AV    13         // la pin de la led où est connecté.
#define LED_COUNT_AV  10          // le nombre de led connecté.
#define LED_PIN_AR    0          // la pin de la led où est connecté.
#define LED_COUNT_AR  10         // le nombre de led connecté. ICI 10 à l'arriére.
#define SOUND_SPEED 0.034

Adafruit_NeoPixel strip_av(LED_COUNT_AV, LED_PIN_AV, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_ar(LED_COUNT_AR, LED_PIN_AR, NEO_GRB + NEO_KHZ800);


int delaimoteur = 3000;
int moteurdatapin1 = 22; // Pin 4 du wemos d1 mini où est relier le moteur
int moteurdatapin2 = 23; // Pin 5 du wemos d1 mini où est relier le moteur
int moteurdatapin3 = 17; // A UTILISER SI L298N
const int watchdog = 100;                              // Fréquence d'envoi des données à Domoticz ICI 100ms
String header;                                          // Current time
unsigned long currentTime = millis();                  // Current Time
unsigned long previousMillis = millis();              // Previous Millis
unsigned long previousTime = 0;                      // Previous time
const long timeoutTime = 2000;                      // Define timeout time in milliseconds (example: 2000ms = 2s)
////////////////////////
const int trigPin1 = 19;
const int echoPin1 = 21;
long duration1;
float distance1;
////////////////////////
const int trigPin2 = 18;
const int echoPin2 = 5;
long duration2;
float distance2;




//                     REMPLACE AVEC TES INFO                   //
//==============================================================//
//                       CONFIGURATION WIFI                     //
//==============================================================//
const char* ssid     = "FREEBOX_FAZAL_DA";                      // Wifi-SSID
const char* password = "0007CBD4FF93";                          // WIFI-PASSWORD
//////////////////////////////////////////////////////////////////




WiFiUDP Udp_G; // Objet UDP permettant d'envoyer et recevoir des trames Wi-Fi selon le protocole UDP
EasyNTPClient ClientNtp_G(Udp_G, "pool.ntp.org"); // Objet NTP synchronisé avec "pool.ntp.org"
TimeChangeRule RegleHeureEteFrance_G = {"RHEE", Last, Sun, Mar, 2, 120}; // Règle de passage à l'heure d'été pour la France
TimeChangeRule RegleHeureHiverFrance_G = {"RHHE", Last, Sun, Oct, 3, 60}; // Règle de passage à l'heure d'hiver la France
Timezone ConvertirHeureFrance_G(RegleHeureEteFrance_G, RegleHeureHiverFrance_G); // Objet de conversion d'heure avec les caractéristique de la métropole française

HTTPClient http;
WiFiServer server(80);


//==============================================================//
//                            SETUP                             //
//==============================================================//
void setup() {
  
  Serial.begin(115200);
  Serial.println("BOOTING...");
  Serial.println("Connexion au WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connecté");
  Serial.println("Adresse IP: ");
  Serial.print(WiFi.localIP());
  ArduinoOTA.setHostname("ESP32-PORTE-AUTMATIQUE");   // le nom de l'appareil
  //ArduinoOTA.setPassword("votre mdp");                  // le mot de passe pour envoyer le code
  ArduinoOTA.begin();
  server.begin();
  strip_ar.begin();
  strip_av.begin();
  strip_av.show(); // Initialize all pixels to 'off'
  strip_av.show(); // Initialize all pixels to 'off'
  pinMode(moteurdatapin1, OUTPUT); 
  pinMode(moteurdatapin2, OUTPUT);
  pinMode(moteurdatapin3, OUTPUT); 
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  ////////////////////////
  digitalWrite(moteurdatapin1, LOW); 
  digitalWrite(moteurdatapin2, LOW);
  digitalWrite(moteurdatapin3, LOW);
}

//==============================================================//
//                            Loop                              //
//==============================================================//
void loop() {
  ArduinoOTA.handle();
ouvrir_la_porte();
  /*
  mesuredistance1();
  mesuredistance2();
  afficheweb();
  animations_ouvert_ar();
  delay(1000);
  mesuretemp();
  stopallled();
  animations_fermer_ar();
  delay(1000);
*/
}
