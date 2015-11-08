//Kelly Honsinger
#include <iostream>
#include <SDL.h>
#include "cGameLoop.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using std::cout;

const int argCount = 10;	//allocate enough memory for objects

int main(int argc, char * argv[])
{
	cGameLoop StartGame(argv, argc);

	StartGame.BeginGame();
	_CrtDumpMemoryLeaks();		//check for memory leaks 
	return 0;
}


