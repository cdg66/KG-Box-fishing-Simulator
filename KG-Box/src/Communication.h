#ifndef COMM_H
#define COMM_H
#include <ArduinoJson.h>

/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(int16_t JStick_X, int16_t JStick_, bool Btn2, bool Btn3, bool Btn4, bool Btn5, int16_t ACC_X, int16_t ACC_Y, int16_t ACC_Z, long Encodeur); 
void readMsg(uint8_t &segement_7, bool &mot);
void serialEvent();




#endif