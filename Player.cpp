#include "Player.h"
#include "Hand.h"

#include <string>

Player::Player() {
    name = "";
    hand = new Hand();
    points = 0;
}

Player::Player(string n) {
    name = n;
    hand = new Hand();
    points = 0;
}

Player::~Player() {
    if (hand != NULL) {
        delete[] hand;
    }
}

string Player::getName() {
    return name;
}

void Player::setName(string n) {
    name = n;
}

int Player::getPoints() {
    return points;
}

void Player::setPoints(int p) {
    points = p;
}

void Player::addCard(Card* c) {
    hand->insertLast(c);
}

//get total value - if over 21 check for Aces of value 11 and convert to value 1
int Player::evaluate() {
    return hand->evaluate(hand->getCount());
}

void Player::showHand() {
    cout<<"Showing "<<name<<"'s hand:"<<endl
        <<hand;
}

ostream& operator<<(ostream& os, const Player& p) {
    os<<"Name: "<<p.name<<endl
      <<"Points: "<<p.points<<endl;
    return os;
} //display Player's info