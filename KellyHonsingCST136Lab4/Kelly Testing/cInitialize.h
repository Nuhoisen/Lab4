#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "cSurfMan.h"
class cInitialize
{
public:
	cInitialize();
	~cInitialize();

	void beginGame(string * fileName);
private: 
	string * fileNames;
	cSurfMan * surface;
	SDL_Texture * imageArray
	
};

#endif
