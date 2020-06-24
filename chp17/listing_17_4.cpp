#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ints { 50, 1, 987, 1001 };

    for (size_t i = 0; i < ints.size(); ++i)
    {
        std::cout << "Element[" << i << "] = " << ints[i] << std::endl;
    }

    ints[2] = 2011;
    std::cout << "Replace element at index 2:" << std::endl;
    std::cout << "Element[2] = " << ints[2] << std::endl;

    return 0;
}