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
enum Employee_Type{
    EXPERIENCE,
    FRESHER,
    INTERN
    };

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
                switch (static_cast<Employee_Type>(emp->getEmpType()))
                {
                case EXPERIENCE:
                    *dynamic_cast<Experience *>(emp) = *dynamic_cast<Experience *>(newInfo);
                    break;

                case FRESHER:
                    *dynamic_cast<Fresher *>(emp) = *dynamic_cast<Fresher *>(newInfo);
                    break;

                case INTERN:
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


    void ShowAllExperiences() {
        std::cout << "Experience Employees:" << std::endl;
        for (const Employee* emp : employees) {
            if (static_cast<Employee_Type>(emp->getEmpType()) == EXPERIENCE) {
                emp->ShowInfo();
                std::cout << std::endl;
            }
        }
    }

    void ShowAllFreshers() {
        std::cout << "Fresher Employees:" << std::endl;
        for (const Employee* emp : employees) {
            if (static_cast<Employee_Type>(emp->getEmpType()) == FRESHER) {
                emp->ShowInfo();
                std::cout << std::endl;
            }
        }
    }
    void ShowAllInterns() {
        std::cout << "Intern Employees:" << std::endl;
        for (const Employee* emp : employees) {
            if (static_cast<Employee_Type>(emp->getEmpType()) == INTERN) {
                emp->ShowInfo();
                std::cout << std::endl;
            }
        }
    }
private:
    std::vector<Employee *> employees;
};