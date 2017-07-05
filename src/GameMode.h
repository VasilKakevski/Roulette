/*
 * GameMode.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef GAMEMODE_H_
#define GAMEMODE_H_

#include "Button.h"
#include "NumberButton.h"
#include "RouletteWheel.h"

class GameMode
{
public:
	GameMode();
	virtual ~GameMode();

	void showAccounting();
	int showRouletteSpin(); // return winning number
	void showLastSpins(); // from XML using TTF


private:
	RouletteWheel roulette;
	NumberButton buttons[37];
	Button lastSpins;
	Button accounting;
};

#endif /* GAMEMODE_H_ */
