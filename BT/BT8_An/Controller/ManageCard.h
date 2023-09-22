#ifndef MANAGECARD_H
#define MANAGECARD_H
#include<string>
#include<iostream>
#include<vector>
#include "../Model/Card.h"
#include "../Model/Student.h"
using namespace std;
class ManageCard{
    public:
        vector<Card> listCard;
    public:
        ManageCard(){}
        ~ManageCard(){}

        void addCard(Card c);
        void show();
        void deleteCard();
        void createCard();
};
#endif