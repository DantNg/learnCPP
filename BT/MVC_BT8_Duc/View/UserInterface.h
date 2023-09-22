#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include<iostream>
#include<string>
#include"..\Model\LibraryCard.h"

class UserInterface
{
    public:
        void Prompt(std::string s);

        void Prompt(int i);

        int GetChoice();

        void Menu();

        LibraryCard GetNewCard();

        int GetCardDelete();
        
        void ShowCard(LibraryCard c);
};

#endif // USERINTERFACE_H
