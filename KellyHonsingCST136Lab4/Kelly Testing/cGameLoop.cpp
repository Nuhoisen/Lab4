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
				for (int i = 0; i < IMAGE_TOTAL-1; i++)
				{
					renderObject[i] = new cImageTextures(TextureGetter(i), RendererGetter());
				}
				renderObject[4] = new cSpriteTextures(TextureGetter(4), RendererGetter());
				
				this->AutoGameLoop();
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
	for (int i = 0; i < IMAGE_TOTAL-1; i++)
	{
		renderObject[i]->Render();
			
	}
	
	renderObject[4]->Render();
	renderObject[4]->Render();
	
}


void cGameLoop::ControlledGameLoop()
{
	
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