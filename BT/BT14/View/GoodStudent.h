#ifndef GOODSTUDENT_H
#define GOODSTDENT_H
#include <string>
#include <vector>
#include<iostream>
#include "Student.h"
using namespace std;
// Student::Student():fullName(""), doB(""), phoneNumber(""), universityName(""), gradeLevel(""), sex('F'){};
class GoodStudent: public Student{
    public:
        double gpa;
        string bestRewardName;
        Student* s;
    public:
        GoodStudent(){}
        // GoodStudent(string fullName, char sex, string doB, string phoneNumber, string universityName, string gradeLevel, double gpa, string bestRewardName): Student( fullName,  sex,  doB,  phoneNumber,  universityName,  gradeLevel), gpa(gpa), bestRewardName(bestRewardName){}
        ~GoodStudent(){}

        
        void enterInfor();

        void ShowMyInfor();
};
#endif