// main.cpp
#include "Card.h"
#include "SinhVien.h"
#include "ManageCard.h"
#include<iostream>
using namespace std;

void Menu(){
    cout << "1. Add card\n";
    cout << "2. Delete Card\n";
    cout << "3. Show cards\n";
    cout << "4. Quit\n";
    cout << "Enter your option: ";
}
int main() {
    ManageCard m;   
    int option=0;
    while(option!=4){
        switch (option)
            {
            case 1:
                m.createCard();
                break;
            case 2:
                m.deleteCard();
                break;
            case 3:
                m.show();
                break;
            case 4:
                break;
            default:
                break;
            }

    }
    
}

// g++ Main.cpp SinhVien.cpp Card.cpp ManageCard.cpp -o output 