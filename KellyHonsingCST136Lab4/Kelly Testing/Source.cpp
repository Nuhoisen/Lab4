//Kelly Honsinger
#include <iostream>
#include <SDL.h>
#include "cMainGame.h"
#include "cSpriteGameLoop.h"

using std::cout;

const int argCount = 10;	//allocate enough memory for objects

int main(int argc, char * argv[])
{
	cSpriteGameLoop  Sprites;
	cImageTextures Images;
	cMainGame Loop;

	SDL_Texture * mainSurface[IMAGE_TOTAL];

	if (!Images.Init(argv))
	{
		cout << "failed to initialize...";
	}
	else
	{
		if (!Images.LoadMedia(mainSurface, argv))
		{
			cout << "failed to load.";
		} 
		
	}

	bool again = false;		//initializes the first few objects of array; it doesnt allocate the last one
	do{						//do loop triggers again when 'Retry()' function returns true
		Loop.GameLoop(mainSurface, Sprites, Images);
		Images.Close(mainSurface);
		again = Images.Retry();

	} while (again == true);	
	
	return 0;
}


