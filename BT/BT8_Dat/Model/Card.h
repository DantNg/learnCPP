#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>
class Card {
public:
    Card();
    void EntryBorrowCard(int studentIndex,std::vector<Student> studentList);
    void ReturnCard();
    void DisplayInfo() const;
    int  GetBorrowCode() const;
    int  GetBorrowDate() const;
    int  GetDueDate() const;
    int  GetBookCode() const;
    std::string  GetStudentName() const;
private:
    int borrowCode;
    int borrowDate;
    int dueDate;
    int bookCode;
    std::string studentName;
};

#endif // CARD_H
