#include "Application.h"
#include "../Model/Intern.h"
#include "../Model/Fresher.h"
#include "../Model/Experience.h"
// #include<iostream>
Application::Application() : manageEmployee(ManageEmployee()) {}
using namespace std;
void Application::Run(){
    while (true) {
    int choice;
    cout << "\n\nMenu:\n";
    cout << ADD_INTERN << ". Add intern\n";
    cout << ADD_FRESHER << ". Add fresher\n";
    cout << ADD_EXPERIENCE << ". Add experience\n";
    cout << ADD_CERTIFICATE << ". Add Certi\n";
    cout << DELETE_EMPLOYEE << ". Delete employee\n";
    cout << UPDATE_EMPLOYEE << ". Update employee\n";
    cout << SHOW_ALL << ". Show all employee\n";
    cout << EXIT << ". Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (static_cast<MenuChoice>(choice)) {
        case ADD_INTERN: {
            Employee* p = new Intern();
            p->enterInfor();
            // p->showMe();
            manageEmployee.addEmployee(p);
            p->setEmployeeCount(manageEmployee.size());
            break;
        }
        case ADD_FRESHER: {
            // manageEmployee.deleteEmployee();
            Employee* p = new Fresher();
            p->enterInfor();
            // p->showMe();
            manageEmployee.addEmployee(p);
             p->setEmployeeCount(manageEmployee.size());
            break;
        }
        
        case ADD_EXPERIENCE: {
            Employee* p = new Experience();
            p->enterInfor();
            // p->showMe();
            manageEmployee.addEmployee(p);
            p->setEmployeeCount(manageEmployee.size());
            break;
        }
        case DELETE_EMPLOYEE:{
            manageEmployee.deleteEmployee();
            break;
        }
        case ADD_CERTIFICATE:{
            manageEmployee.addCerti();
            break;
        }
        case SHOW_ALL:{
            manageEmployee.showAll();
            break;
        }
        case UPDATE_EMPLOYEE:
            manageEmployee.updateEmployee();
            break;
        case EXIT: {
            return;
        }
        default: {
            cout << "\nInvalid choice. Please try again.\n";
            break;
        }
    }
}
}