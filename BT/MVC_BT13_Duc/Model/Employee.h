#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include<vector>
#include"Certificate.h"

enum EType
{
    EXPERIENCE,
    FRESHER,
    INTERN
};

class Employee
{
    private:
        int ID;
        std::string FullName;
        std::string BirthDay;
        std::string Phone;
        std::string Email;
        EType EmpType;
        std::vector<Certificate> EmpCertificate;
    public:
        Employee(int _ID, std::string _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, EType _EmpType);

        virtual ~Employee();

        void SetID(int _ID);

        int GetID();

        void SetFullName(std::string _FullName);

        std::string GetFullName();

        void SetBirthDay(std::string _BirthDay);

        std::string GetBirthDay();

        void SetPhone(std::string _Phone);

        std::string GetPhone();

        void SetEmail(std::string _Email);

        std::string GetEmail();

        void SetEmpType(int _EmpType);

        int GetEmpType();

        void SetEmpCer(std::vector<Certificate> _EmpCertificate);

        std::vector<Certificate> GetEmpCer();
};

#endif // EMPLOYEE_H
