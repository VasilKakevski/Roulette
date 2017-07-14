/*
 * Globals.h
 *
 *  Created on: Jul 8, 2017
 *      Author: kakev
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;


 enum GameState{
	INTRO_MENU=1,
	INFO,
	GAME_BOARD,
	SPIN,
	OUTRO,
	WIN
};

static SDL_Window * gWindow = NULL;
//screen dimention
const int SCREEN_W = 1300;
const int SCREEN_H = 800;
//screen dimention
const int SCREEN_BOARD_W = 1200;
const int SCREEN_BOARD_H = 428;
//screen dimentions of spining roulette
const int SCREEN_ROULETTE_W = 800;
const int SCREEN_ROULETTE_H = 800;
//button dimention
const int BUTTON_W = 200;
const int BUTTON_H = 100;
//ball dimention
const int BALL_W=50;
const int BALL_H=50;
//button dimention
const int INTRO_BUTTON_W= 59;
const int INTRO_BUTTON_H=59;
//button dimention
const int PULLS_W = 60;
const int PULLS_H = 60;

const int COIN_COUNT =10;
const int COIN_W=59;
const int COIN_H=59;
#endif /* GLOBALS_H_ */
