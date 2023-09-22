#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Certificate.h"
class Employee
{
public:
    Employee(){
        //totalEmployees++;
    };
    Employee(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email, int type)
        : empID(id), fullName(name), birthDay(dob), phone(phone), email(email), empType(type), empCount(1) {
            totalEmployees++;
        }
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

    int getID() const { return empID; }
    int getEmpType() const { return empType; }
    int getEmpCount() const { return empCount; }
    std::string GetFullName() const { return fullName; }
    std::string GetBirthDate() const { return birthDay; }
    std::string GetPhone() const { return phone; }
    std::string GetEmail() const { return email; }
    static int GetTotalEmployees() { return totalEmployees; }

    void SetEmployeesID(int _id){empID = _id; }
    void SetFullName(std::string full_name) { fullName = full_name;}
    void SetBirthDate(std::string birthDate) { birthDate = birthDate;}
    void SetPhone(std::string _phone) { phone = _phone;}
    void SetEmail(std::string _email) { email = _email;}
    void SetEmpType(int emp_type) { empType = emp_type;}
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
