#include "Card.h"
#include <vector>
Card::Card() : borrowCode(0), borrowDate(0), dueDate(0), bookCode(0), studentName("") {}
int Card::GetBorrowCode() const { return borrowCode; }

void Card::EntryBorrowCard(int studentIndex, std::vector<Student> studentList)  {
    std::cout << "\n\nEnter borrow code: ";
    std::cin >> borrowCode;
    std::cout << "Enter borrow date: ";
    std::cin >> borrowDate;
    std::cout << "Enter due date: ";
    std::cin >> dueDate;
    std::cout << "Enter book code: ";
    std::cin >> bookCode;
    studentName = studentList[studentIndex].GetFullName(); // Sửa thành studentList
}


void Card::ReturnCard() {
    int returnCode;
    std::cout << "\n\nEnter return code: ";
    std::cin >> returnCode;
    if (borrowCode == returnCode) {
        borrowCode = 0;
        borrowDate = 0;
        dueDate = 0;
        bookCode = 0;
        studentName = "";
        std::cout << "Book returned.\n";
    } else {
        std::cout << "Return code not found.\n";
    }
}

void Card::DisplayInfo() const {
    std::cout << "->Borrow Code: " << borrowCode << ", Student Name: " << studentName << std::endl;
}


std::string Card::GetStudentName() const {
    return studentName;
}

int Card::GetBorrowDate() const {
    return borrowDate;
}
int Card::GetDueDate() const {
    return dueDate;
}