/*
 * Acounting.h
 *
 *  Created on: 5.07.2017 ã.
 *      Author: Viktor
 */

#ifndef ACOUNTING_H_
#define ACOUNTING_H_

class Acounting
{
public:
	Acounting();
	virtual ~Acounting();

	int getCredits();

	void addCredits(int); // number of credits
	void addBet(int); // number of credits bet
	void winBet(int, double); // credits, multiplier

	void addBonus(); // after spin of wheel use this
					 // +13% of creditsBet
	double getBonus();


private:
	double profitByNumber[37];
	static int creditsIn;
	static int creditsOut;
	int creditsLeft;
	int creditsBet;
	double bonus;
};

#endif /* ACOUNTING_H_ */
