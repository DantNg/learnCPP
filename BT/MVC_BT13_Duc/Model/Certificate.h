#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include<iostream>
#include<string>

class Certificate
{
    private:
        int CertificateID;
        std::string CertificateName;
        std::string CertificateRank;
        std::string CertificateDate;
    public:
        Certificate(int _CertificateID, std::string _CertificateName, std::string _CertificateRank, std::string _CertificateDate);
        
        ~Certificate();

        void SetCerID(int _CertificateID);

        int GetCerID();

        void SetCerName(std::string _CertificateName);

        std::string GetCerName();

        void SetCerRank(std::string _CertificateRank);

        std::string GetCerRank(std::string _CertificateRank);

        void SetCerDate(std::string _CertificateDate);

        std::string GetCerDate();
};

#endif // CERTIFICATE_H