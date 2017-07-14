/*
 * LTexture.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "LTexture.h"

LTexture::LTexture(int _x, int _y)
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	x = _x;
	y = _y;
}
LTexture::~LTexture()
{
	Free();
}

int LTexture::getHeight() const
{
	return mHeight;
}

void LTexture::setHeight(int height)
{
	this->mHeight = height;
}

int LTexture::getWidth() const
{
	return mWidth;
}

void LTexture::setWidth(int width)
{
	this->mWidth = width;
}

void LTexture::setX(int x)
{
	this->x = x;
}
void LTexture::setY(int y)
{
	this->y = y;
}

int LTexture::getX() const
{
	return x;
}

int LTexture::getY() const
{
	return y;
}

void LTexture::render(SDL_Renderer* gRenderer, SDL_Rect* clip, double angle)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w / 2;
		renderQuad.h = clip->h / 2;
	}

	//Render to screen
	SDL_RenderCopyEx(Background::gRenderer, mTexture, clip, &renderQuad, angle,
			NULL, SDL_FLIP_NONE);
	SDL_RenderPresent(Background::gRenderer);
}

void LTexture::Free()
{
	//SDL_RenderClear(Background::gRenderer);
	if (mTexture)
	{
		SDL_DestroyTexture(mTexture);
		mWidth = 0;
		mHeight = 0;
		IMG_Quit();
		mTexture = NULL;
		SDL_RenderPresent(Background::gRenderer);

	}
}

bool LTexture::loadFromFile(SDL_Renderer* gRenderer, std::string path)
{

	Free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
				IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0, 0xff, 0xff));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;

}

void LTexture::setPosition(int _x, int _y)
{
	this->x = _x;
	this->x = _y;
}

void LTexture::Show()
{
	SDL_RenderCopy(Background::gRenderer, mTexture, NULL, NULL);
	SDL_RenderPresent(Background::gRenderer);
}
