#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <iostream>

using namespace std;

class Player
{
private:
	string name;
	Hand* hand;
	int points;
public:
	Player();
	Player(string n);
	~Player();
	string getName();
	void setName(string n);
	int getPoints();
	void setPoints(int p); 

	void addCard(Card* c);
	//get total value - if over 21 check for Aces of value 11 and convert to value 1
	int evaluate();

	void showHand();
	friend ostream& operator<<(ostream&, const Player&); //display Player's info
};

#endif