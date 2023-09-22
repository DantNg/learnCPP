#ifndef MANAGEEMPLOYEE_H
#define MANAGEEMPLOYEE_H
#include<string>
#include<vector>
#include "../Model/Employee.h"

class ManageEmployee{
    public:
        vector<Employee*> listEmployee;
    public:
        ManageEmployee(){}
        void addEmployee(Employee* employee);
        void deleteEmployee();
        void showAll();
        void updateEmployee();
        int size();
        void addCerti();
        // void createEmployee(){
            
        // }
};
#endif