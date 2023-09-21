#include<string>
#include<iostream>
using namespace std;

#ifndef SINHVIEN_H
#define SINHVIEN_H
class SinhVien{
    public:
        string fullName;
        string grade;
        int age;
    public:
    SinhVien(){}
    SinhVien(string f, string g, int a){
        this->fullName=f;
        this->grade=g;
        this->age=a;
    }
    ~SinhVien(){}
    void show();
};
#endif

