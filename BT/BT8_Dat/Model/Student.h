#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
class Student {
public:
    Student();
    void EnterInfo();
    void DisplayInfo() const;
    std::string GetFullName() const;
    int GetAge() const;
    std::string GetClassName() const;
private:
    std::string fullName;
    int age;
    std::string className;
};

#endif // STUDENT_H
