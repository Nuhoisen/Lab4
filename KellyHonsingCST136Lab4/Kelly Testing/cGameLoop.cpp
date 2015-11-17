//Kelly Honsinger
#include "cGameLoop.h"

/*
...................................................................
cGameLoop(char *argv[], int argc)

Purpose:Class contructor; Initialize the class' private data members.

Entry: char *argv[], int argc

Exit: None
...................................................................*/
cGameLoop::cGameLoop(char *argv[], int argc)
{
	files = new string[argc];
	for (int count = 0; count < argc; count++)
	{
		files[count] = argv[count];
	}
	surfaceObject = new cSurfMan;
	index = 0;
}

/*
...................................................................
cGameLoop()

Purpose:contructor; Initialize the class' private data members.

Entry : None

Exit : None
...................................................................*/
cGameLoop::cGameLoop()
{
	files = nullptr;
	image[IMAGE_TOTAL] = nullptr;

	index = 0;	
}

/*
...................................................................
cGameLoop(cGameLoop & copy)

Purpose:Copy contructor; Initialize the class' private data members to the passed copy.

Entry : cGameLoop & copy

Exit : None
...................................................................*/
cGameLoop::cGameLoop(cGameLoop & copy)
{
	files = copy.files;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		image[i] = copy.image[i];
	index = copy.index;
}

/*
...................................................................
cGameLoop & operator=(cGameLoop &copy);

Purpose:assignment contructor; Initialize the class' private data members to the passed copy.

Entry : cGameLoop & copy; copy object to initialize to.

Exit : invoked object
...................................................................*/
cGameLoop & cGameLoop::operator=(cGameLoop & copy)
{
	files = copy.files;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		image[i]=copy.image[i];
	index = copy.index;

	return *this;
}

/*
...................................................................
~cGameLoop()

Purpose:destructor; Deletes all dynamically allocated memory and sets pointers to null.

Entry : None

Exit : None
...................................................................*/
cGameLoop::~cGameLoop()
{	
	delete[] files;
	files = nullptr;
	index = 0;
	delete surfaceObject;
	surfaceObject = nullptr;
}

/*
...................................................................
void BeginGame()

Purpose:Iniates Game; Calls all methods in the game and creates a pvbc object to hold derived objects.

Entry : None

Exit : None
...................................................................*/
void cGameLoop::BeginGame()
{
	do {
		if (!surfaceObject->Init(files))
		{
			cout << "Initialization Failed\n";
		}
		else {
			if (!surfaceObject->LoadMedia(files))
			{
				cout << "failed to load";
			}
			else
			{
				
				int imageIndex = 0;
				for (int i = 2; i < (IMAGE_TOTAL+2); i++)
				{
					image[imageIndex]=new cImageTextures(surfaceObject->TextureGetter(i), surfaceObject->RendererGetter());
					imageIndex++;
				}	
				
				collidingObj = new cCollisionObj(surfaceObject->TextureGetter(0), surfaceObject->RendererGetter());
				
				this->AutoGameLoop();

				this->ControlledGameLoop();
			}
			surfaceObject->Close();
			for (int i = 0; i < IMAGE_TOTAL; i++)	
			{
				delete[] image[i];
				image[i] = nullptr;
			}			
			delete collidingObj;
			collidingObj = nullptr;			
		}
	} while (this->Retry());
}

/*
...................................................................
void AutoGameLoop()

Purpose:First Game Loop; Starts automatic display of images.

Entry : None

Exit : None
...................................................................*/
void cGameLoop::AutoGameLoop()
{
	bool quit = false;
	collidingObj->Start(surfaceObject->TextureGetter(1));
	for (int i = 0; i < IMAGE_FOURTH; i++)
		{
			image[i]->Render(image[i+1]);		//render sprites  
		}
}
/*
...................................................................
void ControlledGameLoop()

Purpose:Second Game Loop; Starts user controlled display of images.
The user can controll the images using the arrow right and arrow left keys.

Entry : None

Exit : None
...................................................................*/
void cGameLoop::ControlledGameLoop()
{
	SDL_Event loop;
	bool quit = false;
	image[index]->CntrlLoopRender();		//display first image in the array
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
		image[index]->CntrlLoopRender();
	}
}

/*
...................................................................
bool Retry()

Purpose:Method that prompts the user if they want to go again

Entry : None

Exit : bool again;  if true the game will run again; otherwise it will stop
...................................................................*/
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