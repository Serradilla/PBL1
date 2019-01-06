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

ELEMENTUA jokalariaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa, ELEMENTUA plataforma1, ELEMENTUA plataforma2) {

	if ((jokalaria.posizioa.x > plataforma1.posizioa.x) && (jokalaria.posizioa.x < plataforma1.posizioa.x + 300)) {
		jokalaria.lurra = plataforma1.posizioa.y - 50;
		printf("en la plataforma1 ");
	}
	else if ((jokalaria.posizioa.x > plataforma2.posizioa.x) && (jokalaria.posizioa.x < plataforma2.posizioa.x + 300)) {
		jokalaria.lurra = plataforma2.posizioa.y - 50;
		printf("en la plataforma2 ");
	}
	else {
		jokalaria.lurra = 400;
	}
	if ((jokalaria.posizioa.y < jokalaria.lurra) && (jokalaria.saltatzen == 0)) {
		jokalaria.dy = 4;
	}
	else if ((jokalaria.posizioa.y == jokalaria.lurra) && (jokalaria.saltatzen == 0)) {
		jokalaria.dy = 0;
	}
	else if ((jokalaria.posizioa.y == 400) && (jokalaria.saltatzen == 0)) {
		jokalaria.dy = 0;
	}


	switch (ebentuaJasoGertatuBada()) {

	case TECLA_RIGHT:

		if (jokalaria.posizioa.x < 601) {
			jokalaria.dx = 3;
		}
		else {
			jokalaria.dx = 0;
		}

		jokalaria.kont = 0;

		jokalaria.ebentua = TECLA_RIGHT;

		break;

	case TECLA_LEFT:

		if (jokalaria.posizioa.x > 10) {
			jokalaria.dx = -3;
		}
		else {
			jokalaria.dx = 0;
		}

		jokalaria.kont = 0;

		jokalaria.ebentua = TECLA_LEFT;

		break;

	case TECLA_SPACE:

 		jokalaria.saltatzen = 1;

		break;

	default:

		if (jokalaria.kont > 9) {

			if (jokalaria.dx > 0)
			{
				jokalaria.dx--;
			}
			else if (jokalaria.dx < 0) {
				jokalaria.dx++;
			}
			else {
				jokalaria.dx = 0;
				jokalaria.ebentua = 0;
			}
		}
		jokalaria.kont++;

		break;
	}

	printf("%d ", jokalaria.saltatzen);

	return jokalaria;

}

ELEMENTUA eszenarioaFuntzioak(ELEMENTUA jokalaria, ELEMENTUA eszenarioa) {

	switch (jokalaria.ebentua) {

	case TECLA_RIGHT:

		if ((jokalaria.posizioa.x > 600) && (eszenarioa.posizioa.x > -340)) {
			eszenarioa.dx = -6;
		}
		else {
			eszenarioa.dx = 0;
		}

		break;

	case TECLA_LEFT:

		if ((jokalaria.posizioa.x < 12) && (eszenarioa.posizioa.x < 0)) {
			eszenarioa.dx = 6;
		}
		else {
			eszenarioa.dx = 0;
		}

		break;


	default:

		eszenarioa.dx = 0;

		break;
	}

	return eszenarioa;
}

ELEMENTUA salto(ELEMENTUA elementua) {

	int grabitatea = 4;

	if ((elementua.dy > -32) && (elementua.dy <= 0)) {
		elementua.dy -= grabitatea;
	}

	else {

		if (elementua.dy == -32) {
			elementua.dy = elementua.dy + 32;
		}

		if (elementua.posizioa.y > elementua.lurra - grabitatea) {
			elementua.saltatzen = 0;
			elementua.dy = 0;
		}
		else {
			elementua.dy += grabitatea;
		}
	}

	return elementua;
}