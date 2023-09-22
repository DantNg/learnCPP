#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <vector>
#include "Certificate.h"
using namespace std;
class Employee {
private:
    int ID;
    string FullName;
    string BirthDay;
    string Phone;
    string Email;
    string Employee_type;
    int Employee_count;
    vector<Certificate> listCertificate;

public:
    Employee(int ID, string FullName,string BirthDay,string Phone,string Email,string Employee_type){
        this->ID=ID;
        this->FullName=FullName;
        this->BirthDay=BirthDay;
        this->Phone=Phone;
        this->Email=Email;
        this->Employee_type=Employee_type;
    }
    virtual void enterInfor();
    virtual void showMe();
    int getID();
    string getFullName();
    string getBirthDay();
    string getPhone();
    string getEmail();
    string getEmployeeType();
    int getEmployeeCount();

    void addCertificate(Certificate certificate);
    void setID(int id);
    void setFullName( string fullName);
    void setBirthDay( string birthDay);
    void setPhone( string phone);
    void setEmail( string email);
    void setEmployeeType( string employeeType);
    void setEmployeeCount(int employee_count);


    Employee() { }


    ~Employee() {}
};


#endif
