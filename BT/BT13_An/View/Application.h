#ifndef APPLICATION_H
#define APPLICATION_H

#include "../Controller/ManageEmployee.h"
#include <iostream>
#include <vector>


class Application {
public:
    enum MenuChoice {
        ADD_INTERN = 1,
        ADD_FRESHER,
        ADD_EXPERIENCE,
        ADD_CERTIFICATE,
        DELETE_EMPLOYEE,
        UPDATE_EMPLOYEE,
        SHOW_ALL,
        EXIT
    };

    Application();
    void Run();
private:
    ManageEmployee manageEmployee;


};


#endif // APPLICATION_H
