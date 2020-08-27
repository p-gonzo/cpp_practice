#include <algorithm>
#include <list>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void DisplayContainer(const T& container)
{
    for (auto item: container) { std::cout << item << std::endl;}
    std::cout << std::endl;
}

int main()
{
    std::list<char> charList { 'A', 'B', 'C' };
    DisplayContainer(charList);

    charList.reverse();
    DisplayContainer(charList);

    std::reverse(charList.begin(), charList.end());
    DisplayContainer(charList);

    std::vector<char> charVec(charList.cbegin(), charList.cend());
    DisplayContainer(charVec);

    std::string charString(charVec.cbegin(), charVec.cend());

    std::cout << charString << std::endl;
    
    std::reverse(charString.begin(), charString.end());
    std::cout << charString << std::endl;

    return 0;
}