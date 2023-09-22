#include<iostream>
#include"Fresher.h"

Fresher::Fresher(int _ID, std::string& _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, std::string _GraduationDate, int _GraduationRank, std::string _Education)
    : Employee(_ID, _FullName, _BirthDay, _Phone, _Email, 1), GraduationDate(_GraduationDate), GraduationRank(_GraduationRank), Education(_Education) {}
        
Fresher::~Fresher() {}

void Fresher::SetGraDate(std::string _GraduationDate)
{
    GraduationDate = _GraduationDate;
}

std::string Fresher::GetGraDate()
{
    return GraduationDate;
}

void Fresher::SetGraRank(int _GraduationRank)
{
    GraduationRank = _GraduationRank;
}

int Fresher::GetGraRank()
{
    return GraduationRank;
}

void Fresher::SetEdu(std::string _Education)
{
    Education = _Education;
}

std::string Fresher::GetEdu()
{
    return Education;
}
