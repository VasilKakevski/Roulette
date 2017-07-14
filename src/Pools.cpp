/*
 * Pools.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#include "Pools.h"
Pools::Pools(Credits & cr,int posx,int posy, int number)
	:Button(posx, posy)
{

	this->number=number;
	//static counter
}

Pools::~Pools() {
	// TODO Auto-generated destructor stub
}

bool Pools::isBet()
{
return false;
}

int Pools::GetNumber()
{
	return this->number;
}
