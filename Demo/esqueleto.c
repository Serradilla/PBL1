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

ELEMENTUA esqueletoFuntzioak(ELEMENTUA esqueleto, ELEMENTUA jokalaria) {
	if (esqueleto.posizioa.x < jokalaria.posizioa.x) {
		esqueleto.dx = 1;
	}
	else if (esqueleto.posizioa.x > jokalaria.posizioa.x) {
		esqueleto.dx = -1;
	}
	else {
		esqueleto.dx = 0;
	}

	return esqueleto;
}