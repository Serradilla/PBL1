#ifndef JOKUA_H_
#define	JOKUA_H_

#include "definizioak.h"

ELEMENTUA musikaMenu, mainCharAtakeSoinua, mainCharJotzenSoinua, mainCharDamage, dragoiaSuaBota, saltoarenSoinua;

int jokoaAurkeztu(void);
void sarreraMezuaIdatzi();
void instrukzioakIdatzi();
void jolastu(void);
int jokalariaSortu(void);
int eszenarioaSortu(void);
int eszenarioa1Sortu(void);
int enemigoSortu(void);
int enemigo1Sortu(void);
int sua1Sortu(void);
int sua2Sortu(void);
int esqueletoSortu(void);
ELEMENTUA mugitu(ELEMENTUA elementua);
int bizitzaSortu(void);
void demohasi(void);

int enemigoKont;
int ronda;

#endif
