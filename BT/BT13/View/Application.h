#pragma once

#include <iostream>
#include <vector>
#include "../Controller/EmployeeManagement.h"
using namespace std;
class Application {
public:
    enum MenuChoice {
        ADD_NEW_EMPLOYEE = 1,
        EDIT_EMPLOYEE ,
        DELETE_EMPLOYEE,
        SHOW_ALL_EMPLOYEE,
        EXIT
    };

    Application();
    void Run();

private:
     EmployeeManagement empManager;
};



Application::Application(){}

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
           int employeeType;
            cout << "Select staff type (1 - Experience, 2 - Fresher, 3 - Intern): ";
            cin >> employeeType;
            if (employeeType == 1)
            {
                Experience* expEmployee = new Experience(1, "John Doe", "1990-01-15", "123-456-7890", "john.doe@email.com", 5);
                empManager.AddEmployee(expEmployee);
                // delete worker;
            }
            else if (employeeType == 2)
            {
               
            }
            else if (employeeType == 3)
            {
                
            }
            break;

        case EDIT_EMPLOYEE:
            // Sửa thông tin nhân viên
           
            break;

        case DELETE_EMPLOYEE:
            // Xóa nhân viên
            
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


