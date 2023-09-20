#include<iostream>
#include<vector>
#include<string>
#include<memory>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unique_ptr;
using std::vector;
using std::move;
class Candidate 
{
    protected:
        int Id;
        string Name;
        string Address;
        int Priority;
    public:
        Candidate(int _Id, string _Name, string _Address, int _Priority) : Id(_Id), Name(_Name), Address(_Address), Priority(_Priority) {}
        virtual ~Candidate() {}
        virtual void GetInformation() const
        {
            cout << "Id: " << Id << endl;
            cout << "Name: " << Name << endl;
            cout << "Address: " << Address << endl;
            cout << "Priority: " << Priority << endl;
        }
        int GetId()
        {
            return Id;
        }
};

class A_Candidate : public Candidate
{
    private:
        static const string Math;
        static const string Physic;
        static const string Chemistry;
    public:
        A_Candidate(int _Id, string _Name, string _Address, int _Priority) : Candidate(_Id, _Name, _Address, _Priority) {}
        ~A_Candidate() {}
        void GetInformation() const
        {
            Candidate::GetInformation();
            cout << "Grade A: " << Math << ", " << Physic << ", " << Chemistry << endl;
        }
};
const string A_Candidate::Math = "Toan";
const string A_Candidate::Physic = "Ly";
const string A_Candidate::Chemistry = "Hoa";

class B_Candidate : public Candidate
{
    private:
        static const string Math;
        static const string Physic;
        static const string Biology;
    public:
        B_Candidate(int _Id, string _Name, string _Address, int _Priority) : Candidate(_Id, _Name, _Address, _Priority) {}
        ~B_Candidate() {}
        void GetInformation() const
        {
            Candidate::GetInformation();
            cout << "Grade B: " << Math << ", " << Physic << ", " << Biology << endl;
        }

};
const string B_Candidate::Math = "Toan";
const string B_Candidate::Physic = "Ly";
const string B_Candidate::Biology = "Hoa";

class C_Candidate : public Candidate
{
    public:
        static const string Literature;
        static const string History;
        static const string Geography;
    public:
        C_Candidate(int _Id, string _Name, string _Address, int _Priority) : Candidate(_Id, _Name, _Address, _Priority) {}
        ~C_Candidate() {}
        void GetInformation() const
        {
            Candidate::GetInformation();
            cout << "Grade C: " << Literature << ", " << History << ", " << Geography << endl;
        }

};
const string C_Candidate::Literature = "Van";
const string C_Candidate::History = "Su";
const string C_Candidate::Geography = "Dia";

class Entrance
{
    private:
        vector<unique_ptr<Candidate>> entrance;
    public:
        Entrance() {}
        ~Entrance() {}
        void Add(unique_ptr<Candidate>& ptr) // Note
        {
            for(vector<unique_ptr<Candidate>>::iterator it = entrance.begin(); it != entrance.end(); it++)
            {
                if((*it)->GetId() == ptr->GetId())
                {
                    cout << "Id has been existing!" << endl;
                    return;
                }
            }
            entrance.push_back(move(ptr));
        }
        void Show()
        {
            if(entrance.size() == 0)
            {
                cout << "Nobody to show!" << endl;
            }
            else
            {
                int count = 1;
                for(vector<unique_ptr<Candidate>>::iterator it = entrance.begin(); it != entrance.end(); it++)
                {
                    cout << "=====STT: " << count++ << "=====" << endl;
                    (*it)->GetInformation();
                }
            }
        }
        void Search(int Id)
        {   
            for(vector<unique_ptr<Candidate>>::iterator it = entrance.begin(); it != entrance.end(); it++)
            {
                if((*it)->GetId() == Id)
                {
                    (*it)->GetInformation();
                    return;
                } 
            }
            cout << "Can't find!" << endl;
        }
};

void EnterInfor(int& Id, string& Name, string& Address, int& Priority)
{
    cout << "Id: ";
    cin >> Id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Address: ";
    getline(cin, Address);
    cout << "Priority: ";
    cin >> Priority;
}

int main() {
    Entrance entrance;
    int ch;
    do
    {
        cout << "========== College Entrance ==========" << endl;
        cout << "1. Add new candidate" << endl;
        cout << "2. Search by Id" << endl;
        cout << "3. Show candidates" << endl;
        cout << "4. Exit program" << endl;
        cout << "Your choise: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
            {   
                int Id;
                string Name;
                string Address;
                int Priority;
                int pick;
                cout << "========== Which grade does the candidate belong to? ==========" << endl;
                cout << "1. Grade A" << endl;
                cout << "2. Grade B" << endl;
                cout << "3. Grade C" << endl;
                cout << "Your choise: ";
                cin >> pick;
                switch(pick)
                {
                    case 1:
                    {
                        EnterInfor(Id, Name, Address, Priority);
                        unique_ptr<Candidate> temp(new A_Candidate(Id, Name, Address, Priority));
                        entrance.Add(temp);
                        break;
                    }
                    case 2:
                    {
                        EnterInfor(Id, Name, Address, Priority);
                        unique_ptr<Candidate> temp(new B_Candidate(Id, Name, Address, Priority));
                        entrance.Add(temp);
                        break;                        
                    }
                    case 3:
                    {
                        EnterInfor(Id, Name, Address, Priority);
                        unique_ptr<Candidate> temp(new C_Candidate(Id, Name, Address, Priority));
                        entrance.Add(temp);
                        break;                       
                    }
                    default:
                        cout << "Your choise is incorrect!" << endl;
                        break;
                }
                break;
            }
            case 2:
            {
                int Id;
                cout << "Enter the Id which you want to search: ";
                cin >> Id;
                entrance.Search(Id);
                break;
            }
            case 3:
                entrance.Show();
                break;
            default:
                cout << "Your choise is incorrect!" << endl;
                break;
        }
    }while(ch != 4);
    return 0;
}