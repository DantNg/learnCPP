#include "ManageEmployee.h"
#include<string>
#include<vector>
#include<iostream>
void  ManageEmployee::addEmployee(Employee* employee){
    listEmployee.push_back(employee);
}
void ManageEmployee::deleteEmployee(){
    int ID;
    cout << "Enter ID: ";
    cin >> ID;
    for(auto emp= listEmployee.begin(); emp!=listEmployee.end(); emp++){
        if(ID== (*emp)->getID()){
            listEmployee.erase(emp);
            return;
        }
    }
    cout << "Not found\n";
}
void ManageEmployee::showAll(){
    if(listEmployee.empty()){
        cout <<"No employee\n";
        return;}
    for(Employee* employee: listEmployee){
        employee->showMe();
    }
}
void ManageEmployee::updateEmployee(){
    int ID;
    string mode;
    cout << "Enter ID: ";
    cin >> ID;
    Employee* updatedEmployee;
    for(Employee* emp: listEmployee){
        if(ID==emp->getID()){
            updatedEmployee=emp;
            break;
        }
    }
    if(ID!=updatedEmployee->getID()){
        cout << "Not Found"<<endl;
        return;
    }
    string value;
    cout << "Enter mode lower case( name, birthday, phone, email, employee_type): ";
    cin >> mode;
    cout << "Enter value: ";
    cin.ignore();
    getline(cin, value);
    if(mode == "name"){
        updatedEmployee->setFullName(value);
    }
    if(mode == "birthday"){updatedEmployee->setFullName(value);}
    if(mode == "phone"){updatedEmployee->setFullName(value);}
    if(mode == "email"){updatedEmployee->setFullName(value);}
    if(mode == "employee_type"){updatedEmployee->setFullName(value);}
}

int ManageEmployee::size(){
    return listEmployee.size();
}

void ManageEmployee::addCerti(){
    int ID;
    string mode;
    cout << "Enter ID: ";
    cin >> ID;
    Certificate c;
    c.enterCertificate();
    for(Employee* emp: listEmployee){
        if(ID==emp->getID()){
            emp->addCertificate(c);
            break;
        }
    }

}