#include <iostream>
#include <vector>

int main()
{
    std::vector<int> intVec { 1, 2, 3, 4, 5};
    auto rValRef = (std::vector<int>&&)intVec;

    std::cout << intVec.size() << std::endl;
    std::cout << rValRef.size() << std::endl;

    return 0;
}