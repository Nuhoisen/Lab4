//Kelly Honsinger
#include "cImageTextures.h"

/*
...................................................................
cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)

Purpose:Class contructor; Initialize the class' private data members.

Entry: SDL_Texture * tempTexture :initializes object texture.
 SDL_Renderer * tempRenderer :initializes object renderer.

Exit: None
...................................................................*/
cImageTextures::cImageTextures(SDL_Texture * tempTexture, SDL_Renderer * tempRenderer)
{
	imageTexture= tempTexture;
	imageRenderer = tempRenderer;
	imageRect = new SDL_Rect;
	imageRect -> x = 0;
	imageRect -> y = 0;
	imageRect -> w = RENDER_WIDTH;
	imageRect -> h = RENDER_HEIGHT;
}

/*
...................................................................
cImageTextures(cImageTextures & imgCpy)

Purpose:copy contructor; Initialize the class' private data members.

Entry: cImageTextures & imgCpy

Exit: None
...................................................................*/
cImageTextures::cImageTextures(cImageTextures & imgCpy)
{
	imageTexture = imgCpy.imageTexture;
	imageRenderer = imgCpy.imageRenderer;
	imageRect = imgCpy.imageRect;
}

/*
...................................................................
cImageTextures& operator=(cImageTextures& imgCPY)

Purpose:assignment operator; Initialize the class' private data members when equal sign is used.

Entry: cImageTextures& imgCPY; copy object to initialize to.

Exit: Invoking object
...................................................................*/
cImageTextures& cImageTextures::operator=(cImageTextures& imgCPY)
{
	imageTexture = imgCPY.imageTexture;
	imageRenderer = imgCPY.imageRenderer;
	imageRect = imgCPY.imageRect;

	return * this;
}

/*
...................................................................
~cImageTextures()

Purpose:destructor; Deletes all dynamically allocated memory and sets pointers to null.

Entry: None

Exit: none
...................................................................*/
cImageTextures::~cImageTextures()
{
	delete imageRect;
	imageRect = nullptr;
	SDL_DestroyTexture(imageTexture);
	imageTexture = nullptr;
	SDL_DestroyRenderer(imageRenderer);
	imageRenderer = nullptr;
}

/*
...................................................................
void Render()

Purpose:Method that takes the image texture and renderer and prints them to screen.

Entry: None

Exit: none
...................................................................*/
void cImageTextures::Render(cImageTextures * image2)
{
	SDL_Rect * tempRect = imageRect;
	SDL_Rect * temp2Rect = imageRect;													//its okay for the tempRects to be assigned to the same address because they just overwrite their x values with the new index
	for (int i = 0; i <RENDER_WIDTH ; i++)
	{
		(tempRect -> x) = i;
		SDL_RenderClear(imageRenderer);
		SDL_RenderCopy(imageRenderer, imageTexture, nullptr, tempRect);//SDL_RenderCopy(RENDERER, Texture your loading from, rectangle you're drawing from, rectangle you're drawing to)
		
		
		(temp2Rect->x) = (-RENDER_WIDTH + i);											//rect that has coordinants so that the right side of the texture renders first
		SDL_RenderCopy(imageRenderer, image2->imageTexture, nullptr, temp2Rect);		//renders following image using temp2Rects Coordinates 
		SDL_RenderPresent(imageRenderer);												//both images get rendered at the same time
		SDL_Delay(TIME);
	}
}

void cImageTextures::CntrlLoopRender()
{
	
		SDL_RenderClear(imageRenderer);
		SDL_RenderCopy(imageRenderer, imageTexture, nullptr, nullptr);//SDL_RenderCopy(RENDERER, Texture your loading from, rectangle you're drawing from, rectangle you're drawing to)
		SDL_RenderPresent(imageRenderer);
		SDL_Delay(TIME);
}
