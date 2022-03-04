#ifndef AP_H
#define AP_H


int16_t CenterValue(int16_t Value, int16_t midVal);
// prend un vecteur et retourne la magintude et l'angle de ce vecteur
void  Vectorise(int16_t *Vecteur, int16_t size, int16_t *Magnitude, float *angle);

#endif