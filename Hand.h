#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

class Hand
{
private:
	LinkedList<Card*>* hand;
public:
	Hand();
	Hand(Hand& other);
	~Hand();
	void operator=(const Hand& other);
	int getCount();
	void insertByRank(Card* c);
	void insertLast(Card* c);
	void remove(Card* c);
	void removeAll();
	bool isEmpty();
	friend ostream& operator<<(ostream& os, const Hand& other);
	void draw(string mark);
	void drawDealer();
	void drawBack();

	//BlackJack
	int evaluate(int end);
	void convertAcesDown(int start);
	int compare(Hand& other);

	//Go Fish
	bool hasRank(int i);
	Card* findRank(int i);
	Card* getCardAt(int i);
	void insertHand(Hand& other);
	void removeRank(int i);
	int evaluatePair();
	int countRank(int i);
};

#endif