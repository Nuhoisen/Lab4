//Kelly Honsinger
#include <iostream>
#include <SDL.h>
#include "cSurfMan.h"
#include "cSpriteGameLoop.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using std::cout;

const int argCount = 10;	//allocate enough memory for objects

int main(int argc, char * argv[])
{
	cSurfMan mainSurf(argv, argc);

	mainSurf.beginGame();
	_CrtDumpMemoryLeaks();		//check for memory leaks 
	return 0;
}


