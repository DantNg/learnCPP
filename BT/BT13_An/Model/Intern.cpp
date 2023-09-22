#include<string>
#include "Intern.h"
#include<iostream>
using namespace std;


void Intern::showMe() {
    Employee::showMe();
    cout << "Major: " << Majors << endl;
    cout << "Semester: " << Semester << endl;
    cout << "University Name: " << University_name << endl;
}
void Intern::enterInfor() {
    Employee::enterInfor();
    cout << "Enter major: ";
    cin >> Majors;
    cout << "Enter semester: ";
    cin >> Semester;
    cout << "Enter university name: ";
    cin >> University_name;
    // return Intern( ID,  FullName, BirthDay, Phone, Email, Employee_type,  Majors,  Semester,  University_name);
    
}

string Intern::getMajors()  { return Majors; }
int Intern::getSemester()  { return Semester; }
string Intern::getUniversityName()  { return University_name; }

// Setters
void Intern::setMajors( string majors) { Majors = majors; }
void Intern::setSemester(int semester) { Semester = semester; }
void Intern::setUniversityName( string universityName){University_name = universityName;} 