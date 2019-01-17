#include "imagen.h"
#include "definizioak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "sua.h"
#include "jokua.h"

#include <stdio.h>
#include <windows.h>
#include <math.h>

#define SUA ".\\img\\fireBall.bmp"

int bolaBotata1 = 0;
int bolaBotata2 = 0;
int bolarenAbiadura = 6;
int dragoiarenHeina = 250;
int bolaAgertuAhalDa1 = 0;
int bolaAgertuAhalDa2 = 0;
double bolarenAngelua1 = 0;
double bolarenAngelua2 = 0;
POSIZIOA bolarenDirekzioa1 = { 50, 400 };
POSIZIOA bolarenDirekzioa2 = { 50, 400 };

ELEMENTUA suaFuntzioak1(ELEMENTUA sua1, ELEMENTUA enemigo, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa1, sua1.posizioa, bolaBotata1) == 0)
	{
		sua1.posizioa = bolaAgertuEskuan(enemigo.posizioa);
		bolarenDirekzioa1 = jokalaria.posizioa;
		bolarenAngelua1 = bolarenAngeluaKalkulatu(jokalaria.posizioa, enemigo.posizioa);
		if (bolaAgertuAhalDa1 == 0)
		{
			irudiaKendu(sua1.Id);
			bolaAgertuAhalDa1 = 1;
		}
	}
	else
	{
		if (bolaAgertuAhalDa1 == 1)
		{
			sua1.Id = irudiaKargatu(SUA);
			bolaAgertuAhalDa1 = 0;
			playSound(dragoiaSuaBota.Id);
		}
		sua1 = suaAgertu(sua1);
		sua1.posizioa = jarraituBola(bolarenDirekzioa1, sua1.posizioa, bolarenAngelua1);
	}

	return sua1;
}

ELEMENTUA suaFuntzioak2(ELEMENTUA sua2, ELEMENTUA enemigo1, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa2, sua2.posizioa, bolaBotata2) == 0)
	{
		sua2.posizioa = bolaAgertuEskuan(enemigo1.posizioa);
		bolarenDirekzioa2 = jokalaria.posizioa;
		bolarenAngelua2 = bolarenAngeluaKalkulatu(jokalaria.posizioa, enemigo1.posizioa);
		if (bolaAgertuAhalDa2 == 0)
		{
			irudiaKendu(sua2.Id);
			bolaAgertuAhalDa2 = 1;
		}
	}
	else
	{
		if (bolaAgertuAhalDa2 == 1)
		{
			sua2.Id = irudiaKargatu(SUA);
			bolaAgertuAhalDa2 = 0;
			playSound(dragoiaSuaBota.Id);
		}
		sua2 = suaAgertu(sua2);
		sua2.posizioa = jarraituBola(bolarenDirekzioa2, sua2.posizioa, bolarenAngelua2);
	}

	return sua2;
}

POSIZIOA jarraituBola(POSIZIOA posizioa1, POSIZIOA posizioa2, double bolarenAngelua)
{

	posizioa2.x = posizioa2.x + cos(bolarenAngelua) * bolarenAbiadura;
	posizioa2.y = posizioa2.y + sin(bolarenAngelua) * bolarenAbiadura;

	return posizioa2;
}

int suaBotata(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza)
{
	baldintza = 0;

	if (posizioa1.x - posizioa2.x < dragoiarenHeina && posizioa1.x - posizioa2.x > -dragoiarenHeina && posizioa1.y - posizioa2.y < dragoiarenHeina && posizioa1.y - posizioa2.y > -dragoiarenHeina)
	{
		baldintza = 1;
	}

	if (posizioa1.x < 0 || posizioa1.x > 640 || posizioa1.y < 0 || posizioa1.y > 480)
	{
		baldintza = 0;
	}

	return baldintza;
}

double bolarenAngeluaKalkulatu(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	double x, y;
	double alpha;

	x = posizioa1.x - posizioa2.x;
	y = posizioa1.y - posizioa2.y;

	alpha = atan2(y, x);

	return alpha;
}

ELEMENTUA suaAgertu(ELEMENTUA sua)
{
	irudiaKendu(sua.Id);

	sua.Id = irudiaKargatu(SUA);
	irudiaMugitu(sua.Id, sua.posizioa.x, sua.posizioa.y);

	return sua;
}

POSIZIOA bolaAgertuEskuan(POSIZIOA posizioa)
{
	posizioa.x += 45;
	posizioa.y += 55;

	return posizioa;
}
