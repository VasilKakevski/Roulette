/*
 * Credits.h
 *
 *  Created on: Jul 7, 2017
 *      Author: kakev
 */

#ifndef CREDITS_H_
#define CREDITS_H_
#include  "Globals.h"

class Credits
{
public:
	Credits(int=0);
	Credits (Credits &);
	virtual ~Credits();
	void SetBet(int);
	int GetBet() const ;
	int GetCredit() const ;
	bool isCashedOut();
private:
	// TODO THEM Static or something that respond with other object of this class ;
	int currentCredit;
	int betCredit;
};

#endif /* CREDITS_H_ */
