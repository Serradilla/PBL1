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
POSIZIOA bolarenDirekzioa1 = { 50, 400 };
POSIZIOA bolarenDirekzioa2 = { 50, 400 };

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

POSIZIOA jarraituBola(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	double x, y;
	double alpha;

	x = posizioa1.x - posizioa2.x;
	y = posizioa1.y - posizioa2.y;

	alpha = atan2(y, x);

	posizioa2.x = posizioa2.x + cos(alpha) * 3;
	posizioa2.y = posizioa2.y + sin(alpha) * 3;

	return posizioa2;
}

POSIZIOA jarraituLurrean(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	double x;

	x = posizioa1.x - posizioa2.x;

	if (x > 0)
	{
		posizioa2.x = posizioa2.x + 1;
	}
	if (x < 0)
	{
		posizioa2.x = posizioa2.x - 1;
	}

	return posizioa2;
}

int suaBotata(POSIZIOA posizioa1, POSIZIOA posizioa2, int baldintza)
{
	baldintza = 0;

	if (posizioa1.x - posizioa2.x < 150 && posizioa1.x - posizioa2.x > -150 && posizioa1.y - posizioa2.y < 150 && posizioa1.y - posizioa2.y > -150)
	{
		baldintza = 1;
	}

	if (posizioa1.x - posizioa2.x < 2 && posizioa1.x - posizioa2.x > -2 && posizioa1.y - posizioa2.y < 2 && posizioa1.y - posizioa2.y > -2)
	{
		baldintza = 0;
	}

	return baldintza;
}

