#ifndef DEFINIZIOAK_H_
#define DEFINIZIOAK_H_

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU }EGOERA;
typedef enum { MENU, INSTRUKZIOAK, PANTAILA1, PANTAILA2 }PANTAILA;


typedef struct S_ELEMENTUA {

	POSIZIOA posizioa;
	int Id;
	int dx; // elementuen mugimendua x ardatzarekiko
	int dy; // elementuen mugimendua y ardatzarekiko
	int saltatzen; //jokalariaren saltoa egitego
	int kontmugimendua; // jokalariaren mugimendua egiteko
	int kontanim; //jokalariaren animaziorako
	int kontbizitza; //jokalaria bizitza galtzerakoan inbentzibilitate dembora bat izango du
	int konteraso; //jokalariaren erasotze animazioa egiteko
	int egoera; //jokalariaren egoera animazioa egiteko
	int ebentua; //eszenarioa mugitzeko
	int lurra; // jokalariaren lurra
	int bizitza;
	int mugitzen; // elementua mugitzen den edo ez zehazten du

}ELEMENTUA;

#endif