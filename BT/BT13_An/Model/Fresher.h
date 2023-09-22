#include <string>
#include "Employee.h"
using namespace std;
class Fresher: public Employee{
private:
    std::string Graduation_rank;
    std::string Education;

public:
    Fresher(){}
    void showMe() override;
    void enterInfor() override;

    // Getters
    string getGraduationRank();
    string getEducation();

    // Setters
    void setGraduationRank(string graduationRank); 
    void setEducation(string education);
};
