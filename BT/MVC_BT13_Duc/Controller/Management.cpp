#include<iostream>
#include"Management.h"

Management::Management() {}

Management::~Management() {}

void Management::Run()
{

}

void Management::AddNewEmp(Employee* e)
{
    for(const std::unique_ptr<Employee>& x : management)
    {
        if(x->GetID() == e->GetID())
        {
            userinterface.Prompt("ID has been exist!\n");
            return;
        }
    }
    management.push_back(std::unique_ptr<Employee>(e));
}

void Management::DeleteEmp(int ID)
{
    for(std::vector<std::unique_ptr<Employee>>::iterator it = management.begin(); it != management.end(); it++)
    {
        if((*it)->GetID() == ID)
        {
            management.erase(it);
            return;
        }
    }
    userinterface.Prompt("Can't find ID!\n");
}

void Management::ShowAllEmp()
{
    for(const std::unique_ptr<Employee>& x : management)
    {
        switch(x->GetEmpType())
        {
            case EXPERIENCE:
            {
                userinterface.show
                break;
            }
            case FRESHER:
            {
                break;
            }
            case INTERN:
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

void Management::SearchID(int ID)
{

}

void Management::SearchType()
{

}
