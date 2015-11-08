//Kelly Honsinger
#include "cSurfMan.h"


cSurfMan::cSurfMan()
{
	
	
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;
	mRenderer = nullptr;
	mSpriteSheetTexture = nullptr;
	for (int i = 0; i < IMAGE_TOTAL; i++)
	{
		mTexture[i] = nullptr;
	}
	
	
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
	
	

	return *this;
}


cSurfMan::~cSurfMan() 
{
	
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;
	mRenderer = nullptr;
	mSpriteSheetTexture = nullptr;
}




bool cSurfMan::Init(string * path)
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
		 
		mWindow = SDL_CreateWindow(path->c_str(), SDL_WINDOWPOS_UNDEFINED,
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


bool cSurfMan::LoadMedia(string * path)
{
	bool success = true;
	int j = 0;
	for (int i = 1; i < IMAGE_TOTAL; i++)
	{
		
		mTexture[j] = LoadSurface(path[i]); //First image
		if (mTexture[j]
			== nullptr)//Checks that the image successfully opened
		{
			cout << "Failed to load image!\n";
			success = false;
		}
		j++;
	}
	mTexture[j] = Loadtexture(path[5]);
	
	//bool returns successful 
	return success;
}


SDL_Texture* cSurfMan::LoadSurface(std::string path)
{	
	//Texture 
	SDL_Texture *tempTexture= nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image, SDL Error: %s\n" << SDL_GetError();
	}
	else
	{
		//Convert surface to texture
		tempTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
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


SDL_Texture * cSurfMan::TextureGetter(int i)
{
	return mTexture[i];		//returns the address of mTexture
}

