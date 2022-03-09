#ifndef COMM_H
#define COMM_H
#include <ArduinoJson.h>

extern volatile bool shouldSend_;  // Drapeau prêt à envoyer un message
extern volatile bool shouldRead_;  // Drapeau prêt à lire un message
/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(int16_t JStick_X, int16_t JStick_Y, bool Btn2, bool Btn3, bool Btn4, bool Btn5, int16_t ACC_X, int16_t ACC_Y, int16_t ACC_Z, long Encodeur); 
void readMsg(uint8_t &segement_7, bool &mot);
//void serialEvent();




#endif