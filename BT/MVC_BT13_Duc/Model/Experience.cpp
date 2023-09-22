#include<iostream>
#include"Experience.h"

Experience::Experience(int _ID, std::string _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, int _ExpYear, std::string _ProSkill)
    : Employee(_ID, _FullName, _BirthDay, _Phone, _Email, 0), ExpYear(_ExpYear), ProSkill(_ProSkill) {}
        
Experience::~Experience() {}

void Experience::SetExpYear(int _ExpYear)
{
    ExpYear = _ExpYear;
}

int Experience::GetExpYear()
{
    return ExpYear;
}

void Experience::SetProSkill(std::string _ProSkill)
{
    ProSkill = _ProSkill;
}

std::string Experience::GetProSkill()
{
    return ProSkill;
}
