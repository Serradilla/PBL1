#ifndef DRAGOIAK_H
#define DRAGOIAK_H

#include "ebentoak.h"
#include "definizioak.h"

int heganEgingoDu1;
int heganEgingoDu2;
int dragoienArtekoDistantzia;

ELEMENTUA dragoiarenFuntzioak1(ELEMENTUA enemigo, ELEMENTUA enemigo1, ELEMENTUA sua1, ELEMENTUA jokalaria);
ELEMENTUA dragoiarenFuntzioak2(ELEMENTUA enemigo1, ELEMENTUA enemigo, ELEMENTUA sua2, ELEMENTUA jokalaria);
POSIZIOA jarraituAirean(POSIZIOA posizioa1, POSIZIOA posizioa2);
int heganEginAhalDu(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza);
POSIZIOA dragoienArtekoKolisioaSortu(POSIZIOA posizioa1, POSIZIOA posizioa2);
ELEMENTUA dragoienAnimazioa1(ELEMENTUA enemigo);
ELEMENTUA dragoienAnimazioa2(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu1(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu2(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu3(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu4(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu5(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu6(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu7(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu8(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu9(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu10(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu11(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu12(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu13(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu14(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu15(ELEMENTUA enemigo);
ELEMENTUA enemigoSortu16(ELEMENTUA enemigo);
int ezkerreraAlaEskumaraDragoia1(POSIZIOA jokalaria, POSIZIOA dragoia);
int ezkerreraAlaEskumaraDragoia2(POSIZIOA jokalaria, POSIZIOA dragoia);
ELEMENTUA dragoiaEtaJokalaria1(ELEMENTUA dragoia, ELEMENTUA jokalaria);
ELEMENTUA dragoiaEtaJokalaria2(ELEMENTUA dragoia, ELEMENTUA jokalaria);

#endif