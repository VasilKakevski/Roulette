/*
 * Background.cpp
 *
 *  Created on: Jul 8, 2017
 *      Author: kakev
 */

#include "Background.h"


SDL_Renderer* Background::gRenderer= NULL;

Background::Background(string title, int width, int height, string path) :
		_title(title), _width(width), _height(height), _path(path)
{
		gWindow = NULL;
		Background::gRenderer = NULL;
	if (false==Init())
		std::cerr<<"cant init sdl";

}


Background::~Background()
{
	Clear();

}

void Background::Clear()
{
	SDL_FreeSurface( loadedSurface );
	SDL_DestroyTexture(Texture);
	loadedSurface=NULL;
	SDL_RenderClear(Background::gRenderer);
	IMG_Quit();
	SDL_Quit();

}

void Background::Show()
{
	SDL_RenderCopy(Background::gRenderer,Texture,NULL,NULL);
	SDL_RenderPresent(Background::gRenderer);
}

bool Background::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO))
		{
			std::cerr << "Failed to initilize\n";
			return false;
		}
	if (IMG_Init (IMG_INIT_PNG)!=IMG_INIT_PNG)
			{
				std::cerr << "Failed to initialized image.\n";
				return false;
			}
	gWindow = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, _width, _height, 0);
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				SDL_DestroyWindow( gWindow );
				gWindow = NULL;
			}
	loadedSurface = IMG_Load(this->_path.c_str());
	Texture= SDL_CreateTextureFromSurface( Background::gRenderer, loadedSurface );
	SDL_RenderCopy(Background::gRenderer,Texture,NULL,NULL);

	if (gWindow == NULL)
	{
		std::cerr << "FAILED to create window";
		return false;
		if (gRenderer == NULL)
			{
				std::cerr << "FAILED TO create Redner";
			}
				if(loadMedia()==false)
				{
					std::cerr<<"failed to load img";
					return false;
				}
	}
	return true;
}



bool Background::loadMedia()
{

	bool success = true;
	//load image to surface
	loadedSurface = IMG_Load( this->_path.c_str());

		if( loadedSurface == NULL )
			{
				std::cerr<< "Unable to load image";
				success = false;
			}

	return success;
}

int Background::getHeight() const {
	return _height;
}

void Background::setHeight(int height) {
	_height = height;
}

const string& Background::getPath() const {
	return _path;
}

void Background::setPath(const string& path) {
	_path = path;
}

int Background::getWidth() const {
	return _width;
}

void Background::setWidth(int width) {
	_width = width;
}


void Background::setTitle(const string& title) {
	_title = title;
}
