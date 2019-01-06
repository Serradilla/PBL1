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
#include "enemigo.h"
#include "plataformak.h"



#define ONGI_ETORRI_MEZUA "ONGI ETORRI SAKATU RETURN BOTOIA JOKUA HASTEKO"
#define ESZENARIOA ".\\img\\escenario.bmp"
#define JOKALARIA ".\\img\\mainChar.bmp"
#define ENEMIGO ".\\img\\enemyDragon.bmp"
#define PLATAFORMA ".\\img\\descarga.bmp"
#define SUA ".\\img\\fireBall.bmp"

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

	ELEMENTUA jokalaria, eszenarioa, enemigo, enemigo1, plataforma1, plataforma2, sua1, sua2;

	eszenarioa.Id = eszenarioaSortu();
	eszenarioa.posizioa.x = 0;
	eszenarioa.posizioa.y = 0;
	eszenarioa.dx = 0;
	eszenarioa.dy = 0;

	plataforma1.Id = plataformaSortu();
	plataforma1.posizioa.x = 100;
	plataforma1.posizioa.y = 350;
	plataforma1.dx = 0;
	plataforma1.dy = 0;

	plataforma2.Id = plataformaSortu();
	plataforma2.posizioa.x = 500;
	plataforma2.posizioa.y = 350;
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

	jokalaria.Id = jokalariaSortu();
	jokalaria.posizioa.x = 50;
	jokalaria.posizioa.y = 400;
	jokalaria.dx = 0;
	jokalaria.dy = 0;
	jokalaria.kont = 0;
	jokalaria.lurra = 400;


	EGOERA egoera;
	egoera = JOLASTEN;
	do{

		jokalaria = jokalariaFuntzioak(jokalaria, eszenarioa, plataforma1, plataforma2);
		eszenarioa = eszenarioaFuntzioak(jokalaria, eszenarioa);
		plataforma1 = plataformaFuntzioak(plataforma1, eszenarioa);
		plataforma2 = plataformaFuntzioak(plataforma2, eszenarioa);

		bolaBotata1 = suaBotata(bolarenDirekzioa1, sua1.posizioa, bolaBotata1);
		bolaBotata2 = suaBotata(bolarenDirekzioa2, sua2.posizioa, bolaBotata2);

		sua1.posizioa = jarraituBola(bolarenDirekzioa1, sua1.posizioa);
		sua2.posizioa = jarraituBola(bolarenDirekzioa2, sua2.posizioa);

		if (bolaBotata1 == 0)
		{
			enemigo.posizioa = jarraituAirean(jokalaria.posizioa, enemigo.posizioa);
			sua1.posizioa = enemigo.posizioa;
			bolarenDirekzioa1 = jokalaria.posizioa;
		}
		if (bolaBotata2 == 0)
		{
			enemigo1.posizioa = jarraituAirean(jokalaria.posizioa, enemigo1.posizioa);
			sua2.posizioa = enemigo1.posizioa;
			bolarenDirekzioa2 = jokalaria.posizioa;
		}

		//------mugimenduen ejekuzioa-------//
		jokalaria = mugitu(jokalaria);
		eszenarioa = mugitu(eszenarioa);
		enemigo = mugitu(enemigo);
		enemigo1 = mugitu(enemigo1);
		plataforma1 = mugitu(plataforma1);
		plataforma2 = mugitu(plataforma2);
		sua1 = mugitu(sua1);
		sua2 = mugitu(sua2);

		if (jokalaria.saltatzen == 1) {
			jokalaria = salto(jokalaria);
		}
		//-----------------------------------//
		Sleep(40);

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

int plataformaSortu(void) {

	int Id = -1;

	Id = irudiaKargatu(PLATAFORMA);
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

