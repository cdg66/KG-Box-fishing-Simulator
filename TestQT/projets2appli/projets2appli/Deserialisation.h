#pragma once
#include <iostream>
#include <string>
#include <cstdint>
#include "SerialPort.hpp"
#include "json.hpp"

#define BAUD 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message
SerialPort* arduino; //doit etre un objet global!

using json = nlohmann::json;
//using namespace std;
class Serialisation
{
public:
	Serialisation(std::string com);
	~Serialisation();
	json SerialUpdate();
	void SetSegement(uint8_t Segment);
	uint8_t GetSegement();
	void SetMoteur(bool Moteur);
	bool GetMoteur();
private:
	uint8_t Seg = 0;
	bool Mot = false;
	std::string Com;
	bool RcvFromSerial(SerialPort* arduino, std::string& msg);
	bool  SendToSerial(SerialPort* arduino, json j_msg);
};
Serialisation::Serialisation(std::string com)
{
	Com = com;
	arduino = new SerialPort(com.c_str(), BAUD);

	if (!arduino->isConnected()) {
		std::cerr << "Impossible de se connecter au port " << std::string(com) << ". Fermeture du programme!" << std::endl;
		exit(1);
	}
}

Serialisation::~Serialisation()
{
	delete arduino;
}

bool Serialisation::GetMoteur()
{
	return Mot;
}

void Serialisation::SetMoteur(bool Moteur)
{
	Mot = Moteur;
}

uint8_t Serialisation::GetSegement()
{
	return Seg;
}

void Serialisation::SetSegement(uint8_t Segement)
{
	Seg = Segement;
}

json Serialisation::SerialUpdate()
{
	std::string raw_msg = " ";
	json j_msg_send, j_msg_rcv;

	j_msg_send["7segement"] = Seg;      // Cr�ation du message � envoyer
	j_msg_send["Moteur"] = Mot;
	if (!SendToSerial(arduino, j_msg_send)) {    //Envoie au Arduino
		std::cerr << "Erreur lors de l'envoie du message. " << std::endl;
	}

	// Reception message Arduino
	j_msg_rcv.clear(); // effacer le message precedent
	if (!RcvFromSerial(arduino, raw_msg)) {
		//cout << raw_msg;
		std::cerr << "Erreur lors de la reception du message. " << std::endl;
	}
	// Impression du message de l'Arduino, si valide
	if (raw_msg.size() > 0) {
		j_msg_rcv = json::parse(raw_msg);       // Transfert du message en json
	}
	return j_msg_rcv;

}

/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entr�e : Port de communication, tampon de r�ception du message
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : R�ception du message
-----------------------------------------------------------------------------*/
bool Serialisation::SendToSerial(SerialPort* arduino, json j_msg)
{
	// Return 0 if error
	std::string msg = j_msg.dump();
	bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
	return ret;
}


/*---------------------------Definition de fonctions ------------------------
Fonction de r�ception
Entr�e : Port de communication, message � envoyer
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : Envoie du message
-----------------------------------------------------------------------------*/
bool Serialisation::RcvFromSerial(SerialPort* arduino, std::string& msg) {
	// Return 0 if error
	// Message output in msg
	std::string str_buffer;
	char char_buffer[MSG_MAX_SIZE];
	int buffer_size;

	msg.clear(); // clear string
	msg = " ";
	// Read serialport until '\n' character (Blocking)
	while (msg.back() != '\n') {
		if (msg.size() > MSG_MAX_SIZE) {
			return false;
		}

		buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
		str_buffer.assign(char_buffer, buffer_size);
		msg.append(str_buffer);
	}

	msg.pop_back(); //remove '/n' from string
	return true;
}