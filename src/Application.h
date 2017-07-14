/*
 * Application.h
 *
 *  Created on: Jul 9, 2017
 *      Author: kakev
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Globals.h"
#include "RouletteWheel.h"
#include "Pools.h"
#include "Button.h"
#include "Background.h"
#include "Point.h"
#include <math.h>
#include "Ball.h"


//GameState MenuState;

class Application {
public:
	Application();
	void initIntro();
	void initInfo();
	void initGameBoard();
	void initRoulette();
	void initOutro();
	void initWin();
	void initSpin();
	void Free();
	void GamePlay();
	void SpinRoulette(int);//some argument time , sector , velocity
	bool spinBall();
	bool WinAnimation(int);
	virtual ~Application();

	GameState getMenuState() const;

private:
	GameState MenuState;

	Background * intro;
	Button * introButtons[5];
	//insert credit , volume , info,start new game , resume game


	Background *info;
	Button *infoBackToIntro;
	//back to intro from info buton
	//TODO MAIN make other class who enherit button

	Background *gameBoard;
	Button * spin;

	Button * cashOut;
	Pools *gameBoardPools[5];
	//5 button for beting pools and two buttons for cashout and spin

	//ball ,wheel , and boreder;
	RouletteWheel *wheel ;
	Ball *ball;
	Background * rouletteBorder ;



	Background *outro;// Animation who backs to Intro 10 sec;
	Background *win;// animation 6 seconds
	LTexture *coin;
	//TODO OTHER BUTTONS;


	//hardcoded limit of 100 Pulls

	Background *roulette;// spin roulette border


	vector<Point> v_coordsAllBetPulls;
};

#endif /* APPLICATION_H_ */


