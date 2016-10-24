#include "Card.h"
#include "LinkedList.h"
#include "Hand.h"
#include <iostream>
using namespace std;

Hand::Hand() {
    hand = new LinkedList<Card*>();
}

Hand::~Hand() {
    if (hand != NULL) {
        delete[] hand;//call ~LinkedList()
    }
}

Hand::Hand(Hand& other) {
    hand = other.hand;
}

void Hand::operator=(const Hand& other) {
    hand = other.hand;
}

int Hand::getCount() {
    return hand->getSize();
}

void Hand::insertByRank(Card* c) {
    hand->insertAtIndex(c, getCount());
    hand->sort();
}

void Hand::insertLast(Card* c) {
    hand->insertAtIndex(c, getCount());
}

void Hand::remove(Card* c) {
    for (int i = 0; i < getCount(); i++) {
        if (hand->getAtIndex(i) == c) {
            hand->removeAtIndex(i);
        }
    }
}

void Hand::removeAll() {
    delete[] hand;
}

bool Hand::isEmpty() {
    return getCount() == 0;
}

ostream& operator<<(ostream& os, const Hand& h) {
    os<<h.hand;
    return os;
}

void Hand::draw(string mark) {
    	string rankAsString[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string suitAsString[] = { "<>", ">3", "<3", ">>" };
    for (int i = 0; i < getCount(); i++) {
	    cout<<" ________  ";
    }
    cout<<endl;
   for (int i = 0; i < getCount(); i++) {
		cout<<"|"<<rankAsString[hand->getAtIndex(i)->getRank()]<<"      "<<mark<<"| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|        | ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|   "<<suitAsString[hand->getAtIndex(i)->getSuit()]<<"   | ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|        | ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|       "<<rankAsString[hand->getAtIndex(i)->getRank()]<<"| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|________| ";
    }
}

void Hand::drawDealer() {
	string rankAsString[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string suitAsString[] = { "<>", ">3", "<3", ">>" };
	cout<<" ________  ";
    cout<<" ________  ";
    cout<<endl;
    cout<<"|"<<rankAsString[hand->getAtIndex(0)->getRank()]<<"      █| ";//dealer tag to set it apart
	cout<<"|████████| ";
    cout<<endl;
    cout<<"|        | ";
	cout<<"|████████| ";
    cout<<endl;
    cout<<"|   "<<suitAsString[hand->getAtIndex(0)->getSuit()]<<"   | ";
    cout<<"|████████| ";
    cout<<endl;
    cout<<"|        | ";
	cout<<"|████████| ";
    cout<<endl;
    cout<<"|       "<<rankAsString[hand->getAtIndex(0)->getRank()]<<"| ";
    cout<<"|████████| ";
    cout<<endl;
    cout<<"|________| ";
    cout<<"|████████| ";
}

void Hand::drawBack() {
	string rankAsString[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string suitAsString[] = { "<>", ">3", "<3", ">>" };
    for (int i = 0; i < getCount(); i++) {
	    cout<<" ________  ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|████████| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|████████| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|████████| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|████████| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|████████| ";
    }
    cout<<endl;
    for (int i = 0; i < getCount(); i++) {
		cout<<"|████████| ";
    }
}

//BlackJack
int Hand::evaluate(int end) {
    int total = 0;
    for (int i = 0; i < end; i++) {
        total += hand->getAtIndex(i)->getValue();
    }
    return total;
}

void Hand::convertAcesDown(int start) {
    for (int i = start; i < getCount(); i++) {
        Card* c = hand->getAtIndex(start);
        if (c->getRank() == 12) {
            c->setValue(1);
        }
    }
}

int Hand::compare(Hand& other) {
    return evaluate(getCount()) - other.evaluate(getCount());
}

//Go Fish
bool Hand::hasRank(int i) {
    for (int j = 0; j < getCount(); j++) {
        if (hand->getAtIndex(i)->getRank() == i) {
            return true;
        }
    }
    return false;
}

Card* Hand::findRank(int i) {
    for (int j = 0; j < getCount(); j++) {
        if (hand->getAtIndex(i)->getRank() == i) {
            return hand->getAtIndex(j);
        }
    }
    return NULL;
}

Card* Hand::getCardAt(int i) {
    return hand->getAtIndex(i);
}

void Hand::insertHand(Hand& other) {
    hand->setSize(getCount() + other.getCount());
    
    delete[] other.hand;
}

void Hand::removeRank(int i) {
    for (int j = 0; j < getCount(); j++) {
        if (hand->getAtIndex(i)->getRank() == i) {
            hand->removeAtIndex(j);
        }
    }
}

int Hand::evaluatePair() {
    
}

int Hand::countRank(int i) {
    
}