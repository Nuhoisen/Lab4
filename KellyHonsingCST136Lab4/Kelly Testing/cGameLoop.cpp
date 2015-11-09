//Kelly Honsinger

#include <iostream>
#include <SDL.h>
#include "cGameLoop.h"
using std::cout;
using std::cin;

cGameLoop::cGameLoop(char *argv[], int argc)
{
	files = new string[argc];
	for (int count = 0; count < argc; count++)
	{
		files[count] = argv[count];
	}
	index = 0;
}
cGameLoop::cGameLoop()
{
	files = nullptr;
	
}
cGameLoop::cGameLoop(cGameLoop & copy)
{
	image = copy.image;
}

cGameLoop & cGameLoop::operator=(cGameLoop & copy)
{
	image = copy.image;
	return *this;
}

cGameLoop::~cGameLoop()
{
	
	delete image;
	delete[] files;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		delete[] renderObject[i];
}


void cGameLoop::BeginGame()
{
	do {
		if (!this->Init(files))
		{
			cout << "Initialization Failed\n";
		}
		else {
			if (!this->LoadMedia(files))
			{
				cout << "failed to load";
			}
			else
			{
				for (int i = 0; i < IMAGE_TOTAL; i++)
				{
					renderObject[i] = new cImageTextures(TextureGetter(i), RendererGetter());
				}
				renderObject[4] = new cSpriteTextures(TextureGetter(4), RendererGetter());
				
				this->AutoGameLoop();

				this->ControlledGameLoop();
			}
			this->Close();
		}
	} while (this->Retry());
}



void cGameLoop::AutoGameLoop()
{
	//bool checks if application is running
	bool quit = false;

	
	//render sprites  
	for (int i = 0; i < IMAGE_TOTAL; i++)
	{
		renderObject[i]->Render();
			
	}
	
	renderObject[IMAGE_TOTAL]->Render();
	renderObject[IMAGE_TOTAL]->Render();
	
}


void cGameLoop::ControlledGameLoop()
{
	SDL_Event loop;
	bool quit = false;
	renderObject[index]->Render();
	while (!quit)
	{
		while (SDL_PollEvent(&loop) != 0)
		{
			if (loop.type == SDL_KEYDOWN && index <= IMAGE_FIRST)
			{
				index = IMAGE_FIRST;
				switch (loop.key.keysym.sym)
				{
				case SDLK_RIGHT:
					index++;
					break;
				case SDLK_LEFT:
					break;
				default:
					break;
				}
			}
			else if (loop.type == SDL_KEYDOWN && index >= IMAGE_FOURTH)
			{
				index = IMAGE_FOURTH;
				switch (loop.key.keysym.sym)
				{
				case SDLK_RIGHT:
					break;
				case SDLK_LEFT:
					index--;
					break;
				default:
					break;
				}
			}
			else if (loop.type == SDL_KEYDOWN)
			{
				switch (loop.key.keysym.sym)
				{
				case SDLK_RIGHT:
					index++;
					break;
				case SDLK_LEFT:
					index--;
					break;
				default:
					break;
				}
			}
			else if (loop.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		renderObject[index]->Render();
	}
}

	



bool cGameLoop::Retry()
{
	bool again = true;
	char answer = 'x';
	while (answer != 'N')
	{
		while (answer != 'Y')
		{
			cout << "would you like to go again(y/n)?";
			cin >> answer;
			answer = toupper(answer);
			if (answer == 'N')
			{
				again = false;
				return again;
			}
			else if (answer == 'Y')
			{
				return again;
			}
		}
	}
}