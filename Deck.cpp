#include "Stack.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Deck::Deck() {//creates a traditional 52 card deck
	deck = new Stack<Card*>(52);
	for (int i = 0; i < 52; i++) {
		deck->push(new Card(i));//deck is a stack
	}
}

void Deck::shuffle() {
	Card* random[52];
	srand (time(NULL));
	int size = deck->getSize();
	for (int i = 0; i < size; i++) {
		random[i] = deck->pop();
	}
	for (int i = size; i > 0; i--) {
		int index = rand() % size;
		while (random[index] == NULL) {
			index = rand() % size;
		}
		deck->push(random[index]);
		random[index] = NULL;
	}
}

Card* Deck::deal() {
	Card* temp = deck->pop();
	if (temp == NULL) {
		//do something
		//Re-shuffle?
		//Return more specific error
	}
	return temp;
}

int Deck::getSize() {
	return deck->getSize();
	//return (*deck).getSize();
}

void Deck::display() {
	deck->display();
}
