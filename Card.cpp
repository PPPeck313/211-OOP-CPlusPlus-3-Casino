#include "Card.h"

#include<iostream>
using namespace std;

Card::Card()
{
	//intentionally left blank
}

Card::Card(int r, int s, int v)
{
	rank = r;
	suit = s;
	value = v;
}

Card::Card(int r, int s)
{
	rank = r;
	suit = s;
}

Card::Card(int n)
{
	
	rank = n % 13;
	suit = n % 4;
}

void Card::setRank(int r){ rank = r; }
int Card::getRank(){ return rank; }

void Card::setSuit(int s){ suit = s; }
int Card::getSuit(){ return suit; }

void Card::setValue(int v){ value = v; }
int Card::getValue(){ return value; }

int Card::compareTo(const Card& other)
{
	if (compareByRank(other) == 0) {
		return compareBySuit(other);
	}
	else {
		return compareByRank(other);
	}
}

int Card::compareByRank(const Card& other)
{
	return rank - other.rank; 
}

int Card::compareBySuit(const Card& other)
{
	return suit - other.suit;
}

int Card::compareByValue(const Card& other)
{
	return value - other.value;
}

ostream& operator << (ostream& out, Card& c) {
	string rankAsString[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
	string suitAsString[] = { "Diamonds", "Clubs", "Hearts", "Spades" };

	out<<rankAsString[c.rank] + " of " + suitAsString[c.suit];
	return out;
}

void Card::draw() {
	string rankAsString[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string suitAsString[] = { "<>", ">3", "<3", ">>" };
	cout<<" ________ "<<endl
		<<"|"<<rankAsString[rank]<<"       | "<<endl
		<<"|        | "<<endl
		<<"|   "<<suitAsString[suit]<<"   | "<<endl
		<<"|        | "<<endl
		<<"|       "<<rankAsString[rank]<<"| "<<endl
		<<"|________| "<<endl;
}