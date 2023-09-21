#pragma once
#define EXPERIENCE_TYPE 0
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Employee.h"
// Abstract classes for Employee types
class Experience : public Employee
{
public:
    Experience():Employee(){
        std::cout<<"Experience created"<<std::endl;
    };
    Experience(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email, int expInYear)
        : Employee(id, name, dob, phone, email, EXPERIENCE_TYPE), expYears(expInYear) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Experience in Years: " << expYears << std::endl;
    }
    int GetExpYears() const { return expYears; }
    void SetExpYears(int _expYears) { expYears = _expYears;}
private:
    int expYears;
};