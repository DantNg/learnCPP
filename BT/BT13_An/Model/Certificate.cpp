#include "Certificate.h"
#include<string>
#include<iostream>

void Certificate::showMe(){
    cout << "\nId: " << CertificatedID<<endl;
    cout << "Name: " << CertificateName<<endl;
    cout << "Rank: " << CertificateRank<<endl;
    cout << "Date: " << CertificatedDate<<endl;
}
void Certificate::enterCertificate(){
    cout << "Id:"; 
    cin>> CertificatedID;
    cout << "Name: ";
    getline(cin, CertificateName);
    cout << "Rank: "; 
    cin>> CertificateRank;
    cout << "Date: "; 
    cin>> CertificatedDate;
}

void Certificate::setCertificatedID(int id) {
        CertificatedID = id;
    }

void Certificate::setCertificateName(string name) {
    CertificateName = name;
}

void Certificate::setCertificateRank(string rank) {
    CertificateRank = rank;
}

void Certificate::setCertificatedDate(string date) {
    CertificatedDate = date;
}

// Getters
int Certificate::getCertificatedID() {
    return CertificatedID;
}

string Certificate::getCertificateName() {
    return CertificateName;
}

string Certificate::getCertificateRank() {
    return CertificateRank;
}

string Certificate::getCertificatedDate() {
    return CertificatedDate;
}