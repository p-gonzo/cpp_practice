#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int inputNum = 0;
    std::cin >> inputNum;

    int halfNum = inputNum >> 1;
    int quarterNum = inputNum >> 2;
    int doubleNum = inputNum << 1;
    int quadrupleNum = inputNum << 2;

    std::cout << "Quarter: " << quarterNum << std::endl;
    std::cout << "Half: " << halfNum << std::endl;
    std::cout << "Double: " << doubleNum << std::endl;
    std::cout << "Quadruple: " << quadrupleNum << std::endl;
    
    return 0;
}