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
	mFiles = new string[argc];
	for (int count = 0; count < argc; count++)
	{
		mFiles[count] = argv[count];
	}
	mSurfaceObject = new cSurfMan;
	mIndex = 0;
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
	mFiles = nullptr;
	mImage[IMAGE_TOTAL] = nullptr;

	mIndex = 0;	
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
	mFiles = copy.mFiles;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		mImage[i] = copy.mImage[i];
	mIndex = copy.mIndex;
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
	mFiles = copy.mFiles;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		mImage[i]=copy.mImage[i];
	mIndex = copy.mIndex;

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
	delete[] mFiles;
	mFiles = nullptr;
	delete mSurfaceObject;
	mSurfaceObject = nullptr;
	mIndex = 0;
}

/*
...................................................................
void BeginGame()

Purpose:Iniates Game; Calls all methods and instantiates aggregrate objects from within it.

Entry : None

Exit : None
...................................................................*/
void cGameLoop::BeginGame()
{
	do {
		if (!mSurfaceObject->Init(mFiles))
		{
			cout << "Initialization Failed\n";
		}
		else {
			if (!mSurfaceObject->LoadMedia(mFiles))
			{
				cout << "failed to load";
			}
			else
			{				
				int imageIndex = 0;
				for (int i = PATH_SECOND; i < (PATH_TOTAL); i++)
				{
					mImage[imageIndex]=new cImageTextures(mSurfaceObject->TextureGetter(i), mSurfaceObject->RendererGetter());
					imageIndex++;
				}	
				
				mCollidingObj = new cCollisionObj(mSurfaceObject->TextureGetter(0), mSurfaceObject->RendererGetter());
				
				this->AutoGameLoop();

				this->ControlledGameLoop();
			}
			mSurfaceObject->Close();
			for (int i = 0; i < IMAGE_TOTAL; i++)	
			{
				delete[] mImage[i];
				mImage[i] = nullptr;
			}			
			delete mCollidingObj;
			mCollidingObj = nullptr;			
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
	
	mCollidingObj->Start(mSurfaceObject->TextureGetter(1));
	
	for (int i = 0; i < IMAGE_FOURTH; i++)
		{
			mImage[i]->Render(mImage[i+1]);		//render sprites  
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
	mImage[mIndex]->CntrlLoopRender();		//display first image in the array
	while (!quit)
	{
		while (SDL_PollEvent(&loop) != 0)
		{
			if (loop.type == SDL_KEYDOWN && mIndex <= IMAGE_FIRST)
			{
				mIndex = IMAGE_FIRST;
				switch (loop.key.keysym.sym)
				{
				case SDLK_RIGHT:
					mIndex++;
					break;
				case SDLK_LEFT:
					break;
				default:
					break;
				}
			}
			else if (loop.type == SDL_KEYDOWN && mIndex >= IMAGE_FOURTH)
			{
				mIndex = IMAGE_FOURTH;
				switch (loop.key.keysym.sym)
				{
				case SDLK_RIGHT:
					break;
				case SDLK_LEFT:
					mIndex--;
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
					mIndex++;
					break;
				case SDLK_LEFT:
					mIndex--;
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
		mImage[mIndex]->CntrlLoopRender();
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