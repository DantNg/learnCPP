#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Certificate.h"
class Employee
{
public:
    Employee(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email, int type)
        : empID(id), fullName(name), birthDay(dob), phone(phone), email(email), empType(type), empCount(1) {}
    virtual ~Employee()
    {
    }
    virtual void ShowInfo() const
    {
        std::cout << "Employee ID: " << empID << std::endl;
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Date of Birth: " << birthDay << std::endl;
        std::cout << "Phone: " << phone << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Employee Type: " << empType << std::endl;
    }

    virtual void AddCertificate(int id, const std::string &name, const std::string &rank, const std::string &date)
    {
        Certificate cert(id, name, rank, date);
        certificates.push_back(cert);
    }

    int getID() const
    {
        return empID;
    }
    int getEmpType() const
    {
        return empType;
    }
    static int GetTotalEmployees()
    {
        return totalEmployees;
    }

protected:
    int empID;
    std::string fullName;
    std::string birthDay;
    std::string phone;
    std::string email;
    int empType;
    int empCount;
    std::vector<Certificate> certificates;

private:
    static int totalEmployees;
};
int Employee::totalEmployees = 0;
