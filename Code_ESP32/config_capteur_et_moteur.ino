//==============================================================//
//                      LES DIVERSES CAPTEURS                   //
//==============================================================//
void mesuredistance1(){
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);   // Reads the echoPin, returns the sound wave travel time in microseconds
  distance1 = duration1 * SOUND_SPEED/2; // Calcul de la distance 
  Serial.print("La distance mesurée par le premier capteur arrière est de :");
  Serial.print(distance1);
  Serial.println("cm");
//  delay(500);    
  }


void mesuredistance2(){
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);   // Reads the echoPin, returns the sound wave travel time in microseconds
  distance2 = duration2 * SOUND_SPEED/2; // Calcul de la distance 
  Serial.print("La distance mesurée par le second capteur avant est de :");
  Serial.print(distance2);
  Serial.println("cm");    
//  delay(500);
  }


void mesuretemp(){
 const float T0 = 25 + 273.15;
 const float RT0 = 1000.0;
 const float R0 = 1000.0;
 const float B = 3950.0;
 uint16_t Vtn;
 float T;
 Vtn = analogRead(35);
 T= 1/ ((1/T0) + (1/B)*log((R0/RT0)*((4096.0/Vtn)-1))) - 273.15;
 Serial.print("T=");
 Serial.println(T);
  }


void mesureldr1(){
  uint16_t sensorValue1;
  sensorValue1 = analogRead(32); // CAPTEUR ARRIERE ALWAYS ON FUNCTION
  Serial.println(sensorValue1); // prints the value read
  delay(1000); // wait 100ms for next reading
  }

void mesureldr2(){
  uint16_t sensorValue2;
  sensorValue2 = analogRead(34); // CAPTEUR AVANT NON CONNECTEE
  Serial.println(sensorValue2); // prints the value read
  delay(1000); // wait 100ms for next reading
  }

//==============================================================//
//                      MOTEUR                                  //
//==============================================================//

void Reculer(void){

  digitalWrite(moteurdatapin1 , HIGH);
  digitalWrite(moteurdatapin2, LOW);
}
 
void Avancer(void){

  digitalWrite(moteurdatapin1 , LOW);
  digitalWrite(moteurdatapin2, HIGH);
}
 
void Stop(void){
  digitalWrite(moteurdatapin1, HIGH);
  digitalWrite(moteurdatapin2, HIGH);
}
 
