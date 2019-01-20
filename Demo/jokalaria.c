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

#define JOKALARIA ".\\img\\mainChar.bmp"
#define JOKALARIA1 ".\\img\\mainChar1.bmp"
#define JOKALARIA2 ".\\img\\mainChar2.bmp"
#define JOKALARIA3 ".\\img\\mainChar3.bmp"
#define JOKALARIA4 ".\\img\\mainChar4.bmp"
#define JOKALARIA5 ".\\img\\mainChar5.bmp"
#define ERASO1 ".\\img\\attack1.bmp"
#define ERASO2 ".\\img\\attack2.bmp"
#define ERASO3 ".\\img\\attack3.bmp"
#define ERASO4 ".\\img\\attack4.bmp"
#define ERASO5 ".\\img\\attack5.bmp"
#define ERASO6 ".\\img\\attack6.bmp"
#define ERASO7 ".\\img\\attack7.bmp"
#define ERASO8 ".\\img\\attack8.bmp"
#define ERASO9 ".\\img\\attack9.bmp"
#define ERASO10 ".\\img\\attack10.bmp"

#define ESKUBIKOBORDEA 590
#define EZKERREKOBORDEA 10
#define PLATAFORMALUZERA 170

#define TXURIZULOA 15
#define ESKELETOZABALERA 20

#define JOKALARIALUZERA 40
#define JOKALARIARANGO 10

int erasoarenKontadorea = 0;

ELEMENTUA jokalariaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa, ELEMENTUA plataforma1, ELEMENTUA plataforma2,ELEMENTUA esqueleto1, ELEMENTUA esqueleto2, ELEMENTUA esqueleto3, ELEMENTUA sua1, ELEMENTUA sua2) {

	//jokalariaren lurra//
	if ((jokalaria.posizioa.x > plataforma1.posizioa.x) && (jokalaria.posizioa.x < plataforma1.posizioa.x + PLATAFORMALUZERA) && (jokalaria.posizioa.y <= plataforma1.posizioa.y)) {
		jokalaria.lurra = plataforma1.posizioa.y;
	}
	else if ((jokalaria.posizioa.x > plataforma2.posizioa.x) && (jokalaria.posizioa.x < plataforma2.posizioa.x + PLATAFORMALUZERA) && (jokalaria.posizioa.y <= plataforma1.posizioa.y)) {
		jokalaria.lurra = plataforma2.posizioa.y;
	}
	else {
		jokalaria.lurra = 350;
	}


	if (jokalaria.posizioa.y >= jokalaria.lurra) {
		jokalaria.posizioa.y = jokalaria.lurra;
		jokalaria.dy = 0;
	}
	//----------------------------//

	switch (ebentuaJasoGertatuBada()) {

	case TECLA_RIGHT:

		if (jokalaria.posizioa.x < ESKUBIKOBORDEA) {
			jokalaria.dx = 3;
		}
		else {
			jokalaria.dx = 0;
		}

		jokalaria.kontmugimendua = 0;

		jokalaria.ebentua = TECLA_RIGHT;



		break;

	case TECLA_LEFT:

		if (jokalaria.posizioa.x > EZKERREKOBORDEA) {
			jokalaria.dx = -3;
		}
		else {
			jokalaria.dx = 0;
		}

		jokalaria.kontmugimendua = 0;

		jokalaria.ebentua = TECLA_LEFT;


		break;

	case TECLA_SPACE:

		if (jokalaria.posizioa.y == jokalaria.lurra) {
			jokalaria.saltatzen = 1;
			jokalaria.dy = -22;
			playSound(saltoarenSoinua.Id);
		}

		break;

	case TECLA_d:

		jokalaria.egoera = 6;
		jokalaria.konteraso = 0;
		
		break;

	case TECLA_a:

		jokalaria.egoera = 7;
		jokalaria.konteraso = 0;

		break;

	default:

		if (jokalaria.kontmugimendua > 14) {

			jokalaria.kontanim = 0;

			if (jokalaria.dx > 0)
			{
				jokalaria.dx--;
			}
			else if (jokalaria.dx < 0) {
				jokalaria.dx++;
			}
			else {
				jokalaria.dx = 0;
				jokalaria.ebentua = 0;
			}
		}
		jokalaria.kontmugimendua++;

		break;
	}
	
	jokalaria = animazioa(jokalaria, eszenarioa);

	jokalaria = animatu(jokalaria);

	jokalaria = jokalariaEtaEsqueleto(jokalaria, esqueleto1);
	jokalaria = jokalariaEtaEsqueleto(jokalaria, esqueleto2);
	jokalaria = jokalariaEtaEsqueleto(jokalaria, esqueleto3);
	jokalaria = jokalariaEtaBola(jokalaria, sua1);
	jokalaria = jokalariaEtaBola(jokalaria, sua2);


	//------------------------//
	return jokalaria;

}

ELEMENTUA jokalariaEtaEsqueleto(ELEMENTUA jokalaria, ELEMENTUA esqueleto) {
	if (((jokalaria.posizioa.x + JOKALARIALUZERA > esqueleto.posizioa.x - JOKALARIARANGO + TXURIZULOA) && (jokalaria.posizioa.x + JOKALARIALUZERA < esqueleto.posizioa.x + TXURIZULOA) && (jokalaria.posizioa.y == esqueleto.posizioa.y) && (jokalaria.kontbizitza > 300)) || ((jokalaria.posizioa.x < esqueleto.posizioa.x + TXURIZULOA + TXURIZULOA + JOKALARIARANGO + ESKELETOZABALERA) && (jokalaria.posizioa.x > esqueleto.posizioa.x + TXURIZULOA + TXURIZULOA + ESKELETOZABALERA) && (jokalaria.posizioa.y == esqueleto.posizioa.y) && (jokalaria.kontbizitza > 300))) {
		jokalaria.bizitza--;
		jokalaria.kontbizitza = 0;
		playSound(mainCharDamage.Id);
	}
	jokalaria.kontbizitza++;

	return jokalaria;
}

ELEMENTUA jokalariaEtaBola(ELEMENTUA jokalaria, ELEMENTUA sua) {
	if ((sua.posizioa.x <= jokalaria.posizioa.x + 30) && (sua.posizioa.x >= jokalaria.posizioa.x) && (sua.posizioa.y >= jokalaria.posizioa.y) && (sua.posizioa.y <= jokalaria.posizioa.y + 50) && (jokalaria.kontbizitza > 300)) {
		jokalaria.bizitza--;
		jokalaria.kontbizitza = 0;
		playSound(mainCharDamage.Id);
	}
	jokalaria.kontbizitza++;

	return jokalaria;
}


ELEMENTUA eszenarioaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa) {

	switch (jokalaria.ebentua) {

	case TECLA_RIGHT:

		if ((jokalaria.posizioa.x > ESKUBIKOBORDEA - 5) && (eszenarioa.posizioa.x > -(1608 - 640))) {
			eszenarioa.dx = -6;
		}
		else {
			eszenarioa.dx = 0;
		}

		break;

	case TECLA_LEFT:

		if ((jokalaria.posizioa.x < EZKERREKOBORDEA + 5) && (eszenarioa.posizioa.x < 0)) {
			eszenarioa.dx = 6;
		}
		else {
			eszenarioa.dx = 0;
		}

		break;


	default:

		eszenarioa.dx = 0;

		break;
	}

	return eszenarioa;
}

ELEMENTUA salto(ELEMENTUA elementua) {

	int grabitatea = 1;

	if ((elementua.posizioa.y > elementua.lurra)) {
		elementua.posizioa.y = elementua.lurra;
	}

	elementua.dy += grabitatea;

	return elementua;
}

ELEMENTUA animatu(ELEMENTUA jokalaria) {

	switch (jokalaria.egoera) {

	case 0:

		jokalaria = jokalariaEgoera0(jokalaria);
		erasoarenKontadorea = 0;

		break;

	case 1:

		jokalaria = jokalariaEgoera1(jokalaria);

		break;

	case 2:

		jokalaria = jokalariaEgoera2(jokalaria);

		break;

	case 3:

		jokalaria = jokalariaEgoera3(jokalaria);

		break;

	case 4:

		jokalaria = jokalariaEgoera4(jokalaria);

		break;

	case 5:

		jokalaria = jokalariaEgoera5(jokalaria);

		break;

	case 6:

		jokalaria = erasoEgoera1(jokalaria);

		break;

	case 7:

		jokalaria = erasoEgoera2(jokalaria);

		break;
	}
	return jokalaria;

}

ELEMENTUA animazioa(ELEMENTUA jokalaria, ELEMENTUA eszenarioa) {

	if ((jokalaria.egoera == 7) && (jokalaria.konteraso < 15)) {
		jokalaria.egoera = 7;
		jokalaria.konteraso++;
	}
	else if ((jokalaria.egoera == 6) && (jokalaria.konteraso < 15)) {
		jokalaria.egoera = 6;
		jokalaria.konteraso++;
	}
	else {

		if (jokalaria.dy != 0) {

			if (jokalaria.dx < 0) {
				jokalaria.egoera = 5;
			}
			else {
				jokalaria.egoera = 4;
			}

		}
		else {

			if ((jokalaria.dx > 0) || (eszenarioa.dx < 0)) {
				jokalaria.egoera = 1;
				jokalaria.kontanim++;

				if (jokalaria.kontanim > 5) {
					jokalaria.egoera = 0;

					if (jokalaria.kontanim > 10) {
						jokalaria.kontanim = 0;
					}
				}
			}
			else if ((jokalaria.dx < 0) || (eszenarioa.dx > 0)) {
				jokalaria.egoera = 2;
				jokalaria.kontanim++;

				if (jokalaria.kontanim > 5) {
					jokalaria.egoera = 3;

					if (jokalaria.kontanim > 10) {
						jokalaria.kontanim = 0;
					}
				}
			}
			else if (jokalaria.dx == 0) {
				jokalaria.egoera = 0;
			}
		}
	}
	return jokalaria;
}

ELEMENTUA jokalariaEgoera0(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	return jokalaria;
}

ELEMENTUA jokalariaEgoera1(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA1);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	return jokalaria;
}

ELEMENTUA jokalariaEgoera2(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA2);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	return jokalaria;
}

ELEMENTUA jokalariaEgoera3(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA3);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	return jokalaria;
}

ELEMENTUA jokalariaEgoera4(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA4);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	return jokalaria;
}

ELEMENTUA jokalariaEgoera5(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA5);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	return jokalaria;
}

ELEMENTUA erasoEgoera1(ELEMENTUA jokalaria) {

	if (erasoarenKontadorea == 0)
	{
		playSound(mainCharAtakeSoinua.Id);
	}
	if (erasoarenKontadorea >= 0 && erasoarenKontadorea < 4)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO1);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	}
	if (erasoarenKontadorea >= 4 && erasoarenKontadorea < 8)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO2);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	}
	if (erasoarenKontadorea >= 8 && erasoarenKontadorea < 12)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO3);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea >= 12 && erasoarenKontadorea < 16)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO4);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea >= 16 && erasoarenKontadorea < 20)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO5);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea == 20)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(JOKALARIA1);
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

		erasoarenKontadorea = 0;
	}

	return jokalaria;
}
ELEMENTUA erasoEgoera2(ELEMENTUA jokalaria) {

	if (erasoarenKontadorea == 0)
	{
		playSound(mainCharAtakeSoinua.Id);
	}
	if (erasoarenKontadorea >= 0 && erasoarenKontadorea < 4)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO6);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea >= 4 && erasoarenKontadorea < 8)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO7);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea >= 8 && erasoarenKontadorea < 12)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO8);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea >= 12 && erasoarenKontadorea < 16)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO9);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea >= 16 && erasoarenKontadorea < 20)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(ERASO10);
		erasoarenKontadorea++;
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

	}
	if (erasoarenKontadorea == 20)
	{
		irudiaKendu(jokalaria.Id);

		jokalaria.Id = irudiaKargatu(JOKALARIA3);
		irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);

		erasoarenKontadorea = 0;
	}

	return jokalaria;
}