#include<iostream>
#include<string>
#include"Employee.h"

Employee::Employee(int _ID, std::string _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, int _EmpType)
    : ID(_ID), FullName(_FullName), BirthDay(_BirthDay), Phone(_Phone), Email(_Email), EmpType(_EmpType) {}

Employee::~Employee() {}

void Employee::SetID(int _ID)
{
    ID = _ID;
}

int Employee::GetID()
{
    return ID;
}

void Employee::SetFullName(std::string _FullName)
{
    FullName = _FullName;
}

std::string Employee::GetFullName()
{
    return FullName;
}

void Employee::SetBirthDay(std::string _BirthDay)
{
    BirthDay = _BirthDay;
}

std::string Employee::GetBirthDay()
{
    return BirthDay;
}

void Employee::SetPhone(std::string _Phone)
{
    Phone = _Phone;
}

std::string Employee::GetPhone()
{
    return Phone;
}

void Employee::SetEmail(std::string _Email)
{
    Email = _Email;
}

std::string Employee::GetEmail()
{
    return Email;
}

void Employee::SetEmpType(int _EmpType)
{
    EmpType = _EmpType;
}

int Employee::GetEmpType()
{
    return EmpType;
}

void Employee::SetEmpCer(std::vector<Certificate> _EmpCertificate)
{
    EmpCertificate = _EmpCertificate;
}

std::vector<Certificate> Employee::GetEmpCer()
{
    return EmpCertificate;
}
