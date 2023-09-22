#pragma once

#include <iostream>
#include <vector>
#include "../Controller/EmployeeManagement.h"
using namespace std;
class Application
{
public:
    enum MenuChoice
    {
        ADD_NEW_EMPLOYEE = 1,
        EDIT_EMPLOYEE,
        DELETE_EMPLOYEE,
        SHOW_ALL_EMPLOYEE,
        EXIT
    };

    enum EmployeeTypeChoice
    {
        EXPERIENCE = 1,
        FRESHER,
        INTERN
    };
    Application();
    void Run();

private:
    EmployeeManagement empManager;
};

Application::Application() {}

void Application::Run()
{
    while (true)
    {
        cout << "----------------------------------------------" << endl;
        cout << "Employee Management System" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Edit Employee" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Show All Employees" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------------------------" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (static_cast<MenuChoice>(choice))
        {
        case ADD_NEW_EMPLOYEE:
            // Thêm nhân viên
            {
            int employeeType;
            cout << "Select staff type (1 - Experience, 2 - Fresher, 3 - Intern): ";
            cin >> employeeType;
            switch (static_cast<EmployeeTypeChoice>(employeeType))
            {
            case EXPERIENCE:
            {
                Employee *expEmployee = new Experience(1, "John Doe", "1990-01-15", "123-456-7890", "john.doe@email.com", 5);
                cout<<"Enter employee id : \n";
                int id;
                cin >> id;
                expEmployee->SetEmployeesID(id);
                cout<<"Enter employee name : \n";
                string name;
                cin>>name;
                expEmployee->SetFullName(name);
                cout<<"Enter employee birth date : \n";
                string birthDate;
                cin>>birthDate;
                expEmployee->SetBirthDate(birthDate);
                cout<<"Enter employee phone : \n";
                string phone;
                cin>>phone;
                expEmployee->SetPhone(phone);
                cout<<"Enter employee email : \n";
                string email;
                cin>>email;
                expEmployee->SetEmail(email);
                cout<<"Enter employee experience : \n";
                int experience;
                cin>>experience;
                dynamic_cast<Experience*>(expEmployee)->SetExpYears(experience);

                empManager.AddEmployee(expEmployee);
            }
                break;
            case FRESHER:
            {
                Employee *fresherEmployee = new Fresher(2, "Alice Smith", "1995-03-20", "987-654-3210", "alice.smith@email.com", "2022-06-01", "Honors", "University A");
                empManager.AddEmployee(fresherEmployee);
            }
                break;
            case INTERN:
            {
                Employee *internEmployee = new Intern(3, "Bob Johnson", "2000-07-10", "555-555-5555", "bob.johnson@email.com", "Computer Science", "Spring 2023", "University B");
                empManager.AddEmployee(internEmployee);
            }
                break;
            default:
                break;
            }
            }
            break;

        case EDIT_EMPLOYEE:
            // Sửa thông tin nhân viên   
        {
            int employeeType;
            cout << "Select staff type (1 - Experience, 2 - Fresher, 3 - Intern): ";
            cin >> employeeType;
            cout<< "\nSelect employee ID : ";
            int id;
            cin >> id;
            switch (static_cast<EmployeeTypeChoice>(employeeType))
            {
            case EXPERIENCE:
            {
                Experience *expEmployee = new Experience();
                empManager.EditEmployee(id,expEmployee);
            }
                break;
            case FRESHER:
            {
                Fresher *fresherEmployee = new Fresher(2, "Alice Smith", "1995-03-20", "987-654-3210", "alice.smith@email.com", "2022-06-01", "Honors", "University A");
                empManager.EditEmployee(id,fresherEmployee);
            }
                break;
            case INTERN:
            {
                Intern *internEmployee = new Intern(3, "Bob Johnson", "2000-07-10", "555-555-5555", "bob.johnson@email.com", "Computer Science", "Spring 2023", "University B");
                empManager.EditEmployee(id,internEmployee);
            }
                break;
            default:
                break;
            }
        }
        
            break;

        case DELETE_EMPLOYEE:
            // Xóa nhân viên
            cout << "Select employee ID to delete : ";
            int id;
            cin >> id;
            empManager.DeleteEmployee(id);
            break;

        case SHOW_ALL_EMPLOYEE:
            // Hiển thị danh sách nhân viên
            empManager.ShowAllEmployees();
            break;

        case EXIT:
            // Thoát khỏi chương trình
            break;
            return;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
