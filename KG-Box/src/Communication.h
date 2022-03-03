#ifndef COMM_H
#define COMM_H
#include <ArduinoJson.h>

/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();

/*---------------------------- Variables globales ---------------------------*/
volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message
StaticJsonDocument<500> docSend;
StaticJsonDocument<500> docRecive;


#endif