
// Lớp Worker kế thừa từ Employee
class Worker : public Employee
{
public:
    Worker(string name, int age, string gender, string address, int bac)
        : Employee(name, age, gender, address), bac(bac) {}
    ~Worker()
    {
        cout << "Cong nhan released" << endl;
    }
    void enterInformation()
    {
        Employee::enterInformation();
        cout << "Employee rank: ";
        cin >> bac;
    }

    void displayInfomation()
    {
        Employee::displayInfomation();
        cout << "Employee rank: " << bac << endl;
    }

private:
    int bac;
};
