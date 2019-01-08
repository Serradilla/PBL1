#include "imagen.h"
#include "definizioak.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"

#include <stdio.h>
#include <windows.h>
#include <math.h>

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

