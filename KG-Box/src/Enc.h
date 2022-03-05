#ifndef ENC_H
#define ENC_H

#include <Arduino.h>
#include "Encoder.h"

class Enc
{
private:
    Encoder *myEnc;
public:
    Enc(uint8_t PinA, uint8_t PinB);
    ~Enc();
    long getPulseCount();
};

Enc::Enc(uint8_t PinA, uint8_t PinB)
{
    *myEnc = new Encoder(PinA, PinB);
}

Enc::~Enc()
{
    delete *myEnc;
}

Enc::getPulseCount()
{
    return  myEnc.read();
}

#endif