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

#include <SDL.h>

const int TIME = 2;				//delay
const int RENDER_HEIGHT = 480;	//renderer height
const int RENDER_WIDTH = 640;		//renderer width
enum IMAGE_COUNT
{
	IMAGE_FIRST,
	IMAGE_SECOND,
	IMAGE_THIRD,
	IMAGE_FOURTH,
	IMAGE_TOTAL
};

class cImageTextures  
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
	void Render(cImageTextures * image2);
	void CntrlLoopRender();
private: 
	SDL_Renderer * imageRenderer;	//renderer
	SDL_Texture * imageTexture;		//texture

	SDL_Rect * imageRect;			//renderer cliping size

};
#endif
