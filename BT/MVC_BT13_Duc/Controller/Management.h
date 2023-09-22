#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include<iostream>
#include<vector>
#include<memory>
#include"..\Model\Employee.h"
#include"..\View\UserInterface.h"

class Management
{
    private:
        UserInterface userinterface;
        std::vector<std::unique_ptr<Employee>> management;
    public:
        Management();

        ~Management();

        void Run();

        void AddNewEmp(Employee* e);

        void DeleteEmp(int ID);

        void ShowAllEmp();

        void SearchID(int ID);

        void SearchType();
};

#endif // MANAGEMENT_H