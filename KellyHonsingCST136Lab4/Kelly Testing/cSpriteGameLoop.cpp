//Kelly Honsinger
#include "cSpriteGameLoop.h"
cSpriteGameLoop::cSpriteGameLoop()
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

cSpriteGameLoop::cSpriteGameLoop(cSpriteGameLoop & cpy)
{
	
	for (size_t i = 0; i < 2; i++)
	{
		cpy.mSpriteClips[i] = mSpriteClips[i];
	}
	cpy.hHeight = hHeight;
	cpy.hWidth = hWidth;

}
cSpriteGameLoop& cSpriteGameLoop::operator=(cSpriteGameLoop & opCopy)
{
	for (size_t i = 0; i < 2; i++)
	{
		opCopy.mSpriteClips[i] = mSpriteClips[i];
	}

	opCopy.hWidth= hWidth;
	opCopy.hHeight = hHeight;
	return opCopy;
}
cSpriteGameLoop::~cSpriteGameLoop()
{
	

}


void cSpriteGameLoop::SpriteRender(SDL_Rect* clip, 
	SDL_Texture *tempTexture, SDL_Renderer * tempRenderer,  const int tim)
{
	SDL_RenderClear(tempRenderer);
	SDL_RenderCopy(tempRenderer, tempTexture, clip, nullptr);
	SDL_RenderPresent(tempRenderer);
	SDL_Delay(tim);	
}


SDL_Rect * cSpriteGameLoop::ReturnRect()
{
	return &mSpriteClips[0];
}

SDL_Rect * cSpriteGameLoop::ReturnRect1()
{
	return &mSpriteClips[1];
}
