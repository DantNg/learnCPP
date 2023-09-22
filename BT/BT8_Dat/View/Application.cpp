#include "Application.h"
Application::Application() : studentList(std::vector<Student>()), libraryManagement(LibraryManagement()) {}

void Application::Run() {
    while (true) {
        int choice;
        std::cout << "\n\nMenu:\n";
        std::cout << ADD_STUDENT << ". Add student\n";
        std::cout << BORROW_BOOK << ". Borrow book\n";
        std::cout << RETURN_BOOK << ". Return book\n";
        std::cout << DISPLAY_CARDS << ". Display borrow cards\n";
        std::cout << EXIT << ". Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<MenuChoice>(choice)) {
            case ADD_STUDENT: {
                Student student;
                student.EnterInfo();
                studentList.push_back(student);
                break;
            }
            case BORROW_BOOK: {
                libraryManagement.BorrowBook(studentList);
                break;
            }
            case RETURN_BOOK: {
                libraryManagement.ReturnBook();
                break;
            }
            case DISPLAY_CARDS: {
                libraryManagement.DisplayBorrowCards();
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
