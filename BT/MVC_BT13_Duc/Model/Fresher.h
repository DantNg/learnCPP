#ifndef FRESHER_H
#define FRESHER_H

#include<iostream>
#include"Employee.h"

class Fresher : public Employee
{
    private:
        std::string GraduationDate;
        int GraduationRank;
        std::string Education;
    public:
        Fresher(int _ID, std::string& _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, std::string _GraduationDate, int _GraduationRank, std::string _Education);
        
        ~Fresher() {}

        void SetGraDate(std::string _GraduationDate);

        std::string GetGraDate();

        void SetGraRank(int _GraduationRank);

        int GetGraRank();

        void SetEdu(std::string _Education);

        std::string GetEdu();
};

#endif // FRESHER_H