//Kelly Honsinger
#include <iostream>
#include <SDL.h>
#include "cSurfMan.h"
#include "cSpriteGameLoop.h"

using std::cout;

const int argCount = 10;	//allocate enough memory for objects

int main(int argc, char * argv[])
{
	cSurfMan mainSurf(argv, argc);

	mainSurf.beginGame();
	
	return 0;
}


