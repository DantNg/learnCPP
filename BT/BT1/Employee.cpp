#include "employee.h"

Employee::Employee(std::string name, int age, std::string gender, std::string address)
    : name(name), age(age), gender(gender), address(address) {}

Employee::~Employee()
{
    std::cout << "Can bo released" << std::endl;
}

void Employee::enterInformation()
{
    std::cout << "Name : ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gender: ";
    std::cin >> gender;
    std::cout << "Address: ";
    std::cin >> address;
}

void Employee::displayInfomation()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Address: " << address << std::endl;
}

std::string Employee::getName()
{
    return name;
}

Worker::Worker(std::string name, int age, std::string gender, std::string address, int bac)
    : Employee(name, age, gender, address), bac(bac) {}

Worker::~Worker()
{
    std::cout << "Cong nhan released" << std::endl;
}

void Worker::enterInformation()
{
    Employee::enterInformation();
    std::cout << "Employee rank: ";
    std::cin >> bac;
}

void Worker::displayInfomation()
{
    Employee::displayInfomation();
    std::cout << "Employee rank: " << bac << std::endl;
}

Engineer::Engineer(std::string name, int age, std::string gender, std::string address, std::string major)
    : Employee(name, age, gender, address), major(major) {}

Engineer::~Engineer()
{
    std::cout << "Engineer released" << std::endl;
}

void Engineer::enterInformation()
{
    Employee::enterInformation();
    std::cout << "Major : ";
    std::cin >> major;
}

void Engineer::displayInfomation()
{
    Employee::displayInfomation();
    std::cout << "Major" << major << std::endl;
}

Officer::Officer(std::string name, int age, std::string gender, std::string address, std::string worktype)
    : Employee(name, age, gender, address), worktype(worktype) {}

Officer::~Officer()
{
    std::cout << "Officer released" << std::endl;
}

void Officer::enterInformation()
{
    Employee::enterInformation();
    std::cout << "Nhap cong viec: ";
    std::cin >> worktype;
}

void Officer::displayInfomation()
{
    Employee::displayInfomation();
    std::cout << "Work type: " << worktype << std::endl;
}
