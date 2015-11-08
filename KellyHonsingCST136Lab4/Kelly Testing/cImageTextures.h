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
the .png images to textures.They are then rendered to the screen.  
The last two images are sprites on one .png image.This image is converted
to a texture and then partially rendered once to display the first
part of it, and then again once more to display the second part of it.
...................................................................
DECLARATIONS
------------
cKeyBoard()

Purpose:Class contructor; Initialize the class' private data members.

Entry: None

Exit: Set it all to NULL

...................................................................
~cKeyBoard()

Purpose:Class destructor.

Entry: None

Exit: None

...................................................................

cImageTextures(cImageTextures & imgCpy)

Purpose:Copy Constructor. (Here to follow OCCF)

Entry: copy class object is passed by reference.

Exit: None. There are no data members

...................................................................
cImageTextures& operator=(cImageTextures& imgCPY)

Purpose:Assignment Operator. (Here to follow OCCF)

Entry: copy class object is passed by reference.

Exit: None. There are no data members.

...................................................................

void Render(SDL_Texture *tempTexture,  const int tim)

Purpose: This method is copys the texture to the render and then presents 
it to screen.

Entry:  SDL_Texture *tempTexture: Texture that was orignally .png image. 
Its dimensions are set to be rendered.
const int tim: const int represents time to present the textures to the
screen. In this case it's half a second

Exit: Nothing is returned

...................................................................
*/

#ifndef CIMAGETEXTURES_H
#define CIMAGETEXTURES_H
#include <SDL.h>
#include <SDL_image.h>
#include "cRender.h"
class cImageTextures  : public cRender
{
public:
	//Constructors
	cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer);
	cImageTextures(cImageTextures & imgCpy);
	//Assignment Operator
	cImageTextures& operator=(cImageTextures& imgCPY);
	//Destructor
	virtual ~cImageTextures();
	//Render method
	virtual void Render();

private: 
	SDL_Renderer * imageRenderer;
	SDL_Texture * imageTexture;
	const int time = 500;
};
#endif
