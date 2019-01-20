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
#define DEATH ".\\img\\death.bmp"
#define GAMEOVER "game over"
#define OVERX SCREEN_WIDTH*0.37
#define OVERY SCREEN_HEIGHT*0.63
#define RETRY "RETRY"
#define RETRYX SCREEN_WIDTH*0.41
#define RETRYY SCREEN_HEIGHT*0.75
#define MENU "MAIN MENU"
#define MENUX SCREEN_WIDTH*0.36
#define MENUY SCREEN_HEIGHT*0.81
#define EXIT "EXIT"
#define EXITX SCREEN_WIDTH*0.42
#define EXITY SCREEN_HEIGHT*0.87


int deathScreen() {

	int sakatu = 0, sakatu1 = 0, sakatu2 = 0, ret = 0;
	ELEMENTUA death;

	pantailaGarbitu();
	death.Id = irudiaKargatu(DEATH);
	irudiaMugitu(death.Id, 0, 0);

	textuaIdatzi(OVERX, OVERY, GAMEOVER);
	textuaIdatzi(RETRYX, RETRYY, RETRY);
	textuaIdatzi(MENUX, MENUY, MENU);
	textuaIdatzi(EXITX, EXITY, EXIT);

	irudiakMarraztu();
	pantailaBerriztu();

	while ((sakatu == 0) && (sakatu1 == 0) && (sakatu2 == 0)) {
		if (sakatu = clickaBarruanDago(RETRYX, RETRYY, RETRYX + 85, RETRYY + 20)) {//retry button
			irudiaKendu(death.Id);
			ret = 0;
			sakatu = 1;

		}
		if (sakatu1 = clickaBarruanDago(MENUX, MENUY, MENUX + 150, MENUY + 20)) {//menu button
			ret = 1;
			irudiaKendu(death.Id);
			sakatu1 = 1;
		}
		if (sakatu2 = clickaBarruanDago(EXITX, EXITY, EXITX + 70, EXITY + 20)) {//exit button
			ret = 2;
			irudiaKendu(death.Id);
			sakatu2 = 1;
		}
	}

	audioTerminate();
	pantailaBerriztu();

	return ret;
}