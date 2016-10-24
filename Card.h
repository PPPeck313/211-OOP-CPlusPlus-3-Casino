#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
private:
	int rank; //"A, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King"
	int suit; //"Spade, Heart, Diamond, Club"
	int value;
public:
	Card();
	Card(int r, int s, int v);
	Card(int r, int s);
	Card(int n);
	
	void setRank(int r);
	int getRank();

	void setSuit(int s);
	int getSuit();

	void setValue(int v);
	int getValue();

	int compareTo(const Card& other);
	int compareByRank(const Card& other);
	int compareBySuit(const Card& other);
	int compareByValue(const Card& other);
	
	friend ostream& operator << (ostream& out, Card& c);
	
	void draw();
};

#endif