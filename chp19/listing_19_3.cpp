#include <iostream>
#include <set>

int main()
{
    std::set<int> setInts { 43, 78, 27, -999, 21 };

    for (auto elem : setInts)
        std::cout << elem << ", ";
    std::cout << std::endl;

    auto foundElem = setInts.find(27);
    if (foundElem != setInts.end())
        std::cout << "Found elem: " << *foundElem << std::endl;

    foundElem = setInts.find(-1);
    if (foundElem != setInts.end())
        std::cout << "Found elem: " << *foundElem << std::endl;
    else { std::cout << "Didn't find -1" << std::endl; }

    return 0;
}