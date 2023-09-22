#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
class Certificate
{
public:
    Certificate(int id, const std::string &name, const std::string &rank, const std::string &date)
        : certID(id), certName(name), certRank(rank), certDate(date) {}

    void ShowInfo() const
    {
        std::cout << "Certificate ID: " << certID << std::endl;
        std::cout << "Certificate Name: " << certName << std::endl;
        std::cout << "Certificate Rank: " << certRank << std::endl;
        std::cout << "Certificate Date: " << certDate << std::endl;
    }

private:
    int certID;
    std::string certName;
    std::string certRank;
    std::string certDate;
};

class Employee
{
public:
    Employee(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email, int type)
        : empID(id), fullName(name), birthDay(dob), phone(phone), email(email), empType(type), empCount(1) {}
    virtual ~Employee()
    {
    }
    virtual void ShowInfo() const
    {
        std::cout << "Employee ID: " << empID << std::endl;
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Date of Birth: " << birthDay << std::endl;
        std::cout << "Phone: " << phone << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Employee Type: " << empType << std::endl;
    }

    virtual void AddCertificate(int id, const std::string &name, const std::string &rank, const std::string &date)
    {
        Certificate cert(id, name, rank, date);
        certificates.push_back(cert);
    }

    int getID() const
    {
        return empID;
    }
    int getEmpType() const
    {
        return empType;
    }
    static int GetTotalEmployees()
    {
        return totalEmployees;
    }

protected:
    int empID;
    std::string fullName;
    std::string birthDay;
    std::string phone;
    std::string email;
    int empType;
    int empCount;
    std::vector<Certificate> certificates;

private:
    static int totalEmployees;
};

int Employee::totalEmployees = 0;

// Abstract classes for Employee types
class Experience : public Employee
{
public:
    Experience(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email, int expInYear)
        : Employee(id, name, dob, phone, email, 0), expYears(expInYear) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Experience in Years: " << expYears << std::endl;
    }

private:
    int expYears;
};

class Fresher : public Employee
{
public:
    Fresher(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email,
            const std::string &gradDate, const std::string &gradRank, const std::string &edu)
        : Employee(id, name, dob, phone, email, 1), graduationDate(gradDate), graduationRank(gradRank), education(edu) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Graduation Date: " << graduationDate << std::endl;
        std::cout << "Graduation Rank: " << graduationRank << std::endl;
        std::cout << "Education: " << education << std::endl;
    }

private:
    std::string graduationDate;
    std::string graduationRank;
    std::string education;
};

class Intern : public Employee
{
public:
    Intern(int id, const std::string &name, const std::string &dob, const std::string &phone, const std::string &email,
           const std::string &majors, const std::string &semester, const std::string &university)
        : Employee(id, name, dob, phone, email, 2), majors(majors), currentSemester(semester), universityName(university) {}

    void ShowInfo() const override
    {
        Employee::ShowInfo();
        std::cout << "Majors: " << majors << std::endl;
        std::cout << "Current Semester: " << currentSemester << std::endl;
        std::cout << "University Name: " << universityName << std::endl;
    }

private:
    std::string majors;
    std::string currentSemester;
    std::string universityName;
};

class EmployeeManagement
{
public:
    EmployeeManagement()
    {
        std::cout << "Employee Management created" << std::endl;
    }
    ~EmployeeManagement()
    {
        for (Employee *ee : employees)
        {
            delete ee;
        }
        std::cout << "Employee Management deleted!" << std::endl;
    }
    void AddEmployee(Employee *emp)
    {
        employees.push_back(emp);
    }

    void EditEmployee(int id, Employee *newInfo)
    {
        for (Employee *&emp : employees)
        {
            if (emp->getID() == id && emp->getEmpType() == newInfo->getEmpType())
            {
                std::cout<<"Modified employee!"<<std::endl;
                switch (emp->getEmpType())
                {
                case 0:
                    *dynamic_cast<Experience *>(emp) = *dynamic_cast<Experience *>(newInfo);
                    break;

                case 1:
                    *dynamic_cast<Fresher *>(emp) = *dynamic_cast<Fresher *>(newInfo);
                    break;

                case 2:
                    *dynamic_cast<Intern *>(emp) = *dynamic_cast<Intern *>(newInfo);
                    break;
                default:
                    break;
                };
                break;
            }
        }
    }

    void DeleteEmployee(int id)
    {
        auto it = employees.begin();
        while (it != employees.end())
        {
            if ((*it)->getID() == id)
            {
                delete *it; // Xóa đối tượng Employee khi xóa nhân viên
                it = employees.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
   
    
    void ShowAllEmployees() const
    {
        for (const Employee *emp : employees)
        {
            emp->ShowInfo();
            std::cout << std::endl;
        }
    }

private:
    std::vector<Employee *> employees;
};

int main()
{
    EmployeeManagement empManager;
    std::cout << "-------------------------Create new employees---------------------------------------" << std::endl;
    // Tạo và thêm nhân viên
    Experience exp(1, "John Doe", "1990-01-15", "123-456-7890", "john.doe@email.com", 5);
    Fresher fresh(2, "Alice Smith", "1995-03-20", "987-654-3210", "alice.smith@email.com", "2022-06-01", "Honors", "University A");
    Intern intern(3, "Bob Johnson", "2000-07-10", "555-555-5555", "bob.johnson@email.com", "Computer Science", "Spring 2023", "University B");
    std::cout << "-------------------------------- Add certificate --------------------------------" << std::endl;
    // Thêm bằng cấp cho nhân viên
    exp.AddCertificate(101, "Cert A", "Rank A", "2020-02-01");
    fresh.AddCertificate(102, "Cert B", "Rank B", "2021-03-15");
    intern.AddCertificate(103, "Cert C", "Rank C", "2023-05-10");
    std::cout << "-------------------------------- Add employees into the list of employees --------------------------------" << std::endl;
    // Thêm nhân viên vào quản lý nhân viên
    empManager.AddEmployee(&exp);
    empManager.AddEmployee(&fresh);
    empManager.AddEmployee(&intern);

    // Hiển thị tất cả nhân viên
    empManager.ShowAllEmployees();
    std::cout << "\n\n -------------------------- Modify employee information --------------------" << std::endl;
    // Sửa thông tin nhân viên
    Experience newExp(1, "John Doe (Updated)", "2010-01-15", "123-456-7890", "john.doe@email.com", 6);
    empManager.EditEmployee(1, &newExp);
    // empManager.EditEmployee(2, &newExp); //cố tính thay đổi 1 nhân viên fresher bằng 1 nv experience

    // Hiển thị lại danh sách sau khi sửa
    std::cout << "Updated Employee List:" << std::endl;
    empManager.ShowAllEmployees();
    std::cout << "\n\n---------------------------- Deleted Employee List --------------------" << std::endl;
    // Xóa nhân viên
    empManager.DeleteEmployee(2);

    // Hiển thị lại danh sách sau khi xóa
    std::cout << "Employee List after Deletion:" << std::endl;
    empManager.ShowAllEmployees();

    return 0;
}
