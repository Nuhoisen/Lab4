//Kelly Honsinger
#include "cSpriteTextures.h"

/*
...................................................................
cSpriteTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)

Purpose:Class contructor; Initialize the class' private data members.

Entry: SDL_Renderer * imageRenderer;
	SDL_Texture * imageTexture;
	SDL_Rect * imageRect;

Exit: None
...................................................................*/
cSpriteTextures::cSpriteTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)
{
	hWidth = 775;
	hHeight = 586;
	spriteIndex = 0;
	spriteTexture = tempTexture;
	spriteRenderer = tempRenderer;
	mSpriteClips[SPRITE_FIRST] = new SDL_Rect;
	mSpriteClips[SPRITE_FIRST]->x = 0;
	mSpriteClips[SPRITE_FIRST]->y = 0;
	mSpriteClips[SPRITE_FIRST]->w = hWidth;
	mSpriteClips[SPRITE_FIRST]->h = hHeight;
	
	mSpriteClips[SPRITE_SECOND] = new SDL_Rect;
	mSpriteClips[SPRITE_SECOND]->x = hWidth;
	mSpriteClips[SPRITE_SECOND]->y = 0;
	mSpriteClips[SPRITE_SECOND]->w = hWidth;
	mSpriteClips[SPRITE_SECOND]->h = hHeight;
}

/*
...................................................................
cSpriteTextures(cSpriteTextures  & cpy)

Purpose:Copy contructor; Initialize the class' private data members to the passed copy.

Entry : cSpriteTextures  & cpy

Exit : None

...................................................................*/
cSpriteTextures::cSpriteTextures(cSpriteTextures & cpy)
{	
	for (int i = 0; i < SPRITE_TOTAL; i++)
	{
		mSpriteClips[i]=cpy.mSpriteClips[i];
	}
	hHeight = cpy.hHeight;
	hWidth = cpy.hWidth;
}

/*
...................................................................
cSpriteTextures & operator=(cSpriteTextures  & opCopy)

Purpose:assignment contructor; Initialize the class' private data members to the passed copy.

Entry : cSpriteTextures & opCopy; copy object to initialize to.

Exit : invoked object
...................................................................*/
cSpriteTextures & cSpriteTextures ::operator=(cSpriteTextures & opCopy)
{
	for (int i = 0; i < SPRITE_TOTAL; i++)
	{
		mSpriteClips[i]= opCopy.mSpriteClips[i];
	}
	hHeight = opCopy.hHeight;
	hWidth = opCopy.hWidth;
	return *this;
}

/*
...................................................................
~cSpriteTextures()

Purpose:destructor; Deletes all dynamically allocated memory and sets pointers to null.

Entry: None

Exit: none
...................................................................*/
cSpriteTextures ::~cSpriteTextures()
{	
	for (int i = 0; i <SPRITE_TOTAL; i++)
	{
		delete[] mSpriteClips[i];
		mSpriteClips[i] = nullptr;
	}
	SDL_DestroyTexture(spriteTexture);
	SDL_DestroyRenderer(spriteRenderer);
	spriteTexture = nullptr;
	spriteRenderer = nullptr;
}

/*
...................................................................
void Render()

Purpose:Method that takes the image texture and renderer and prints them to screen.

Entry: None

Exit: none
...................................................................*/
void cSpriteTextures::Render(int i)
{
	SDL_RenderClear(spriteRenderer);	//clear old surface
	SDL_RenderCopy(spriteRenderer, spriteTexture, mSpriteClips[i], nullptr); //copy texture and renderer
	SDL_RenderPresent(spriteRenderer);	//send to screen
	SDL_Delay(TIME);	//delay for certain amount of TIME
		//INCREMENT COUNTER
}




