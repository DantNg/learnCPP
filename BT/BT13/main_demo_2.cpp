#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract class Employee
class Employee {
protected:
    int ID;
    string FullName;
    string BirthDay;
    string Phone;
    string Email;
    int Employee_type;
    static int Employee_count;

public:
    Employee() {
        Employee_count++;
        ID = Employee_count;
    }

    virtual void ShowInfo() = 0; // Abstract method

    // Getter and Setter methods 
    int GetID() { return ID; }
    string GetFullName() { return FullName; }
    void SetFullName(string name) { FullName = name; }
    static int GetEmployeeCount() { return Employee_count; }
    int GetEmployeeType() { return Employee_type; }
};

int Employee::Employee_count = 0;

// Certificate class
class Certificate {
protected:
    int CertificatedID;
    string CertificateName;
    string CertificateRank;
    string CertificatedDate;

public:
    Certificate(int id, string name, string rank, string date)
        : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {}
};

// Experience class
class Experience : public Employee {
private:
    int ExpInYear;
    string ProSkill;

public:
    Experience(int expYear, string skill)
        : ExpInYear(expYear), ProSkill(skill) {
        Employee_type = 0; // Employee_type 0 corresponds to Experience
    }

    void ShowInfo() override {
        cout << "Experience Employee" << endl;
        cout << "ID: " << ID << endl;
        cout << "Full Name: " << FullName << endl;
        cout << "BirthDay: " << BirthDay << endl;
        cout << "Phone: " << Phone << endl;
        cout << "Email: " << Email << endl;
        cout << "Experience In Years: " << ExpInYear << endl;
        cout << "Professional Skill: " << ProSkill << endl;
    }
};

// Fresher class
class Fresher : public Employee {
private:
    string Graduation_date;
    string Graduation_rank;
    string Education;

public:
    Fresher(string gradDate, string gradRank, string edu)
        : Graduation_date(gradDate), Graduation_rank(gradRank), Education(edu) {
        Employee_type = 1; // Employee_type 1 corresponds to Fresher
    }

    void ShowInfo() override {
        cout << "Fresher Employee" << endl;
        cout << "ID: " << ID << endl;
        cout << "Full Name: " << FullName << endl;
        cout << "BirthDay: " << BirthDay << endl;
        cout << "Phone: " << Phone << endl;
        cout << "Email: " << Email << endl;
        cout << "Graduation Date: " << Graduation_date << endl;
        cout << "Graduation Rank: " << Graduation_rank << endl;
        cout << "Education: " << Education << endl;
    }
};

// Intern class
class Intern : public Employee {
private:
    string Majors;
    string Semester;
    string University_name;

public:
    Intern(string majors, string semester, string uniName)
        : Majors(majors), Semester(semester), University_name(uniName) {
        Employee_type = 2; // Employee_type 2 corresponds to Intern
    }

    void ShowInfo() override {
        cout << "Intern Employee" << endl;
        cout << "ID: " << ID << endl;
        cout << "Full Name: " << FullName << endl;
        cout << "BirthDay: " << BirthDay << endl;
        cout << "Phone: " << Phone << endl;
        cout << "Email: " << Email << endl;
        cout << "Majors: " << Majors << endl;
        cout << "Semester: " << Semester << endl;
        cout << "University Name: " << University_name << endl;
    }
};

// Controller class for managing employees
class EmployeeController {
private:
    vector<Employee*> employees;

public:
    void AddEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void UpdateEmployee(int id, Employee* emp) {
        for (Employee* e : employees) {
            if (e->GetID() == id) {
                *e = *emp;
                break;
            }
        }
    }

    void DeleteEmployee(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if ((*it)->GetID() == id) {
                delete *it;
                employees.erase(it);
                break;
            }
        }
    }

    void ShowAllInterns() {
        cout << "Intern Employees:" << endl;
        for (Employee* emp : employees) {
            if (emp->GetEmployeeType() == 2) {
                emp->ShowInfo();
                cout << endl;
            }
        }
    }

    void ShowAllExperiences() {
        cout << "Experience Employees:" << endl;
        for (Employee* emp : employees) {
            if (emp->GetEmployeeType() == 0) {
                emp->ShowInfo();
                cout << endl;
            }
        }
    }

    void ShowAllFreshers() {
        cout << "Fresher Employees:" << endl;
        for (Employee* emp : employees) {
            if (emp->GetEmployeeType() == 1) {
                emp->ShowInfo();
                cout << endl;
            }
        }
    }
};

int main() {
    EmployeeController controller;
    
    // Create and add employees
    Experience* expEmployee = new Experience(5, "Java");
    // expEmployee->SetFullName("John Doe");
    // expEmployee->BirthDay = "01/01/1980";
    // expEmployee->Phone = "123-456-7890";
    // expEmployee->Email = "john.doe@example.com";

    Fresher* fresherEmployee = new Fresher("01/01/2023", "Distinction", "ABC University");
    // fresherEmployee->SetFullName("Jane Smith");
    // fresherEmployee->BirthDay = "01/01/1995";
    // fresherEmployee->Phone = "987-654-3210";
    // fresherEmployee->Email = "jane.smith@example.com";

    Intern* internEmployee = new Intern("Computer Science", "Spring 2023", "XYZ University");
    // internEmployee->SetFullName("Alice Johnson");
    // internEmployee->BirthDay = "01/01/2000";
    // internEmployee->Phone = "555-555-5555";
    // internEmployee->Email = "alice.johnson@example.com";

    controller.AddEmployee(expEmployee);
    controller.AddEmployee(fresherEmployee);
    controller.AddEmployee(internEmployee);

    // Show all employees of each type
    controller.ShowAllExperiences();
    controller.ShowAllFreshers();
    controller.ShowAllInterns();

    // Update an employee
    Experience* updatedExpEmployee = new Experience(7, "C++");
    updatedExpEmployee->SetFullName("John Doe (Updated)");
    // updatedExpEmployee->BirthDay = "01/01/1980 (Updated)";
    // updatedExpEmployee->Phone = "111-111-1111";
    // updatedExpEmployee->Email = "updated.john.doe@example.com";
    controller.UpdateEmployee(expEmployee->GetID(), updatedExpEmployee);

    // Show all employees of each type after update
    controller.ShowAllExperiences();
    controller.ShowAllFreshers();
    controller.ShowAllInterns();

    // Delete an employee
    controller.DeleteEmployee(fresherEmployee->GetID());

    // Show all employees of each type after delete
    controller.ShowAllExperiences();
    controller.ShowAllFreshers();
    controller.ShowAllInterns();

    // Clean up memory
    delete updatedExpEmployee;
    delete expEmployee;
    delete fresherEmployee;
    delete internEmployee;

    return 0;
}
