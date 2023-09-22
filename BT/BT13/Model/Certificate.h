#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <typeinfo>

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
    int GetCertificateID() const { return certID; }
    std::string GetCertificateName() const { return certName; }
    std::string GetCertificateRank() const { return certRank; }
    std::string GetCertificateDate() const { return certDate; }

    void SetCertID(int _id) { certID = _id; }
    void SetCertName(std::string _certName){ certName = _certName; }
    void SetCertRank(int _certRank) { certRank =_certRank; }
    void SetCertDate(std::string _certDate) { certDate =_certDate; }
private:
    int certID;
    std::string certName;
    std::string certRank;
    std::string certDate;
};
