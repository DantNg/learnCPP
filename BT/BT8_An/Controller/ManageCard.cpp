#include "ManageCard.h"
#include "../Model/Card.h"
#include "../Model/Student.h"
using namespace std;

void ManageCard::addCard(Card c){
    listCard.push_back(c);
}

void ManageCard::show(){
    for(Card c: listCard){
        c.show();
    }
}
void ManageCard::deleteCard(){
    string code;
    cout << "Enter code of card: ";
    cin.ignore();
    getline(cin, code);
    for(auto c=listCard.begin(); c!=listCard.end();c++){
        if(c->GetCode()==code){
            listCard.erase(c);
            return;
        }
    }
    cout << "Not found\n";
}
    void ManageCard::createCard(){
        Card c;
        c.CreateCard();
        addCard(c);

    }

