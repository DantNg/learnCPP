#ifndef INTERN_H
#define INTERN_H
#include<iostream>
#include "Employee.h"
#include<string>
using namespace std;
class Intern: public Employee{
private:
    string Majors;
    int Semester;
    string University_name;

public:

    void showMe() override;
    void enterInfor() override;
    Intern(){}
    Intern(int ID, string FullName,string BirthDay,string Phone,string Email,string Employee_type, string Majors, int Semester, string University_name):Employee(ID, FullName, BirthDay, Phone, Email, Employee_type), Majors(Majors), Semester(Semester), University_name(University_name){}
    // Getters
    string getMajors();
    int getSemester();
    string getUniversityName();

    // Setters
    void setMajors( string majors);
    void setSemester(int semester);
    void setUniversityName( string universityName);
};
#endif