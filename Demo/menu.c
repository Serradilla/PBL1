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
#include <SDL_ttf.h> 
#include "definizioak.h"
#include "menu.h"
#include "definizioak.h"
//-----------------------------------------------------------------------
#define START "START"
#define SETTINGS "SETTINGS"
#define LOGO ".\\img\\logo.bmp"
#define COPYRIGHT "2019 - Woodwind TM"
#define STARTX SCREEN_WIDTH*0.43
#define STARTY SCREEN_HEIGHT / 2
#define SETTINGSX SCREEN_WIDTH*0.40
#define SETTINGSY SCREEN_HEIGHT*0.60
#define COPYRIGHTX SCREEN_WIDTH*0.27
#define COPYRIGHTY SCREEN_HEIGHT*0.95

void menuText() {
	pantailaGarbitu();
	textuaIdatzi(STARTX, STARTY, START);
	textuaIdatzi(SETTINGSX, SETTINGSY, SETTINGS);
	textuaIdatzi(COPYRIGHTX, COPYRIGHTY, COPYRIGHT);
	pantailaBerriztu();
}

void menuImages() {
	POSIZIOA start;
	start.x;

	int Id = irudiaKargatu(LOGO);
	irudiaMugitu(Id, SCREEN_WIDTH*0.23, SCREEN_HEIGHT / 8);
	arkatzKoloreaEzarri(255, 255, 255);
	puntuaMarraztu(STARTX - 5, STARTY + 20);
	irudiakMarraztu();
	pantailaBerriztu();
}

int startSakatu() {

	int x, y, sakatu = 0;


	switch (ebentuaJasoGertatuBada()) {

	case SAGU_BOTOIA_EZKERRA:

		SDL_GetMouseState(&x, &y);
		printf("%d", y);
		if ((x > STARTX - 5) && (x < STARTX + 85) && (y > STARTY) && (y < STARTY + 20)) sakatu = 1;

		break;

	default:
		break;
	}


	return sakatu;
}