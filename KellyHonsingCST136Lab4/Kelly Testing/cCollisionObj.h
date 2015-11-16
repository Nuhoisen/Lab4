#pragma once

#include <SDL.h>

const int DOT_VELOCITY=5;
const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class cCollisionObj
{
public:
	cCollisionObj(SDL_Texture *tempTexture, SDL_Renderer * tempRenderer);
	~cCollisionObj(); //heey
	void HandleEvent(SDL_Event& collideEvent);
	bool CheckCollision();
	void RenderColliders();
	void Move();
	void Start();

private:
	SDL_Texture * mDotTexture;
	SDL_Rect  mRectCoordinates;
	SDL_Renderer * mCollisionRenderer;
	SDL_Rect  mDotDimensions;
	int mDotVelX, mDotVelY;
	
	int mDotPosX, mDotPosY;
};

