#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>
using namespace std;
class Student{
    private:
        string fullName;
        string grade;
        int age;
    public:
    Student(){}
    ~Student(){}
    string GetFullName();
    string GetGrade();
    int GetAge();

    void SetAge(int Age);
    void SetFullName(string FullName);
    void setGrade(string GradeName);

    void ShowInfor();
    void EnterInfor();
};
#endif

