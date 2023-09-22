#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include <string>
using namespace std;
class Certificate {
private:
    int CertificatedID;
    string CertificateName;
    string CertificateRank;
    string CertificatedDate;

public:
    Certificate(){};
    // Setters
    void setCertificatedID(int id);

    void setCertificateName(string name);

    void setCertificateRank(string rank);

    void setCertificatedDate(string date);

    // Getters
    int getCertificatedID();

    string getCertificateName();

    string getCertificateRank();

    string getCertificatedDate();

    void showMe();
    void enterCertificate();
};

#endif