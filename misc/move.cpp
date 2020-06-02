#include <iostream>
#include <string>

std::string passByValueAndMove(std::string str)
{
    std::string newStr = std::move(str);
    return newStr;
}

std::string passByRefAndMove(std::string &str)
{
    std::string newStr = std::move(str);
    return newStr;
}

int main()
{
    std::string hello {"Hello"};
    std::string hello2 = passByValueAndMove(hello);

    std::cout << hello << " " << hello2 << std::endl;

    std::string world = {"World"};
    std::string world2 = passByRefAndMove(world);

    std::cout << world << " " << world2 << std::endl;
}