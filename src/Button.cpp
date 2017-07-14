/*
 * Button.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Button.h"

Button::Button(int x, int y)
	:LTexture(x,y)
{
}

bool Button::isHover() {
	int x,y;
	SDL_GetMouseState(&x,&y);
		if (x >= getX() && x <= getWidth() + getX() && y >= getY()
						&& y <= getY() + getHeight()) {
			//cout<<"isHovered Button"<<endl;
			return true;
		}

	return false;
}

bool Button::isClicked(	SDL_Event * e)
{
	if( isHover() && e->type == SDL_MOUSEBUTTONDOWN )
	{
		cout<<"isClicked Button"<<endl;
		return true;
	}
	return false;

}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

