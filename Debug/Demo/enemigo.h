#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "ebentoak.h"

int bolaBotata1;
int bolaBotata2;
POSIZIOA bolarenDirekzioa1;
POSIZIOA bolarenDirekzioa2;

POSIZIOA jarraituAirean(POSIZIOA posizioa1, POSIZIOA posizioa2);
POSIZIOA jarraituBola(POSIZIOA posizioa1, POSIZIOA posizioa2);
POSIZIOA jarraituLurrean(POSIZIOA posizioa1, POSIZIOA posizioa2);
int suaBotata(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza);

#endif