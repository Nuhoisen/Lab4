//Kelly Honsinger
#include "cSpriteTextures.h"
cSpriteTextures::cSpriteTextures()
{
	
	mSpriteClips[0].x = 0;
	mSpriteClips[0].y = 0;
	mSpriteClips[0].w = hWidth;
	mSpriteClips[0].h = hHeight;

	mSpriteClips[1].x = hWidth;
	mSpriteClips[1].y = 0;
	mSpriteClips[1].w = hWidth;
	mSpriteClips[1].h = hHeight;
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
	

}


void cSpriteTextures::SpriteRender(SDL_Rect* clip,
	SDL_Texture *tempTexture, SDL_Renderer * tempRenderer,  const int tim)
{
	SDL_RenderClear(tempRenderer);
	SDL_RenderCopy(tempRenderer, tempTexture, clip, nullptr);
	SDL_RenderPresent(tempRenderer);
	SDL_Delay(tim);	
}


SDL_Rect * cSpriteTextures::ReturnRect()
{
	return &mSpriteClips[0];
}

SDL_Rect * cSpriteTextures::ReturnRect1()
{
	return &mSpriteClips[1];
}
