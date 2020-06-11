#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> intVec;

    intVec.push_back(50);
    intVec.push_back(2991);
    intVec.push_back(314);
    intVec.push_back(9999);
    intVec.push_back(-37);

    for(auto ptr = intVec.begin(); ptr != intVec.end(); ++ptr)
    {
        std::cout << *ptr << std::endl;
    }

    const int targetVal = 314;
    auto target = find(intVec.begin(), intVec.end(), targetVal);

    if (target != intVec.end())
    {
        int targetPos = distance(intVec.begin(), target);
        std::cout << "Found: " << *target << " at position: " << targetPos <<  " at address: " << &(*target) << std::endl;
    }
    else
    {
        std::cout << targetVal << " not found in the vector." << std::endl;
    }
    
    return 0;
}
