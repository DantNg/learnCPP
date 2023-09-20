#include <iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

class People{
    string name, job, identifyNumber;
    int age;
    
    public:
        People(){}
        People(string name, int age, string job, string identifyNumber){
            this->name=name;
            this->age=age;
            this->job=job;
            this->identifyNumber=identifyNumber;
        }
        ~People(){
            // cout << "Release people"<< endl;
        }

        string getName(){
            return name;
        }
        string getJob(){
            return job;
        }
        string getIdentify(){
            return identifyNumber;
        }
        int getAge(){
            return age;
        }

        void show(){
            cout << "Name: " << getName() << endl;
            cout << "Age: " << getAge() << endl;
            cout << "Job: " << getJob() << endl;
            cout << "identifyNumber: " << getIdentify() <<endl;
        }
};

class Family{
    public:
        string address;
        // Number of members
        int n;
        vector<People> listPeople;
    public:
        
        Family(){}
        ~Family(){
            // cout << "Release Family"<< endl;
            }
        void setMember(int number){
            n=number;
        }
        void setAddress(string s){
            address=s;
        }
        void show(){
            cout << "Address of house: " << address << endl;
            cout << "Number of members: " << n << endl;
            for(People p: listPeople){
                p.show();
            }
        }
        int enterN(string enterMessage, string enterFaultMessage, int min=1, int max=100){
            int n;
            cout << enterMessage;
            while (!(cin >> n)) {
                
                cin.clear();

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if(min<=n && n<=max){
                    break;
                }else{
                    cout << enterFaultMessage;
                }
            }
            return n;
        }   
        void addPeople(People p){
            listPeople.push_back(p);
        }
        bool isDuplicated(string identifyNumber){
            for(People p: listPeople){
                    if(p.getIdentify() == identifyNumber){
                        return true;
                }
        }
            return false;
        }
        void createFamily(){
            cout << "Enter address: ";
            cin.ignore();
            getline(cin, address);
            cin.clear();
            n = enterN("Enter your number of members: ", "Number of member must be great than 0");
        }
};
class City: public Family{
    public:
        vector<Family*> listFamily;
        City(){}
        ~City(){
            // cout << "Release City"<<endl;
            }
        void show(){ 
            int i=1;
            cout << "All family:"<<endl;
            for(Family* f : listFamily){
                cout << "House "<<i<<":\n";
                f->show();
                i++;
            }
        }
        void removeFamily(vector<Family*>& listFamily, int i){
            int count=0;
            for(auto p=listFamily.begin(); p!=listFamily.end();p++){
                count++;
                if(count==i){
                    listFamily.erase(p);
                    p--;
                }
            }
        }
        void addFamily(Family* f){
            listFamily.push_back(f);
        }

        bool isDuplicated(string identifyNumber, vector<People>& listPeople){
            for(Family* f: listFamily){
                for(People p: f->listPeople){
                    if(p.getIdentify() == identifyNumber){
                        return true;
                }
                }
               
            }
            for(People p: listPeople){
                    if(p.getIdentify() == identifyNumber){
                        return true;
                }
         }
          return false;
         }
       
        void createPeople(string& name, int& age, string& job, string& identifyNumber, vector<People>& listPeople){
            cin.ignore();
            cout << "Enter name: ";
            getline(cin, name);
            age = enterN("Enter age: ", "Age must be greate than 0");
            cout << "Enter job: ";
            cin.ignore();
            getline(cin, job);
            while(true){
                cout << "Enter identifyNumber: ";
                cin.ignore();
                getline(cin, identifyNumber);
                if(!isDuplicated(identifyNumber, listPeople)){
                    break;
                }else{
                    cout << "Identify Number is duplicated, Try again: "<<endl;
                }
            }
        }
        
     
};
void Menu(){
    cout << "Choose your options below: \n";
    cout << "1. create family"<<endl;
    cout << "2. Create a city"<<endl;
    cout << "3. Show all city"<<endl;
    cout << "4. Remove member from a family"<<endl;
    cout << "5. Remove a family from city" <<endl;
    cout << "6. Quit" <<endl;
}
int main(){
    string name;
    int age;
    string job, identifyNumber;
    City c;
    int n;

    while(true){
        Menu();
        while(true){
        n=c.enterN("Enter your option: ", "1<=option<=6, try again: ");
        if(n==1){
            Family* f = new Family();
            f->createFamily();
            for(int i=0; i<f->n;i++){
                cout << "People " << i+1 << endl;
                c.createPeople(name, age, job, identifyNumber, f->listPeople);
                People p = People(name, age, job, identifyNumber);
                f->addPeople(p);
            }
            c.addFamily(f);
            c.show();
        }
    
        if(n==2){
        int m;
        m=c.enterN("Enter number of house: ", "Number must be greater than 0");
            
        for(int i=0; i<m; i++){
            cout << "House "<<i+1<<endl;
            Family* f = new Family();
            f->createFamily();
            for(int i=0; i<f->n;i++){
                cout << "People " << i+1 << endl;
                c.createPeople(name, age, job, identifyNumber, f->listPeople);
                cout << "\n\n";
                People p = People(name, age, job, identifyNumber);
                f->addPeople(p);
            }
            c.addFamily(f);
        }
        
        c.show();
    }

        if(n==3){
            c.show();
        }
        
        if(n==4){
            if(c.listFamily.empty()){
                cout << "Empty family in this city\n";
                break;
            }
            string identifyNumberDeleted;
            cout << "Enter identifyNumberDeleted: ";
          cin>> identifyNumberDeleted;
            
            int b=0;

            for(Family* f: c.listFamily){
                for(auto p=f->listPeople.begin(); p!=f->listPeople.end(); p++){
                    // cout << p1.getIdentify() << endl;
                    if(p->getIdentify()==identifyNumberDeleted){
                        f->listPeople.erase(p);
                        p--;
                        b=1;
                        break;
                }
                if(b){break;}
            }
        }
        }
        if(n==5){
            if(c.listFamily.empty()){
                cout << "Empty family in this city\n";
                break;
            }
            //Remove a member from a family
            cout << "Current families:\n\n";
            c.show();
            int num=c.enterN("Enter number of family which you wanted delete: ", "Out of range, try again: ", 1, c.listFamily.size());
            cout << "Families after deleted\n";
            if(c.listFamily.empty()){
                cout << "Empty family in this city\n";
                break;
            }
            c.removeFamily(c.listFamily, num);
            c.show();
        }
        if(n==6){
            break;
        }
    }
    
    }
    return 0;
}
