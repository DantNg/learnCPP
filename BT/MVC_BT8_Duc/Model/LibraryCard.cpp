#include<iostream>
#include"LibraryCard.h"

LibraryCard::LibraryCard(Student _student, int _CardNumber, std::string _StartDate, std::string _EndDate, int _BookNumber) : student(_student), CardNumber(_CardNumber), StartDate(_StartDate), EndDate(_EndDate), BookNumber(_BookNumber) {}

LibraryCard::~LibraryCard() {}

void LibraryCard::SetStudent(Student _student)
{
    student = _student;
}

Student LibraryCard::GetStudent()
{
    return student;
}

void LibraryCard::SetCardNumber(int _CarNumber)
{
    CardNumber = _CarNumber;
}

int LibraryCard::GetCardNumber()
{
    return CardNumber;
}

void LibraryCard::SetStartDate(std::string _StartDate)
{
    StartDate = _StartDate;
}

std::string LibraryCard::GetStartDate()
{
    return StartDate;
}

void LibraryCard::SetEndDate(std::string _EndDate)
{
    EndDate = _EndDate;
}

std::string LibraryCard::GetEndDate()
{
    return EndDate;
}

void LibraryCard::SetBookNumber(int _BookNumber)
{
    BookNumber = _BookNumber;
}

int LibraryCard::GetBookNumber()
{
    return BookNumber;
}
