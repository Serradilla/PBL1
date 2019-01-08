#ifndef DRAGOIAK_H
#define DRAGOIAK_H

#include "ebentoak.h"
#include "definizioak.h"

int heganEgingoDu1;
int heganEgingoDu2;
int dragoienArtekoDistantzia;

POSIZIOA jarraituAirean(POSIZIOA posizioa1, POSIZIOA posizioa2);
int heganEginAhalDu(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza);
POSIZIOA dragoienArtekoKolisioaSortu(POSIZIOA posizioa1, POSIZIOA posizioa2);
ELEMENTUA dragoiarenFuntzioak1(ELEMENTUA enemigo, ELEMENTUA enemigo1, ELEMENTUA sua1, ELEMENTUA jokalaria);
ELEMENTUA dragoiarenFuntzioak2(ELEMENTUA enemigo1, ELEMENTUA enemigo, ELEMENTUA sua2, ELEMENTUA jokalaria);

#endif