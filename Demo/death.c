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


void deathScreen() {

	int sakatu = 0;

	pantailaGarbitu();
	int deathID = irudiaKargatu(DEATH);

	deathID = irudiaKargatu(DEATH);
	irudiaMugitu(deathID, 0, 0);

	textuaIdatzi(OVERX, OVERY, GAMEOVER);
	textuaIdatzi(RETRYX, RETRYY, RETRY);
	textuaIdatzi(MENUX, MENUY, MENU);
	textuaIdatzi(EXITX, EXITY, EXIT);

	arkatzKoloreaEzarri(255, 255, 255);
	puntuaMarraztu(RETRYX+85, RETRYY+20);



	irudiakMarraztu();
	pantailaBerriztu();
}