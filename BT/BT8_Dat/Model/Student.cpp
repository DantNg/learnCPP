#include "Student.h"

Student::Student() : fullName(""), age(0), className("") {}

void Student::EnterInfo() {
    std::cout << "Enter full name: ";
    std::cin.ignore();
    std::getline(std::cin, fullName);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter class name: ";
    std::cin.ignore();
    std::getline(std::cin, className);
}

void Student::DisplayInfo() const {
    std::cout << "Full Name: " << fullName << ", Age: " << age << ", Class: " << className << std::endl;
}

std::string Student::GetFullName() const {
    return fullName;
}
int Student::GetAge() const {
    return age;
}
std::string Student::GetClassName() const {
    return className;
}