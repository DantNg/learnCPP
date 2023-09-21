#pragma once
#define FRESHER_TYPE 1
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Employee.h"
class Fresher : public Employee
{
public:
    Fresher():Employee(){};
    Fresher(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email,
            const std::string &gradDate, const std::string &gradRank, const std::string &edu)
        : Employee(id, name, dob, phone, email, FRESHER_TYPE), graduationDate(gradDate), graduationRank(gradRank), education(edu) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Graduation Date: " << graduationDate << std::endl;
        std::cout << "Graduation Rank: " << graduationRank << std::endl;
        std::cout << "Education: " << education << std::endl;
    }
    std::string GetGraduationDate() const { return graduationDate; }
    std::string GetGraduationRank() const { return graduationRank; }
    std::string GetEducation() const { return education; }

    void SetGraduationDate(const std::string _graduationDate) { graduationDate = _graduationDate; }
    void SetGraduationRank(const std::string _graduationRank) { graduationRank = _graduationRank; }
    void SetEducation(const std::string _education) { education = _education;}
private:
    std::string graduationDate;
    std::string graduationRank;
    std::string education;
};
