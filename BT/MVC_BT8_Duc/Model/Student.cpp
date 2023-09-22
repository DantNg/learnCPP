#include "Student.h"

Student::Student(std::string _Name, int _Age, std::string _Class) : Name(_Name), Age(_Age), Class(_Class) {}

Student::~Student() {}

void Student::SetName(std::string _Name)
{
    Name = _Name;
}

std::string Student::GetName()
{
    return Name;
}

void Student::SetAge(int _Age)
{
    Age = _Age;
}

int Student::GetAge()
{
    return Age;
}

void Student::SetClass(std::string _Class)
{
    Class = _Class;
}

std::string Student::GetClass()
{
    return Class;
}
