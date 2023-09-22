#include<string>
#include "Fresher.h"
#include<iostream>
using namespace std;
// Getters
string Fresher::getGraduationRank()  { return Graduation_rank; }
string Fresher::getEducation()  { return Education; }

// Setters
void Fresher:: setGraduationRank( string graduationRank) { Graduation_rank = graduationRank; }
void Fresher:: setEducation( string education) { Education = education; }

void Fresher::showMe() {
    Employee::showMe();
    cout << "Graduation_rank: " << Graduation_rank << endl;
    cout << "Education: " << Education << endl;
}
void Fresher::enterInfor(){
    Employee::enterInfor();
    cout << "Enter Graduation_rank: ";
    cin >> Graduation_rank;
    cout << "Enter Education: ";
    cin >> Education;
}