/*
 * Player.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: mediff
 */

#include "Player.h"

Player::Player(int c,int b) {
this->credit=c;
this->bet=b;

}

void Player::setCredit(int c) {
	this->credit=c;

}

int Player::getCredit() {
	return credit;
}

void Player::setBet(int b) {
	this->bet=(credit>b)?b:0;
}

void Player::PrintInfo() {
	std::cout<<"Credit "<<credit<<std::endl;
	std::cout<<"Bet "<<bet<<std::endl;
}

Player::~Player() {

}


