#include <Arduino.h>
#include "Test.h"
#include <ArduinoJson.h>
#include "SeptSegement.h"
#include "Joystick.h"


#define BAUD 9600        // Frequence de transmission serielle

void setup() {
  // put your setup code here, to run once:
  //test_unitaire();
  Serial.begin(BAUD);
  SeptSegement* seg2 = new SeptSegement (sA2,B2,C2,D2, E2, F2, G2,1,SEGON );
  seg2->write(0);
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
  delay(2000);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  //test
  
}