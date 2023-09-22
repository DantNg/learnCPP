#include<iostream>
#include"LibraryMS.h"

LibraryMS::LibraryMS() {}

LibraryMS::~LibraryMS() {}

void LibraryMS::Run()
{
    int ch;
    do
    {
        userinterface.Menu();
        ch = userinterface.GetChoice();
        switch(ch)
        {
            case ADD:
            {
                LibraryCard c = userinterface.GetNewCard();
                libraryMS.push_back(c);
                break;
            }
            case SHOW:
                ShowAllCard();
                break;
            case DELETE:
            {
                int i = userinterface.GetCardDelete();
                EraseCard(i);
                break;
            }
            default:
                userinterface.Prompt("Your choice is incorrect!\n");
                break;
        }
    } while(ch != EXIT);
}

void LibraryMS::AddNewCard(LibraryCard c)
{
    for(LibraryCard x : libraryMS)
    {
        if(x.GetCardNumber() == c.GetCardNumber()) 
        {
            userinterface.Prompt("CardNumer has been exist!\n");
            return;
        }
    }
    libraryMS.push_back(c);
    userinterface.Prompt("Add new card successfully!\n");
}

void LibraryMS::ShowAllCard()
{
    if(libraryMS.size() == 0)
    {
        userinterface.Prompt("No information to show!\n");
        return;
    }
    else
    {
        int count = 1;
        for(LibraryCard x: libraryMS)
        {
            userinterface.Prompt("==========STT: ");
            userinterface.Prompt(count++);
            userinterface.Prompt("==========\n");
            userinterface.ShowCard(x);
        }
    }
}
void LibraryMS::EraseCard(int i)
{
    for(std::vector<LibraryCard>::iterator x = libraryMS.begin(); x != libraryMS.end(); x++)
    {
        if((*x).GetCardNumber() == i)
        {
            libraryMS.erase(x);
            userinterface.Prompt("Delete successfully!");
            return;
        }
    }
    userinterface.Prompt("Can't find cardnumber!");
}
