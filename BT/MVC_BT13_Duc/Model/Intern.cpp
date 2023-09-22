#include<iostream>
#include"Intern.h"

Intern::Intern(int _ID, std::string _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, std::string _Major, std::string _Semester, std::string _University)
    : Employee(_ID, _FullName, _BirthDay, _Phone, _Email, 2), Major(_Major), Semester(_Semester), University(_University) {}

Intern::~Intern() {}

void Intern::SetMajor(std::string _Major)
{
    Major = _Major;
}
        
std::string Intern::GetMajor()
{
    return Major;
}

void Intern::SetSem(std::string _Semester)
{
    Semester = _Semester;
}

std::string Intern::GetSem()
{
    return Semester;
}

void Intern::SetUni(std::string _University)
{
    University = _University;
}

std::string Intern::GetUni()
{
    return University;
}
