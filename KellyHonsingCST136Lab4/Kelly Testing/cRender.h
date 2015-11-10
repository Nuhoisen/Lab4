/*Kelly Honsinger
Date Created:10/18/2015
Last Modification Date 11/9/2015
Lab Number: 5
File Name: cRender .h
-----------------------------------------------------------------------------

Class:cRender
	This class is the pure virtual base class.  This contains the pure virtual method:
	Render(), that will be used for derived classes, cImageTextures and cSpriteTextures.
Constructors:NONE

------------------------------------------------------------------------------
Mutators: NONE

Methods:
virtual void Render();
Pure virtual method to be implemented in derived classes
------------------------------------------------------------------------------
*/

#ifndef CRENDER_H
#define CRENDER_H

#include <SDL.h>
#include <SDL_image.h>

class cRender
{
public:
	virtual void Render() = 0;	//initialize it to 0 because cRender Doesnt have direct function implementation
};
#endif