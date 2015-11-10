/*Kelly Honsinger
Date Created:10/18/2015
Last Modification Date 11/9/2015
Lab Number: 5
File Name: cImageTextures.h
-----------------------------------------------------------------------------

Class:cImageTextures
	Child class of cRender. Will be instantiated and implemented
Constructors:
cImageTextures();	default	constructor:
{
SDL_Renderer * imageRenderer;
SDL_Texture * imageTexture;
const int TIME = 2;
SDL_Rect * imageRect;
const int RENDERHEIGHT = 480;
const int RENDERWIDTH= 640;
}
cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer);  //Constructor
cImageTextures(cImageTextures & imgCpy);  //CopyConstructor

cImageTextures& operator=(cImageTextures & imgCPY);  //Assignment Operator

virtual ~cImageTextures();   //Destructor

------------------------------------------------------------------------------
Mutators: NONE

Methods:
virtual void Render();
	Virtual method that inherits from PVBC: cRender
------------------------------------------------------------------------------
*/

#ifndef CIMAGETEXTURES_H
#define CIMAGETEXTURES_H

#include "cRender.h"

enum IMAGE_COUNT
{
	IMAGE_FIRST,
	IMAGE_SECOND,
	IMAGE_THIRD,
	IMAGE_FOURTH,
	IMAGE_TOTAL
};

class cImageTextures  : public cRender
{
public:
	//Constructors
	cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer);
	cImageTextures(cImageTextures & imgCpy);
	//Assignment Operator
	cImageTextures& operator=(cImageTextures & imgCPY);
	//Destructor
	virtual ~cImageTextures();
	//Render method
	virtual void Render();

private: 
	SDL_Renderer * imageRenderer;	//renderer
	SDL_Texture * imageTexture;		//texture
	const int TIME = 2;				//delay
	SDL_Rect * imageRect;			//renderer cliping size
	const int RENDERHEIGHT = 480;	//renderer height
	const int RENDERWIDTH= 640;		//renderer width
};
#endif
