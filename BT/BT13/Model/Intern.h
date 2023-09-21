#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Employee.h"
class Intern : public Employee
{
public:
    Intern(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email,
           const std::string &majors, const std::string &semester, const std::string &university)
        : Employee(id, name, dob, phone, email, 2), majors(majors), currentSemester(semester), universityName(university) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Majors: " << majors << std::endl;
        std::cout << "Current Semester: " << currentSemester << std::endl;
        std::cout << "University Name: " << universityName << std::endl;
    }

private:
    std::string majors;
    std::string currentSemester;
    std::string universityName;
};