
#include<string>
#include<iostream>
#include "SinhVien.h"
#include "Card.h"
#include<vector>
using namespace std;
#ifndef MANAGECARD_H
#define MANAGECARD_H
class ManageCard{
    public:
        vector<Card> listCard;
    public:
        ManageCard(){}
        ~ManageCard(){}

        void addCard(Card c);
        void show();
        void deleteCard();
        Card createCard();
};
#endif