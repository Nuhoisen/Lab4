/*Kelly Honsinger
Date Created:10/18/2015
Last Modification Date 11/9/2015
Lab Number: 5
File Name: cGameLoop.h
-----------------------------------------------------------------------------

Class:cMainGame
	Child class of abstract base class: cSurfMan.  It implements it's functions and uses its data members.
	It's also the class used to start the game from the main.

Constructors: 
	cGameLoop();	default	constructor:
		{
		string * files;
		cRender * renderObject[IMAGE_TOTAL];
		cImageTextures * image;
		cspriteTextures * sprite;
		int index;
		ALL INITIALIZED TO NULL.
		}
	cGameLoop(char *argv[], int argc);		Constructor takes command line arguments
	virtual ~cGameLoop();					virtual destructor
	cGameLoop(cGameLoop &copy);				Copy constructor
	cGameLoop & operator=(cGameLoop &copy);	Assignment Operator

------------------------------------------------------------------------------
Mutators: NONE

Methods:
	void BeginGame();						
		This method iniates the game.
	
	void AutoGameLoop();
		This method iniates the first game loop which is the automatic display of images
	
	void ControlledGameLoop();
		This method iniates the games second loop which is user controlled.
	
	bool Retry();
		This method asks the user if they want to go again
------------------------------------------------------------------------------
*/
#ifndef CMAINGAME_H
#define CMAINGAME_H

#include <SDL.h>
#include <iostream>
#include "cSurfMan.h"
#include "cImageTextures.h"
#include "cSpriteTextures.h"
#include "cCollisionObj.h"
using std::cout;
using std::cin;


class cGameLoop  
{
public: 
	//CONSTRUCTORS
	cGameLoop();							//Constructor Declaration
	cGameLoop(char *argv[], int argc);		//explicitly defined constructor
	~cGameLoop();					//Destructor Declaration
	cGameLoop(cGameLoop &copy);				//copy constructor
	cGameLoop & operator=(cGameLoop &copy);	//Assignment Operator
	//METHODS
	void BeginGame();						
	void AutoGameLoop();
	void ControlledGameLoop();
	bool Retry();
private:
	//Constant time int for rendering time delays
	
	string * files;
	cSurfMan * surfaceObject;
	cImageTextures * image[IMAGE_TOTAL];
	cCollisionObj * collidingObj;
	int index;
};
#endif
