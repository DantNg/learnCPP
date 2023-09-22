#include <regex>
#include <iostream>
#include <string>
#include "function.h"

bool validFullNameException(string s, int min=10, int max=50){
    if(s.size()==0){return false;}
    for(char c: s){
        if(!isalpha(c) && c!=' '){
            cout << "Name must be alpha"<<endl;
            return false;

        }
    }
    if(int(s.size())<min){
        cout << "Length of name must be greater than " << min << " characters" << endl;
        return false;
    }else if(int(s.size())>max){
        cout << "Length of name must be less than "<< max  << " characters" << endl;
        return false;
    }
    return true;
    
}
string* splitDate(string date){
    string s;
    int i=0;
    string* arr = new string[3];
    for(char c: date){
        if(c=='/'){
            i++;
            arr[i-1] = s;
            s="";
        }else{
             s+=c;
        }
    }
    // cout << arr[1];
    arr[i]=s;
    return arr;
}
bool checkNumberString(string phoneNumber, string faultMessage){
    for(char c: phoneNumber){
        if(!isdigit(c)){
            cout << faultMessage << endl;
            return false;
        }
    }
    return true;
}
bool validDOBException(string doB){
    if(doB.size()!=9 && doB.size()!=10){
        cout << "Invalid doB\n";
        return false;
    }
    string* ptr = splitDate(doB);
    // cout << ptr[0] << "/" << ptr[1] << "/" << ptr[2] << endl;
    // cout << ptr[2].size() << endl;
    if(!(ptr[0]>="1" && ptr[0]<="31")){
        cout << "Invalid day\n";
        return false;
    }
    if(!(ptr[1]>="1" && ptr[1]<="12")){
        cout << "Invalid month\n";
        return false;
    }
    if(!(ptr[2]>="1900" && ptr[2]<="2023")){
        cout << "Invalid year\n";
        return false;
    }
    return true;
}

bool InvalidPhoneNumberException(string phoneNumber){
    if(!checkNumberString(phoneNumber, "Phone number must only contain number!")){
        return false;
    }
    string arr[6]= { "090", "098", "091", "031", "035", "038"};
    if(phoneNumber.size()!=10){
        cout << "Invalid phone nummber" << endl;
        return false;
        }
    string threeDigit = "";
    for(char c: phoneNumber){
        threeDigit += c;
        if(threeDigit.size() == 3){
            break;
        }
    }

    for(string s:arr){
        if(s==threeDigit){
            return true;
            }
    }
    cout << "Invalid phone number" << endl;
    return false;


}

int enterN(string enterMessage, string enterFaultMessage, int min =2, int max=5){
        int x;
        
        while(true){
            double x;
            string input;

            cout << enterMessage;
            getline(cin, input);

            istringstream iss(input);
            iss >> x;

            if (iss.fail()) {
                cout << "You entered a string. Please enter an double next time." << endl;
            } else {
                if(x>=min && x<=max){
                    return x;
                }else{
                    cout << enterFaultMessage << endl;
                }
                
            }
        }
        
        return x;
    }     

bool isValidEmail( std::string& email) {
     std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}