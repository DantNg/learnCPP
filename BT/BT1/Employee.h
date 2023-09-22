#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee
{
public:
    Employee(std::string name, int age, std::string gender, std::string address);
    virtual ~Employee();
    virtual void enterInformation();
    virtual void displayInfomation();
    std::string getName();

protected:
    std::string name;
    int age;
    std::string gender;
    std::string address;
};

class Worker : public Employee
{
public:
    Worker(std::string name, int age, std::string gender, std::string address, int bac);
    ~Worker();
    void enterInformation() override;
    void displayInfomation() override;

private:
    int bac;
};

class Engineer : public Employee
{
public:
    Engineer(std::string name, int age, std::string gender, std::string address, std::string major);
    ~Engineer();
    void enterInformation() override;
    void displayInfomation() override;

private:
    std::string major;
};

class Officer : public Employee
{
public:
    Officer(std::string name, int age, std::string gender, std::string address, std::string worktype);
    ~Officer();
    void enterInformation() override;
    void displayInfomation() override;

private:
    std::string worktype;
};

#endif // EMPLOYEE_H
