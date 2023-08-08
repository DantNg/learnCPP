#include <iostream>

int main()
{
    bool isPassed = true;
    char grade = 'A';
    int age = 25;
    float percent = 50.5;
    double temperature = 98.55;
    std::cout << isPassed << std::endl;
    std::cout << grade << std::endl;
    std::cout << age << std::endl;
    std::cout << percent << std::endl;
    std::cout << temperature <<  std::endl;


    std::cout << "Size of Int: " << sizeof(int) << std::endl;
    std::cout << "Size of signed Int: " << sizeof(signed int) << std::endl;
    std::cout << "Size of unsigned Int: " << sizeof(unsigned int) << std::endl;
    std::cout << "Size of short Int: " << sizeof(short int) << std::endl;
    std::cout << "Size of long Int:	" << sizeof(long int) << std::endl;
   
}
