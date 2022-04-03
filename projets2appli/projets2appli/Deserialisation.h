#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include "SerialPort.hpp"
#include "json.hpp"

#define BAUD 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message

//SerialPort* arduino; //doit etre un objet global!

using json = nlohmann::json;
using namespace std;
class Serialisation
{
public:
	Serialisation(string com);
	~Serialisation();
	json SerialUpdate();
	void SetSegement(uint8_t Segment);
	uint8_t GetSegement();
	void SetMoteur(bool Moteur);
	bool GetMoteur();
private:
	uint8_t Seg = 0;
	bool Mot = false;
	string Com;
	bool RcvFromSerial(SerialPort* arduino, string& msg);
	bool  SendToSerial(SerialPort* arduino, json j_msg);
	SerialPort* arduino; //doit etre un objet global!
};
