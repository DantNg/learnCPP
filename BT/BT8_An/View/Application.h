#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>
#include "../Controller/ManageCard.h"

class Application {
public:
    enum MenuChoice {
        ADD_STUDENT = 1,
        BORROW_BOOK,
        DISPLAY_CARDS,
        EXIT
    };

    Application();
    void Run();

private:
    std::vector<Student> studentList;
    ManageCard manageCard;
};


#endif // APPLICATION_H
