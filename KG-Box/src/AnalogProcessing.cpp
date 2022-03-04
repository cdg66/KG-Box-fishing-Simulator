#include <Arduino.h>
#include "AnalogProcessing.h"
#include <math.h>

int16_t CenterValue(int16_t Value, int16_t midVal)
{
    return Value - midVal;
}
// prend un vecteur[x,y,z] et retourne la magintude et l'angle(x, y) de ce vecteur
void  Vectorise(int16_t *Vecteur, int16_t size, int16_t *Magnitude, float *angle)
{
    // calcul magnitude
    float sum;
    for (int i = 0; i< size; i++)
    {
    Vecteur[i] = (Vecteur[i]*Vecteur[i]);
    //vector[i] = exp()
    }
    for (int i = 0; i< size; i++)
    {
    sum = sum + Vecteur[i];
    }
    
    *Magnitude = sum;

    // clacul phase 
    *angle = atan((Vecteur[2]/Vecteur[1]));
 
}

