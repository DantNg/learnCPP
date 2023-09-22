#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include<iostream>
#include"Employee.h"

class Experience : public Employee
{
    private:
        int ExpYear;
        std::string ProSkill;
    public:
        Experience(int _ID, std::string _FullName, std::string _BirthDay, std::string _Phone, std::string _Email, int _ExpYear, std::string _ProSkill);
        
        ~Experience();

        void SetExpYear(int _ExpYear);

        int GetExpYear();

        void SetProSkill(std::string _ProSkill);

        std::string GetProSkill();
};

#endif // EXPERIENCE_H