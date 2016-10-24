#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "GoFish.h"

#include <iostream>
#include <string>

using namespace std;

GoFish::GoFish() {
}

int GoFish::playGame() {//GoFish and Blackjack have the same function so make a parent Game class?
    //created using Text to ASCII Art Generator (TAAG), Font: Delta Corps Priest 1
    //http://patorjk.com/software/taag/
    cout<<"   ▄██████▄   ▄██████▄          ▄████████  ▄█     ▄████████    ▄█    █▄   "<<endl; 
        <<"  ███    ███ ███    ███        ███    ███ ███    ███    ███   ███    ███  "<<endl; 
        <<"  ███    █▀  ███    ███        ███    █▀  ███▌   ███    █▀    ███    ███  "<<endl; 
        <<" ▄███        ███    ███       ▄███▄▄▄     ███▌   ███         ▄███▄▄▄▄███▄▄"<<endl; 
        <<"▀▀███ ████▄  ███    ███      ▀▀███▀▀▀     ███▌ ▀███████████ ▀▀███▀▀▀▀███▀ "<<endl; 
        <<"  ███    ███ ███    ███        ███        ███           ███   ███    ███  "<<endl; 
        <<"  ███    ███ ███    ███        ███        ███     ▄█    ███   ███    ███  "<<endl; 
        <<"  ████████▀   ▀██████▀         ███        █▀    ▄████████▀    ███    █▀   "<<endl<<endl; 

        <<"                                               Play? (1/2): ";

    int score = 0;  
    string choice1 = "";
    cin>>choice1;
    
    while (choice1 != "1" && choice1 != "2") {
        cout<<"                                               Play? (1/2): ";
        cin>>choice1;
    }
    cout<<endl;
    while (choice1 != "2") {
    }
}