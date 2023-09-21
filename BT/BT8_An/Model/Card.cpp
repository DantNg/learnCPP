#include "Card.h"
// Card::Card() : code(0), startDate(0), endDate(0), studentName("") {}
void Card:: Card::show(){
    cout << "Code: " << code;
    cout << "Borrow date: "<< startDate;
    cout << "Due date: " << endDate;
}
// getter
string Card:: GetCode(){
        return code;
}
string Card:: GetBorrowDate(){
        return startDate;
}
string Card:: GetDueDate(){
        return endDate;
}
string Card:: GetStudentName(){
        return studentName;
}
//seter
void Card::SetCode(string  BookCode){
        code=BookCode;
}
void Card::SetBorrowDate(string  BorrowDate){
        startDate=BorrowDate;
}
void Card::SetDueDate(string  DueDate){
        endDate=DueDate;
}
void Card::GetStudentName(string  s){
        studentName=s;
}

void Card::CreateCard(){
    std::cout << "\n\nEnter borrow code: ";
    std::cin >> code;
    std::cout << "Enter borrow date: ";
    std::cin >> startDate;
    std::cout << "Enter due date: ";
    std::cin >> endDate;
    std::cout << "Enter student name: ";
    std::cin >> studentName;
}
