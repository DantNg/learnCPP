#ifndef CARD_H
#define CARD_H
#include<string>
#include<iostream>
#include "Student.h"
using namespace std;
class Card{
    private:
        // Code of borrowed card
        string code;
        string endDate;
        string startDate;
        string studentName;
    public:
        Card(){}
        ~Card(){}
        
        void show();
        void CreateCard();
        // getter
        string GetCode();
        string GetBorrowDate();
        string GetDueDate();
        string GetStudentName();
        //seter
        void SetCode(string BookCode);
        void SetBorrowDate(string BorrowDate);
        void SetDueDate(string DueDate);
        void GetStudentName(string s);
        
};
#endif
