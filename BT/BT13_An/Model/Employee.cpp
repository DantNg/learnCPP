#include "Employee.h"
#include "Certificate.h"
#include<string>
#include<vector>
#include<iostream>
// #include "function.h"
using namespace std;


 void Employee::enterInfor(){
    cout << "Enter id: ";
    cin >> ID;
    cout << "Enter full name: ";
    cin >> FullName;
    cout << "Enter DOB: ";
    cin >> BirthDay;
    cout << "Enter Email: ";
    cin >> Email;
    cout << "Enter Type: ";
    cin >> Employee_type;
    // return Employee(ID, FullName, BirthDay, Phone, Email, Employee_type);
    

}

void Employee::addCertificate(Certificate certificate){
    listCertificate.push_back(certificate);
}

 void Employee::showMe(){
    cout << "Id: " << ID <<endl;
    cout << "FullName: "<< FullName << endl;
    cout << "DOB: " <<BirthDay<<endl;
    cout << "Email: " <<Email <<endl;
    cout << "Type: " <<Employee_type <<endl;
    cout << "Count: " << Employee_count<<endl;
    for(Certificate c: listCertificate){
        c.showMe();
    }
}



 // Getters
int Employee::getID()  { return ID; }
string Employee::getFullName()  { return FullName; }
string Employee::getBirthDay()  { return BirthDay; }
string Employee::getPhone()  { return Phone; }
string Employee::getEmail()  { return Email; }
string Employee::getEmployeeType()  { return Employee_type; }
int Employee::getEmployeeCount() { return Employee_count; }

// Setters
void Employee::setID(int id) { ID = id; }
void Employee::setFullName( string fullName) { FullName = fullName; }
void Employee::setBirthDay( string birthDay) { BirthDay = birthDay; }
void Employee::setPhone( string phone) { Phone = phone; }
void Employee::setEmail( string email) { Email = email; }
void Employee::setEmployeeType( string employeeType) { Employee_type = employeeType; }
void Employee::setEmployeeCount(int employee_count) { Employee_count =employee_count; }

