#include<iostream>
#include"UserInterface.h"

void UserInterface::Prompt(std::string s)
{
    std::cout << s;
}

void UserInterface::Prompt(int i)
{
    std::cout << i;
}

int UserInterface::GetChoice()
{
    int i;
    std::cin >> i;
    return i;
}

void UserInterface::Menu()
{
    std::cout << "========== Library Management System ==========" << std::endl;
    std::cout << "1. Add a new card" << std::endl;
    std::cout << "2. Show cards" << std::endl;
    std::cout << "3. Delete a card" << std::endl;
    std::cout << "4. Exit program" << std::endl;
    std::cout << "Your choice: ";
}

LibraryCard UserInterface::GetNewCard()
{
    std::string Name;
    int Age;
    std::string Class;
    int CardNumber;
    std::string StartDate;
    std::string EndDate;
    int BookNumber;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, Name);
    std::cout << "Age: ";
    std::cin >> Age;
    std::cout << "Class: ";
    std::cin.ignore();
    std::getline(std::cin, Class);
    std::cout << "CardNumber: ";
    std::cin >> CardNumber;
    std::cout << "StartDate: ";
    std::cin.ignore();
    std::getline(std::cin, StartDate);
    std::cout << "EndDate: ";
    getline(std::cin, EndDate);
    std::cout << "BookNumber: ";
    std::cin >> BookNumber;
    Student student(Name, Age, Class);
    LibraryCard libraryCard(student, CardNumber, StartDate, EndDate, BookNumber);
    return libraryCard;
}

int UserInterface::GetCardDelete()
{
    int i;
    std::cout << "Enter cardnumber which you want to delete: ";
    std::cin >> i;
    return i;
}

void UserInterface::ShowCard(LibraryCard c)
{
    std::cout << "Name: " << c.GetStudent().GetName() << std::endl;
    std::cout << "Age: " << c.GetStudent().GetAge() << std::endl;
    std::cout << "Class: " << c.GetStudent().GetClass() << std::endl;
    std::cout << "CardNumber: " << c.GetCardNumber() << std::endl;
    std::cout << "StartDate: " << c.GetStartDate() << std::endl;
    std::cout << "EndDate: " << c.GetEndDate() << std::endl;
    std::cout << "BookNumber: " << c.GetBookNumber() << std::endl;
}
