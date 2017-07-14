/*
 * RouletteWheel.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: kakev
 */

#include "RouletteWheel.h"

RouletteWheel::RouletteWheel(int _x, int _y) :LTexture (x,y)
{

 isFinish=false;

}

RouletteWheel::~RouletteWheel() {
	// TODO Auto-generated destructor stub
}

void RouletteWheel::Spin()
{
double angle=0;
map<int,double>::iterator it = wheelSectors.begin();

while(angle>360){
	LTexture::render(Background::gRenderer,NULL,angle);
	angle+=0.5;
}
for(int i=0;i <37;i++){
	//9.7 angle 360 / sectors
	wheelSectors[i]= i*9.7;
}
for (it=wheelSectors.begin(); it!=wheelSectors.end(); ++it)
   std::cout << it->first << " => " << it->second << endl;

}


