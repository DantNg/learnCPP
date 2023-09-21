#include "Card.h"
#include "SinhVien.h"
void Card::show(){
        cout << "Show card: \n";
        cout << "Borrow code: " << code<<endl;
        cout << "Start date: " << startDate<<endl;
        cout << "End date: " << endDate<<endl;
        // (*p).show();
        }

string Card::getCode(){
        return code;
    }