#include<iostream>
#include<string>
#include"Certificate.h"

Certificate::Certificate(int _CertificateID, std::string _CertificateName, std::string _CertificateRank, std::string _CertificateDate)
    : CertificateID(_CertificateID), CertificateName(_CertificateName), CertificateRank(_CertificateRank), CertificateDate(_CertificateDate) {}         
Certificate::~Certificate() {}

void Certificate::SetCerID(int _CertificateID)
{
    CertificateID = _CertificateID;
}

int Certificate::GetCerID()
{
    return CertificateID;
}

void Certificate::SetCerName(std::string _CertificateName)
{
    CertificateName = _CertificateName;
}

std::string Certificate::GetCerName()
{
    return CertificateName;
}

void Certificate::SetCerRank(std::string _CertificateRank)
{
    CertificateRank = _CertificateRank;
}

std::string Certificate::GetCerRank(std::string _CertificateRank)
{
    return CertificateRank;
}

void Certificate::SetCerDate(std::string _CertificateDate)
{
    CertificateDate = _CertificateDate;
}

std::string Certificate::GetCerDate()
{
    return CertificateDate;
}
