#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "ebentoak.h"

POSIZIOA jarraitu(POSIZIOA posizioa1, POSIZIOA posizioa2);
POSIZIOA saltoEgin(POSIZIOA posizioa, int dy);
int bukatuDa(POSIZIOA posizioa, POSIZIOA hasieran, int dy);
POSIZIOA enemyMovement(POSIZIOA posizioa1, POSIZIOA posizioa2);

#endif