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
	int kont; // jokalariaren mugimendua egiteko
	int kont2; //jokalariaren animaziorako
	int kont3; //jokalaria bizitza galtzerakoan inbentzibilitate dembora bat izango du
	int egoera; //jokalariaren egoera animazioa egiteko
	int ebentua; //eszenarioa mugitzeko
	int lurra; // jokalariaren lurra
	int bizitza;

}ELEMENTUA;

#endif