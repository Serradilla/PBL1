#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include <stdio.h>
#include <windows.h>
#include <math.h>


POSIZIOA jarraitu(POSIZIOA posizioa1, POSIZIOA posizioa2)
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

POSIZIOA saltoEgin(POSIZIOA posizioa, int dy)
{
	posizioa.y = posizioa.y + dy;

	return posizioa;
}

int bukatuDa(POSIZIOA posizioa, POSIZIOA hasieran, int dy)
{
	int baldintza = 0;

	if (posizioa.y == hasieran.y)
	{
		baldintza = 1;
	}

	return baldintza;
}

POSIZIOA enemyMovement(POSIZIOA posizioa1, POSIZIOA posizioa2)
{
	int saltoEginda = 1, dy = -10;
	POSIZIOA  jarr, hasierakoPos = posizioa2;

	jarr = jarraitu(posizioa1, posizioa2);



	if ((posizioa1.x - posizioa2.x > 50 || posizioa1.x - posizioa2.x < -50 || posizioa1.y - posizioa2.y > 50 || posizioa1.y - posizioa2.y < -50) && saltoEginda == 1)
	{
		posizioa2 = jarr;
		hasierakoPos = posizioa2;
	}
	else
	{
		saltoEginda = 0;
		posizioa2 = saltoEgin(posizioa2, dy);
		saltoEginda = bukatuDa(posizioa2, hasierakoPos, dy);
		dy = dy + 1;

		if (saltoEginda == 1)
		{
			dy = -10;
		}
	}

	return posizioa2;
}