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
#define IMAGEX SCREEN_WIDTH*0.25
#define IMAGEY (SCREEN_HEIGHT / 8)
#define STARTX SCREEN_WIDTH*0.43
#define STARTY IMAGEY+175
#define SETTINGSX SCREEN_WIDTH*0.40
#define SETTINGSY IMAGEY+225
#define COPYRIGHTX SCREEN_WIDTH*0.27
#define COPYRIGHTY IMAGEY*0.2



void animation() {
	int tope = (SCREEN_HEIGHT / 8);
	int anim = IMAGEY + SCREEN_HEIGHT;
	int logoid;

	logoid = menuImages(anim);

	do
	{
		pantailaGarbitu();
		anim -= 1;
		irudiaMugitu(logoid, IMAGEX, anim);
		menuText(anim);
		arkatzKoloreaEzarri(255, 255, 255);
		puntuaMarraztu(STARTX, STARTY+35);
		irudiakMarraztu();
		pantailaBerriztu();
	} while (anim != tope);
}

void menuText(int anim) {

	int starty = anim + 190;
	int settingsy = anim + 225;
	int copyrighty = anim + 385;


	textuaIdatzi(STARTX, starty, START);
	textuaIdatzi(SETTINGSX, settingsy, SETTINGS);
	textuaIdatzi(COPYRIGHTX, copyrighty, COPYRIGHT);
}

int menuImages(int anim) {
	int tope = SCREEN_HEIGHT / 8;

	int Id = irudiaKargatu(LOGO);
	irudiaMugitu(Id, IMAGEX, anim);

	irudiakMarraztu();
	pantailaBerriztu();

	return Id;
}

int startSakatu() {

	int x, y, sakatu = 0;


	switch (ebentuaJasoGertatuBada()) {

	case SAGU_BOTOIA_EZKERRA:

		SDL_GetMouseState(&x, &y);
		if ((x > STARTX - 5) && (x < STARTX + 85) && (y > STARTY + 15) && (y < STARTY + 35)) sakatu = 1;

		break;

	default:
		break;
	}

	return sakatu;
}

int clickaBarruanDago(int x1, int y1, int x2, int y2) {
	//	| - - - y1 - -  |
	//	| - - - - - - - |
	//	x1 - - - - - - x2
	//	| - - - - - - - |
	//	| - - - y2 - - -|
	int x, y, sakatu = 0;


	switch (ebentuaJasoGertatuBada()) {

	case SAGU_BOTOIA_EZKERRA:

		SDL_GetMouseState(&x, &y);
		if ((x > x1) && (x < x2) && (y > y1) && (y < y2)) sakatu = 1;

		break;

	default:
		break;
	}

	return sakatu;
}