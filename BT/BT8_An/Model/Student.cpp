#include "Student.h"
// Student::Student() : fullName(""), age(0), grade("") {}

string Student::GetFullName(){
    return fullName;
}
string Student::GetGrade(){
    return grade;
}
int Student::GetAge(){
    return age;
}

void Student::SetAge(int Age){
    age=Age;
}
void Student::SetFullName(string FullName){
    fullName=FullName;
}
void Student::setGrade(string GradeName){
    grade=GradeName;
}

void Student::ShowInfor(){
    cout << "Full Name: " << fullName << ", Age: " << age << ", Class: " << grade << endl;
}
void Student::EnterInfor(){
    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter grade name: ";
    cin.ignore();
    getline(cin, grade);
}