//==============================================================//
//                      LES DIVERSES CAPTEURS                   //
//==============================================================//

//ACCELEROMETRE PARAM

void initialise_mpu(){
  Serial.println("Adafruit MPU6050 test!");
  if (!mpu.begin()) {
    Serial.println("MPU6050 non détécté !");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 trouvé !");
  

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(10);
}

void mesurertouslescapteurs(){
  distance1=float(hcsr04[0].ping_cm());
  distance2=float(hcsr04[1].ping_cm());
  mesureldr1();
  mesureldr2();
  mesuretemp();
}
/////////// TESTTTTTTTTTT
void test_accel(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  mesure1=a.acceleration.z; 
  delay(10);
  mpu.getEvent(&a, &g, &temp);
  mesure2=a.acceleration.z; 
  resul_mesure = mesure1 - mesure2;
  if (resul_mesure <= trim_accelerometre && resul_mesure <= -trim_accelerometre){
    servoup();
    while(x==true){
     delay(10);
      if ((distance2<=13 && distance2!=0) || (millis() - temps) > 30000){ // ATTENDRE L'ECOULAGE DE 30 sec 
      x=false;
      break;
      }
    }
    servodown();
    x=true;
  }
}

void mesuretemp(){
  Vtn = analogRead(35);
  T= 1/ ((1/TT) + (1/B)*log((R0/RT0)*((4096.0/Vtn)-1))) - 273.15;
}

void mesureldr1(){
  sensorValue1 = analogRead(32); 
}

void mesureldr2(){
  sensorValue2 = analogRead(34); 
}


//////////////////////////////////////////////////////////////////

void lumi_check() {
  int valeur1=sensorValue1 / (4096/255);
  int valeur2=sensorValue2 / (4096/255);
  if (lumiauto) {
    strip_ar.setBrightness(255);//valeur2);
    strip_av.setBrightness(255);//valeur1);
  }
}


//==============================================================//
//                          SERVO                               //
//==============================================================//


void servoup(){
  myservo.attach(servopin);
  myservo.write(0);
  delay(1000);
  myservo.detach();
  servoengage=false;
}

void servodown(){
  myservo.attach(servopin);
  myservo.write(180);
  delay(1000); // waits for it to get to the position
  myservo.detach();
  servoengage=true;
}

//==============================================================//
//                          MOTEUR                              //
//==============================================================//

void Reculer(){
  digitalWrite(moteurdatapin1 , HIGH);
  digitalWrite(moteurdatapin2, LOW);
}
 
void Avancer(){
  digitalWrite(moteurdatapin1 , LOW);
  digitalWrite(moteurdatapin2, HIGH);
}
 
void Stopmoteur(){
  digitalWrite(moteurdatapin1, LOW);
  digitalWrite(moteurdatapin2, LOW);
}

 
