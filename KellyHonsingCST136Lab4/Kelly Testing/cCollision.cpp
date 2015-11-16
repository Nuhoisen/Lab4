#include "cCollisionObj.h"



cCollisionObj::cCollisionObj(SDL_Texture *tempTexture, SDL_Renderer * tempRenderer)
{
	mDotTexture = tempTexture;
	mCollisionRenderer = tempRenderer;

	mDotPosX = 0;
	mDotPosY = 0;

	mDotVelX = 0;
	mDotVelY = 0;

	mDotDimensions.h = DOT_HEIGHT;
	mDotDimensions.w = DOT_WIDTH;

	mRectCoordinates.x = SCREEN_WIDTH / 2;
	mRectCoordinates.y = SCREEN_WIDTH / 2;
	mRectCoordinates.h = 100;
	mRectCoordinates.w = 100;
}

cCollisionObj::~cCollisionObj()
{
	SDL_DestroyRenderer(mCollisionRenderer);
	mCollisionRenderer = nullptr;
	SDL_DestroyTexture(mDotTexture);
	mDotTexture = nullptr;
	mRectCoordinates.h = 0;
	mRectCoordinates.w = 0;
	mRectCoordinates.x = 0;
	mRectCoordinates.y = 0;

	mDotDimensions.h = 0;
	mDotDimensions.w = 0;
	mDotDimensions.x = 0;
	mDotDimensions.y = 0;
}


void cCollisionObj::Start()
{
	SDL_Event collisionEvent;
	bool quit = false;


	while (!quit)
	{

		while (SDL_PollEvent(&collisionEvent) != 0)
		{

			if (collisionEvent.type == SDL_QUIT)
			{
				quit = true;
			}
			this->HandleEvent(collisionEvent);
			this->Move();
		}
		this->RenderColliders();
	}
}


void cCollisionObj::HandleEvent(SDL_Event& collideEvent)
{

	if (collideEvent.type == SDL_KEYDOWN && collideEvent.key.repeat == 0)
	{

		switch (collideEvent.key.keysym.sym)
		{
		case SDLK_UP:
			mDotVelY -= DOT_VELOCITY;
			break;
		case SDLK_DOWN:
			mDotVelY += DOT_VELOCITY;
			break;
		case SDLK_LEFT:
			mDotVelX -= DOT_VELOCITY;
			break;
		case SDLK_RIGHT:
			mDotVelX += DOT_VELOCITY;
			break;
		}
	}

	else if (collideEvent.type == SDL_KEYUP && collideEvent.key.repeat == 0)
	{

		switch (collideEvent.key.keysym.sym)
		{
		case SDLK_UP:
			mDotVelY += DOT_VELOCITY;
			break;
		case SDLK_DOWN:
			mDotVelY -= DOT_VELOCITY;
			break;
		case SDLK_LEFT:
			mDotVelX += DOT_VELOCITY;
			break;
		case SDLK_RIGHT:
			mDotVelX -= DOT_VELOCITY;
			break;
		}
	}
}


void cCollisionObj::Move()
{

	mDotPosX += mDotVelX;
	mDotDimensions.x = mDotPosX;


	if ((mDotPosX < 0) || (mDotPosX + DOT_WIDTH > SCREEN_WIDTH) || CheckCollision())
	{

		mDotPosX -= mDotVelX;
		mDotDimensions.x = mDotPosX;
	}

	mDotPosY += mDotVelY;
	mDotDimensions.y = mDotPosY;


	if ((mDotPosY < 0) || (mDotPosY + DOT_HEIGHT > SCREEN_HEIGHT) || CheckCollision())
	{

		mDotPosY -= mDotVelY;
		mDotDimensions.y = mDotPosY;
	}
}





bool cCollisionObj::CheckCollision()
{

	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;


	leftA = mDotDimensions.x;
	rightA = mDotDimensions.x + mDotDimensions.w;
	topA = mDotDimensions.y;
	bottomA = mDotDimensions.y + mDotDimensions.h;


	leftB = mRectCoordinates.x;
	rightB = mRectCoordinates.x + mRectCoordinates.w;
	topB = mRectCoordinates.y;
	bottomB = mRectCoordinates.y + mRectCoordinates.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}

void cCollisionObj::RenderColliders()
{

	SDL_SetRenderDrawColor(mCollisionRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(mCollisionRenderer);
	SDL_SetRenderDrawColor(mCollisionRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(mCollisionRenderer, &mRectCoordinates);

	SDL_Rect renderQuad = { mDotPosX, mDotPosY, DOT_WIDTH, DOT_WIDTH };

	SDL_RenderCopy(mCollisionRenderer, mDotTexture, nullptr, &renderQuad);
	SDL_RenderPresent(mCollisionRenderer);
}

