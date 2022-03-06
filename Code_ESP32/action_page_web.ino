//==============================================================//
//                         POUR LE SERVEUR                      //
//==============================================================//

void porteOuvrir()
{
  //action effectué by the server
  ouvrir_la_porte();
  mode_porte=2;
  etat_porte=1;
  server.send(404, "text/plain", "OK");
}

void porteFermer()
{
  //action effectué by the server
  fermer_la_porte();
  mode_porte=2;
  etat_porte=0;
  server.send(404, "text/plain", "OK");
}

//==============================================================//
//                          POUR LE HTML                        //
//==============================================================//


void handleRoot()
{
  server.send(200, "text/html", index());
}
/////////////////////// RELATIVE AU OUV ET FERM DE LA PORTE 
void handlePorteOuvouFerm()
{
  actionportevoulu = server.arg("action-porte").toInt();
  //----------------------------------------------------//  
  if(actionportevoulu == 1){
    server.send(200, "text/html", effectuer());
    mode_porte=2;
    etat_porte=1;
    ouvrir_la_porte();
  }
  
  if(actionportevoulu == 0){
    server.send(200, "text/html", effectuer());
    mode_porte=2;
    etat_porte=0;
    fermer_la_porte();
  }
  server.sendHeader("Location","/");
  server.send(303);
}

void handlePorteOuvouFermPEU()
{
  actionportepeu = server.arg("action-porte-peu").toInt();
  //----------------------------------------------------//  
  if(actionportepeu == 1){
  mode_porte=2;
  etat_porte=2;
  ouvrir_peu(); 
  }

  if(actionportepeu == 0) {
  mode_porte=2;
  etat_porte=2;
  fermer_peu();
  }
  
  server.sendHeader("Location","/");
  server.send(303);
}

void handlePorteOuvetFerm()
{
  actionouvetferm = server.arg("action-porte-ouvrir-et-fermer").toInt();
  //----------------------------------------------------//
  if(actionouvetferm == 1){
  server.send(200, "text/html", effectuer());
  mode_porte=2;
  etat_porte=2;
  ouvrir_et_fermer_la_porte();    
  }
  server.sendHeader("Location","/");
  server.send(303);
}

////////////////////////////////////////////// FIN //////////////////////

void handleservo()
{
  actionservo = server.arg("servo").toInt();
  
  if(actionservo == 1) {
  server.send(200, "text/html", effectuer());
  servo=0;
  servodown();
  }
  
  if(actionservo == 0) {
  server.send(200, "text/html", effectuer());
  servo=1;
  servoup();
  }
  server.sendHeader("Location","/");
  server.send(303);
}

void handleTimerSettings()
{
  minuterieOuverture = server.arg("timer-open");
  minuterieFermeture = server.arg("timer-close");
  statusa = server.arg("luminosité_av"); // CECI EST UN TEST !
  modePorte = server.arg("mode");
  updateMinuterie();
  server.sendHeader("Location","/");
  server.send(303);
  Serial.println(statusa);
}

void handleNotFound()
{
 server.send(200, "text/html", error404());
}

/////////////// LA MINUTERIE //////////////////////////

void getCurrentTime()
{
  currentTimeString = Paris.dateTime();
  currentTime[0] = Paris.hour();
  int temp = Paris.minute();
  if(temp < 10)
    minuteExtraZero = "0";
  else
    minuteExtraZero = "";
  currentTime[1] = temp;
  currentTime[2] = Paris.day();
  currentTime[3] = Paris.month();
  currentTime[4] = Paris.year();
}


void updateMinuterie()
{
  int heureActuelle = currentTime[0];
  int heureTimerFerm = minuterieFermeture.toInt();
  int heureTimerOuve = minuterieOuverture.toInt();
  
  if(minuterieOuverture != "désactiver" || minuterieFermeture != "désactiver")
  {
    if(minuterieOuverture <= "")
       minuterieOuverture = "08";
    if(minuterieFermeture <= "")
       minuterieFermeture = "21";
    String tempMinuteString;
    int tempMinute;
    String tempHeureString;
    int tempHeure;
  
    tempHeureString = String(minuterieOuverture[0]) + String(minuterieOuverture[1]);
    tempMinuteString = String(minuterieOuverture[3]) + String(minuterieOuverture[4]);
    tempHeure = tempHeureString.toInt();
    tempMinute = tempMinuteString.toInt();
    tempHeureString = String(minuterieFermeture[0]) + String(minuterieFermeture[1]);
    tempMinuteString = String(minuterieFermeture[3]) + String(minuterieFermeture[4]);
    tempHeure = tempHeureString.toInt();
    tempMinute = tempMinuteString.toInt();

    if(minuterieOuverture != "désactiver"){
      interfaceMinuterie = "Ouverture : " + minuterieOuverture + "H00 /";}
    else if (minuterieOuverture =="désactiver"){
      interfaceMinuterie = "Ouverture : <i class='fas fa-times-circle w3-xxlarge'></i> /";}
      
    if(minuterieFermeture != "désactiver"){
      interfaceMinuterie += " Fermeture : " + minuterieFermeture + "H00";} 
    else if (minuterieFermeture =="désactiver"){
      interfaceMinuterie += "Fermeture : <i class='fas fa-times-circle w3-xxlarge'></i>";}
  }
  
  else if (minuterieOuverture =="désactiver"  && minuterieFermeture =="désactiver"){
    interfaceMinuterie = "<i class='fas fa-times-circle w3-xxlarge'></i>";
  }
  
  else if (minuterieOuverture != "désactiver"  && minuterieFermeture != "désactiver" && minuterieFermeture == minuterieOuverture){
    minuterieOuverture="désactiver";
    minuterieFermeture="désactiver";  
    datalog="Vous avez renseigné la même heure pour l'ouverture et la fermerture !";
    server.send(200, "text/html", echec());   
    interfaceMinuterie = "<i class='fas fa-times-circle w3-xxlarge'></i>";
   }
   else if (heureActuelle == heureTimerFerm && minuterieFermeture != "désactiver" && minuterieFermeture != minuterieOuverture){
    //Serial.println("FERMAGE DE PORTE");
   // TEST
   }
   else if (heureActuelle == heureTimerOuve && minuterieOuverture != "désactiver" && minuterieFermeture != minuterieOuverture){
    //Serial.println("OUVRAGE DE PORTE");
   //TEST
   }

   String interfacemode = interface_mode[mode_porte];

   if (modePorte=="Automatique"){
   mode_porte=0;
   }
   
   if (modePorte=="Veille"){
   mode_porte=2;
   }
   
   if (modePorte=="Veille"){
   mode_porte=2;
   }
}

int dayChanged()
{
  if(jourAJour != currentTime[2])
    {
      jourAJour = currentTime[2];
      updateMinuterie();
      return 1;
    }
    else
      return 0;
}


/////////////////////////////////////////// LES TACHES IMPORTANTES EN SOUS-EXECUTION ///////////////////////////////////////////////

void traitementTimer(){
  
int heureActuelle = currentTime[0];
int heureTimerFerm = minuterieFermeture.toInt();
int heureTimerOuve = minuterieOuverture.toInt();
  
   if (heureTimerOuve == heureTimerFerm && minuterieFermeture != "désactiver" && minuterieOuverture != "désactiver"){
    minuterieOuverture="désactiver";
    minuterieFermeture="désactiver";  
    datalog="Vous avez renseigné la même heure pour l'ouverture et la fermerture !";
    server.send(200, "text/html", echec());   
   }
   else if (heureActuelle == heureTimerFerm && minuterieFermeture != "désactiver" && minuterieFermeture != minuterieOuverture){
    //Serial.println("FERMAGE DE PORTE");
    // TRAITEMEENT   
   }
   else if (heureActuelle == heureTimerOuve && minuterieOuverture != "désactiver" && minuterieFermeture != minuterieOuverture){
    //Serial.println("OUVRAGE DE PORTE");
    //TRAITEMENT
   }
  
}
