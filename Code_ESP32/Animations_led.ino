//==============================================================//
//                          ANIMATIONS                          //
//==============================================================//

// L'ordres des couleurs 
// Rouge, Vert, Bleu


/////////////////////////////////////////////////////////////////////////////////////

void animation_att_av(){
Serial.println("ceci est un test");
}

void animation_att_ar(){
  int compteur=0;
    while (compteur <= 12){
    for(int i = 0, j = 10; (i < 6) && (j > 4); i++, j--){
    strip_ar.setPixelColor(i, 0, 0, 255); 
    strip_ar.setPixelColor(j, 0, 0, 255); 
    strip_ar.show();  
    delay(50);
    //strip_ar.setPixelColor(j, 0, 0, 255);
  }
  
  

  delay(500);
  
  for (int i = 0; i <= 10; i++) {
    strip_ar.setPixelColor(i, 0, 0, 0);
    strip_ar.show();
  }
  delay(500);
  compteur++;
    }
}


/////////////////////////////////////////////////////////////////////////////////////

void animations_fermer_ar() {

  for (int i = 10; i >= 0; i--) {
    strip_ar.setPixelColor(i, 255, 0, 0);  
    strip_ar.show();
    delay(25);
  }
}

/////////////////////////////////////////////////////////////////////////////////////

void animations_fermer_av() {

  for (int i = 10; i >= 0; i--) {
    strip_ar.setPixelColor(i, 255, 0, 0);  
    strip_ar.show();
    delay(25);
  }
}

/////////////////////////////////////////////////////////////////////////////////////

void animations_ouvert_av() {

  for (int i = 10; i >= 0; i--) {
    strip_av.setPixelColor(i, 0, 255, 0);
    strip_av.show();
    delay(25);
  }
}

/////////////////////////////////////////////////////////////////////////////////////

void animations_ouvert_ar() {

  for (int i = 10; i >= 0; i--) {
    strip_ar.setPixelColor(i, 0, 255, 0);  
    strip_ar.show();
    delay(25);
  }
}

/////////////////////////////////////////////////////////////////////////////////////

void stopallled() {

  for (int i = 0; i <= 10; i++) {
    strip_av.setPixelColor(i, 0, 0, 0);
    strip_av.show();
    strip_ar.setPixelColor(i, 0, 0, 0);
    strip_ar.show();
    delay(25);
  }
}

/////////////////////////////////////////////////////////////////////////////////////

void bloquer(){
  int compteur=0;
    while (compteur <= 1){
        for (int i = 10; i >= 0; i--) {
    strip_ar.setPixelColor(i, 255, 0, 0);  
    strip_ar.show();
  }

  delay(400);
  
  for (int i = 0; i <= 10; i++) {
    strip_ar.setPixelColor(i, 0, 0, 0);
    strip_ar.show();
  }
  
  delay(400);
  compteur++;
  
   }}
