/*Author:		Kelly Honsinger
Date Created:	10/28/15
Last Mod Date:	11/2/15
Lab Number:		2
File Name:		CST136L1

Overview:
The purpose of this program is to load a series of .png images from the cmd
line and convert them to textures.  This is done using inheritance and 
derived object classes to represent the images.  There are regular images
and there are sprites. This is the regular image class

Input:
Input includes the command line arguments which take the name of the file 
and pass it to the SDL library functions.

Output:
Output includes the SDL window, the SDL surface, and the image.  The first
4 are generated using typical sdl functions from the sdl library to convert
the .png images to textures. They are then rendered to the screen.  
The last two images are sprites on one .png image. This image is converted
to a texture and then partially rendered once to display the first
part of it, and then again once more to display the second part of it.
...................................................................
DECLARATIONS
------------
cSpriteGameLoop();

Purpose:Class contructor; Initialize the class' private data members.

Entry: None

Exit: Set it all to NULL

...................................................................
cSpriteGameLoop(cSpriteGameLoop & cpy)

Purpose:Copy Constructor

Entry: copy of the object

Exit: returns the same copy 
...................................................................
cSpriteGameLoop & operator=(cSpriteGameLoop & opCopy);

Purpose:Class assignment operator.

Entry: copy of the object

Exit: returns the same copy 

...................................................................

~cMainGame()

Purpose:Class destructor.

Entry: None

Exit: None

...................................................................
void SpriteRender(SDL_Rect* clip, SDL_Texture * tempTexture,  const 
int tim)

Purpose:Renders Images on sprites by cutting the images to their own 
dimensions and then rendering those specific dimensions to the screen.

Entry:SDL_Rect* clip:Clip is an array of a  rect that holds the dimensions 
of a sdl rect SDL_Texture * tempTexture: Texture holds sprite textures 
const int tim: tim is used as a delayed time tracker
Exit: Function returns nothing
*/

#ifndef CSPRITEGAMELOOP_H
#define CSPRITEGAMELOOP_H
#include <SDL.h>
#include <SDL_image.h>
#include "cRender.h"


enum SPRITE_COUNT
{
	SPRITE_FIRST,
	SPRITE_SECOND,
	SPRITE_TOTAL
};


class cSpriteTextures : public cRender
{
public:
	
	//Constructors
	cSpriteTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer);
	cSpriteTextures(cSpriteTextures & cpy);
	//Assignment Operator
	cSpriteTextures & operator=(cSpriteTextures & opCopy);
	//Destructor
	virtual ~cSpriteTextures();
	//Sprite render method
	virtual void Render();
	//Mutators
	
	

private:
	
	SDL_Rect * mSpriteClips[2];
	//counter

	int hWidth;
	int hHeight;
	SDL_Texture * SpriteTexture;
	SDL_Renderer * SpriteRenderer;
	const int time = 500;
	
	int spriteIndex;
};
#endif
