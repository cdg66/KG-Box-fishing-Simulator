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
   Position[1] = analogRead(PinY);
   // rend les valeurs Carthesiennes
   Position[0] = CenterValue( Position[0], 0x7FF);
   Position[1] = CenterValue( Position[1], 0x7FF);
   // rend les valeurs sous forme de vecteur
   Vectorise(Position, 2, &MagnitudeJstick, &PhaseJstick);

}
void Joystick::GetVector(int16_t *Magnitude, float *Phase)
{
    *Magnitude = MagnitudeJstick;
    *Phase = PhaseJstick;
}


#endif