#ifndef POISSON
#define POISSON

#include "Coordinates.h"

class Poisson
{

private:

int score;
Coordinates cord;

public:

  Poisson(); //instencie une coordonnee random
  ~Poisson();
  
  void setMouvement(); //modifie la coordonnee instanciee
  void dessinPoisson(); //met le poisson sur la grille
  
};

#endif

