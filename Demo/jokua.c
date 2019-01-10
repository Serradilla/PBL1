//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "SDL.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------------
#include "jokua.h"
#include "definizioak.h"
#include "jokalaria.h"
#include "sua.h"
#include "dragoiak.h"
#include "plataformak.h"
#include "esqueleto.h"

#define ONGI_ETORRI_MEZUA "ONGI ETORRI SAKATU RETURN BOTOIA JOKUA HASTEKO"
#define ESZENARIOA ".\\img\\escenario.bmp"
#define JOKALARIA ".\\img\\mainChar.bmp"
#define ENEMIGO ".\\img\\dragon1.bmp"
#define SUA ".\\img\\fireBall.bmp"
#define ESQUELETO ".\\img\\esqueleto.bmp"

void jokoaAurkeztu(void)
{
	int ebentu = 0;

	sarreraMezuaIdatzi();
	instrukzioakIdatzi();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_RETURN);
	pantailaGarbitu();
	pantailaBerriztu();
}

void sarreraMezuaIdatzi()
{
	pantailaGarbitu();
	textuaIdatzi(125, 200, ONGI_ETORRI_MEZUA);
	pantailaBerriztu();
}

void instrukzioakIdatzi() {
	textuaIdatzi(225, 300, "INSTRUKZIOAK");
	pantailaBerriztu();
}

void jolastu(void) {

	ELEMENTUA jokalaria, eszenarioa, enemigo, enemigo1, plataforma1, plataforma2, sua1, sua2, esqueleto1,esqueleto2,esqueleto3;

	eszenarioa.Id = eszenarioaSortu();
	eszenarioa.posizioa.x = 0;
	eszenarioa.posizioa.y = 0;
	eszenarioa.dx = 0;
	eszenarioa.dy = 0;

	plataforma1.posizioa.x = 35;
	plataforma1.posizioa.y = 123;
	plataforma1.dx = 0;
	plataforma1.dy = 0;

	plataforma2.posizioa.x = 370;
	plataforma2.posizioa.y = 123;
	plataforma2.dx = 0;
	plataforma2.dy = 0;

	sua1.Id = sua1Sortu();
	sua1.posizioa.x = 400;
	sua1.posizioa.y = 0;
	sua1.dx = 0;
	sua1.dy = 0;

	sua2.Id = sua2Sortu();
	sua2.posizioa.x = 100;
	sua2.posizioa.y = 0;
	sua2.dx = 0;
	sua2.dy = 0;

	enemigo.Id = enemigoSortu();
	enemigo.posizioa.x = 400;
	enemigo.posizioa.y = 0;
	enemigo.dx = 0;
	enemigo.dy = 0;

	enemigo1.Id = enemigoSortu();
	enemigo1.posizioa.x = 100;
	enemigo1.posizioa.y = 0;
	enemigo1.dx = 0;
	enemigo1.dy = 0;

	esqueleto1.Id = esqueletoSortu();
	esqueleto1.posizioa.x = -20;
	esqueleto1.posizioa.y = 350;
	esqueleto1.dy = 0;
	esqueleto1.dx = 0;

	esqueleto2.Id = esqueletoSortu();
	esqueleto2.posizioa.x = 400;
	esqueleto2.posizioa.y = 350;
	esqueleto2.dy = 0;
	esqueleto2.dx = 0;

	esqueleto3.Id = esqueletoSortu();
	esqueleto3.posizioa.x = 600;
	esqueleto3.posizioa.y = 350;
	esqueleto3.dy = 0;
	esqueleto3.dx = 0;

	jokalaria.Id = jokalariaSortu();
	jokalaria.posizioa.x = 50;
	jokalaria.posizioa.y = 350;
	jokalaria.dx = 0;
	jokalaria.dy = 0;
	jokalaria.saltatzen = 0;
	jokalaria.kont = 0;
	jokalaria.lurra = 350;
	jokalaria.kont2 = 0;


	EGOERA egoera;
	egoera = JOLASTEN;
	do{

		jokalaria = jokalariaFuntzioak(jokalaria, eszenarioa, plataforma1, plataforma2);
		//eszenarioa = eszenarioaFuntzioak(jokalaria, eszenarioa);
		enemigo = dragoiarenFuntzioak1(enemigo, enemigo1, sua1, jokalaria);
		enemigo1 = dragoiarenFuntzioak2(enemigo1, enemigo, sua2, jokalaria);
		sua1 = suaFuntzioak1(sua1, enemigo, jokalaria);
		sua2 = suaFuntzioak2(sua2, enemigo1, jokalaria);
		esqueleto1 = esqueletoFuntzioak(esqueleto1, jokalaria);
		esqueleto2 = esqueletoFuntzioak(esqueleto2, jokalaria);
		esqueleto3 = esqueletoFuntzioak(esqueleto3, jokalaria);

		//------mugimenduen ejekuzioa-------//
		jokalaria = mugitu(jokalaria);
		//eszenarioa = mugitu(eszenarioa);
		enemigo = mugitu(enemigo);
		enemigo1 = mugitu(enemigo1);
		plataforma1 = mugitu(plataforma1);
		plataforma2 = mugitu(plataforma2);
		sua1 = mugitu(sua1);
		sua2 = mugitu(sua2);
		esqueleto1 = mugitu(esqueleto1);
		esqueleto2 = mugitu(esqueleto2);
		esqueleto3 = mugitu(esqueleto3);

		if (jokalaria.saltatzen == 1) {
			jokalaria = salto(jokalaria);
		}
		//-----------------------------------//
		Sleep(20);

	} while (egoera == JOLASTEN);

}

int jokalariaSortu(void){

	int Id = -1;

	Id = irudiaKargatu(JOKALARIA);
	irudiaMugitu(Id, 0, 400);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}

int esqueletoSortu() {
	
	int Id = -1;

	Id = irudiaKargatu(ESQUELETO);
	irudiaMugitu(Id, 0, 400);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}

int enemigoSortu(void) {

	int Id = -1;

	Id = irudiaKargatu(ENEMIGO);
	irudiaMugitu(Id, 0, 400);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}

int enemigo1Sortu(void) {

	int Id = -1;

	Id = irudiaKargatu(ENEMIGO);
	irudiaMugitu(Id, 0, 400);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}



int eszenarioaSortu(void){

	int eszenarioaId = -1;

	eszenarioaId = irudiaKargatu(ESZENARIOA);
	irudiaMugitu(eszenarioaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return eszenarioaId;
}

int sua1Sortu(void) {

	int Id = -1;

	Id = irudiaKargatu(SUA);
	irudiaMugitu(Id, 0, 400);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}

int sua2Sortu(void) {

	int Id = -1;

	Id = irudiaKargatu(SUA);
	irudiaMugitu(Id, 0, 400);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}

ELEMENTUA mugitu(ELEMENTUA elementua) {

		
	elementua.posizioa.x += elementua.dx;
	elementua.posizioa.y += elementua.dy;

	irudiaMugitu(elementua.Id, elementua.posizioa.x, elementua.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return elementua;
}

