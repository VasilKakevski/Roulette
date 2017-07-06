/*
 * Player.h
 *
 *  Created on: Jul 5, 2017
 *      Author: mediff
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
using std::cout;
using std::endl;

class Player {

public:
	Player(int c,int b);
	void setCredit(int );
	int getCredit();
	void setBet(int);
	void PrintInfo();
	virtual ~Player();
private:
	int credit;
	int bet;

};

#endif /* PLAYER_H_ */
