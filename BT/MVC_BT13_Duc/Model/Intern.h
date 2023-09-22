#ifndef INTERN_H
#define INTERN_H

#include<iostream>
#include"Employee.h"

class Intern : public Employee
{
    private:
        std::string Major;
        std::string Semester;
        std::string University;
    public:
        Intern(int _ID, std::string _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, std::string _Major, std::string _Semester, std::string _University);

        ~Intern();

        void SetMajor(std::string _Major);
        
        std::string GetMajor();

        void SetSem(std::string _Semester);

        std::string GetSem();

        void SetUni(std::string _University);

        std::string GetUni();
};

#endif // INTERN_H