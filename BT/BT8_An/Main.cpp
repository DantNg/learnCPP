#include "View/Application.h"
using namespace std;

int main() {
    Application app;
    app.Run();
    
}

// g++ -g Main.cpp View/Application.cpp Controller/ManageCard.cpp Model/Card.cpp Model/Student.cpp -o output