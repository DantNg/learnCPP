#include "GoodStudent.h"
#include "../Model/Student.h"

// Student::Student():fullName(""), doB(""), phoneNumber(""), universityName(""), gradeLevel(""), sex('F'){};

void GoodStudent:: ShowMyInfor()
{
    s->ShowMyInfor();
    cout << "GPA: " << gpa << endl;
    cout << "Best Reward Name: " << bestRewardName << endl;
}
