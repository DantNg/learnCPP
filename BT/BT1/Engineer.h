#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee_test.h"
using namespace std;

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