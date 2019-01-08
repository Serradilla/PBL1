#include "imagen.h"
#include "definizioak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include <stdio.h>
#include <windows.h>
#include <math.h>

int bolaBotata1 = 0;
int bolaBotata2 = 0;
int bolarenAbiadura = 3;
int dragoiarenHeina = 100;
POSIZIOA bolarenDirekzioa1 = { 50, 400 };
POSIZIOA bolarenDirekzioa2 = { 50, 400 };

POSIZIOA jarraituBola(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	double x, y;
	double alpha;

	x = posizioa1.x - posizioa2.x;
	y = posizioa1.y - posizioa2.y;

	alpha = atan2(y, x);

	posizioa2.x = posizioa2.x + cos(alpha) * bolarenAbiadura;
	posizioa2.y = posizioa2.y + sin(alpha) * bolarenAbiadura;

	return posizioa2;
}

int suaBotata(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza)
{
	baldintza = 0;

	if (posizioa1.x - posizioa2.x < dragoiarenHeina && posizioa1.x - posizioa2.x > -dragoiarenHeina && posizioa1.y - posizioa2.y < dragoiarenHeina && posizioa1.y - posizioa2.y > -dragoiarenHeina)
	{
		baldintza = 1;
	}

	if (posizioa1.x - posizioa2.x < 2 && posizioa1.x - posizioa2.x > -2 && posizioa1.y - posizioa2.y < 2 && posizioa1.y - posizioa2.y > -2)
	{
		baldintza = 0;
	}

	return baldintza;
}

ELEMENTUA suaFuntzioak1(ELEMENTUA sua1, ELEMENTUA enemigo, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa1, sua1.posizioa, bolaBotata1) == 0)
	{
		sua1.posizioa = enemigo.posizioa;
		bolarenDirekzioa1 = jokalaria.posizioa;
	}
	else
	{
		sua1.posizioa = jarraituBola(bolarenDirekzioa1, sua1.posizioa);
	}

	return sua1;
}

ELEMENTUA suaFuntzioak2(ELEMENTUA sua2, ELEMENTUA enemigo1, ELEMENTUA jokalaria)
{
	if (suaBotata(bolarenDirekzioa2, sua2.posizioa, bolaBotata2) == 0)
	{
		sua2.posizioa = enemigo1.posizioa;
		bolarenDirekzioa2 = jokalaria.posizioa;
	}
	else
	{
		sua2.posizioa = jarraituBola(bolarenDirekzioa2, sua2.posizioa);
	}

	return sua2;
}

