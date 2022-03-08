#ifndef JOYSTICK_H
#define JOYSTICH_H

#include <Arduino.h>
#include "AnalogProcessing.h"



class Joystick
{
private:
    int16_t Position[2]; //[X,Y]
    int16_t MagnitudeJstick = 0;
    float PhaseJstick = 0;
    uint8_t PinX = 0; 
    uint8_t PinY = 0;
public:
    Joystick(uint8_t PinAX, uint8_t PinAY);
    ~Joystick();
    void Update();
    void GetVector(int16_t *Magnitude, float *Phase);
    int16_t GetX();
    int16_t GetY();

};

Joystick::Joystick(uint8_t PinAX, uint8_t PinAY)
{
    PinX = PinAX;
    PinY = PinAY;
}

Joystick::~Joystick()
{
}

void Joystick::Update()
{
   // lis le jstick
   Position[0] = analogRead(PinX);
   //Serial.print(Position[0]);
   Position[1] = analogRead(PinY);
   //Serial.print(Position[1]);
   // rend les valeurs Carthesiennes
   Position[0] = CenterValue( Position[0], 511);
   Position[1] = CenterValue( Position[1], 511);
   // rend les valeurs sous forme de vecteur
   //Vectorise(Position, 2, &MagnitudeJstick, &PhaseJstick);

}
void Joystick::GetVector(int16_t *Magnitude, float *Phase)
{
    *Magnitude = MagnitudeJstick;
    *Phase = PhaseJstick;
}


int16_t Joystick::GetX()
{
    return Position[0];
};
int16_t Joystick::GetY()
{
    return Position[1];
};
#endif