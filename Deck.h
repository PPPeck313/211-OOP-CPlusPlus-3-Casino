#ifndef DECK_H
#define DECK_H

#include "Stack.h"
#include "Card.h"

using namespace std;

class Deck
{
private:
	Stack<Card*>* deck;
public:
	Deck();
	void shuffle();
	Card* deal();
	int getSize();
	void display();
};

#endif