#include<iostream>
#include<string>
#include<vector>
#include<memory>
using namespace std;

class Student
{
    private:
        string Name;
        int Age;
        string Class;
    public:
        Student(string _Name, int _Age, string _Class) : Name(_Name), Age(_Age), Class(_Class) {}
        ~Student() {}
        void  GetInformation() const
        {
            cout << "Name: " << Name << endl;
            cout << "Age: " << Age << endl;
            cout << "Class: " << Class << endl;
        }
};

class LibraryCard
{
    private:
        Student student;
        int CardNumber;
        string StartDate;
        string EndDate;
        int BookNumber;
    public:
        LibraryCard(Student _student, int _CardNumber, string _StartDate, string _EndDate, int _BookNumber) : student(_student), CardNumber(_CardNumber), StartDate(_StartDate), EndDate(_EndDate), BookNumber(_BookNumber) {}
        ~LibraryCard() {}
        void GetInformation() const
        {
            student.GetInformation();
            cout << "CardNumber: " << CardNumber << endl;
            cout << "StartDate: " << StartDate << endl;
            cout << "EndDate: " << EndDate << endl;
            cout << "BookNumber: " << BookNumber << endl;
        }
        int GetCardNumber()
        {
            return CardNumber;
        }
};

class LibraryMS
{
    private:
        vector<LibraryCard> libraryMS;
    public:
        LibraryMS() {}
        ~LibraryMS() {}
        void Add(LibraryCard& temp) // Note
        {
            for(auto x : libraryMS) // x equivalent with libraryMS[index]
            {
                if(x.GetCardNumber() == temp.GetCardNumber()) 
                {
                    cout << "CardNumer has been exist!" << endl;
                    return;
                }
            }
            libraryMS.push_back(temp);
            cout << "Add new card successfully!" << endl;
        }
        void Show()
        {
            if(libraryMS.size() == 0)
            {
                cout << "No information to show!" << endl;
                return;
            }
            else
            {
                int count = 1;
                for(auto x: libraryMS)
                {
                    cout << "==========STT: " << count++ << "==========" << endl;
                    x.GetInformation();
                }
            }
        }
        void Erase(int CardNumber)
        {
            for(auto x = libraryMS.begin(); x != libraryMS.end(); x++) // iterator
            {
                if((*x).GetCardNumber() == CardNumber)
                {
                    libraryMS.erase(x);
                    cout << "Delete successfully!" << endl;
                    return;
                }
            }
            cout << "Can't find cardnumber!" << endl;
        }
};

int main()
{
    LibraryMS libraryMS;
    int ch;
    do
    {
        cout << "========== Library Management System ==========" << endl;
        cout << "1. Add a new card" << endl;
        cout << "2. Show cards" << endl;
        cout << "3. Delete a card" << endl;
        cout << "4. Exit program" << endl;
        cout << "Your choise: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
            {   
                string Name;
                int Age;
                string Address;
                int CardNumber;
                string StartDate;
                string EndDate;
                int BookNumber;
                cout << "Name: ";
                cin.ignore();
                getline(cin, Name);
                cout << "Age: ";
                cin >> Age;
                cout << "Addresss: ";
                cin.ignore();
                getline(cin, Address);
                cout << "CardNumber: ";
                cin >> CardNumber;
                cout << "StartDate: ";
                cin.ignore();
                getline(cin, StartDate);
                cout << "EndDate: ";
                getline(cin, EndDate);
                cout << "BookNumber: ";
                cin >> BookNumber;
                Student student(Name, Age, Address);
                LibraryCard libraryCard(student, CardNumber, StartDate, EndDate, BookNumber);
                libraryMS.Add(libraryCard);   
                break;
            }
            case 2:
                libraryMS.Show();
                break;
            case 3:
            {
                int CardNumber;
                cout << "Enter cardnumber which you want to delete: ";
                cin >> CardNumber;
                libraryMS.Erase(CardNumber);
                break;
            }
            default:
                cout << "Your choise is incorrect!" << endl;
                break;
        }
    } while(ch != 4);
    return 0;   
}