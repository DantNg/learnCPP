#include "Application.h"
Application::Application() : studentList(std::vector<Student>()), manageCard(ManageCard()) {}

void Application::Run() {
    while (true) {
        int choice;
        std::cout << "\n\nMenu:\n";
        std::cout << ADD_STUDENT << ". Add student\n";
        std::cout << BORROW_BOOK << ". Borrow book\n";
        std::cout << DISPLAY_CARDS << ". Display borrow cards\n";
        std::cout << EXIT << ". Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<MenuChoice>(choice)) {
            case ADD_STUDENT: {
                Student student;
                student.EnterInfor();
                studentList.push_back(student);
                break;
            }
            case BORROW_BOOK: {
                manageCard.createCard();
                break;
            }
            case DISPLAY_CARDS: {
                manageCard.show();
                break;
            }
            case EXIT: {
                return;
            }
            default: {
                std::cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }
    }
}
