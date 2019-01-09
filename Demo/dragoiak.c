#include "imagen.h"
#include "definizioak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "sua.h"
#include "dragoiak.h"

#include <stdio.h>
#include <windows.h>
#include <math.h>

#define ENEMIGO1 ".\\img\\dragon1.bmp"
#define ENEMIGO2 ".\\img\\dragon2.bmp"
#define ENEMIGO3 ".\\img\\dragon3.bmp"
#define ENEMIGO4 ".\\img\\dragon4.bmp"
#define ENEMIGO5 ".\\img\\dragon5.bmp"
#define ENEMIGO6 ".\\img\\dragon6.bmp"
#define ENEMIGO7 ".\\img\\dragon7.bmp"
#define ENEMIGO8 ".\\img\\dragon8.bmp"

int heganEgingoDu1 = 1;
int heganEgingoDu2 = 1;
int dragoienAnimazioarenKontadorea1 = 0;
int dragoienAnimazioarenKontadorea2 = 0;
int dragoienArtekoDistantzia = 50;

ELEMENTUA dragoiarenFuntzioak1(ELEMENTUA enemigo, ELEMENTUA enemigo1, ELEMENTUA sua1, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa1, sua1.posizioa, bolaBotata1) == 0)
	{
		if (heganEginAhalDu(enemigo.posizioa, enemigo1.posizioa, heganEgingoDu1) == 1)
		{
			enemigo.posizioa = jarraituAirean(jokalaria.posizioa, enemigo.posizioa);
		}
		else
		{
			enemigo.posizioa = dragoienArtekoKolisioaSortu(enemigo.posizioa, enemigo1.posizioa);
		}
	}

	enemigo = dragoienAnimazioa1(enemigo);

	return enemigo;
}

ELEMENTUA dragoiarenFuntzioak2(ELEMENTUA enemigo1, ELEMENTUA enemigo, ELEMENTUA sua2, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa2, sua2.posizioa, bolaBotata2) == 0)
	{
		if (heganEginAhalDu(enemigo1.posizioa, enemigo.posizioa, heganEgingoDu2) == 1)
		{
			enemigo1.posizioa = jarraituAirean(jokalaria.posizioa, enemigo1.posizioa);
		}
		else
		{
			enemigo1.posizioa = dragoienArtekoKolisioaSortu(enemigo1.posizioa, enemigo.posizioa);
		}
	}

	enemigo1 = dragoienAnimazioa2(enemigo1);

	return enemigo1;
}

POSIZIOA jarraituAirean(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	double x, y;
	double alpha;

	x = posizioa1.x - posizioa2.x;
	y = posizioa1.y - posizioa2.y;

	alpha = atan2(y, x);

	posizioa2.x = posizioa2.x + cos(alpha);
	posizioa2.y = posizioa2.y + sin(alpha);

	return posizioa2;
}

int heganEginAhalDu(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza)
{

	if (posizioa1.x - posizioa2.x > dragoienArtekoDistantzia || posizioa1.x - posizioa2.x < -dragoienArtekoDistantzia || posizioa1.y - posizioa2.y > dragoienArtekoDistantzia || posizioa1.y - posizioa2.y < -dragoienArtekoDistantzia)
	{
		baldintza = 1;
	}
	else
	{
		baldintza = 0;
	}

	return baldintza;
}

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

ELEMENTUA dragoienAnimazioa1(ELEMENTUA enemigo)
{
	switch (dragoienAnimazioarenKontadorea1)
	{
	case 0:

		enemigo = enemigoSortu1(enemigo);

		break;

	case 5:

		enemigo = enemigoSortu2(enemigo);

		break;

	case 10:

		enemigo = enemigoSortu3(enemigo);
		
		break;
	case 15:
	
		enemigo = enemigoSortu4(enemigo);
		
		break;

	case 20:

		enemigo = enemigoSortu5(enemigo);
		
		break;

	case 25:

		enemigo = enemigoSortu6(enemigo);
		
		break;

	case 30:

		enemigo = enemigoSortu7(enemigo);
		
		break;

	case 40:

		enemigo = enemigoSortu8(enemigo);
		
		break;

	case 45:

		enemigo = enemigoSortu7(enemigo);
		
		break;

	case 50:

		enemigo = enemigoSortu6(enemigo);
		
		break;

	case 55:

		enemigo = enemigoSortu5(enemigo);
		
		break;

	case 60:

		enemigo = enemigoSortu4(enemigo);
	
		break;

	case 65:

		enemigo = enemigoSortu3(enemigo);
		
		break;

	case 70:

		enemigo = enemigoSortu2(enemigo);
	
		break;

	case 75:

		enemigo = enemigoSortu1(enemigo);
	
		break;
	}
	dragoienAnimazioarenKontadorea1++;

	if (dragoienAnimazioarenKontadorea1 > 80)
	{
		dragoienAnimazioarenKontadorea1 = 0;
	}

	return enemigo;
}

ELEMENTUA dragoienAnimazioa2(ELEMENTUA enemigo)
{
	switch (dragoienAnimazioarenKontadorea2)
	{
	case 0:

		enemigo = enemigoSortu6(enemigo);

		break;

	case 5:

		enemigo = enemigoSortu7(enemigo);

		break;

	case 10:

		enemigo = enemigoSortu8(enemigo);

		break;
	case 15:

		enemigo = enemigoSortu7(enemigo);

		break;

	case 20:

		enemigo = enemigoSortu6(enemigo);

		break;

	case 25:

		enemigo = enemigoSortu5(enemigo);

		break;

	case 30:

		enemigo = enemigoSortu4(enemigo);

		break;

	case 40:

		enemigo = enemigoSortu3(enemigo);

		break;

	case 45:

		enemigo = enemigoSortu2(enemigo);

		break;

	case 50:

		enemigo = enemigoSortu1(enemigo);

		break;

	case 55:

		enemigo = enemigoSortu2(enemigo);

		break;

	case 60:

		enemigo = enemigoSortu3(enemigo);

		break;

	case 65:

		enemigo = enemigoSortu4(enemigo);

		break;

	case 70:

		enemigo = enemigoSortu5(enemigo);

		break;

	case 75:

		enemigo = enemigoSortu3(enemigo);

		break;
	}
	dragoienAnimazioarenKontadorea2++;

	if (dragoienAnimazioarenKontadorea2 > 80)
	{
		dragoienAnimazioarenKontadorea2 = 0;
	}

	return enemigo;
}

ELEMENTUA enemigoSortu1(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO1);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu2(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO2);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu3(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO3);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu4(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO4);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu5(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO5);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu6(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO6);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu7(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO7);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}

ELEMENTUA enemigoSortu8(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO8);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();

	return enemigo;
}