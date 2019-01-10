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

#define ESKUBIKOBORDEA 601
#define EZKERREKOBORDEA 10
#define PLATAFORMALUZERA 170

ELEMENTUA jokalariaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa, ELEMENTUA plataforma1, ELEMENTUA plataforma2) {

	//jokalariaren lurra//
	if ((jokalaria.posizioa.x > plataforma1.posizioa.x) && (jokalaria.posizioa.x < plataforma1.posizioa.x + PLATAFORMALUZERA)) {
		jokalaria.lurra = plataforma1.posizioa.y;
	}
	else if ((jokalaria.posizioa.x > plataforma2.posizioa.x) && (jokalaria.posizioa.x < plataforma2.posizioa.x + PLATAFORMALUZERA)) {
		jokalaria.lurra = plataforma2.posizioa.y;
	}
	else {
		jokalaria.lurra = 350;
	}
	if ((jokalaria.posizioa.y < jokalaria.lurra) && (jokalaria.saltatzen == 0)) {
		jokalaria.dy += 1;
	}
	else if ((jokalaria.posizioa.y >= 350) && (jokalaria.saltatzen == 0) && (jokalaria.dy > 0)) {
		jokalaria.dy = 0;
	}

	printf("%f ",jokalaria.posizioa.y);

	//----------------------------//

	switch (ebentuaJasoGertatuBada()) {

	case TECLA_RIGHT:

		if (jokalaria.posizioa.x < ESKUBIKOBORDEA) {
			jokalaria.dx = 3;
		}
		else {
			jokalaria.dx = 0;
		}

		jokalaria.kont = 0;

		jokalaria.ebentua = TECLA_RIGHT;



		break;

	case TECLA_LEFT:

		if (jokalaria.posizioa.x > EZKERREKOBORDEA) {
			jokalaria.dx = -3;
		}
		else {
			jokalaria.dx = 0;
		}

		jokalaria.kont = 0;

		jokalaria.ebentua = TECLA_LEFT;


		break;

	case TECLA_SPACE:

		if (jokalaria.dy == 0) {
			jokalaria.saltatzen = 1;
			jokalaria.dy = -22;
		}

		break;

	default:

		if (jokalaria.kont > 14) {

			jokalaria.kont2 = 0;

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
		jokalaria.kont++;

		break;
	}
	
	jokalaria = animazioa(jokalaria, eszenarioa);

	jokalaria = animatu(jokalaria);


	//------------------------//
	return jokalaria;

}

ELEMENTUA eszenarioaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa) {

	switch (jokalaria.ebentua) {

	case TECLA_RIGHT:

		if ((jokalaria.posizioa.x > ESKUBIKOBORDEA - 5) && (eszenarioa.posizioa.x > -340)) {
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

	if (elementua.dy <= 0) {
		elementua.dy += grabitatea;
	}

	else {

		if (elementua.posizioa.y > elementua.lurra) {
			elementua.saltatzen = 0;
			elementua.dy = 0;
		}
		else {
			elementua.dy += grabitatea;
		}
	}

	return elementua;
}

ELEMENTUA animatu(ELEMENTUA jokalaria) {

	switch (jokalaria.egoera) {

	case 0:

		jokalaria = jokalariaEgoera0(jokalaria);

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
	}

	return jokalaria;
}

ELEMENTUA animazioa(ELEMENTUA jokalaria, ELEMENTUA eszenarioa) {

	if (jokalaria.dy != 0) {
		jokalaria.egoera = 4;
	}
	else {

		if ((jokalaria.dx > 0) || (eszenarioa.dx < 0)) {
			jokalaria.egoera = 1;
			jokalaria.kont2++;

			if (jokalaria.kont2 > 5) {
				jokalaria.egoera = 0;

				if (jokalaria.kont2 > 10) {
					jokalaria.kont2 = 0;
				}
			}
		}
		else if ((jokalaria.dx < 0) || (eszenarioa.dx > 0)) {
			jokalaria.egoera = 2;
			jokalaria.kont2++;

			if (jokalaria.kont2 > 5) {
				jokalaria.egoera = 3;

				if (jokalaria.kont2 > 10) {
					jokalaria.kont2 = 0;
				}
			}
		}
		else if (jokalaria.dx == 0) {
			jokalaria.egoera = 0;
		}
	}

	return jokalaria;
}

ELEMENTUA jokalariaEgoera0(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}

ELEMENTUA jokalariaEgoera1(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA1);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}

ELEMENTUA jokalariaEgoera2(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA2);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}

ELEMENTUA jokalariaEgoera3(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA3);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}

ELEMENTUA jokalariaEgoera4(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA4);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}