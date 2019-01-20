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
#include "death.h"

int main(int argc, char * str[]) {
	int jarraitu = 0, sakatu, atera = 0, menu = 0;

	if (sgHasieratu() == -1)
	{
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		return 1;
	}

	textuaGaitu();

	while (menu == 0) {
		menu = jokoaAurkeztu();
		if (menu == 1) {
			atera = 1;
		}
		else(atera = 0);
		while (atera == 0) {
			demohasi();
			jolastu();
			atera = deathScreen();
			if (atera == 2) menu = 1;
		}
	}

	sgItxi();
	return 0;
}