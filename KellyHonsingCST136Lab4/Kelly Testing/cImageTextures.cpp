//Kelly Honsinger
#include "cImageTextures.h"
cImageTextures::cImageTextures()
{
}

cImageTextures::~cImageTextures()
{
}

cImageTextures::cImageTextures(cImageTextures & imgCpy)
{

}
cImageTextures& cImageTextures::operator=(cImageTextures& imgCPY)
{
	return imgCPY;
}


void cImageTextures::Render(SDL_Texture * tempTexture, SDL_Renderer* tempRenderer, const int tim)
{						
		SDL_RenderClear(tempRenderer);
		
		//SDL_RenderCopy(RENDERER, Texture your loading from, rectangle you are drawing from, rectangle your drawing to)
		SDL_RenderCopy(tempRenderer, tempTexture, nullptr, nullptr);
		SDL_RenderPresent(tempRenderer);
		SDL_Delay(tim);
}

