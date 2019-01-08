#ifndef JOKALARIA_H_
#define JOKALARIA_H_
#include "definizioak.h"

ELEMENTUA jokalariaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa, ELEMENTUA plataforma1, ELEMENTUA plataforma2);
ELEMENTUA eszenarioaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa);
ELEMENTUA salto(ELEMENTUA elementua);
ELEMENTUA jokalariaEgoera1(ELEMENTUA jokalaria);
ELEMENTUA jokalariaEgoera0(ELEMENTUA jokalaria);
ELEMENTUA jokalariaEgoera2(ELEMENTUA jokalaria);
ELEMENTUA jokalariaEgoera3(ELEMENTUA jokalaria);
ELEMENTUA jokalariaEgoera4(ELEMENTUA jokalaria);
ELEMENTUA animazioa(ELEMENTUA jokalaria, ELEMENTUA eszenarioa);
ELEMENTUA animatu(ELEMENTUA jokalaria);

#endif