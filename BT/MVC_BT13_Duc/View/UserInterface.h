#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include<iostream>
#include<string>
#include"..\Controller\Management.h"
#include"..\Model\Experience.h"
#include"..\Model\Fresher.h"
#include"..\Model\Intern.h"

class UserInterface
{
    public:
        void Prompt(std::string s);

        void Prompt(int i);

        int GetChoice();

        void Menu();

        void NewEmpMenu();

        Employee GetNewEmp();

        Employee* GetNewExperience();

        Employee* GetNewFresher();

        Employee* GetNewIntern();

        int GetIDDelete();

        int GetIDRevice();
        
        void ShowEmpInfo(Employee* e);

        void ShowExpInfo(Employee* e);

        void ShowFrhInfo(Employee* e);

        void ShowIntInfo(Employee* e);
};

#endif // USERINTERFACE_H