#include <Arduino.h>
#include "Test.h"
#include <ArduinoJson.h>
#include "SeptSegement.h"
#include "Joystick.h"
#include "Encoder.h"
#include "Bouton.h"
#include "Communication.h"

#define BAUD 9600        // Frequence de transmission serielle

void setup() {
  // put your setup code here, to run once:
  //test_unitaire();
  Serial.begin(BAUD);

  //Enc* Encodeur0 = new Enc (ENC_A, ENC_B);
  
  
   
  /*seg2->write(0);
  delay(2000);
  seg2->write(1);
  delay(2000);
  seg2->write(2);
  delay(2000);
  seg2->write(3);
  delay(2000);
  seg2->write(4);
  delay(2000);
  seg2->write(5);
  delay(2000);
  seg2->write(6);
  delay(2000);
  seg2->write(7);
  delay(2000);
  seg2->write(8);
  delay(2000);
  seg2->write(9);
  delay(2000);*/

  
}

void loop() {
  // put your main code here, to run repeatedly:
  //test
  //int16_t Position[2] = {0,0}; //[X,Y]
  SeptSegement* seg1 = new SeptSegement (sA1,sB1,C1,D1, E1, F1, G1,0,SEGON );
  SeptSegement* seg2 = new SeptSegement (sA2,B2,C2,D2, E2, F2, G2,0,SEGON );
  uint8_t segement_7 = 0;
  bool mot = 0;
  Encoder* myEnc = new Encoder(ENC_A, ENC_B);
  Joystick* Joystick0 = new Joystick(JSTICK_A1, JSTICK_A2);
  while (1)
  {

    Joystick0->Update();
    //Joystick0->GetArray(Position);

    /*Serial.print("Joystick X: ");
    Serial.print( Joystick0->GetX());
    Serial.print(" ,");

    Serial.print("Joystick Y: ");
    Serial.print( Joystick0->GetY());
    Serial.print(" ,");

    Serial.print("Bouton2: ");
    Serial.print(BOUTONSTATE(BTN2));
    Serial.print(" ,");

    Serial.print("Bouton3: ");
    Serial.print(BOUTONSTATE(BTN3));
    Serial.print(" ,");

    Serial.print("Bouton4: ");
    Serial.print(BOUTONSTATE(BTN4));
    Serial.print(" ,");

    Serial.print("Bouton5: ");
    Serial.print(BOUTONSTATE(JSTICK_BTN));
    Serial.print(" ,");

    Serial.print("Encodeur: ");
    Serial.print(myEnc->read());
    Serial.print(" ,");
    Serial.print(" \n");*/


    //sendMsg(Joystick0->GetX(), Joystick0->GetY(), BOUTONSTATE(BTN2), BOUTONSTATE(BTN3), BOUTONSTATE(BTN4), BOUTONSTATE(JSTICK_BTN), 0, 0, 0, myEnc->read());
    if (shouldRead_)
    {
      Serial.print("Message Recu \n");
      readMsg(segement_7, mot);
      seg1->write(segement_7);
      seg2->write((segement_7>>4));
    }
    delay(10);

  }
}