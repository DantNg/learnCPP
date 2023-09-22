#include "LibraryManagement.h"
void LibraryManagement::BorrowBook(const std::vector<Student>& studentList) {
    int studentIndex;
    std::cout << "Select student: " << std::endl;
    for (size_t i = 0; i < studentList.size(); ++i) {
        std::cout << i + 1 << ". ";
        studentList[i].DisplayInfo();
    }
    std::cin >> studentIndex;
    if (studentIndex >= 1 && studentIndex <= static_cast<int>(studentList.size())) {
        Card card;
        card.EntryBorrowCard(studentIndex - 1,studentList);
        cardList.push_back(card);
    } else {
        std::cout << "Invalid student selection.\n";
    }
}

void LibraryManagement::ReturnBook() {
    int returnCode;
    std::cout << "Enter return code: ";
    std::cin >> returnCode;
    for (size_t i = 0; i < cardList.size(); ++i) {
        if (cardList[i].GetBorrowCode() == returnCode) {
            cardList.erase(cardList.begin() + i);
            std::cout << "Book returned.\n";
            return;
        }
    }
    std::cout << "Return code not found.\n";
}

void LibraryManagement::DisplayBorrowCards() const {
    std::cout << "Borrow Cards:\n";
    for (const Card& card : cardList) {
        card.DisplayInfo();
    }
}