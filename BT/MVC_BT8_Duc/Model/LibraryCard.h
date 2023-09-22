#pragma once

#include<iostream>
#include<string>
#include"Student.h"

class LibraryCard
{
    private:
        Student student;
        int CardNumber;
        std::string StartDate;
        std::string EndDate;
        int BookNumber;
    public:
        LibraryCard(Student _student, int _CardNumber, std::string _StartDate, std::string _EndDate, int _BookNumber);

        ~LibraryCard();

        void SetStudent(Student _student);

        Student GetStudent();

        void SetCardNumber(int _CarNumber);

        int GetCardNumber();

        void SetStartDate(std::string _StartDate);

        std::string GetStartDate();

        void SetEndDate(std::string _EndDate);

        std::string GetEndDate();

        void SetBookNumber(int _BookNumber);

        int GetBookNumber();
};
