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
#define JOKALARIA6 ".\\img\\mainChar6.bmp"
#define JOKALARIA7 ".\\img\\mainChar7.bmp"

#define ESKUBIKOBORDEA 601
#define EZKERREKOBORDEA 10
#define PLATAFORMALUZERA 170

ELEMENTUA jokalariaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa, ELEMENTUA plataforma1, ELEMENTUA plataforma2,ELEMENTUA esqueleto1, ELEMENTUA esqueleto2, ELEMENTUA esqueleto3) {

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

	case TECLA_d:

		jokalaria.egoera = 7;
		jokalaria.kont4 = 0;
		
		break;

	case TECLA_a:

		jokalaria.egoera = 6;
		jokalaria.kont4 = 0;

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

	jokalaria = jokalariaEtaEsqueleto(jokalaria, esqueleto1);
	jokalaria = jokalariaEtaEsqueleto(jokalaria, esqueleto2);
	jokalaria = jokalariaEtaEsqueleto(jokalaria, esqueleto3);


	//------------------------//
	return jokalaria;

}

ELEMENTUA jokalariaEtaEsqueleto(ELEMENTUA jokalaria, ELEMENTUA esqueleto) {
	if ((esqueleto.posizioa.x + 10 > jokalaria.posizioa.x) && (esqueleto.posizioa.x < jokalaria.posizioa.x + 10) && (jokalaria.kont3 > 70)) {
		jokalaria.bizitza--;
		jokalaria.kont3 = 0;
	}
	jokalaria.kont3++;

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

		jokalaria = jokalariaEgoera6(jokalaria);

		break;

	case 7:

		jokalaria = jokalariaEgoera7(jokalaria);

		break;
	}


	return jokalaria;
}

ELEMENTUA animazioa(ELEMENTUA jokalaria, ELEMENTUA eszenarioa) {

	if ((jokalaria.egoera == 7) && (jokalaria.kont4 < 15)) {
		jokalaria.egoera = 7;
		jokalaria.kont4++;
	}
	else if ((jokalaria.egoera == 6) && (jokalaria.kont4 < 15)) {
		jokalaria.egoera = 6;
		jokalaria.kont4++;
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

ELEMENTUA jokalariaEgoera5(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA5);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}

ELEMENTUA jokalariaEgoera6(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA6);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}

ELEMENTUA jokalariaEgoera7(ELEMENTUA jokalaria) {

	int Id = -1;

	irudiaKendu(jokalaria.Id);

	jokalaria.Id = irudiaKargatu(JOKALARIA7);
	irudiaMugitu(jokalaria.Id, jokalaria.posizioa.x, jokalaria.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return jokalaria;
}