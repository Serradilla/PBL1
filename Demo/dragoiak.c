#include "imagen.h"
#include "definizioak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "sua.h"

#include <stdio.h>
#include <windows.h>
#include <math.h>


int heganEgingoDu1 = 1;
int heganEgingoDu2 = 1;
int dragoienArtekoDistantzia = 50;

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

	return enemigo1;
}