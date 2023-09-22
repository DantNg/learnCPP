#include<iostream>
#include "View/Application.h"

int main(){
    Application app;
    app.Run();
    return 0;
}
// g++ -g Main.cpp View/Application.cpp Controller/ManageCard.cpp Model/Card.cpp Model/Student.cpp -o output