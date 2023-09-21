#pragma once
#define INTERN_TYPE 2
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Employee.h"
class Intern : public Employee
{
public:
    Intern():Employee(){};
    Intern(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email,
           const std::string &majors, const std::string &semester, const std::string &university)
        : Employee(id, name, dob, phone, email, INTERN_TYPE), majors(majors), currentSemester(semester), universityName(university) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Majors: " << majors << std::endl;
        std::cout << "Current Semester: " << currentSemester << std::endl;
        std::cout << "University Name: " << universityName << std::endl;
    }
    std::string GetMajors() const { return majors; }
    std::string GetCurrentSemester() const { return currentSemester; }
    std::string GetUniversity() const { return universityName; }

    void GetMajors(std::string _major){majors = _major;}
    void GetCurrentSemester(std::string _semester){currentSemester =_semester;}
    void GetUniversity(std::string _university){universityName =_university;}
private:
    std::string majors;
    std::string currentSemester;
    std::string universityName;
};