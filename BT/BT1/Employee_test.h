#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp cơ sở Employee
class Employee
{
public:

    Employee(string name, int age, string gender, string address)
        : name(name), age(age), gender(gender), address(address) {}
    virtual ~Employee()
    {
        cout << "Can bo release" << endl;
    }
    virtual void enterInformation()
    {
        cout << "Name : ";
        cin>>name;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin>>gender;
        cout << "Address: ";
        cin>> address;
    }

    virtual void displayInfomation()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
    }
    string getName()
    {
        return name;
    }

protected:
    string name;
    int age;
    string gender;
    string address;
};


// Lớp Officer kế thừa từ Employee
class Officer : public Employee
{
public:
    Officer(string name, int age, string gender, string address, string worktype)
        : Employee(name, age, gender, address), worktype(worktype) {}
    ~Officer()
    {
        cout << "Officer released" << endl;
    }
    void enterInformation()
    {
        Employee::enterInformation();
        cout << "Nhap cong viec: ";
        cin >> worktype;
    }

    void displayInfomation()
    {
        Employee::displayInfomation();
        cout << "Work type: " << worktype << endl;
    }

private:
    string worktype;
};
