#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Model/Employee.h"
#include "../Model/Fresher.h"
#include "../Model/Intern.h"
#include "../Model/Experience.h"
class EmployeeManagement
{
public:
    EmployeeManagement()
    {
        std::cout << "Employee Management created" << std::endl;
    }
    ~EmployeeManagement()
    {
        for (Employee *ee : employees)
        {
            delete ee;
        }
        std::cout << "Employee Management deleted!" << std::endl;
    }
    void AddEmployee(Employee *emp)
    {
        employees.push_back(emp);
    }

    void EditEmployee(int id, Employee *newInfo)
    {
        for (Employee *&emp : employees)
        {
            if (emp->getID() == id && emp->getEmpType() == newInfo->getEmpType())
            {
                std::cout<<"Modified employee!"<<std::endl;
                switch (emp->getEmpType())
                {
                case 0:
                    *dynamic_cast<Experience *>(emp) = *dynamic_cast<Experience *>(newInfo);
                    break;

                case 1:
                    *dynamic_cast<Fresher *>(emp) = *dynamic_cast<Fresher *>(newInfo);
                    break;

                case 2:
                    *dynamic_cast<Intern *>(emp) = *dynamic_cast<Intern *>(newInfo);
                    break;
                default:
                    break;
                };
                break;
            }
        }
    }

    void DeleteEmployee(int id)
    {
        auto it = employees.begin();
        while (it != employees.end())
        {
            if ((*it)->getID() == id)
            {
                delete *it; // Xóa đối tượng Employee khi xóa nhân viên
                it = employees.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
   
    
    void ShowAllEmployees() const
    {
        for (const Employee *emp : employees)
        {
            emp->ShowInfo();
            std::cout << std::endl;
        }
    }

    void ShowAllInterns() {
        cout << "Intern Employees:" << endl;
        for (const Employee* emp : employees) {
            if (emp->GetEmployeeType() == 2) {
                emp->ShowInfo();
                cout << endl;
            }
        }
    }

    void ShowAllExperiences() {
        cout << "Experience Employees:" << endl;
        for (const Employee* emp : employees) {
            if (emp->GetEmployeeType() == 0) {
                emp->ShowInfo();
                cout << endl;
            }
        }
    }

    void ShowAllFreshers() {
        cout << "Fresher Employees:" << endl;
        for (const Employee* emp : employees) {
            if (emp->GetEmployeeType() == 1) {
                emp->ShowInfo();
                cout << endl;
            }
        }
    }
private:
    std::vector<Employee *> employees;
};