#include "cInitialize.h"



cInitialize::cInitialize()
{
	surface = nullptr;
}


cInitialize::~cInitialize()
{
}

void cInitialize::beginGame(string * fileName)
{
	surface->Init(fileName);
	surface->LoadMedia(SDL_Texture * imageArray[IMAGE_TOTAL], string * fileName)
}


