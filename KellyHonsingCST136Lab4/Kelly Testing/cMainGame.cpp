//Kelly Honsinger
#include "cMainGame.h"
#include <iostream>
#include <SDL.h>

using std::cout;
using std::cin;

cMainGame::cMainGame() 
{
}

cMainGame::~cMainGame() 
{

}

void cMainGame::GameLoop( SDL_Texture * mainSurface[IMAGE_TOTAL], SDL_Renderer * mainRender)
{
	//bool checks if application is running
	bool quit = false;

	
	
	//render sprites
	for (int i = 0; i < IMAGE_TOTAL; i++)
	{
		image->Render(mainSurface[i], TIME);
	}

	sprite->SpriteRender( sprite->ReturnRect(), mainSurface[4], TIME);
	sprite->SpriteRender( sprite->ReturnRect1(), mainSurface[4],  TIME);
}
