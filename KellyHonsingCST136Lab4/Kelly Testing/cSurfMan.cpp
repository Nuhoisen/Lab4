//Kelly Honsinger
#include "cSurfMan.h"


cSurfMan::cSurfMan(char * argv[], int argc)
{
	files = new string[argc];
	for (int count = 0; count < argc; count++)
	{
		files[count] = argv[count];
	}
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;
	mRenderer = nullptr;
	mSpriteSheetTexture = nullptr;
	for (int i = 0; i < IMAGE_TOTAL; i++)
	{
		mTexture[i] = nullptr;
	}
	tempGame = new cMainGame();
}


cSurfMan::cSurfMan()
{
	
	files = nullptr;
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;
	mRenderer = nullptr;
	mSpriteSheetTexture = nullptr;
	for (int i = 0; i < IMAGE_TOTAL; i++)
	{
		mTexture[i] = nullptr;
	}
	tempGame=new cMainGame();
	
}

cSurfMan::cSurfMan(cSurfMan & copy)
{
	mRenderer= copy.mRenderer;
	mScreenSurface= copy.mScreenSurface;
	mWindow= copy.mWindow;
	mStretchedSurface= copy.mStretchedSurface;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		mTexture[i]=copy.mTexture[i];
	mSpriteSheetTexture= copy.mSpriteSheetTexture;
	files= copy.files;
	tempGame= copy.tempGame;
}

cSurfMan & cSurfMan::operator=(cSurfMan & copy)
{
	mRenderer = copy.mRenderer;
	mScreenSurface = copy.mScreenSurface;
	mWindow = copy.mWindow;
	mStretchedSurface = copy.mStretchedSurface;
	for (int i = 0; i < IMAGE_TOTAL; i++)
		mTexture[i] = copy.mTexture[i];
	mSpriteSheetTexture = copy.mSpriteSheetTexture;
	files = copy.files;
	tempGame = copy.tempGame;

	return *this;
}


cSurfMan::~cSurfMan() 
{
	delete []files;
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;
	mRenderer = nullptr;
	mSpriteSheetTexture = nullptr;
	
	delete tempGame;
	tempGame = nullptr;
}


void cSurfMan::beginGame()
{
	do {
		if (!this->Init())
		{
			cout << "Initialization Failed\n";
		}
		else {
			if (!this->LoadMedia(mTexture, files))
			{
				cout << "failed to load";
			}
			else
			{
				tempGame->GameLoop(mTexture, mRenderer);
			}
			this->Close();
		}
	} while (this->Retry());
}


bool cSurfMan::Init()
{
	bool pass = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Initialization failure. ERROR: ", SDL_GetError();
		pass = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cout << "Linear Texture Filtering not enabled!";
		}
		 
		mWindow = SDL_CreateWindow(files->c_str(), SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == nullptr)
		{
			cout << "Can't Create Window! SDL ERROR: " << SDL_GetError();
			pass = false;
		}
		else
		{
			mRenderer = SDL_CreateRenderer(mWindow, -1,
				SDL_RENDERER_ACCELERATED);
			if (mRenderer == nullptr)
			{
				cout << "Renderer Failed to be created!";
				pass = false;
			}
			else
			{	
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 
					0xFF, 0xFF);  //RGB Opacity

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout << "SDL_Image couldn't initialize!";
					pass = false;
				}
			}
		}
	}
	return pass;
}


bool cSurfMan::LoadMedia(SDL_Texture *KeySurfaces[IMAGE_TOTAL],
	string * path)
{
	bool success = true;
	
	mTexture[IMAGE_FIRST] = LoadSurface(path[1]); //First image
	if (mTexture[IMAGE_FIRST]
		== nullptr)//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	mTexture[IMAGE_SECOND] = LoadSurface(path[2]);	//Second image
	if (mTexture[IMAGE_SECOND] 
		== nullptr)	//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	mTexture[IMAGE_THIRD] = LoadSurface(path[3]); //Third image
	if (mTexture[IMAGE_THIRD] 
		== nullptr)  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	mTexture[IMAGE_FOURTH] = LoadSurface(path[4]);//Third image
	if (mTexture[IMAGE_FOURTH]
		== nullptr)	//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";	
		success = false;
	}

	mTexture[IMAGE_TOTAL] = Loadtexture(path[5]);	//Fourth image
	if (mTexture[IMAGE_TOTAL]
		== nullptr)	//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}
	
	//bool returns successful 
	return success;
}

SDL_Texture * cSurfMan::Loadtexture(string path)
{
	SDL_Texture * tempTexture = nullptr;

	SDL_Surface* tempSurface = IMG_Load(path.c_str());
	if (tempSurface == nullptr)
	{
		cout << "unable to load image! SDL Error:" << IMG_GetError();
	}
	else
	{
		SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB
			(tempSurface->format, 0, 0xFF, 0xFF));  
		//(format, Red,Green,Blue)

		tempTexture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
		if (tempTexture == nullptr)
		{
			cout << "Unable to Create Texture! SDL Error:" <<
				SDL_GetError();
		}
		
	}
	return tempTexture;
}


SDL_Texture* cSurfMan::LoadSurface(std::string path)
{	
	//Texture 
	SDL_Texture *tempTexture= nullptr;
	//create cSurfMan object to access getter from the class

	

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image, SDL Error: %s\n" << SDL_GetError();
	}
	else
	{
			//Convert surface to texture
			tempTexture = SDL_CreateTextureFromSurface(mRenderer,
				loadedSurface);
			if (tempTexture == nullptr)
			{
				cout << "Unable to create texture from image! SDL Error:"
					<< SDL_GetError();
			}

			//Get rid of old loaded surfaces
			SDL_FreeSurface(loadedSurface);
			loadedSurface = nullptr;
	}
	return tempTexture;
}



void cSurfMan::ConvertSurface(SDL_Surface * CurrentSurface)
{
	SDL_Rect rectMod;
	rectMod.x = 0;
	rectMod.y = 0;
	rectMod.w = WIDTH;
	rectMod.h = HEIGHT;
	SDL_BlitScaled(CurrentSurface, nullptr, mScreenSurface, &rectMod);
	SDL_UpdateWindowSurface(mWindow);
}

bool cSurfMan::Retry()
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

void cSurfMan::Close()
{
	for (int i = 0; i < IMAGE_TOTAL; i++)
	{
		SDL_DestroyTexture(mTexture[i]);
		mTexture[i] = nullptr;
	}
	//destroy window and renderer
	SDL_DestroyRenderer(mRenderer);
	mRenderer = nullptr;
	SDL_FreeSurface(mStretchedSurface);
	mStretchedSurface = nullptr;

	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;

	SDL_Quit(); 
}

SDL_Window * cSurfMan::WindowGetter()
{
	return mWindow;
}

SDL_Renderer * cSurfMan::RendererGetter()
{
	return mRenderer;
}

