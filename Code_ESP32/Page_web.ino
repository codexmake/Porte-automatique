//==============================================================//
//                          LA PAGE WEB                         //
//==============================================================//
//                    Affichage de la page WEB                  // 

void afficheweb(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("Nouveau Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
//==============================================================//
//                Les diverses liens internet                   //
//==============================================================//    

            if (header.indexOf("GET /ouvre-la-porte") >= 0) {
            Serial.println("La porte s'ouvre actuellement");
            server.stop();
            delay(1000);
            server.begin();   // Listen for incoming clients
            }


            if (header.indexOf("GET /ouvre-la-porte") >= 0) {
            Serial.println("La porte s'ouvre actuellement");
            server.stop();
            delay(1000);
            server.begin();   // Listen for incoming clients
            }

              if (header.indexOf("GET /ouvre-la-porte") >= 0) {
            Serial.println("La porte s'ouvre actuellement");
            server.stop();
            delay(1000);
            server.begin();   // Listen for incoming clients
            }


              if (header.indexOf("GET /ouvre-la-porte") >= 0) {
            Serial.println("La porte s'ouvre actuellement");
            server.stop();
            delay(1000);
            server.begin();   // Listen for incoming clients
            }
    
// TU SAIS TU PEUX TE FAIS PLAISIR EN RAJOUTANT D'AUTRE FONCTIONS//
//==============================================================//
//                     La Page HTML                             //
//==============================================================//    

client.println("<!DOCTYPE html><html>");           
client.println("<head> <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
client.println("<link rel=\"icon\" href=\"data:,\">");
client.print  ("<body style=background-color:#252525>"); //set background to white

     
client.println("<body style=\"background-color:,\"#000000" ">");
client.println("<body><center><h1 style=\"color:#FFFFFF\";><u>BIENVENUE A TOI !</u></h1>");
client.println("<body><center><h2 style=\"color:#FFFFFF\";>Voici un peu tous les liens possibles de faire, et ainsi ce que cela va faire.</h2>");
client.println("<body><center><h3 style=\"color:#FF0000\";>ATTENTION, cette page ne s'actualise pas dès lors que vous appuyez sur les liens en dessous mais l'action aura bien lieu sans l'actualisation de la page et vous resterez sur cette page.</h3>");
client.println("<body><center><a href=\"./ouvre-la-porte\" style=\"color:#FFFFFF\" target=\"_blank\" class=\"link\";>ouvrir la porte</a>");          
client.println(); // The HTTP response ends with another blank line
            break;  }           // Break out of the while loop
           else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("le client est déconnecter.");
    Serial.println("");
  }
}
