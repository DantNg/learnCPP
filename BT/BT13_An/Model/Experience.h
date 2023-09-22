#ifndef EXPERIENCE_H
#define EXPERIENCE_H
#include "Employee.h"

class Experience: public Employee{
private:
    int ExpInYear;
    std::string ProSkill;

public:
    Experience(){}
    void showMe() override;
    void enterInfor() override;
    int  getExpInYear();
    string getProSkill();

    // Setters
    void setExpInYear(int expInYear);
    void setProSkill( string proSkill);


};
#endif