#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Blackjack.h"

#include <iostream>
#include <string>

using namespace std;
//incorporate spliting
//incorporate switch case
//how do you open terminal/program window to an appropriate size?
void assignValues(Hand* h, int start);

Blackjack::Blackjack() {
}

int Blackjack::playGame() {//Blackjack and GoFish have the same function so make a parent Game class?
    //created using Text to ASCII Art Generator (TAAG), Font: Delta Corps Priest 1
    //http://patorjk.com/software/taag/
    cout<<"▀█████████▄   ▄█          ▄████████  ▄████████    ▄█   ▄█▄      ▄█    ▄████████  ▄████████    ▄█   ▄█▄"<<endl  
        <<"  ███    ███ ███         ███    ███ ███    ███   ███ ▄███▀     ███   ███    ███ ███    ███   ███ ▄███▀"<<endl     
        <<"  ███    ███ ███         ███    ███ ███    █▀    ███▐██▀       ███   ███    ███ ███    █▀    ███▐██▀  "<<endl     
        <<" ▄███▄▄▄██▀  ███         ███    ███ ███         ▄█████▀        ███   ███    ███ ███         ▄█████▀   "<<endl     
        <<"▀▀███▀▀▀██▄  ███       ▀███████████ ███        ▀▀█████▄        ███ ▀███████████ ███        ▀▀█████▄   "<<endl     
        <<"  ███    ██▄ ███         ███    ███ ███    █▄    ███▐██▄       ███   ███    ███ ███    █▄    ███▐██▄  "<<endl     
        <<"  ███    ███ ███▌    ▄   ███    ███ ███    ███   ███ ▀███▄     ███   ███    ███ ███    ███   ███ ▀███▄"<<endl     
        <<"▄█████████▀  █████▄▄██   ███    █▀  ████████▀    ███   ▀█▀ █▄ ▄███   ███    █▀  ████████▀    ███   ▀█▀"<<endl    
        <<"             ▀                                   ▀         ▀▀▀▀▀▀                            ▀        "<<endl<<endl
        
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
        int victory = 2;
        
        Deck* bJ = new Deck();
        bJ->shuffle();
        
        cout<<"Removing factory seal..."<<endl;
        cout<<"Shuffling..."<<endl;
        cout<<"Dealing..."<<endl<<endl;
        
        int pTotal = 0;//store evaluate in variable so don't have to call function as often
        Hand* player = new Hand();//player(s) dealt first
        player->insertLast(bJ->deal());
        player->insertLast(bJ->deal());
        assignValues(player, 0);
        pTotal = player->evaluate(2);
        
        if(pTotal == 22) {//meaning two aces
            player->convertAcesDown(1);
            pTotal = player->evaluate(2);
        }//only necessary to convert one of them
        
        int dTotal = 0;
        Hand* dealer = new Hand();//dealer dealt last
        dealer->insertLast(bJ->deal());
        dealer->insertLast(bJ->deal());
        assignValues(dealer, 0);
        dTotal = dealer->evaluate(1);

        cout<<"DEALER's hand:"<<endl
            <<"Total: "<<dTotal<<endl;
        dealer->drawDealer();
        cout<<endl<<endl;
        
        
        cout<<"YOUR hand:"<<endl
            <<"Total: "<<pTotal<<endl;
        player->draw(" ");
        cout<<endl<<endl;
        
  
        if (pTotal == 21) {
            victory = 1;
        }
    
    
        if (victory == 2) {
            string choice2 = "";
            cout<<"YOUR turn: "<<endl
                <<"1) Hit"<<endl
                <<"2) Stay"<<endl<<endl
                
                <<"Make your decision (1/2): ";
            cin>>choice2;
            
            while (choice2 != "1" && choice2 != "2") {
                cout<<"Make your decision (1/2): ";
                cin>>choice2;
            }  
                 
                      
            while (choice2 != "2") {
                while (choice2 != "1" && choice2 != "2") {
                    cout<<"Make your decision (1/2): ";
                    cin>>choice2;
                }
                cout<<endl;
                
                player->insertLast(bJ->deal());
                assignValues(player, player->getCount() - 1);
                pTotal = player->evaluate(player->getCount());
                
                if (pTotal > 21) {
                    player->convertAcesDown(0);
                    pTotal = player->evaluate(player->getCount());
                }
                
                cout<<"Total: "<<pTotal<<endl;
                player->draw(" ");
                cout<<endl<<endl;
                

                if (pTotal > 21) {
                    cout<<"BUST!"<<endl;
                    victory = 0;
                    break;
                }
                
                if ((pTotal) == 21) {
                    cout<<"Staying..."<<endl;
                    break;
                }
                
                
                
                cout<<"1) Hit"<<endl
                    <<"2) Stay"<<endl<<endl
                    
                    <<"Make your decision (1/2): ";
                cin>>choice2;
                
                while (choice2 != "1" && choice2 != "2") {
                    cout<<"Make your decision (1/2): ";
                    cin>>choice2;
                }
            }
            cout<<endl;
        }
            
        dTotal = dealer->evaluate(2);
        
        if (dTotal == 22) {//if two aces, don't have to convert both down'
            dealer->convertAcesDown(1);
            dTotal = dealer->evaluate(2);
        }
        
        if (dTotal == 17) {//have to hit on soft 17
            dealer->convertAcesDown(0);
            dTotal = dealer->evaluate(2);
         }
         
         if (dTotal == 21) {
             victory = 0;
         }
         
         
        cout<<endl<<"DEALER's hand:"<<endl
                        <<"Total: "<<dTotal<<endl;
        dealer->draw("█");            
        cout<<endl<<endl;
        
        
        int loop = 0;
        while (dTotal < 17 && victory == 2) {
            if (loop == 0) {
                cout<<"DEALER's turn: "<<endl;
            }
            
            cout<<"Hitting..."<<endl;
            
            dealer->insertLast(bJ->deal());
            assignValues(dealer, dealer->getCount() - 1);
            dTotal = dealer->evaluate(dealer->getCount());
            
            if (dTotal > 21) {
                dealer->convertAcesDown(0);
                dTotal = dealer->evaluate(dealer->getCount());
            }
            
            cout<<"Total: "<<dTotal<<endl;
            dealer->draw("█");
            cout<<endl<<endl;
            
            if (dTotal > 21) {
                cout<<"BUST!"<<endl<<endl;
                victory = 1;
                break;  
            }
            loop++;    
        }
         
         
         
        if (pTotal == dTotal) {
            cout<<"TIE!"<<endl<<endl;
        }   
        
        else if (victory == 1 || ((pTotal > dTotal) && pTotal <= 21)) {
            cout<<"YOU WIN!"<<endl<<endl;
            score++;     
        }
        
        else if (victory == 0 || ((pTotal < dTotal) && dTotal <= 21)) {
            cout<<"HOUSE WINS!"<<endl<<endl;
            score--;     
        }
        
        cout<<"Current score: "<<score<<endl<<endl
        
                <<"Play again? (1/2): ";
            cin>>choice1;
            
        while (choice1 != "1" && choice1 != "2") {
            cout<<"Play again? (1/2): ";
            cin>>choice1;
        }
        cout<<endl;
        if (choice1 == "1") {
            cout<<endl<<"Starting new game..."<<endl<<endl;
        }
    }
    cout<<endl;
    return score;
}

void assignValues(Hand* h, int start) {//assign to cards that are drawn and not to unused deck cards
    for (int i = start; i < h->getCount(); i++) {
        if (h->getCardAt(i)->getRank() == 12 && h->getCardAt(i)->getValue() != 1) {
            h->getCardAt(i)->setValue(11);
        }
        else if (h->getCardAt(i)->getRank() > 8 && h->getCardAt(i)->getRank() < 12) {
            h->getCardAt(i)->setValue(10);
        }
        else {
            h->getCardAt(i)->setValue(h->getCardAt(i)->getRank() + 2);
        }
    }
}