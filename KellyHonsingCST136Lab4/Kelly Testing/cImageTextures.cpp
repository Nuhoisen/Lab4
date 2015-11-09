//Kelly Honsinger
#include "cImageTextures.h"
cImageTextures::cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)
{
	imageTexture= tempTexture;
	imageRenderer = tempRenderer;
	imageRect = new SDL_Rect;
	imageRect->x = 0;
	imageRect->y = 0;
	imageRect->w = 640;
	imageRect->h = 480;
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
	SDL_Rect * tempRect = imageRect;
	for (int i = 640; i > 0; i--)
	{
		(tempRect->x) = i;
		SDL_RenderClear(imageRenderer);

		//SDL_RenderCopy(RENDERER, Texture your loading from, rectangle you 
		//are drawing from, rectangle your drawing to)
		SDL_RenderCopy(imageRenderer, imageTexture, nullptr, tempRect);
		SDL_RenderPresent(imageRenderer);
		SDL_Delay(time);
	}
}

