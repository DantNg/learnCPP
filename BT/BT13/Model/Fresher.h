#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Employee.h"
class Fresher : public Employee
{
public:
    Fresher(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email,
            const std::string &gradDate, const std::string &gradRank, const std::string &edu)
        : Employee(id, name, dob, phone, email, 1), graduationDate(gradDate), graduationRank(gradRank), education(edu) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Graduation Date: " << graduationDate << std::endl;
        std::cout << "Graduation Rank: " << graduationRank << std::endl;
        std::cout << "Education: " << education << std::endl;
    }

private:
    std::string graduationDate;
    std::string graduationRank;
    std::string education;
};
