#include "Player.h"
#include "Blackjack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string choice;
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<endl<<endl;
    Player* p1 = new Player(name);
    
    cout<<"Welcome to the Casino, "<<p1->getName()<<"!"<<endl
        <<"     1) Blackjack"<<endl
        <<"     2) Exit"<<endl<<endl
        
        <<"Select your game (1/2): ";
    cin>>choice;
    
    while (choice != "1" && choice != "2") {
        cout<<"Select your game (1/2): ";
        cin>>choice;
    }
    
    while (choice != "2") {
        cout<<endl;
        if (choice == "1") {
            Blackjack* game = new Blackjack();
            p1->setPoints(game->playGame());
        }
        
        cout<<"Welcome back to the Casino, "<<p1->getName()<<"!"<<endl
            <<"     1) Blackjack"<<endl
            <<"     2) Exit"<<endl<<endl
        
            <<"Select your game (1/2): ";
        cin>>choice;     
    }
    
    cout<<endl<<endl<<"Final score: "<<p1->getPoints()<<endl;
    
    if (p1->getPoints() == 0) {
        cout<<"You broke even!"<<endl<<endl;
    }
    else if (p1->getPoints() < 0) {
        cout<<"Better luck next time!"<<endl<<endl;
    }
    else if (p1->getPoints() > 0) {
        cout<<"Wow! You're a natural!"<<endl<<endl;
    }
        
    cout<<"Thanks for playing!"<<endl<<endl;
    return 0;
}