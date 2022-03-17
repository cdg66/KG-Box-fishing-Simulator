#include <Arduino.h>
#include "Test.h"
#include <ArduinoJson.h>
#include "SeptSegement.h"
#include "Joystick.h"
#include "Encoder.h"
#include "Bouton.h"
#include "Communication.h"

#define BAUD 460800       // Frequence de transmission serielle



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
  uint8_t Diz = 0;
  uint8_t unite = 0;
  bool mot = 0;
  Encoder* myEnc = new Encoder(ENC_A, ENC_B);
  Joystick* Joystick0 = new Joystick(JSTICK_A1, JSTICK_A2);
  int16_t Acc_X = 0;
  int16_t Acc_Y = 0;
  int16_t Acc_Z = 0;
  //init moteur
  pinMode(MOTEUR, OUTPUT);
  digitalWrite(MOTEUR, 0);
  while (1)
  {

    Joystick0->Update();
    if (BOUTONSTATE(BTN1) == BTNON)
    {
      Acc_X = analogRead(ACC_X);
      Acc_Y = analogRead(ACC_Y);
      Acc_Z = analogRead(ACC_Z);
    }
    else
    {
      Acc_X = 0;
      Acc_Y = 0;
      Acc_Z = 0;
    }

    

    
    if (Serial.available() )
    {
      //Serial.print("Message Recu \n");
      readMsg(segement_7, mot);
      unite = segement_7%10;
      Diz = (segement_7 - unite)/10; 
      seg2->write(unite);
      seg1->write(Diz);
      digitalWrite(MOTEUR, mot);
      sendMsg(Joystick0->GetX(), Joystick0->GetY(), BOUTONSTATE(BTN2), BOUTONSTATE(BTN3), BOUTONSTATE(BTN4), BOUTONSTATE(JSTICK_BTN), Acc_X, Acc_Y, Acc_Z, myEnc->read());
    }
    delay(10);
    //sendMsg(Joystick0->GetX(), Joystick0->GetY(), BOUTONSTATE(BTN2), BOUTONSTATE(BTN3), BOUTONSTATE(BTN4), BOUTONSTATE(JSTICK_BTN), Acc_X, Acc_Y, Acc_Z, myEnc->read());
  }
}

void serialEvent() { 
  //Serial.print("toggle\n");
  shouldRead_ = true; }