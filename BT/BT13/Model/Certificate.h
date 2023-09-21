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

private:
    int certID;
    std::string certName;
    std::string certRank;
    std::string certDate;
};
