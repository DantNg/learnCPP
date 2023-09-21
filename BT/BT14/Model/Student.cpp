
#include "Student.h"
#include<iostream>
using namespace std;

Student::Student():fullName(""), doB(""), phoneNumber(""), universityName(""), gradeLevel(""), sex('F'){};
void Student::ShowMyInfor(){
        cout << "Name: " << fullName << endl;
        cout << "Date of birth: " << doB << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout <<  "Univerity Name: "<< universityName << endl;
        cout << "Grade level: " <<gradeLevel <<endl;
    }

string Student::getName(){
    return fullName;
}
string Student::getGradeLevel(){
    return gradeLevel;
}
string Student::getDOB(){
    return doB;
}
string Student::getPhoneNumber(){
    return phoneNumber;
}
string Student::getUniversityName(){
    return universityName;
}
string Student::getGradeLevel(){
    return gradeLevel;
}
char Student:: getGender(){
    return sex;
}

void Student::EnterInfor(){
    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Enter date of birth: ";
    cin >> doB;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter university name: ";
    cin >> universityName;
    cout << "Enter grade level: ";
    cin >> gradeLevel;
    cout << "Enter gender: ";
    cin >> sex;
}
void Student::setName(string FullName){
    fullName=fullName;
}
void Student::setGradeLevel(string GradeLevel){
    gradeLevel=GradeLevel;
}
void Student::setDOB(string DOB){
    doB=DOB;
}
void Student::setPhoneNumber(string PhoneNumber){
    phoneNumber=phoneNumber;
}
void Student::setUniversityName(string UniversityName){
    universityName=UniversityName;
}
void Student::setGender(char gender){
    sex=gender;
}

