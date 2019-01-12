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
#include "esqueleto.h"

#define ENEMIGO1 ".\\img\\esqueleto.bmp"
#define ENEMIGO2 ".\\img\\esqueleto1.bmp"
#define ENEMIGO3 ".\\img\\esqueleto2.bmp"
#define ENEMIGO4 ".\\img\\esqueleto4.bmp"
#define ENEMIGO5 ".\\img\\esqueleto5.bmp"
#define ENEMIGO6 ".\\img\\esqueleto6.bmp"

int eskeletoenAnimazioarenKontadorea = 0;
int eskerreraAlaEskumaraJoangoDaEskeletoa = 1;


ELEMENTUA esqueletoFuntzioak(ELEMENTUA esqueleto, ELEMENTUA jokalaria) {
	if ((esqueleto.posizioa.x < jokalaria.posizioa.x) && (enemigoKont >= 0) && (esqueleto.mugitzen == 1)) {
		esqueleto.dx = 1;
	}
	else if ((esqueleto.posizioa.x > jokalaria.posizioa.x) && (enemigoKont >= 0) && (esqueleto.mugitzen == 1)) {
		esqueleto.dx = -1;
	}
	else {
		esqueleto.dx = 0;
	}


	eskerreraAlaEskumaraJoangoDaEskeletoa = ezkerreraAlaEskumaraEskeletoa(jokalaria.posizioa, esqueleto.posizioa);
	esqueleto = eskeletoarenAnimazioa(esqueleto);
	esqueleto = esqueletoEtaJokalaria(esqueleto, jokalaria);


	return esqueleto;
}

ELEMENTUA esqueletoEtaJokalaria(ELEMENTUA esqueleto, ELEMENTUA jokalaria) {
	if (((esqueleto.posizioa.x < jokalaria.posizioa.x) && (esqueleto.posizioa.x > jokalaria.posizioa.x - 20) && (jokalaria.egoera == 6)) || ((esqueleto.posizioa.x < jokalaria.posizioa.x + 10 + 20) && (esqueleto.posizioa.x > jokalaria.posizioa.x + 10) && (jokalaria.egoera == 7))) {

		enemigoKont--;

		if (enemigoKont > 4) {
			irudiaMugitu(esqueleto.Id, -10, 350);
			esqueleto.posizioa.x = -100;
			esqueleto.posizioa.y = 350;
			esqueleto.mugitzen = 1;
		}
		else {
			irudiaMugitu(esqueleto.Id, -10, 350);
			esqueleto.posizioa.x = -102;
			esqueleto.posizioa.y = 350;
			esqueleto.mugitzen = 0;
		}


	}
	return esqueleto;
}

ELEMENTUA eskeletoarenAnimazioa(ELEMENTUA esqueleto)
{
	switch (eskeletoenAnimazioarenKontadorea)
	{
	case 0:

		if (eskerreraAlaEskumaraJoangoDaEskeletoa == -1)
		{
			esqueleto = eskeletoSortu1(esqueleto);
		}
		if (eskerreraAlaEskumaraJoangoDaEskeletoa == 1)
		{
			esqueleto = eskeletoSortu4(esqueleto);
		}

		break;

	case 1:

		if (eskerreraAlaEskumaraJoangoDaEskeletoa == -1)
		{
			esqueleto = eskeletoSortu2(esqueleto);
		}
		if (eskerreraAlaEskumaraJoangoDaEskeletoa == 1)
		{
			esqueleto = eskeletoSortu5(esqueleto);
		}

	case 2:

		if (eskerreraAlaEskumaraJoangoDaEskeletoa == -1)
		{
			esqueleto = eskeletoSortu3(esqueleto);
		}
		if (eskerreraAlaEskumaraJoangoDaEskeletoa == 1)
		{
			esqueleto = eskeletoSortu6(esqueleto);
		}
	
	}

	eskeletoenAnimazioarenKontadorea++;

	if (eskeletoenAnimazioarenKontadorea > 10)
	{
		eskeletoenAnimazioarenKontadorea = 0;
	}

	return esqueleto;
}


/*
POSIZIOA dragoienArtekoKolisioaSortu(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	if (posizioa1.x - posizioa2.x > 0)
	{
		posizioa1.x += 1;
	}
	if (posizioa1.x - posizioa2.x < 0)
	{
		posizioa1.x -= 1;
	}
	if (posizioa1.y - posizioa2.y > 0)
	{
		posizioa1.y += 1;
	}
	if (posizioa1.y - posizioa2.y < 0)
	{
		posizioa1.y -= 1;
	}

	return posizioa1;
}
*/

int ezkerreraAlaEskumaraEskeletoa(POSIZIOA jokalaria, POSIZIOA esqueleto)
{
	if (jokalaria.x - esqueleto.x > 0)
	{
		eskerreraAlaEskumaraJoangoDaEskeletoa = 1;
	}
	else
	{
		eskerreraAlaEskumaraJoangoDaEskeletoa = -1;
	}

	return eskerreraAlaEskumaraJoangoDaEskeletoa;
}

ELEMENTUA eskeletoSortu1(ELEMENTUA esqueleto) {

	irudiaKendu(esqueleto.Id);

	esqueleto.Id = irudiaKargatu(ENEMIGO1);
	irudiaMugitu(esqueleto.Id, esqueleto.posizioa.x, esqueleto.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return esqueleto;
}

ELEMENTUA eskeletoSortu2(ELEMENTUA esqueleto) {

	irudiaKendu(esqueleto.Id);

	esqueleto.Id = irudiaKargatu(ENEMIGO2);
	irudiaMugitu(esqueleto.Id, esqueleto.posizioa.x, esqueleto.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return esqueleto;
}

ELEMENTUA eskeletoSortu3(ELEMENTUA esqueleto) {

	irudiaKendu(esqueleto.Id);

	esqueleto.Id = irudiaKargatu(ENEMIGO3);
	irudiaMugitu(esqueleto.Id, esqueleto.posizioa.x, esqueleto.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return esqueleto;
}

ELEMENTUA eskeletoSortu4(ELEMENTUA esqueleto) {

	irudiaKendu(esqueleto.Id);

	esqueleto.Id = irudiaKargatu(ENEMIGO4);
	irudiaMugitu(esqueleto.Id, esqueleto.posizioa.x, esqueleto.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return esqueleto;
}

ELEMENTUA eskeletoSortu5(ELEMENTUA esqueleto) {

	irudiaKendu(esqueleto.Id);

	esqueleto.Id = irudiaKargatu(ENEMIGO5);
	irudiaMugitu(esqueleto.Id, esqueleto.posizioa.x, esqueleto.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return esqueleto;
}

ELEMENTUA eskeletoSortu6(ELEMENTUA esqueleto) {

	irudiaKendu(esqueleto.Id);

	esqueleto.Id = irudiaKargatu(ENEMIGO6);
	irudiaMugitu(esqueleto.Id, esqueleto.posizioa.x, esqueleto.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return esqueleto;
}