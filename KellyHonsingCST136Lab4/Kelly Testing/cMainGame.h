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
the .png images to textures. They are then rendered to the screen.  The
last two images are sprites on one .png image. This image is converted to 
a texture and then partially rendered once to display the first part of it,
and then again once more to display the second part of it.
...................................................................
DECLARATIONS
------------
cMainGame()

Purpose:Class contructor; Initialize the class' private data members.

Entry: None

Exit: Set it all to NULL

...................................................................
~cMainGame()

Purpose:Class destructor.

Entry: None

Exit: None

...................................................................
void GameLoop(SDL_Texture * mainSurface[IMAGE_TOTAL], cSpriteGameLoop * 
tempSprite, cImageTextures* tempImage)

Purpose: Initates the rendering of either the regurlar images or the
sprites.  It does this by calling their respective functions from its body.

Entry: SDL_Texture * mainSurface[IMAGE_TOTAL]:This is a series of textures
that are passed via the cmd line args. cSpriteGameLoop * tempSprite: 
Contains a sprite object so that the sprite object can call its render 
function. cImageTextures* tempImage: Contains a image object so that the 
image object can call its render function.


Exit: Function returns nothing
*/
#ifndef CMAINGAME_H
#define CMAINGAME_H

#include "cSpriteGameLoop.h"
#include "cImageTextures.h"
#include <SDL.h>
#include <iostream>


/* Class:cMainGame

Constructors:
cTime(): Window, ScreenSurface, and Image are initialized to null.

Methods: */

enum KeyPressSurfaces
{
	IMAGE_DEFAULT,
	IMAGE_FIRST,
	IMAGE_SECOND,
	IMAGE_THIRD,
	IMAGE_FOURTH,
	IMAGE_TOTAL
};

class cMainGame  
{
public: 
	cMainGame();								//Constructor Declaration
	~cMainGame();						//Destructor Declaration
	cMainGame(cMainGame &copy);			//copy constructor
	cMainGame & operator=(cMainGame &copy);		//Assignment Operator
	void GameLoop(SDL_Texture * mainSurface[IMAGE_TOTAL],
		SDL_Renderer * mainRender);

private:
	//Constant time int for rendering time delays
	const int TIME = 500;

	cSpriteGameLoop * sprite;
	cImageTextures * image;

};
#endif
