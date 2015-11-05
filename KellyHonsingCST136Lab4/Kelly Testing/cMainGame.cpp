//Kelly Honsinger
#include "cMainGame.h"
#include <iostream>
#include <SDL.h>

using std::cout;
using std::cin;

cMainGame::cMainGame() 
{
	sprite = nullptr;
	image = nullptr;
	sprite = new cSpriteGameLoop;
	image = new cImageTextures;
}

cMainGame::~cMainGame() 
{
	delete sprite;
	delete image;
}

cMainGame::cMainGame(cMainGame & copy)
{
	sprite = copy.sprite;
	image = copy.image;
}

cMainGame & cMainGame::operator=(cMainGame & copy)
{
	sprite = copy.sprite;
	image = copy.image;
	return copy;
}

void cMainGame::GameLoop( SDL_Texture * mainSurface[IMAGE_TOTAL],
	SDL_Renderer * mainRender)
{
	//bool checks if application is running
	bool quit = false;

	
	//render sprites
	for (int i = 1; i < IMAGE_TOTAL; i++)
	{
		image->Render(mainSurface[i], mainRender, TIME);
	}

	sprite->SpriteRender( sprite->ReturnRect(),  mainSurface[IMAGE_TOTAL], 
		mainRender, TIME);
	sprite->SpriteRender( sprite->ReturnRect1(), mainSurface[IMAGE_TOTAL],
		mainRender, TIME);
}
