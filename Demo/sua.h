#ifndef SUA_H
#define SUA_H

#include "ebentoak.h"
#include "definizioak.h"

int bolaBotata1;
int bolaBotata2;
int bolarenAbiadura;
int dragoiarenHeina;
POSIZIOA bolarenDirekzioa1;
POSIZIOA bolarenDirekzioa2;

POSIZIOA jarraituBola(POSIZIOA posizioa1, POSIZIOA posizioa2);
int suaBotata(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza);
ELEMENTUA suaFuntzioak2(ELEMENTUA sua2, ELEMENTUA enemigo1, ELEMENTUA jokalaria);
ELEMENTUA suaFuntzioak1(ELEMENTUA sua1, ELEMENTUA enemigo, ELEMENTUA jokalaria);

#endif