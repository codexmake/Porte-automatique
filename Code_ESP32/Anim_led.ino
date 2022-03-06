//==============================================================//
//                          ANIMATIONS                          //
//==============================================================//
//                 RAPPEL: L'ordres des couleurs                //
//                      Rouge, Vert, Bleu                       //
//////////////////////////////////////////////////////////////////


void animation_att_ar(){
  lumi_check();
  int compteur = 0 ;
  while (compteur != 15){//tant que compteur est différent de 10
    compteur ++ ;
    lumi_check();
    for (int i = 0; i <= 10; i++) {
      strip_ar.setPixelColor(i, 0, 0, 255);
      strip_ar.show();
      delay(25);
    }
    delay(100);
    for (int i = 10; i >= 0; i--) {
      strip_ar.setPixelColor(i, 0, 0, 0);
      strip_ar.show();
      delay(25);
    }
  }
}

//////////////////////////////////////////////////////////////////

void animation_att(){
  lumi_check();
  int compteur = 0 ;
  while (compteur != 15){ //tant que compteur est différent de 10
    compteur ++ ;
    lumi_check();
    for (int i = 0; i <= 14; i++) {
      strip_ar.setPixelColor(i, 0, 0, 255);
      strip_ar.show();
      strip_av.setPixelColor(i, 0, 0, 255);
      strip_av.show();
      delay(25);
    }
    delay(100);
    for (int i = 14; i >= 0; i--) {
      strip_ar.setPixelColor(i, 0, 0, 0);
      strip_ar.show();
      strip_av.setPixelColor(i, 0, 0, 0);
      strip_av.show();
      delay(25);
    } 
  }
}
//////////////////////////////////////////////////////////////////

void animations_fermer_ar() {
  lumi_check();
  for (int i = 10; i >= 0; i--) {
    strip_ar.setPixelColor(i, 255, 0, 0);  
    strip_ar.show();
    delay(25);
  }
}

//////////////////////////////////////////////////////////////////

void animations_fermer_av() {
  lumi_check();
  for (int i = 14; i >= 0; i--) {
    strip_av.setPixelColor(i, 255, 0, 0);  
    strip_av.show();
    delay(25);
  }
}

//////////////////////////////////////////////////////////////////

void animations_ouvert_av() {
  lumi_check();
  for (int i = 14; i >= 0; i--) {
    strip_av.setPixelColor(i, 0, 255, 0);
    strip_av.show();
    delay(25);
  }
}

//////////////////////////////////////////////////////////////////

void animations_ouvert_ar() {
  lumi_check();
  for (int i = 10; i >= 0; i--) {
    strip_ar.setPixelColor(i, 0, 255, 0);  
    strip_ar.show();
    delay(25);
  }
}

//==============================================================//
//                           STOP LED                           //
//==============================================================//

void stopallled() {
  for (int i = 0; i <= 10; i++) {
    strip_ar.setPixelColor(i, 0, 0, 0);
    strip_ar.show();
    delay(25);
  }
   for (int j = 0; j <= 14; j++) {
    strip_av.setPixelColor(j, 0, 0, 0);
    strip_av.show();
    delay(25);
  }
}

//////////////////////////////////////////////////////////////////

void stop_led_ar() {
  for (int i = 0; i <= 10; i++) {
    strip_ar.setPixelColor(i, 0, 0, 0);
    strip_ar.show();
    delay(25);
  }
}
//////////////////////////////////////////////////////////////////

void stop_led_av() {
  for (int i = 0; i <= 14; i++) {
    strip_av.setPixelColor(i, 0, 0, 0);
    strip_av.show();
    delay(25);
  }
}
//////////////////////////////////////////////////////////////////

void bloquer(){
  lumi_check();
  int compteur=0;
    while (compteur <= 1){
      lumi_check();
      for (int i = 10; i >= 0; i--) {
        strip_ar.setPixelColor(i, 255, 0, 0);  
        strip_ar.show();
        strip_av.setPixelColor(i, 255, 0, 0);  
        strip_av.show();
       }
      delay(400);
      for (int i = 0; i <= 10; i++) {
        strip_ar.setPixelColor(i, 0, 0, 0);
        strip_ar.show();
        strip_av.setPixelColor(i, 255, 0, 0);  
        strip_av.show();
      }
      delay(400);
      compteur++;
   }  
}

///////////////////////////////FIN////////////////////////////////
