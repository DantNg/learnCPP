#include <iostream>
#include "Employee_test.h"
// Lớp quản lý cán bộ (EmployeeManegement)
class EmployeeManegement
{
public:
    ~EmployeeManegement()
    {
        cout<<"EmployeeManegement cleared."<<endl;
        for (Employee *cb : danhSachEmployee)
        {
            delete cb;
        }
    }
    void addNewEmployee(Employee *Employee)
    {
        danhSachEmployee.push_back(Employee);
    }

    void searchName(string name)
    {
        cout << "Search result:" << endl;
        for (Employee *cb : danhSachEmployee)
        {
            if (cb->getName() == name)
            {
                cb->displayInfomation();
            }
        }
    }

    void displayListEmployee()
    {
        cout << "List of officers:" << endl;
        for (Employee *cb : danhSachEmployee)
        {
            cb->displayInfomation();
            cout << "---------------------" << endl;
        }
    }

private:
    vector<Employee *> danhSachEmployee;
};

int main()
{
    int choice = 0;
    EmployeeManegement employeeManagement;

    do
    {
        cout << "MENU:" << endl;
        cout << "1. Add new employee" << endl;
        cout << "2. Search employee with name" << endl;
        cout << "3. Display list of employees" << endl;
        cout << "4. Exit" << endl;
        cout << "Select function (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int loaiEmployee;
            cout << "Select staff type (1 - Worker, 2 - Engineer, 3 - Officer): ";
            cin >> loaiEmployee;
            if (loaiEmployee == 1)
            {
                Employee *worker = new Worker("", 0, "", "", 0);
                worker->enterInformation();
                employeeManagement.addNewEmployee(worker);
                // delete worker;
            }
            else if (loaiEmployee == 2)
            {
                Employee *engineer = new Engineer("", 0, "", "", "");
                engineer->enterInformation();
                employeeManagement.addNewEmployee(engineer);
                // delete engineer;
            }
            else if (loaiEmployee == 3)
            {
                Employee *officer = new Officer("", 0, "", "", "");
                officer->enterInformation();
                employeeManagement.addNewEmployee(officer);
                // delete officer;
            }
            break;
        case 2:
            {
                string search_name;
                cout << "Enter search name : ";
                cin>>search_name;
                employeeManagement.searchName(search_name);
            }
            break;
        case 3:
            employeeManagement.displayListEmployee();
            break;
        case 4:
            cout << "End system!" << endl;
            break;
        default:
            cout << "Your choice is not valid . Please select again!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
