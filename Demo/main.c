//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <windows.h>
//---------------------------------------------------------------------------------

#include <stdio.h>
#include "jokua.h"
#include "SDL.h"

int main(int argc, char * str[]) {
	int jarraitu = 0;

	if (sgHasieratu() == -1)
	{
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		return 1;
	}
	textuaGaitu();

	jokoaAurkeztu();

	demohasi();

	jolastu();

	do
	{
		jarraitu = ebentuaJasoGertatuBada();
	} while (jarraitu != TECLA_RETURN);
	sgItxi();
	return 0;
}

