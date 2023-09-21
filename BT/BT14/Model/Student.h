#include<string>
#ifndef STUDENT_H
#define STUDENT_H
class Student{
    private:
        string fullName, doB, phoneNumber, universityName, gradeLevel;
        char sex;
    public:
        Student( string fullName,  char sex,  string doB,  string phoneNumber, string universityName, string gradeLevel){
            this->fullName=fullName;
            this-> sex=sex;
            this-> doB=doB;
            this-> phoneNumber=phoneNumber;
            this-> universityName=universityName;
            this-> gradeLevel=gradeLevel;

        }
        Student(){}
        ~Student(){}

        
        string getName();
        string getGradeLevel();
        string getDOB();
        string getPhoneNumber();
        string getUniversityName();

        char getGender();
        void EnterInfor();
        void ShowMyInfor();
        void setName(string FullName);
        void setGradeLevel(string Level);
        void setDOB(string DOB);
        void setPhoneNumber(string PhoneNumber);
        void setUniversityName(string UniversityName);
        void setGender(char gender);



        // virtual double getGPA()=0;
        // virtual double getEntryScore()=0;
        // virtual double getEnglishScore()=0;
        

};

#endif