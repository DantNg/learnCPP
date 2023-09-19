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

// Lớp Worker kế thừa từ Employee
class Worker : public Employee
{
public:
    Worker(string name, int age, string gender, string address, int bac)
        : Employee(name, age, gender, address), bac(bac) {}
    ~Worker()
    {
        cout << "Cong nhan released" << endl;
    }
    void enterInformation()
    {
        Employee::enterInformation();
        cout << "Employee rank: ";
        cin >> bac;
    }

    void displayInfomation()
    {
        Employee::displayInfomation();
        cout << "Employee rank: " << bac << endl;
    }

private:
    int bac;
};

// Lớp Engineer kế thừa từ Employee
class Engineer : public Employee
{
public:
    Engineer(string name, int age, string gender, string address, string major)
        : Employee(name, age, gender, address), major(major) {}
    ~Engineer()
    {
        cout << "Engineer released" << endl;
    }
    void enterInformation()
    {
        Employee::enterInformation();
        cout << "Major : ";
        cin >> major;
    }

    void displayInfomation()
    {
        Employee::displayInfomation();
        cout << "Major" << major << endl;
    }

private:
    string major;
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
