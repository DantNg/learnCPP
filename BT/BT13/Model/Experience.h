#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Employee.h"
// Abstract classes for Employee types
class Experience : public Employee
{
public:
    Experience(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email, int expInYear)
        : Employee(id, name, dob, phone, email, 0), expYears(expInYear) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Experience in Years: " << expYears << std::endl;
    }

private:
    int expYears;
};