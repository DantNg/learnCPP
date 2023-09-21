#include<string>
#include<iostream>
#include "SinhVien.h"
using namespace std;
#ifndef CARD_H
#define CARD_H
class Card{
    public:
        // Code of borrowed card
        string code;
        string endDate;
        string startDate;
        SinhVien* p;
    public:
        Card(){}
        ~Card(){}
        
        void show();
        string getCode();
};

#endif
