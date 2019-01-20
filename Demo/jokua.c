#define _CRT_SECURE_NO_WARNINGS
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
#include <string.h>
//---------------------------------------------------------------------------------
#include "jokua.h"
#include "definizioak.h"
#include "jokalaria.h"
#include "sua.h"
#include "dragoiak.h"
#include "plataformak.h"
#include "esqueleto.h"
#include "bizitza.h"
#include "menu.h"
#include "death.h"

#define ONGI_ETORRI_MEZUA "ONGI ETORRI SAKATU RETURN BOTOIA JOKUA HASTEKO"
#define ESZENARIOA ".\\img\\escenario.bmp"
#define ESZENARIOA1 ".\\img\\escenario1.bmp"
#define JOKALARIA ".\\img\\mainChar.bmp"
#define ENEMIGO ".\\img\\dragon1.bmp"
#define SUA ".\\img\\fireBall.bmp"
#define ESQUELETO ".\\img\\esqueleto.bmp"
#define BIZITZA6 ".\\img\\6heart.bmp"

#define MUSIKA ".\\sound\\SirOboe.wav"
#define MUSIKAMENU ".\\sound\\Menu.wav"
#define MENUTRANTSIZIOA ".\\sound\\TransitionMenu.wav"
#define ATAKESOINUA ".\\sound\\MainCharSlash.wav"
#define JOTZENSOINUA ".\\sound\\MainCharSlashHits.wav"
#define SUABOTA ".\\sound\\DragonShoot.wav"
#define DAMAGESOINUA ".\\sound\\MainCharGetsHit.wav"
#define SALTO ".\\sound\\Jump.wav"

#define STARTX SCREEN_WIDTH*0.43
#define STARTY (SCREEN_HEIGHT / 8)+175
#define SETTINGSX SCREEN_WIDTH*0.44
#define SETTINGSY (SCREEN_HEIGHT / 8)+225

ELEMENTUA musikaMenu, mainCharAtakeSoinua, mainCharJotzenSoinua, mainCharDamage, dragoiaSuaBota, saltoarenSoinua;

int jokoaAurkeztu(void)
{
	int sakatu = 0, sakatu1 = 0, ret = 0;
	ELEMENTUA logo;

	audioInit();
	loadTheMusic(MUSIKAMENU);
	playMusic();
	
	logo.Id = animation();

	//do
	//{
	//	sakatu = clickaBarruanDago(STARTX - 5, STARTY + 15, STARTX + 85, STARTY + 35);
	//	sakatu = clickaBarruanDago(SETTINGSX, SETTINGSY, SETTINGSX + 67, SETTINGSY + 22);
	//} while (sakatu == 0);

	while ((sakatu == 0) && (sakatu1 == 0)) {
		if (sakatu = clickaBarruanDago(STARTX - 5, STARTY + 15, STARTX + 85, STARTY + 35)) {//start button
			sakatu = 1;

		}
		if (sakatu1 = clickaBarruanDago(SETTINGSX, SETTINGSY, SETTINGSX + 67, SETTINGSY + 22)) {//menu button
			sakatu = 1;
			ret = 1;
		}
	}

	irudiaKendu(logo.Id);
	pantailaGarbitu();
	pantailaBerriztu();

	return ret;
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

void demohasi(void) {

	musikaMenu.Id = loadSound(MENUTRANTSIZIOA);
	mainCharAtakeSoinua.Id = loadSound(ATAKESOINUA);
	mainCharJotzenSoinua.Id = loadSound(JOTZENSOINUA);
	dragoiaSuaBota.Id = loadSound(SUABOTA);
	mainCharDamage.Id = loadSound(DAMAGESOINUA);
	saltoarenSoinua.Id = loadSound(SALTO);

	musicUnload();
	playSound(musikaMenu.Id);

	Sleep(2000);

	ELEMENTUA jokalaria, eszenarioa, enemigo, enemigo1, plataforma1, plataforma2, sua1, sua2, esqueleto1, esqueleto2, esqueleto3, bizitza;

	plataforma1.posizioa.x = 90000;
	plataforma1.posizioa.y = 123;
	plataforma1.dx = 0;
	plataforma1.dy = 0;

	plataforma2.posizioa.x = 1111;
	plataforma2.posizioa.y = 123;
	plataforma2.dx = 0;
	plataforma2.dy = 0;

	sua1.posizioa.x = 9000;
	sua1.posizioa.y = 0;
	sua1.dx = 0;
	sua1.dy = 0;

	sua2.posizioa.x = 9000;
	sua2.posizioa.y = 0;
	sua2.dx = 0;
	sua2.dy = 0;

	enemigo.posizioa.x = 9000;
	enemigo.posizioa.y = 0;
	enemigo.dx = 0;
	enemigo.dy = 0;
	enemigo.mugitzen = 0;

	enemigo1.posizioa.x = 9000;
	enemigo1.posizioa.y = 0;
	enemigo1.dx = 0;
	enemigo1.dy = 0;
	enemigo1.mugitzen = 0;

	esqueleto1.posizioa.x = -9000;
	esqueleto1.posizioa.y = 350;
	esqueleto1.dy = 0;
	esqueleto1.dx = 0;
	esqueleto1.mugitzen = 0;

	esqueleto2.posizioa.x = 9000;
	esqueleto2.posizioa.y = 350;
	esqueleto2.dy = 0;
	esqueleto2.dx = 0;
	esqueleto2.mugitzen = 0;

	esqueleto3.posizioa.x = 9000;
	esqueleto3.posizioa.y = 350;
	esqueleto3.dy = 0;
	esqueleto3.dx = 0;
	esqueleto3.mugitzen = 0;

	bizitza.posizioa.x = 50;
	bizitza.posizioa.y = 20;
	bizitza.dy = 0;
	bizitza.dx = 0;

	eszenarioa.Id = eszenarioaSortu();
	eszenarioa.posizioa.x = 0;
	eszenarioa.posizioa.y = 0;
	eszenarioa.dx = 0;
	eszenarioa.dy = 0;

	jokalaria.Id = jokalariaSortu();
	jokalaria.posizioa.x = 50;
	jokalaria.posizioa.y = 350;
	jokalaria.dx = 0;
	jokalaria.dy = 0;
	jokalaria.saltatzen = 0;
	jokalaria.kontmugimendua = 0;
	jokalaria.lurra = 350;
	jokalaria.kontanim = 0;
	jokalaria.kontbizitza = 0;
	jokalaria.bizitza = 6;

	do {

		jokalaria = jokalariaFuntzioak(jokalaria, eszenarioa, plataforma1, plataforma2, esqueleto1, esqueleto2, esqueleto3, sua1, sua2);
		eszenarioa = eszenarioaFuntzioak(jokalaria, eszenarioa);

		//------mugimenduen ejekuzioa-------//
		jokalaria = mugitu(jokalaria);
		eszenarioa = mugitu(eszenarioa);
		enemigo = mugitu(enemigo);
		enemigo1 = mugitu(enemigo1);
		sua1 = mugitu(sua1);
		sua2 = mugitu(sua2);

		if (jokalaria.saltatzen == 1) {
			jokalaria = salto(jokalaria);
		}

		Sleep(25);


		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

	} while (eszenarioa.posizioa.x > -(1608 - 640));
	
	pantailaGarbitu();
	irudiaKendu(jokalaria.Id);
	irudiaKendu(eszenarioa.Id);
}

void jolastu(void) {

	ELEMENTUA jokalaria, eszenarioa, enemigo, enemigo1, plataforma1, plataforma2, sua1, sua2, esqueleto1, esqueleto2, esqueleto3, bizitza;

	eszenarioa.Id = eszenarioa1Sortu();
	eszenarioa.posizioa.x = -(1608 - 640);
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
	enemigo.mugitzen = 1;

	enemigo1.Id = enemigoSortu();
	enemigo1.posizioa.x = 100;
	enemigo1.posizioa.y = 0;
	enemigo1.dx = 0;
	enemigo1.dy = 0;
	enemigo1.mugitzen = 1;

	esqueleto1.Id = esqueletoSortu();
	esqueleto1.posizioa.x = -20;
	esqueleto1.posizioa.y = 350;
	esqueleto1.dy = 0;
	esqueleto1.dx = 0;
	esqueleto1.mugitzen = 1;

	esqueleto2.Id = esqueletoSortu();
	esqueleto2.posizioa.x = 400;
	esqueleto2.posizioa.y = 350;
	esqueleto2.dy = 0;
	esqueleto2.dx = 0;
	esqueleto2.mugitzen = 1;

	esqueleto3.Id = esqueletoSortu();
	esqueleto3.posizioa.x = 700;
	esqueleto3.posizioa.y = 350;
	esqueleto3.dy = 0;
	esqueleto3.dx = 0;
	esqueleto3.mugitzen = 1;

	bizitza.Id = bizitzaSortu();
	bizitza.posizioa.x = 50;
	bizitza.posizioa.y = 20;
	bizitza.dy = 0;
	bizitza.dx = 0;

	jokalaria.Id = jokalariaSortu();
	jokalaria.posizioa.x = 600;
	jokalaria.posizioa.y = 350;
	jokalaria.dx = 0;
	jokalaria.dy = 0;
	jokalaria.saltatzen = 0;
	jokalaria.kontmugimendua = 0;
	jokalaria.lurra = 350;
	jokalaria.kontanim = 0;
	jokalaria.kontbizitza = 0;
	jokalaria.bizitza = 6;

	audioInit();
	loadTheMusic(MUSIKA);
	playMusic();

	ronda = 1;
	char RondaKopuru[7];
	char EnemigoKopuru[7];
	EGOERA egoera;
	egoera = JOLASTEN;
	enemigoKont = 5;


	do{
		jokalaria = jokalariaFuntzioak(jokalaria, eszenarioa, plataforma1, plataforma2,esqueleto1,esqueleto2,esqueleto3, sua1, sua2);
		enemigo = dragoiarenFuntzioak1(enemigo, enemigo1, sua1, jokalaria);
		enemigo1 = dragoiarenFuntzioak2(enemigo1, enemigo, sua2, jokalaria);
		sua1 = suaFuntzioak1(sua1, enemigo, jokalaria);
		sua2 = suaFuntzioak2(sua2, enemigo1, jokalaria);
		esqueleto1 = esqueletoFuntzioak1(esqueleto1, jokalaria);
		esqueleto2 = esqueletoFuntzioak2(esqueleto2, jokalaria);
		esqueleto3 = esqueletoFuntzioak3(esqueleto3, jokalaria);
		bizitza = bizitzaFuntzioak(bizitza,jokalaria);

		//------mugimenduen ejekuzioa-------//
		jokalaria = mugitu(jokalaria);
		enemigo = mugitu(enemigo);
		enemigo1 = mugitu(enemigo1);
		sua1 = mugitu(sua1);
		sua2 = mugitu(sua2);
		esqueleto1 = mugitu(esqueleto1);
		esqueleto2 = mugitu(esqueleto2);
		esqueleto3 = mugitu(esqueleto3);
		bizitza = mugitu(bizitza);

		if (jokalaria.saltatzen == 1) {
			jokalaria = salto(jokalaria);
		}
		//-----------------------------------//
		

		if ((enemigoKont == 0) && (jokalaria.posizioa.y == jokalaria.lurra)) {
			esqueleto1.mugitzen = 1;
			esqueleto2.mugitzen = 1;
			esqueleto3.mugitzen = 1;
			enemigo.mugitzen = 1;
			enemigo1.mugitzen = 1;
			ronda++;
			enemigoKont = ronda * 2 + 2;
			Sleep(1000);
			sprintf(RondaKopuru, "%d", ronda);
		}

		sprintf(RondaKopuru, "%d", ronda);
		sprintf(EnemigoKopuru, "%d", enemigoKont);

		pantailaGarbitu();
		irudiakMarraztu();

		textuaIdatzi(430, 50, "Enemies:");
		textuaIdatzi(560, 50, EnemigoKopuru);
		textuaIdatzi(50, 50, "Round: ");
		textuaIdatzi(150, 50, RondaKopuru);

		pantailaBerriztu();

		Sleep(25);

		if (jokalaria.bizitza == 0) {
			egoera = GALDU;
			irudiaKendu(eszenarioa.Id);
			irudiaKendu(eszenarioa1Sortu());
			irudiaKendu(jokalaria.Id);
			irudiaKendu(esqueleto1.Id);
			irudiaKendu(esqueleto2.Id);
			irudiaKendu(esqueleto3.Id);
			irudiaKendu(sua1.Id);
			irudiaKendu(sua2.Id);
			irudiaKendu(enemigo.Id);
			irudiaKendu(enemigo1.Id);
			irudiaKendu(bizitza.Id);
		}

	} while (egoera == JOLASTEN);

	pantailaGarbitu();
	pantailaBerriztu();
}

int bizitzaSortu(void) {

	int Id = -1;

	Id = irudiaKargatu(BIZITZA6);
	irudiaMugitu(Id, 0, 400);


	return Id;
}

int jokalariaSortu(void){

	int Id = -1;

	Id = irudiaKargatu(JOKALARIA);
	irudiaMugitu(Id, 0, 400);


	return Id;
}

int esqueletoSortu() {
	
	int Id = -1;

	Id = irudiaKargatu(ESQUELETO);
	irudiaMugitu(Id, 0, 400);


	return Id;
}

int enemigoSortu(void) {

	int Id = -1;

	Id = irudiaKargatu(ENEMIGO);
	irudiaMugitu(Id, 0, 400);


	return Id;
}

int enemigo1Sortu(void) {

	int Id = -1;

	Id = irudiaKargatu(ENEMIGO);
	irudiaMugitu(Id, 0, 400);


	return Id;
}



int eszenarioaSortu(void){

	int eszenarioaId = -1;

	eszenarioaId = irudiaKargatu(ESZENARIOA);
	irudiaMugitu(eszenarioaId, 0, 0);


	return eszenarioaId;
}

int eszenarioa1Sortu(void) {

	int eszenarioaId = -1;

	eszenarioaId = irudiaKargatu(ESZENARIOA1);
	irudiaMugitu(eszenarioaId, 0, 0);


	return eszenarioaId;
}

int sua1Sortu(void) {

	int Id = -1;

	Id = irudiaKargatu(SUA);
	irudiaMugitu(Id, 0, 400);


	return Id;
}

int sua2Sortu(void) {

	int Id = -1;

	Id = irudiaKargatu(SUA);
	irudiaMugitu(Id, 0, 400);

	return Id;
}

ELEMENTUA mugitu(ELEMENTUA elementua) {

	elementua.posizioa.x += elementua.dx;
	elementua.posizioa.y += elementua.dy;

	irudiaMugitu(elementua.Id, elementua.posizioa.x, elementua.posizioa.y);
	irudiakMarraztu();

	return elementua;
}

