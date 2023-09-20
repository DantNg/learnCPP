#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;


class Student{
    private:
        string fullName, doB, phoneNumber, universityName, gradeLevel;
        char sex;
    public:
        Student(){}
        Student(string fullName, char sex, string doB, string phoneNumber, string universityName, string gradeLevel){
            this->fullName=fullName;
            this->sex = sex;
            this->doB=doB;
            this->phoneNumber=phoneNumber;
            this->universityName=universityName;
            this->gradeLevel=gradeLevel;
        }
        ~Student(){}

        virtual  void ShowMyInfor(){
            cout << "Name: " << fullName << endl;
            cout << "Date of birth: " << doB << endl;
            cout << "Phone number: " << phoneNumber << endl;
            cout <<  "Univerity Name: "<< universityName << endl;
            cout << "Grade level: " <<gradeLevel <<endl;
        }
        string getName(){
            return fullName;
        }
        string getGradeLevel(){
            return gradeLevel;
        }
        virtual double getGPA()=0;
        virtual double getEntryScore()=0;
        virtual double getEnglishScore()=0;
        

};

class GoodStudent: public Student{
    public:
        double gpa;
        string bestRewardName;
        vector<Student*> listGoodStudent;
    public:
        GoodStudent(){}
        GoodStudent(string fullName, char sex, string doB, string phoneNumber, string universityName, string gradeLevel, double gpa, string bestRewardName): Student( fullName,  sex,  doB,  phoneNumber,  universityName,  gradeLevel), gpa(gpa), bestRewardName(bestRewardName){}
        ~GoodStudent(){}

        void enterInfor(){
            cout << "Enter gpa: ";
            cin >> gpa;
            cout << "Enter bestRewardName: ";
            cin >> bestRewardName;
        }
        void addGoodStudent(Student* s){
            listGoodStudent.push_back(s);
        }
        void ShowMyInfor ()override{
            Student::ShowMyInfor();
            cout << "GPA: " << gpa << endl;
            cout << "Best Reward Name: " << bestRewardName << endl;
        }
        double getGPA(){return gpa;};
        double getEntryScore(){
            return 0;
        }
        double getEnglishScore(){
            return 0;
        }

};

class NormalStudent:public Student{
    public:
        int englisScore;
        double entryTestScore;
        vector<Student*> listNormalStudent;
    public:
    NormalStudent(){}
        void addNormalStudent(Student* s){
            listNormalStudent.push_back(s);
        }
        NormalStudent(string fullName, char sex, string doB, string phoneNumber, string universityName, string gradeLevel, int englisScore, double entryTestScore): Student( fullName,  sex,  doB,  phoneNumber,  universityName,  gradeLevel), englisScore(englisScore), entryTestScore(entryTestScore){}
        void ShowMyInfor() override{
            Student::ShowMyInfor();
            cout << "English score: "<< englisScore << endl;
            cout << "Entry test score: " << entryTestScore << endl;
        }
        double getGPA(){return 0;}
        double getEntryScore(){
            return entryTestScore;
        }
        double getEnglishScore(){
            return englisScore;
        }
   
        
};

class chooseCandidates{
    // number of candidates
    public:
    int n;
    vector<Student*> Candidates;
    public:
    chooseCandidates(){}
    ~chooseCandidates(){}
    void showCandidates(vector<GoodStudent> listGoodStudent){
        for(GoodStudent g:listGoodStudent){
            g.ShowMyInfor();
        }
    }
int enterN(string enterMessage, string enterFaultMessage, int min =2, int man=5){
        int n;
        
        while(true){
            int n;
            string input;

            cout << enterMessage;
            getline(cin, input);

            istringstream iss(input);
            iss >> n;

            if (iss.fail()) {
                cout << "You entered a string. Please enter an int nent time." << endl;
            } else {
                if(n>=min && n<=man){
                    return n;
                }else{
                    cout << enterFaultMessage << endl;
                }
                
            }
        }
        
        return n;
    }   
    void addCandidate(Student* s){
        Candidates.push_back(s);
    }
    vector<Student*> sortGoodStudent(vector<Student*> listGoodStudent){
    for(int i=0; i<listGoodStudent.size(); i++){
        for(int j=i; j<listGoodStudent.size(); j++){
            if(listGoodStudent[i]->getGPA()<listGoodStudent[j]->getGPA()){
                Student* temp = listGoodStudent[i];
                listGoodStudent[i] = listGoodStudent[j];
                listGoodStudent[j] = temp;
            }
            if(listGoodStudent[i]->getGPA() == listGoodStudent[j]->getGPA()){
                if(listGoodStudent[i]->getName()>listGoodStudent[j]->getName()){
                    Student* temp = listGoodStudent[i];
                    listGoodStudent[i] = listGoodStudent[j];
                    listGoodStudent[j] = temp;
            }
            }
        }
    }    
    return listGoodStudent;
    }
    vector<Student*> sortNormalStudent(vector<Student*> listNormalStudent){
        for(int i=0; i<listNormalStudent.size(); i++){
            for(int j=i; j<listNormalStudent.size(); j++){
                if(listNormalStudent[i]->getEntryScore()<listNormalStudent[j]->getEntryScore()){
                    Student* temp = listNormalStudent[i];
                    listNormalStudent[i] = listNormalStudent[j];
                    listNormalStudent[j] = temp;
                }
                if(listNormalStudent[i]->getEntryScore() == listNormalStudent[j]->getEntryScore()){
                    if(listNormalStudent[i]->getEnglishScore()<listNormalStudent[j]->getEnglishScore()){
                        Student* temp = listNormalStudent[i];
                        listNormalStudent[i] = listNormalStudent[j];
                        listNormalStudent[j] = temp;
                    }
                }
                if((listNormalStudent[i]->getEntryScore()==listNormalStudent[j]->getEntryScore()) && (listNormalStudent[i]->getEnglishScore()==listNormalStudent[j]->getEnglishScore())){
                    if(listNormalStudent[i]->getName()>listNormalStudent[j]->getName()){
                        Student* temp = listNormalStudent[i];
                        listNormalStudent[i] = listNormalStudent[j];
                        listNormalStudent[j] = temp;
                    }
                }
            }
        }    
        return listNormalStudent;
        }
};





string removeBlank(string fullName){
    vector<string> words;
    string s = "";
    for(char c:fullName){
        if(s!="" && c==' '){
            words.push_back(s);
            s="";
        }
        if(isalpha(c)){
            s += c;
        }
    }
    if(s!=""){
        words.push_back(s);
        s="";
    }
    for(int i=0; i<words.size(); i++){
        if(i==words.size()-1){
            s += words[i];
        }else{
            s += (words[i]+' ');
        }
    }
    return s;
}
bool InvalidFullNameException(string s, int min=10, int max=50){
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
bool InvalidDOBException(string doB){
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

double enterN(string enterMessage, string enterFaultMessage, double min =2, double max=5){
        double x;
        
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



void Menu(){
    cout << "Your options:\n";
    cout << "1. Add good student\n";
    cout << "2. Add normal student\n";
    cout << "3. Take candidates\n";
    cout << "4. Quit\n";
    
    // cout << "Enter your option: ";
     
}


int main(){
    // Student g1 = Student("An", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Good");
    // NormalStudent* g2 = new NormalStudent("An", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Good",330, 5.2);
    // GoodStudent(string fullName, char sex, string doB, string phoneNumber, string universityName, string gradeLevel, double gpa, string bestRewardName)
    GoodStudent* g = new GoodStudent();
    NormalStudent* n = new NormalStudent();
    chooseCandidates* c = new chooseCandidates();
    // Student* g1 = new GoodStudent("Nguyen B", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Good", 7.7, "a");
    // Student* g2 = new GoodStudent("Nguyen A", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Good", 7.7, "a");
    // Student* g3 = new GoodStudent("Nguyen D", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Good", 8.7, "a");

    // Student* n1 = new NormalStudent("Nguyen B", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Normal", 300, 5.3);
    // Student* n2 = new NormalStudent("Nguyen A", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Normal", 800, 6);
    // Student* n3 = new NormalStudent("Nguyen D", 'M', "27/11/2001", "0123456789", "FPT Univerity", "Normal", 450, 7);
    
    // g->addGoodStudent(g1);
    // g->addGoodStudent(g2);
    // g->addGoodStudent(g3);

    // n->addNormalStudent(n1);
    // n->addNormalStudent(n2);
    // n->addNormalStudent(n3);

    // g->listGoodStudent = c->sortGoodStudent(g->listGoodStudent);
    // n->listNormalStudent = c->sortNormalStudent(n->listNormalStudent);

    // lấy 3 người
    // int members = 3;
    // if(g->listGoodStudent.size() <=members){
    //     for(Student* s:g->listGoodStudent){
    //         // s->ShowMyInfor();
    //         c->addCandidate(s);
    //     }
    // }

    // for(Student* s: c->Candidates){
    //     s->ShowMyInfor();
    // }
    // cout << c->Candidates.size();
    string fullName, doB, phoneNumber, universityName, gradeLevel, bestRewardName;
    double gpa;
    char sex;

    int englishScore;
    double entryScore;

    int option=0;
    while(true){
        Menu();
        option = c->enterN("Enter your option: ", "Invalid", 0, 5);
        if(option==4){break;}
        if(option==1){
            fullName="";
            phoneNumber="";
            doB="";
            while(true){
            cout << "Enter full name: ";
            while(!fullName.size()){
                getline(cin, fullName);
            }
            if(InvalidFullNameException(fullName)){
                fullName=removeBlank(fullName);
                break;
            }else{
                fullName="";
            }
        }
            while(true){
                    cout << "Enter date of birth: ";
                    getline(cin, doB);
                    if(InvalidDOBException(doB)){
                        break;
                    }
                }
            while(true){
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                if(InvalidPhoneNumberException(phoneNumber)){
                    break;
                }
                }
            while(true){
            cout << "Enter university name: ";
            getline(cin, universityName);
            if(InvalidFullNameException(universityName, 4, 10)){
                universityName=removeBlank(universityName);
                break;
            }
        }
            gradeLevel="Good";
            gpa = enterN("Enter gpa: ", "Invalid", 8, 10);
            while (true)
            {
                cout << "Enter your gender (F/M): ";
                cin >> sex;
                if(sex=='F' || sex=='M'){
                    break;
                }else{
                    cout << "Invalid gender\n";
                }
            }
            while(true){
            cout << "Best reward or no: ";
            while(!bestRewardName.size()){
                getline(cin, bestRewardName);
            }
            if(InvalidFullNameException(bestRewardName, 0, 10)){
                bestRewardName=removeBlank(bestRewardName);
                break;
            }else{
                bestRewardName="";
            }
        }
            Student* sxs = new GoodStudent( fullName,  sex,  doB,  phoneNumber,  universityName,  gradeLevel,  gpa,  bestRewardName);
            g->addGoodStudent(sxs);
            
        }
        if(option==2){
            fullName="";
            phoneNumber="";
            doB="";
            while(true){
            cout << "Enter full name: ";
            while(!fullName.size()){
                cin.ignore();
                cin.clear();
                getline(cin, fullName);
            }
            if(InvalidFullNameException(fullName)){
                fullName=removeBlank(fullName);
                break;
            }else{
                fullName="";
            }
        }
    
            while(true){
                    cout << "Enter date of birth: ";
                    getline(cin, doB);
                    if(InvalidDOBException(doB)){
                        break;
                    }
                }
            while(true){
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                if(InvalidPhoneNumberException(phoneNumber)){
                    break;
                }
                }
            while(true){
            cout << "Enter university name: ";
            getline(cin, universityName);
            if(InvalidFullNameException(universityName, 4, 10)){
                universityName=removeBlank(universityName);
                break;
            }
        }
     
            cout << "Enter university name: ";
            cin >> universityName;
            if(InvalidFullNameException(universityName, 3, 10)){
                universityName=removeBlank(universityName);
            }
        
            gradeLevel="Normal";
            while (true)
            {
                cout << "Enter your gender (F/M): ";
                cin >> sex;
                if(sex=='F' || sex=='M'){
                    break;
                }else{
                    cout << "Invalid gender\n";
                }
            }
            englishScore = c->enterN("Enter Toeic score from 0-> 990: ", "Invalid score", 0,990);
            entryScore = enterN("Enter entry score: ", "Invaid score", 0, 10);
            Student* sxs = new NormalStudent( fullName,  sex,  doB,  phoneNumber,  universityName,  gradeLevel,  englishScore,  entryScore);
            n->addNormalStudent(sxs);
        }

        if(option==3){
            int numberMem = c->enterN("Enter number of candidate (11-15)s: ", "Invalid number", 11, 15);
            for(Student* s: c->Candidates){
                    if(s->getGradeLevel()=="Good"){
                        g->addGoodStudent(s);
                    }else{
                        n->addNormalStudent(s);
                    }
                }
            g->listGoodStudent = c->sortGoodStudent(g->listGoodStudent);
            n->listNormalStudent = c->sortNormalStudent(n->listNormalStudent);
            if(numberMem> ((g->listGoodStudent).size())){
                for(Student* s: g->listGoodStudent){
                    c->addCandidate(s);
                }
                numberMem -= (g->listGoodStudent).size();
                for(int i=0; i<numberMem; i++){
                    c->addCandidate(n->listNormalStudent[i]);
                }
            }else{
                 for(Student* s: g->listGoodStudent){
                    c->addCandidate(s);
                }
            }
            cout << "All candidates: \n";
            for(Student* s: c->Candidates){
                s->ShowMyInfor();
            }
        }
    }
  


    return 0;
}