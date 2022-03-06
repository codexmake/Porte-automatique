//==============================================================//
//                     FONCTIONS DE LA PORTE                    //
//==============================================================//

void ouvrir_et_fermer_la_porte(){
  if (servoengage==true){
    animations_fermer_av();
    animations_ouvert_ar();
    Reculer();
    delay(delaimoteur);
    Stopmoteur();
    animation_att();
    animations_fermer_ar();
    Avancer();
    animations_ouvert_av();
    delay(delaimoteur);
    Stopmoteur();
    stopallled();
    fermer=false; // on évite les chocs avec le mur
    ouvert=true;
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////

void fermer_la_porte(){
  if (servoengage==true){
//    if (etat_porte=!0){
      animations_fermer_ar();
      animations_ouvert_av();
      Avancer();
      delay(delaimoteur);
      Stopmoteur();
      stopallled();
//    }
  }
  mode_porte=2;
  etat_porte=1;
  //fermer=false; // on évite les chocs avec le mur
  //ouvert=true;
}
//////////////////////////////////////////////////////////////////

void ouvrir_la_porte(){
  if (servoengage==true){
//    if (etat_porte=!1){
      animations_fermer_av();
      animations_ouvert_ar();
      Reculer();
      delay(delaimoteur);
      Stopmoteur();
      stopallled();
      myservo.detach();
    }
//  }
  mode_porte=2;
  etat_porte=0;
  //ouvert=false;
  //fermer=true;
}


//////////////////////////////////////////////////////////////////

void fermer_peu(){
  if (servoengage==true){
    Avancer();
    delay(200);
    Stopmoteur();
    ouvert=true;
    fermer=true;
  }
}

void ouvrir_peu(){
  if (servoengage==true){
    Reculer();
    delay(200);
    Stopmoteur();
    ouvert=true;
    fermer=true;
  }
}

///////////////////////////////FIN////////////////////////////////
