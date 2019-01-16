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
#include "bizitza.h"

#define BIZITZA0 ".\\img\\0heart.bmp"
#define BIZITZA1 ".\\img\\1heart.bmp"
#define BIZITZA2 ".\\img\\2heart.bmp"
#define BIZITZA3 ".\\img\\3heart.bmp"
#define BIZITZA4 ".\\img\\4heart.bmp"
#define BIZITZA5 ".\\img\\5heart.bmp"
#define BIZITZA6 ".\\img\\6heart.bmp"

ELEMENTUA bizitzaFuntzioak(ELEMENTUA bizitza, ELEMENTUA jokalaria) {

	switch (jokalaria.bizitza) {

	case 0:

		bizitza = Egoera0(bizitza);

		break;

	case 1:

		bizitza = Egoera1(bizitza);

		break;

	case 2:

		bizitza = Egoera2(bizitza);

		break;

	case 3:

		bizitza = Egoera3(bizitza);

		break;

	case 4:

		bizitza = Egoera4(bizitza);

		break;

	case 5:

		bizitza = Egoera5(bizitza);

		break;

	case 6:

		bizitza = Egoera6(bizitza);

		break;

	}
	return bizitza;
}

ELEMENTUA Egoera0(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA0);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}

ELEMENTUA Egoera1(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA1);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}

ELEMENTUA Egoera2(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA2);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}

ELEMENTUA Egoera3(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA3);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}

ELEMENTUA Egoera4(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA4);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}

ELEMENTUA Egoera5(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA5);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}

ELEMENTUA Egoera6(ELEMENTUA bizitza) {

	int Id = -1;

	irudiaKendu(bizitza.Id);
	bizitza.Id = irudiaKargatu(BIZITZA6);
	irudiaMugitu(bizitza.Id, bizitza.posizioa.x, bizitza.posizioa.y);

	return bizitza;
}
