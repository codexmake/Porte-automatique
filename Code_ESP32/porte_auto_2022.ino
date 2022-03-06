 //==============================================================//
//                         CODE X MAKE                          //
//==============================================================//
//                    REMPLACE AVEC TES INFOS                   //
//==============================================================//
//                       CONFIGURATION WIFI                     //
//==============================================================//
const char* ssid     = "xxxxxxxxxxxxx";                      // Wifi-SSID
const char* password = "xxxxxxxxxxxxx";                          // WIFI-PASSWORD
const char* host = "xxx.xxx.x.xx";                              // Adresse-Ip où se trouve Domoticz
const int   port = 8080;                                        // Port où se trouve Domoticz | Par défaut port 8080
//////////////////////////////////////////////////////////////////

#include <NewPing.h>   // pour les hc-sr04
#include <WiFi.h>   // pour le wifi
#include <ArduinoOTA.h>
#include <Adafruit_NeoPixel.h>
#include <HTTPClient.h>
#include <ESP32Servo.h> 
#include <ezTime.h>
#include <WebServer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define LED_PIN_AV    13         // la pin de la led où est connecté.
#define LED_COUNT_AV  14          // le nombre de led connecté.
#define LED_PIN_AR    0          // la pin de la led où est connecté.
#define LED_COUNT_AR  10         // le nombre de led connecté. ICI 10 à l'arriére.
#define MAX_DISTANCE 200        // distance max
#define hcsr04_num     2         // Number or sensors.

Timezone Paris;
Adafruit_MPU6050 mpu;

String currentTimeString = "";
String minuteExtraZero = "";
int currentTime[5] = {0, 0, 0, 0, 0}; //Heure = 0, Minute = 1, Jour = 2, Mois = 3, Année = 4
char monthList[13][16] = {"", "janvier", "février", "mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre"}; //Le premier est vide sinon janvier serait 0 au lieu de 1
int jourAJour = 0;

bool lumiauto = true; 
bool auth = true;
bool fermer = true;
bool ouvert = true;
bool servoengage = true;
bool authservomot = true;
bool x = true;


//Variables à afficher sur l'interface
const char interface_etat_porte[3][20] = {"Fermée", "Ouverte","Entrouverte"};
bool etat_porte = 0; 

const char interface_mode[3][70] = {"Automatique", "Semi-Automatique", "Manuel"};
//  <i class='material-icons'>brightness_auto</i>
int mode_porte = 0; // Luminosité = 0, Minuterie = 1, Manuel = 2

// POUR LE BOUTON engagement servo 
const char interface_servo[2][20] = {"Engagé", "Désengagé",};
const char color_servo[2][20] = {"green", "red",};
const char value_servo[2][2]={"0","1"};
int servo = 0;

String interfaceMinuterie = "";
String interfaceErreur = "";
String statusa =""; // A SUP 

int actionportevoulu=0;
int actionportepeu=0;
int actionservo=0;
int actionouvetferm=0;
int modeRideaux = 2; // Luminosité = 0, Minuterie = 1, Manuel = 2
String minuterieOuverture = "";
String minuterieFermeture = "";
String modePorte = "";
String slider_value = "0";
String datalog = "";

const int watchdog = 100;                              // Fréquence d'envoi des données à Domoticz ICI 100ms
const long timeoutTime = 100;                      // Define timeout time in milliseconds (example: 2000ms = 2s)
unsigned long previousMillis = millis();              // Previous Millis
unsigned long previousTime = 0;                      // Previous time

int servopin =  27;      // GPIO pin used to connect the servo control (digital out)
int delaimoteur = 2200;
int distance_min_av = 50;
int distance_min_ar = 50;
int moteurdatapin1 = 23; // Pin 4 du wemos d1 mini où est relier le moteur
int moteurdatapin2 = 4; // A REVIRIFIER, A CAUSE DES CHANGEMENT !
float distance1;
float distance2;
int test;//////////////////////////

float temp;
float T;
float resul_mesure;
float mesure1;
float mesure2;
float trim_accelerometre = 0.04;
const float TT = 25 + 273.15;
//const float Ressistor_thermistor = 1000.0;
//const float Ressistor_data = 1000.0;
const float RT0 = 1000.0;
const float R0 = 1000.0;
const float B = 3950.0;
uint16_t Vtn;
long temps; // variable qui stocke la mesure du temps


uint16_t sensorValue1;
uint16_t sensorValue2;
Adafruit_NeoPixel strip_av(LED_COUNT_AV, LED_PIN_AV, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_ar(LED_COUNT_AR, LED_PIN_AR, NEO_GRB + NEO_KHZ800);

NewPing hcsr04[hcsr04_num] = {   
  NewPing(18, 5, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(19, 16, MAX_DISTANCE),  // POSSIBILITE D'ERREUR SOIT 16 SOIT 4 == DU AU CHANGEMENT AVEC L'ACCELEROMETRE
};


Servo myservo;  // create servo object to control a servo
HTTPClient http;
WebServer server(80);



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
  ArduinoOTA.setHostname("ESP32-PORTE-AUTOMATIQUE");   // le nom de l'appareil
  //ArduinoOTA.setPassword("votre mdp");                  // le mot de passe pour envoyer le code
  ArduinoOTA.begin();
  strip_ar.begin();
  strip_ar.show(); // Initialize all pixels to 'off'
  strip_av.begin();
  strip_av.show(); // Initialize all pixels to 'off'
  pinMode(moteurdatapin1, OUTPUT); 
  pinMode(moteurdatapin2, OUTPUT);
  digitalWrite(moteurdatapin1, LOW); 
  digitalWrite(moteurdatapin2, LOW);
  stopallled();
  myservo.attach(servopin);   
  servodown();
  setDebug(DEBUG);
  waitForSync();
  Paris.setLocation("Europe/Paris");
  Paris.setDefault();
  getCurrentTime();
  jourAJour = currentTime[2];
  updateMinuterie();
  initialise_mpu(); // ACELEROMETETRE PARMAM
  server.on("/", HTTP_GET, handleRoot);
  server.on("/porte-ouvrir", HTTP_GET, porteOuvrir);
  server.on("/porte-fermer", HTTP_GET, porteFermer);
  server.on("/action-porte", HTTP_POST, handlePorteOuvouFerm);
  server.on("/action-porte-peu", HTTP_POST, handlePorteOuvouFermPEU);
  server.on("/action-porte-ouvrir-et-fermer", HTTP_POST, handlePorteOuvetFerm);
  server.on("/servo", HTTP_POST, handleservo);
  server.on("/timer-settings", HTTP_POST, handleTimerSettings);
  server.onNotFound(handleNotFound);
  server.begin();
}

void loop() {
  
ArduinoOTA.handle();    //A NE PAS ENLEVER SOUS AUCUN PRETEXTE !!!!! (ARDUINO OVER THE AIR)
server.handleClient();
traitementTimer();
//events(); //?
if(minuteChanged())
{
  getCurrentTime();
  }
  if(dayChanged()){
    updateMinuterie();
}
//test_accel();
mesurertouslescapteurs();
senddomoticz();

/*
//Serial.println(minuterieOuverture.toInt());
Serial.println(value_servo[servo]);
//Serial.println(modePorte);
senddomoticz();

*/
}
