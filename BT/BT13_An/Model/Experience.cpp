#include <string>
#include<iostream>
#include "Experience.h"
using namespace std;

// Getters
int Experience::getExpInYear(){ return ExpInYear; }
string Experience::getProSkill(){ return ProSkill; }

// Setters
void Experience::setExpInYear(int expInYear) { ExpInYear = expInYear; }
void Experience::setProSkill( string proSkill) { ProSkill = proSkill; }

void Experience::showMe() {
    Employee::showMe();
    cout << "ExpInYear: " << ExpInYear << endl;
    cout << "ProSkill: " << ProSkill << endl;
}
void Experience::enterInfor(){
    Employee::enterInfor();
    cout << "Enter ExpInYear: ";
    cin >> ExpInYear;
    cout << "Enter ProSkill: ";
    cin >> ProSkill;
}

