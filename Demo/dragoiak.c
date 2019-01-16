#include "imagen.h"
#include "definizioak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "sua.h"
#include "dragoiak.h"
#include "jokua.h"

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
#define ENEMIGO9 ".\\img\\dragon9.bmp"
#define ENEMIGO10 ".\\img\\dragon10.bmp"
#define ENEMIGO11 ".\\img\\dragon11.bmp"
#define ENEMIGO12 ".\\img\\dragon12.bmp"
#define ENEMIGO13 ".\\img\\dragon13.bmp"
#define ENEMIGO14 ".\\img\\dragon14.bmp"
#define ENEMIGO15 ".\\img\\dragon15.bmp"
#define ENEMIGO16 ".\\img\\dragon16.bmp"

#define DRAGOIAALTUERA 50
#define DRAGOIALUZERA 30

#define JOKALARIAALTUERA 50
#define JOKALARIALUZERA 35
#define JOKALARIARANGO 70

int heganEgingoDu1 = 1;
int heganEgingoDu2 = 1;
int dragoienAnimazioarenKontadorea1 = 0;
int dragoienAnimazioarenKontadorea2 = 0;
int dragoienArtekoDistantzia = 96;
int eskerreraAlaEskumaraJoangoDaDragoia1 = 1;
int eskerreraAlaEskumaraJoangoDaDragoia2 = -1;

ELEMENTUA dragoiarenFuntzioak1(ELEMENTUA enemigo, ELEMENTUA enemigo1, ELEMENTUA sua1, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa1, sua1.posizioa, bolaBotata1) == 0)
	{
		if ((heganEginAhalDu(enemigo.posizioa, enemigo1.posizioa, heganEgingoDu1) == 1) && (enemigo.mugitzen == 1))
		{
			enemigo.posizioa = jarraituAirean(jokalaria.posizioa, enemigo.posizioa);
		}
		else
		{
			enemigo.posizioa = dragoienArtekoKolisioaSortu(enemigo.posizioa, enemigo1.posizioa);
		}
	}

	eskerreraAlaEskumaraJoangoDaDragoia1 = ezkerreraAlaEskumaraDragoia1(jokalaria.posizioa, enemigo.posizioa);

	enemigo = dragoienAnimazioa1(enemigo);

	enemigo = dragoiaEtaJokalaria1(enemigo, jokalaria);

	return enemigo;
}

ELEMENTUA dragoiaEtaJokalaria1(ELEMENTUA dragoia, ELEMENTUA jokalaria) {
	if (((jokalaria.posizioa.x > dragoia.posizioa.x + DRAGOIALUZERA) && (jokalaria.posizioa.x < dragoia.posizioa.x + DRAGOIALUZERA + JOKALARIARANGO) && (jokalaria.egoera == 7) && (jokalaria.posizioa.y > dragoia.posizioa.y) && (jokalaria.posizioa.y < dragoia.posizioa.y + DRAGOIAALTUERA)) || ((jokalaria.posizioa.x + JOKALARIALUZERA < dragoia.posizioa.x) && (jokalaria.posizioa.x + JOKALARIALUZERA > dragoia.posizioa.x - JOKALARIARANGO) && (jokalaria.egoera == 6) && (jokalaria.posizioa.y > dragoia.posizioa.y) && (jokalaria.posizioa.y < dragoia.posizioa.y + DRAGOIAALTUERA))) {

		enemigoKont--;

		if (enemigoKont > 4) {
			irudiaMugitu(dragoia.Id, -10, 350);
			dragoia.posizioa.x = -100;
			dragoia.posizioa.y = 0;
		}
		else {
			irudiaMugitu(dragoia.Id, -10, 350);
			dragoia.posizioa.x = -100;
			dragoia.posizioa.y = 0;
			dragoia.mugitzen = 0;
		}


	}

	return dragoia;
}

ELEMENTUA dragoiarenFuntzioak2(ELEMENTUA enemigo1, ELEMENTUA enemigo, ELEMENTUA sua2, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa2, sua2.posizioa, bolaBotata2) == 0)
	{
		if ((heganEginAhalDu(enemigo1.posizioa, enemigo.posizioa, heganEgingoDu2) == 1) && (enemigo1.mugitzen == 1))
		{
			enemigo1.posizioa = jarraituAirean(jokalaria.posizioa, enemigo1.posizioa);
		}
		else
		{
			enemigo1.posizioa = dragoienArtekoKolisioaSortu(enemigo1.posizioa, enemigo.posizioa);
		}
	}

	eskerreraAlaEskumaraJoangoDaDragoia2 = ezkerreraAlaEskumaraDragoia2(jokalaria.posizioa, enemigo1.posizioa);

	enemigo1 = dragoienAnimazioa2(enemigo1);

	enemigo1 = dragoiaEtaJokalaria2(enemigo1, jokalaria);

	return enemigo1;
}

ELEMENTUA dragoiaEtaJokalaria2(ELEMENTUA dragoia, ELEMENTUA jokalaria) {
	if (((jokalaria.posizioa.x > dragoia.posizioa.x + DRAGOIALUZERA) && (jokalaria.posizioa.x < dragoia.posizioa.x + DRAGOIALUZERA + JOKALARIARANGO) && (jokalaria.egoera == 7) && (jokalaria.posizioa.y > dragoia.posizioa.y) && (jokalaria.posizioa.y < dragoia.posizioa.y + DRAGOIAALTUERA)) || ((jokalaria.posizioa.x + JOKALARIALUZERA < dragoia.posizioa.x) && (jokalaria.posizioa.x + JOKALARIALUZERA > dragoia.posizioa.x - JOKALARIARANGO) && (jokalaria.egoera == 6) && (jokalaria.posizioa.y > dragoia.posizioa.y) && (jokalaria.posizioa.y < dragoia.posizioa.y + DRAGOIAALTUERA))) {

		enemigoKont--;

		if (enemigoKont > 4) {
			irudiaMugitu(dragoia.Id, -10, 350);
			dragoia.posizioa.x = 800;
			dragoia.posizioa.y = 0;
		}
		else {
			irudiaMugitu(dragoia.Id, -10, 350);
			dragoia.posizioa.x = 800;
			dragoia.posizioa.y = 0;
			dragoia.mugitzen = 0;
		}


	}

	return dragoia;
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

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu1(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu9(enemigo);
		}
		
		break;

	case 2:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu2(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu10(enemigo);
		}

		break;

	case 4:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu3(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu11(enemigo);
		}

		break;
	case 6:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu4(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu12(enemigo);
		}

		break;

	case 8:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu5(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu13(enemigo);
		}

		break;

	case 10:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu6(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu14(enemigo);
		}

		break;

	case 12:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu7(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu15(enemigo);
		}

		break;

	case 14:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu8(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu16(enemigo);
		}

		break;

	case 16:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu7(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu15(enemigo);
		}

		break;

	case 18:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu6(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu14(enemigo);
		}

		break;

	case 20:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu5(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu13(enemigo);
		}

		break;

	case 22:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu4(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu12(enemigo);
		}

		break;

	case 24:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu3(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu11(enemigo);
		}

		break;

	case 26:

		if (eskerreraAlaEskumaraJoangoDaDragoia1 == -1)
		{
			enemigo = enemigoSortu2(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia1 == 1)
		{
			enemigo = enemigoSortu10(enemigo);
		}

		break;
	}

	dragoienAnimazioarenKontadorea1++;

	if (dragoienAnimazioarenKontadorea1 > 28)
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

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu6(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu14(enemigo);
		}

		break;

	case 2:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu7(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu15(enemigo);
		}

		break;

	case 4:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu8(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu16(enemigo);
		}

		break;
	case 6:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu7(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu15(enemigo);
		}

		break;

	case 8:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu6(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu14(enemigo);
		}

		break;

	case 10:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu5(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu13(enemigo);
		}

		break;

	case 12:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu4(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu12(enemigo);
		}

		break;

	case 14:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu3(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu11(enemigo);
		}

		break;

	case 16:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu2(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu10(enemigo);
		}

		break;

	case 18:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu1(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu9(enemigo);
		}

		break;

	case 20:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu2(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu10(enemigo);
		}

		break;

	case 22:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu3(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu11(enemigo);
		}

		break;

	case 24:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu4(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu12(enemigo);
		}

		break;

	case 26:

		if (eskerreraAlaEskumaraJoangoDaDragoia2 == -1)
		{
			enemigo = enemigoSortu5(enemigo);
		}
		if (eskerreraAlaEskumaraJoangoDaDragoia2 == 1)
		{
			enemigo = enemigoSortu13(enemigo);
		}

		break;
	}

	dragoienAnimazioarenKontadorea2++;

	if (dragoienAnimazioarenKontadorea2 > 28)
	{
		dragoienAnimazioarenKontadorea2 = 0;
	}

	return enemigo;
}

ELEMENTUA enemigoSortu1(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO1);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);
	return enemigo;
}

ELEMENTUA enemigoSortu2(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO2);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu3(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO3);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu4(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO4);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu5(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO5);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu6(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO6);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu7(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO7);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu8(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO8);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}
ELEMENTUA enemigoSortu9(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO9);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu10(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO10);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu11(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO11);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu12(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO12);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu13(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO13);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu14(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO14);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu15(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO15);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

ELEMENTUA enemigoSortu16(ELEMENTUA enemigo) {

	irudiaKendu(enemigo.Id);

	enemigo.Id = irudiaKargatu(ENEMIGO16);
	irudiaMugitu(enemigo.Id, enemigo.posizioa.x, enemigo.posizioa.y);

	return enemigo;
}

int ezkerreraAlaEskumaraDragoia1(POSIZIOA jokalaria, POSIZIOA dragoia)
{
	if (jokalaria.x - dragoia.x > 0)
	{
		eskerreraAlaEskumaraJoangoDaDragoia1 = 1;
	}
	else
	{
		eskerreraAlaEskumaraJoangoDaDragoia1 = -1;
	}

	return eskerreraAlaEskumaraJoangoDaDragoia1;
}

int ezkerreraAlaEskumaraDragoia2(POSIZIOA jokalaria, POSIZIOA dragoia)
{
	if (jokalaria.x - dragoia.x > 0)
	{
		eskerreraAlaEskumaraJoangoDaDragoia2 = 1;
	}
	else
	{
		eskerreraAlaEskumaraJoangoDaDragoia2 = -1;
	}

	return eskerreraAlaEskumaraJoangoDaDragoia2;
}