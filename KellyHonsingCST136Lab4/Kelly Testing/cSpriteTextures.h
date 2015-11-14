/*Kelly Honsinger
Date Created:10/18/2015
Last Modification Date 11/9/2015
Lab Number: 5
File Name: cSpriteTextures .h
-----------------------------------------------------------------------------

Class:cSpriteTextures 
	Child class inheriting from cRender.  Will be instantiated and implemented.
Constructors:
cSpriteTextures ();	default	constructor:
{
SDL_Rect * mSpriteClips[SPRITE_TOTAL];
int hWidth;
int hHeight;
SDL_Texture * spriteTexture;
SDL_Renderer * spriteRenderer;
int spriteIndex;
}
cSpriteTextures (SDL_Texture * tempTexture, SDL_Renderer * tempRenderer);  //Constructor

cSpriteTextures (cSpriteTextures  & imgCpy);  //CopyConstructor

cSpriteTextures & operator=(cSpriteTextures  & imgCPY);  //Assignment Operator

virtual ~cSpriteTextures ();   //Destructor

------------------------------------------------------------------------------
Mutators: NONE
------------------------------------------------------------------------------
Methods:
	virtual void Render();
		Virtual method that inherits from PVBC: cRender
------------------------------------------------------------------------------
*/

#ifndef CSPRITEGAMELOOP_H
#define CSPRITEGAMELOOP_H

#include <SDL.h>

//ENUM
enum SPRITE_COUNT	//keeps count of sprites
{
	SPRITE_FIRST,
	SPRITE_SECOND,
	SPRITE_TOTAL
};

class cSpriteTextures 
{
public:
	//Constructors:
	cSpriteTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer);
	cSpriteTextures(cSpriteTextures  & cpy);				//copy constructor
	cSpriteTextures  & operator=(cSpriteTextures  & opCopy);//Assignment Operator
	virtual ~cSpriteTextures();								//Destructor
	//METHODS
	void Render(int i);									//Sprite render method

private:
	SDL_Rect * mSpriteClips[SPRITE_TOTAL];	//array of *SDL_Rects that contains dimensions of sprites
	int hWidth;								//sprite image width
	int hHeight;							//image height
	SDL_Texture * spriteTexture;			//Texture containing image
	SDL_Renderer * spriteRenderer;			//renderer that renders image
	const int TIME = 500;					//delay on rendering 
	int spriteIndex;						//index which determines which sprite will be displayed
};
#endif
