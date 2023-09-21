#include "ManageCard.h"
#include "Card.h"
using namespace std;

void ManageCard::addCard(Card c){
    listCard.push_back(c);
}

void ManageCard::show(){
    for(Card c: listCard){
        c.show();
    }
}
void ManageCard::deleteCard(){
    string code;
    cout << "Enter code of card: ";
    cin.ignore();
    getline(cin, code);
    for(auto c=listCard.begin(); c!=listCard.end();c++){
        if(c->getCode()==code){
            listCard.erase(c);
            return;
        }
    }
    cout << "Not found\n";
}
    Card ManageCard::createCard(){
        Card c;
        string fullName, grade, code, startDate, endDate;
        int age;
        cout << "Enter name: ";
        getline(cin, fullName);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter grade: ";
        cin >> grade;
        cout << "Enter code: ";
        cin >> code;
        cout << "Enter start Date: ";
        cin>>startDate;
        cout << "Enter end Date: ";
        cin >>endDate;
        SinhVien s = SinhVien(fullName, grade, age);
        c.code=code;
        c.startDate=startDate;
        c.endDate=endDate;
        c.p=&s;
        return c;
    }

