#include "Communication.h"
#include <Arduino.h>

/*---------------------------- Variables globales ---------------------------*/
volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message
StaticJsonDocument<500> docSend;
StaticJsonDocument<500> docRecive;
//#TODO  Add comm protocol
/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg(int16_t JStick_X, int16_t JStick_Y, bool Btn2, bool Btn3, bool Btn4, bool Btn5, int16_t ACC_X, int16_t ACC_Y, int16_t ACC_Z, long Encodeur) {
  // Elements du message
  docSend["JStick_X"] = JStick_X;
  docSend["JStick_Y"] = JStick_Y;
  docSend["Bouton2"] = Btn2;
  docSend["Bouton3"] = Btn3;
  docSend["Bouton4"] = Btn4;
  docSend["Bouton5"] = Btn5;
  docSend["ACC_X"] = ACC_X;
  docSend["ACC_Y"] = ACC_Y;
  docSend["ACC_Z"] = ACC_Z;
  docSend["Encodeur"] = Encodeur;
  
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