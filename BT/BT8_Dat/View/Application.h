#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>
#include "../Controller/LibraryManagement.h"

class Application {
public:
    enum MenuChoice {
        ADD_STUDENT = 1,
        BORROW_BOOK,
        RETURN_BOOK,
        DISPLAY_CARDS,
        EXIT
    };

    Application();
    void Run();

private:
    std::vector<Student> studentList;
    LibraryManagement libraryManagement;
};


#endif // APPLICATION_H
