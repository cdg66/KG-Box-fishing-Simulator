#include "Communication.h"
#include <Arduino.h>

/*---------------------------- Variables globales ---------------------------*/
volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message
StaticJsonDocument<500> docSend;
StaticJsonDocument<500> docRecive;
//#TODO  Add comm protocol
/*---------------------------Definition de fonctions ------------------------*/




/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg(int16_t JStick_X, int16_t JStick_Y, bool Btn2, bool Btn3, bool Btn4, bool Btn5, int16_t ACC_X, int16_t ACC_Y, int16_t ACC_Z, long Encodeur) {
  // Elements du message
  docSend["JX"] = JStick_X;
  docSend["JY"] = JStick_Y;
  docSend["2"] = Btn2;
  docSend["3"] = Btn3;
  docSend["4"] = Btn4;
  docSend["5"] = Btn5;
  docSend["X"] = ACC_X;
  docSend["Y"] = ACC_Y;
  docSend["Z"] = ACC_Z;
  docSend["E"] = Encodeur;
  
  // Serialisation
  serializeJson(docSend, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
  return;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(uint8_t &segement_7, bool &mot){
  // Lecture du message Json
  //StaticJsonDocument<500> doc;
  
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(docRecive, Serial);
  shouldRead_ = false;

  
  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  parse_msg = docRecive["7segement"];
  parse_msg = docRecive["Moteur"];
  segement_7 = docRecive["7segement"];
  mot = docRecive["Moteur"].as<bool>();
  // Analyse des éléments du message message
  //parse_msg = doc["led"];
  //if (!parse_msg.isNull()) {
    // mettre la led a la valeur doc["led"]
   // digitalWrite(pinLED,doc["led"].as<bool>());
  //}
}