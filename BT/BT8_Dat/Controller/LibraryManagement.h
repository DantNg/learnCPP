#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H

#include <iostream>
#include <vector>
#include "../Model/Card.h"
#include "../Model/Student.h"

class LibraryManagement {
public:
    void BorrowBook(const std::vector<Student>& studentList);
    void ReturnBook();
    void DisplayBorrowCards() const;

private:
    std::vector<Card> cardList;
};



#endif // CARDMANAGEMENT_H
