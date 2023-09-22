#pragma once

#include<iostream>
#include<vector>
#include"..\Model\LibraryCard.h"
#include"..\View\UserInterface.h"

enum CHOICE
{
    ADD = 1,
    SHOW,
    DELETE,
    EXIT
};

class LibraryMS
{
    private:
        UserInterface userinterface;
        std::vector<LibraryCard> libraryMS;
    public:
        LibraryMS();

        ~LibraryMS();

        void Run();

        void AddNewCard(LibraryCard c);

        void ShowAllCard();

        void EraseCard(int i);
};