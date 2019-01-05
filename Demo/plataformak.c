//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "SDL.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------------
#include "jokua.h"
#include "definizioak.h"
#include "jokalaria.h"
#include "plataformak.h"

ELEMENTUA plataformaFuntzioak(ELEMENTUA plataforma, ELEMENTUA eszenarioa,ELEMENTUA jokalaria) {

	if (eszenarioa.dx == -6) {
		plataforma.dx = -6;
	}
	else if(eszenarioa.dx == 6) {
		plataforma.dx = 6;
	}
	else {
		plataforma.dx = 0;
	}

	return plataforma;

}