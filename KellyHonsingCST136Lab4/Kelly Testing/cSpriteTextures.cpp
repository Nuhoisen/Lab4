//Kelly Honsinger
#include "cSpriteTextures.h"
int i = 0;
cSpriteTextures::cSpriteTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)
{
	SpriteTexture = tempTexture;
	SpriteRenderer = tempRenderer;
	mSpriteClips[0] = new SDL_Rect;
	mSpriteClips[0]->x = 0;
	mSpriteClips[0]->y = 0;
	mSpriteClips[0]->w = hWidth;
	mSpriteClips[0]->h = hHeight;
	
	
	mSpriteClips[1] = new SDL_Rect;
	mSpriteClips[1]->x = hWidth;
	mSpriteClips[1]->y = 0;
	mSpriteClips[1]->w = hWidth;
	mSpriteClips[1]->h = hHeight;
}

cSpriteTextures::cSpriteTextures(cSpriteTextures & cpy)
{
	
	for (size_t i = 0; i < 2; i++)
	{
		mSpriteClips[i]=cpy.mSpriteClips[i];
	}
	hHeight= cpy.hHeight;
	hWidth= cpy.hWidth;

}
cSpriteTextures& cSpriteTextures::operator=(cSpriteTextures & opCopy)
{
	for (size_t i = 0; i < 2; i++)
	{
		mSpriteClips[i]= opCopy.mSpriteClips[i];
	}

	hWidth= opCopy.hWidth;
	hHeight= opCopy.hHeight;
	return *this;
}
cSpriteTextures::~cSpriteTextures()
{
	
	for (int i = 0; i < 2; i++)
	{
		delete[] mSpriteClips[i];
	}
	SpriteTexture = nullptr;
	SpriteRenderer = nullptr;
}


void cSpriteTextures::Render()
{
	
	SDL_RenderClear(SpriteRenderer);
	SDL_RenderCopy(SpriteRenderer, SpriteTexture, mSpriteClips[i], nullptr);
	SDL_RenderPresent(SpriteRenderer);
	SDL_Delay(time);
	i++;
}




