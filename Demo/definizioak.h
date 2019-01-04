#ifndef DEFINIZIOAK_H_
#define DEFINIZIOAK_H_

typedef enum {JOLASTEN,GALDU}EGOERA;
typedef enum {MENU, INSTRUKZIOAK, PANTAILA1, PANTAILA2}PANTAILA;


typedef struct S_ELEMENTUA {

	POSIZIOA posizioa;
	int Id;
	int dx;
	int dy;
	int saltatzen;
	int kont;
	int ebentua;
	int lurra;

}ELEMENTUA;

#endif
