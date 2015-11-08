//Kelly Honsinger
#include "cImageTextures.h"
cImageTextures::cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)
{
	imageTexture= tempTexture;
	imageRenderer = tempRenderer;

}

cImageTextures::cImageTextures(cImageTextures & imgCpy)
{
	imageTexture = nullptr;
	imageRenderer = nullptr;
}

cImageTextures& cImageTextures::operator=(cImageTextures& imgCPY)
{
	return *this;
}

cImageTextures::~cImageTextures()
{
}

void cImageTextures::Render()
{						
	SDL_RenderClear(imageRenderer);
		
	//SDL_RenderCopy(RENDERER, Texture your loading from, rectangle you 
	//are drawing from, rectangle your drawing to)
	SDL_RenderCopy(imageRenderer, imageTexture, nullptr, nullptr);
	SDL_RenderPresent(imageRenderer);
	SDL_Delay(time);
}

